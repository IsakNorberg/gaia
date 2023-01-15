#pragma once

#include "random.h"

namespace gaia
{
	struct NodeSetUp
	{
		NodeSetUp(unsigned int inputNodeAmount, unsigned int hiddenNodeAmountPerLayers, unsigned int hiddenNodeLayers, unsigned int outputNodeAmount) noexcept;
		unsigned int _inputNodeAmount{ 0 };
		unsigned int _hiddenNodeBreadth{ 0 };
		unsigned int _hiddenNodeLayers{ 0 };
		unsigned int _outputNodeAmount{ 0 };
	private:
		void correct_set_up_check(unsigned int inputNodeAmount, unsigned int hiddenNodeAmountPerLayers, unsigned int hiddenNodeLayers, unsigned int outputNodeAmount) noexcept;
	};
	class BrainNode
	{
		float valu;
		std::vector<bool> connections;
	public:
		bool operator[](size_t index);
	};

	class NeuralNet
	{
		std::vector<BrainNode> _inputNodes;
		std::vector <std::vector<BrainNode>> _hiddenNodes;
		std::vector<BrainNode> _outputNodes;
		void set_input_node_amount(unsigned int amount);
		void set_output_node_amount(unsigned int amount);
		void set_hidden_node_layers(unsigned int amount);
		void set_hidden_node_breadth(unsigned int amount);
	public:
		NeuralNet(NodeSetUp setUp);
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
		NodeSetUp _setUp;
		Negativity _attribute;
		std::vector<float> _input;
		NeuralNet _nerualNet;

	public:
		Brain(BrainBluePrint bluePrint);
		NodeSetUp get_node_set_up()const noexcept;
		void seed_neural_net(std::vector<bool> DNA);

		void set_input(std::vector<float> input) noexcept;
		std::vector<float> run_compute(std::vector<bool> DNA) const noexcept;
		float compute_trigger_value(std::vector<bool> DNA) const noexcept;

	};
	std::vector<float> normaleze(std::vector<float> nodsIn); //TODO: implamant
}