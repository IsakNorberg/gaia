#pragma once

#include "random.h"

namespace gaia
{
	struct NodeSetUp
	{
		NodeSetUp(uint inputNodeAmount, uint hiddenNodeAmountPerLayers, uint hiddenNodeLayers, uint outputNodeAmount) noexcept;
		uint _inputNodeAmount{ 0 };
		uint _hiddenNodeBreadth{ 0 };
		uint _hiddenNodeLayers{ 0 };
		uint _outputNodeAmount{ 0 };
	private:
		void correct_set_up_check(uint inputNodeAmount, uint hiddenNodeAmountPerLayers, uint hiddenNodeLayers, uint outputNodeAmount) noexcept;
	};

	class BrainNode
	{
		float _value{ 0 };
		std::vector<bool> connections;
	public:
		bool operator[](size_t index);
	};

	class NeuralNet
	{
		std::vector<BrainNode> _inputNodes;
		std::vector <std::vector<BrainNode>> _hiddenNodes;
		std::vector<BrainNode> _outputNodes;
		void set_input_node_amount(uint amount);
		void set_output_node_amount(uint amount);
		void set_hidden_node_layers(uint amount);
		void set_hidden_node_breadth(uint amount);

		void set_input_nodes(std::vector<bool> nodeConactions);
		void set_hidden_nodes(std::vector<bool> nodeConactions);
		void set_potput_nodes(std::vector<bool> nodeConactions);
	public:
		NeuralNet(NodeSetUp setUp);
		void set_nods(std::vector<bool> DNA);
	};

	enum class Negativity
	{
		NagativAndPositive,
		Positive
	};

	struct BrainBluePrint
	{
		NodeSetUp _setUp;
		Negativity _attribute;
	};

	class Brain
	{
		uint _inputNodeAmount{ 0 };
		uint _hiddenNodeBreadth{ 0 };
		uint _hiddenNodeLayers{ 0 };
		uint _outputNodeAmount{ 0 };
		Negativity _attribute;
		std::vector<float> _input;
		NeuralNet _nerualNet;

	public:
		Brain(BrainBluePrint bluePrint);
		NodeSetUp get_node_set_up()const noexcept;
		void seed_neural_net(std::vector<bool> DNA) noexcept;
		void set_input(std::vector<float> input) noexcept;
		std::vector<float> run_compute(std::vector<bool> DNA) const noexcept;
		float compute_trigger_value(std::vector<bool> DNA) const noexcept;

	};
	std::vector<float> normaleze(std::vector<float> nodsIn); //TODO: implamant
}