#pragma once

#include "random.h"
using IndexValue = std::pair<uint, float>;

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
		float getValue() const;
		void setValue(float newValue);
		bool operator[](size_t index);
		std::vector<bool> set_conections(std::vector<bool> DNA, uint amunt); // todo use dif and macke tis: impl- is run over the amunt of conections an set then return the DNA used up
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

		std::vector<bool> set_input_nodes(std::vector<bool> nodeConactions);
		std::vector<bool> set_hidden_nodes(std::vector<bool> nodeConactions);
		void set_output_nodes(std::vector<bool> nodeConactions);
	public:
		NeuralNet(NodeSetUp setUp);
		void set_nods(std::vector<bool> DNA);
		std::vector<bool> get_set_DNA() const;
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
		std::vector<bool> get_dna_from_net();

	public:
		Brain(BrainBluePrint bluePrint);
		NodeSetUp get_node_set_up()const noexcept;
		void seed_neural_net(std::vector<bool> DNA) noexcept;
		void set_input(std::vector<float> input) noexcept;
		std::vector<float> run_compute(std::vector<bool> DNA) const noexcept;
		IndexValue compute_trigger_value(std::vector<bool> DNA) const noexcept;
		bool verify_DNA(std::vector<bool> DNA);
	};
	std::vector<BrainNode> normaleze(std::vector<gaia::BrainNode> nodsIn); //TODO: implamant

	template <class Type>
	std::vector<Type> erase_move_n(std::vector<Type> vector, size_t n) // todo test
	{
		auto it = std::rotate(vector.begin(), vector.begin() + n, vector.end());
		vector.erase(it);
		return vector;
	};
}