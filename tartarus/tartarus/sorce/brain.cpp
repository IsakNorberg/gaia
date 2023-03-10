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

void gaia::Brain::seed_neural_net(std::vector<bool> DNA) noexcept
{
	_nerualNet.set_nods(DNA);
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

void gaia::Brain::set_input(std::vector<float> input) noexcept
{
	_input = input;
}

std::vector<float> gaia::Brain::run_compute(std::vector<bool>) const noexcept
{
	return std::vector<float>();
}
float gaia::Brain::compute_trigger_value(std::vector<bool> DNA) const noexcept
{
	std::vector<float> out = run_compute(DNA);
	std::ranges::sort(out, [](float lhs, float rhs) // maby partiol sort
	{
		return lhs > rhs; // kolla vilket holl som ?r r?tt
	});
	return out.at(0);
}

bool gaia::BrainNode::operator[](size_t index)
{
	assert(index < connections.size());
	return connections.at(index);
}

void gaia::NeuralNet::set_input_node_amount(uint amount)
{
	_inputNodes.resize(amount);
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
	}
}

std::vector<bool> gaia::NeuralNet::set_input_nodes(std::vector<bool> nodeConactions)
{
	uint i = 0;
	for (BrainNode& node : _inputNodes)
	{
		node[nodeConactions[i++]];
	}
	auto it = std::rotate(nodeConactions.begin(), nodeConactions.begin()+i, nodeConactions.end());
	nodeConactions.erase(it);
	return nodeConactions;
}

std::vector<bool> gaia::NeuralNet::set_hidden_nodes(std::vector<bool> nodeConactions)
{
	return std::vector<bool>();
}

void gaia::NeuralNet::set_output_nodes(std::vector<bool> nodeConactions)
{
}

gaia::NeuralNet::NeuralNet(NodeSetUp setUp)
{
	set_input_node_amount(setUp._inputNodeAmount);
	set_output_node_amount(setUp._outputNodeAmount);
	set_hidden_node_layers(setUp._hiddenNodeLayers);
	set_hidden_node_breadth(setUp._hiddenNodeBreadth);
}

void gaia::NeuralNet::set_nods(std::vector<bool> DNA)
{
	DNA = set_input_nodes(DNA);
	DNA = set_hidden_nodes(DNA);
	set_output_nodes(DNA);
}

std::vector<float> gaia::normaleze(std::vector<float> nodsIn)
{
	return std::vector<float>();
}
