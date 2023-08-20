#include "brain.h"

namespace
{
	inline float random(uint precition, gaia::Negativity atribute) noexcept
	{
		if (atribute == gaia::Negativity::NagativAndPositive)
		{
			return  gaia::get_random_range_normalized(precition);
		}
		else if (atribute == gaia::Negativity::Positive)
		{
			return  gaia::get_random_range_normalized_posetiv(precition);
		}
		assert(!"");
		return .0f;
	}
}


gaia::NodeSetUp::NodeSetUp(uint inputNodeAmount,
						   uint hiddenNodeAmountPerLayers,
						   uint hiddenNodeLayers,
						   uint outputNodeAmount) noexcept
	:_inputNodeAmount{ inputNodeAmount },
	_hiddenNodeBreadth{ hiddenNodeAmountPerLayers },
	_hiddenNodeLayers{ hiddenNodeLayers },
	_outputNodeAmount{ outputNodeAmount }
{
	correct_set_up_check(inputNodeAmount, hiddenNodeAmountPerLayers, hiddenNodeLayers, outputNodeAmount);
}

void gaia::NodeSetUp::correct_set_up_check(uint inputNodeAmount, uint hiddenNodeAmountPerLayers, uint hiddenNodeLayers, uint outputNodeAmount) noexcept
{
	if (0 == inputNodeAmount +
		hiddenNodeLayers +
		hiddenNodeAmountPerLayers +
		outputNodeAmount)
	{
		assert(!"set up is empty");
	}
	if (inputNodeAmount == 0 ||
		hiddenNodeAmountPerLayers == 0 ||
		hiddenNodeLayers == 0 ||
		outputNodeAmount == 0)
	{
		assert(!"no variable can be zero");
	}
}

void gaia::Brain::seed_neural_net(vectorOfBools DNA) 
{
	_nerualNet.set_nods(DNA);
}

vectorOfBools gaia::Brain::get_dna_from_net()
{
	return _nerualNet.get_set_DNA();
}

gaia::Brain::Brain(gaia::BrainBluePrint bluePrint) :_attribute(bluePrint._attribute), _nerualNet(bluePrint._setUp)
{
	const NodeSetUp setUp = bluePrint._setUp;
	_inputNodeAmount = setUp._inputNodeAmount;
	_hiddenNodeBreadth = setUp._hiddenNodeBreadth;
	_hiddenNodeLayers = setUp._hiddenNodeLayers;
	_outputNodeAmount = setUp._outputNodeAmount;
}

gaia::NodeSetUp gaia::Brain::get_node_set_up()const noexcept
{
	return { _inputNodeAmount, _hiddenNodeBreadth, _hiddenNodeLayers, _outputNodeAmount };
}

void gaia::Brain::set_input(vectorOfFlots input) noexcept
{
	_input = input;
}

std::vector<float> gaia::Brain::run_compute(vectorOfBools DNA, vectorOfFlots input)
{ 
	seed_neural_net(DNA);
	verify_DNA(DNA);
	return _nerualNet.run(input);
}

//Get the value of the biggest output: index and value.
IndexValue gaia::Brain::compute_trigger_value(vectorOfBools DNA, vectorOfFlots input)
{
	std::vector<float> out = run_compute(DNA, input);
	IndexValue biggest((uint)0, 0.f);
	for (size_t i = 0; i < out.size(); i++)
	{
		if(out.at(i)> biggest.second)
		{
			biggest = { (uint)i,out.at(i) };
		}
	}
	return biggest;
}

void gaia::Brain::verify_DNA(vectorOfBools DNA)
{
	vectorOfBools testDna = _nerualNet.get_set_DNA();
	if (testDna == DNA)
	{
		return;
	}
	else
	{
		std::runtime_error("The DNA is not the same");
	}
}


float gaia::BrainNode::get_value()const noexcept
{
	return _value;
}

void gaia::BrainNode::set_value(float newValue) noexcept
{
	_value = newValue;
}

bool gaia::BrainNode::operator[](size_t index)
{
	assert(index < _connections.size());
	return _connections.at(index);
}

vectorOfBools gaia::BrainNode::get_DNA() const noexcept
{
	return this->_connections;
}

void gaia::BrainNode::set_conections(vectorOfBools DNA)
{
	_connections = DNA;
	for (size_t i = 0; i < _connections.size()-1; i++)
	{
		_connections.at( i) = DNA.at(i);
	}
}

void gaia::BrainNode::resize(uint size)
{
	_connections.resize(size);
}

size_t gaia::BrainNode::size() const noexcept
{
	return _connections.size();
}

void gaia::BrainNode::add_value(float number)
{
	_value = _value + number;
}

void gaia::NeuralNet::set_input_node_amount(uint amount)
{
	_inputNodes.resize(amount);
	std::for_each(_inputNodes.begin(), _inputNodes.end(), [&](BrainNode& n) {
		n.resize((uint)_hiddenNodes.at(0).size());
	});
}

void gaia::NeuralNet::set_output_node_amount(uint amount)
{
	_outputNodes.resize(amount);
}

void gaia::NeuralNet::set_hidden_node_layers(uint amount)
{
	_hiddenNodes.resize(amount);
}

void gaia::NeuralNet::set_hidden_node_breadth(uint amount)
{
	for (auto& vector : _hiddenNodes)
	{
		vector.resize(amount);
		std::for_each(vector.begin(), vector.end(), [amount](BrainNode& n) {
			n.resize(amount);
		});
	}
	auto vector = _hiddenNodes.at(_hiddenNodes.size() - 1);
	std::for_each(vector.begin(), vector.end(), [&](BrainNode& n) {
		n.resize((uint)_outputNodes.size());
	});
}

vectorOfBools gaia::NeuralNet::set_input_nodes(vectorOfBools nodeConactions)
{
	for (BrainNode& node : _inputNodes)
	{
		vectorOfBools temp;
		std::copy_n(nodeConactions.begin(), node.size(), std::back_inserter(temp));
		node.set_conections(temp);
		nodeConactions = gaia::erase_move_n(nodeConactions, node.size());
	}
	return nodeConactions;
}

vectorOfBools gaia::NeuralNet::set_hidden_nodes(vectorOfBools nodeConactions)
{
	for (size_t i = 0; i < _hiddenNodes.size(); i++)
	{
		
		for (BrainNode& node : _hiddenNodes[i])
		{
			size_t amount = node.size();
			if (i == _hiddenNodes.size() - 1)
			{
				amount = _outputNodes.size();
			}
			vectorOfBools temp;
			std::copy_n(nodeConactions.begin(), amount, std::back_inserter(temp));
			node.set_conections(temp);
			nodeConactions = gaia::erase_move_n(nodeConactions, amount);
		}
	}
	return nodeConactions;
}


void gaia::NeuralNet::calculate_hidden_to_hidden() 
{
	for (size_t i = 0; i < _hiddenNodes.size()-1; i++)
	{
		std::vector<BrainNode> currentNodes = _hiddenNodes.at(i);
		std::vector<BrainNode> nextNodes = _hiddenNodes.at(i+1);
		for (const BrainNode node : currentNodes)
		{
			nextNodes = add_number_to_nodes(node, nextNodes);
		}
		nextNodes = normaleze(nextNodes);
	}
}

vectorOfFlots gaia::NeuralNet::calculade_hidden_to_out()
{
	std::vector<BrainNode>& lastHiddenNode = _hiddenNodes.at(_hiddenNodes.size()-1);
	for (const BrainNode node : lastHiddenNode)
	{
		_outputNodes = add_number_to_nodes(node, _outputNodes);
	}
	_outputNodes = normaleze(_outputNodes);
	vectorOfFlots outValues;
	for (auto& nodes : _outputNodes)
	{
		outValues.push_back(nodes.get_value());
	}
	return outValues;
}

vectorOfFlots gaia::NeuralNet::run(vectorOfFlots input)
{ 
	calculate_in_to_hidden(input);
	calculate_hidden_to_hidden();
	return calculade_hidden_to_out();
}

void gaia::NeuralNet::calculate_in_to_hidden(vectorOfFlots input)
{
	std::vector<BrainNode>& firstHiddenNode = _hiddenNodes.at(0);
	for (size_t i = 0; i < input.size(); i++)
	{
		_inputNodes[i].set_value(input.at(i));
	}
	for (const BrainNode node : _inputNodes)
	{
		firstHiddenNode = add_number_to_nodes(node, firstHiddenNode);
	}
	firstHiddenNode = normaleze(firstHiddenNode);
}

gaia::NeuralNet::NeuralNet(NodeSetUp setUp)
{
	set_output_node_amount(setUp._outputNodeAmount);
	set_hidden_node_layers(setUp._hiddenNodeLayers);
	set_hidden_node_breadth(setUp._hiddenNodeBreadth);
	set_input_node_amount(setUp._inputNodeAmount);
}

void gaia::NeuralNet::set_nods(vectorOfBools DNA)
{
	DNA = set_input_nodes(DNA);
	DNA = set_hidden_nodes(DNA);
}

vectorOfBools gaia::NeuralNet::get_set_DNA() const
{
	vectorOfBools DNA; 
	auto get_DNA_Node = [&DNA](BrainNode b) {
		DNA.append_range(b.get_DNA());
	};
	std::for_each(_inputNodes.begin(), _inputNodes.end(), get_DNA_Node);
	std::for_each(_hiddenNodes.begin(), _hiddenNodes.end(), [&DNA, get_DNA_Node](std::vector<BrainNode> v) {
		std::for_each(v.begin(), v.end(), get_DNA_Node);
	});
	return DNA;
}

std::vector<gaia::BrainNode> gaia::normaleze(std::vector<BrainNode> nodsIn)
{
	auto largest = std::max_element(nodsIn.begin(), nodsIn.end(), [&](gaia::BrainNode nodeA, gaia::BrainNode nodeB)
	{
		return nodeA.get_value() < nodeB.get_value();
	});
	const float biggestValue = largest->get_value();
	std::for_each(nodsIn.begin(), nodsIn.end(), [biggestValue](gaia::BrainNode& node)
	{
		node.set_value(node.get_value() / biggestValue);
	});

	return nodsIn;
}

std::vector<gaia::BrainNode> gaia::add_number_to_nodes(gaia::BrainNode inNode, std::vector<BrainNode> inVector)
{
	vectorOfBools DNA = inNode.get_DNA();
	for (size_t i = 0; i < inVector.size(); i++)
	{
		if (DNA.at(i))
		{
			inVector[i].add_value(inNode.get_value());
		}
	}
	return inVector;
}
