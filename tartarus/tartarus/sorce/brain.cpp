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

void gaia::Brain::seed_neural_net(vectorOfBools DNA) noexcept
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

	return std::vector<float>{};
}

//Get the value of the biggest output: index and value.
IndexValue gaia::Brain::compute_trigger_value(vectorOfBools DNA, vectorOfFlots input)
{
	std::vector<float> out = run_compute(DNA, input);
	IndexValue biggest = { 0,0 };
	for (size_t i = 0; i < out.size(); i++)
	{
		if(out[i]> biggest.second)
		{
			biggest = { i,out[i] };
		}
	}
	return biggest;
}

void gaia::Brain::verify_DNA(vectorOfBools DNA)
{
	seed_neural_net(DNA);
	// Do a get dna and comper
	return false;
}

float gaia::BrainNode::get_value()const
{
	return _value;
}

void gaia::BrainNode::set_value(float newValue)
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

vectorOfBools gaia::BrainNode::set_conections(vectorOfBools DNA)
{
	_connections = DNA;
	uint index = 0;
	std::for_each(_connections.begin(), _connections.end(), [&index, DNA](bool& b) {
		b = DNA[index++];
	});
	return erase_move_n(DNA,_connections.size()); // se if this is a one off error
}

void gaia::BrainNode::resize(uint size)
{
	_connections.resize(size);
}

void gaia::NeuralNet::set_input_node_amount(uint amount)
{
	_inputNodes.resize(amount);
	std::for_each(_inputNodes.begin(), _inputNodes.end(), [amount](BrainNode& n) {
		n.resize(amount);
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
}

vectorOfBools gaia::NeuralNet::set_input_nodes(vectorOfBools nodeConactions)
{
	uint i = 0;
	for (BrainNode& node : _inputNodes)
	{
		nodeConactions = node.set_conections(nodeConactions);
	}
	return gaia::erase_move_n(nodeConactions, i);
}

vectorOfBools gaia::NeuralNet::set_hidden_nodes(vectorOfBools nodeConactions)
{
	for (std::vector<BrainNode>& hiddenNodeLayer : _hiddenNodes)
	{
		uint i = 0;
		for (BrainNode& node : hiddenNodeLayer)
		{
			nodeConactions = node.set_conections(nodeConactions);
		}
		nodeConactions = gaia::erase_move_n(nodeConactions, i);
	}
	return nodeConactions;
}

void gaia::NeuralNet::set_output_nodes(vectorOfBools nodeConactions)
{
	uint i = 0;
	for (BrainNode& node : _outputNodes)
	{
		node[nodeConactions[i++]];
	}
}

gaia::NeuralNet::NeuralNet(NodeSetUp setUp)
{
	set_input_node_amount(setUp._inputNodeAmount);
	set_output_node_amount(setUp._outputNodeAmount);
	set_hidden_node_layers(setUp._hiddenNodeLayers);
	set_hidden_node_breadth(setUp._hiddenNodeBreadth);
}

void gaia::NeuralNet::set_nods(vectorOfBools DNA)
{
	DNA = set_input_nodes(DNA);
	DNA = set_hidden_nodes(DNA);
	set_output_nodes(DNA);
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

std::vector<gaia::BrainNode> gaia::normaleze(std::vector<gaia::BrainNode> nodsIn)
{
	auto largest = std::max_element(nodsIn.begin(), nodsIn.end(), [](gaia::BrainNode nodeA, gaia::BrainNode nodeB)
	{
		return nodeA.get_value() < nodeB.get_value();
	});
	float biggestValue = largest->get_value();
	std::for_each(nodsIn.begin(), nodsIn.end(), [biggestValue](BrainNode& node)
	{
		node.set_value(node.get_value() / biggestValue);
	});

	//todo testa och testa även sett nods more more 
	return nodsIn;
}
