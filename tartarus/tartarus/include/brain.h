#pragma once

#include "random.h"
#include <ranges>
using IndexValue = std::pair<uint, float>;
using vectorOfBools = std::vector<bool>;
using vectorOfFlots = std::vector<float>;

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
		float _value{ 0.f };
		vectorOfBools _connections;
	public:
		float get_value() const noexcept;
		void set_value(float newValue) noexcept;
		bool operator[](size_t index);
		vectorOfBools get_DNA() const noexcept;
		void set_conections(vectorOfBools DNA);
		void resize(uint size);
		size_t size() const noexcept;
		void add_value(float number);

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

		void calculate_hidden_to_hidden();
		vectorOfFlots calculade_hidden_to_out();
		void calculate_in_to_hidden(vectorOfFlots input);

		vectorOfBools set_input_nodes(vectorOfBools nodeConactions);
		vectorOfBools set_hidden_nodes(vectorOfBools nodeConactions);
	public:
		vectorOfFlots run(vectorOfFlots input);
		NeuralNet(NodeSetUp setUp);
		void set_nods(vectorOfBools DNA);
		vectorOfBools get_set_DNA() const;
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
		vectorOfFlots _input;
		NeuralNet _nerualNet;
		vectorOfBools get_dna_from_net();
		void verify_DNA(vectorOfBools DNA);
		void seed_neural_net(vectorOfBools DNA);

	public:
		Brain(BrainBluePrint bluePrint);
		NodeSetUp get_node_set_up()const noexcept;
		void set_input(vectorOfFlots input) noexcept;
		std::vector<float> run_compute(vectorOfBools DNA, vectorOfFlots input) ;
		IndexValue compute_trigger_value(vectorOfBools DNA, vectorOfFlots input);
	};
	
	std::vector<BrainNode> normaleze(std::vector<BrainNode> nodsIn); 
	std::vector<BrainNode> add_number_to_nodes(gaia::BrainNode inNode, std::vector<BrainNode> inVector);
	template <class Type>
	std::vector<Type> erase_move_n(std::vector<Type> vector, size_t n) // todo test
	{
		auto it = std::rotate(vector.begin(), vector.begin() + n, vector.end());
		vector.erase(it);
		return vector;
	};
	
}