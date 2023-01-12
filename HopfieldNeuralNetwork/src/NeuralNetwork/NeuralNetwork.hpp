#pragma once

#include <vector>
#include <random>
#include <array>
#include <numeric>
#include <SFML/Graphics/Color.hpp>

// GLOBAL VARIABLE !!! // N of Neurons
constexpr int neuronCount = 10'000;

/*
i made a branch on the OG repo for when we removed the Neural Netowork part
im gonna make a new repo for THIS directory, as it seems we are slowly re-building the OG repo but better
 */

using Neuron = struct
{
	short state; 
	sf::Color color;
	// done !
};

struct NeuronUpdateManager {
	std::array<int, neuronCount> neuronIndexes{};
	unsigned int currentIndex = 0; // 

	NeuronUpdateManager()
	{
		std::iota(neuronIndexes.begin(), neuronIndexes.end(), 1);
	}

	int getNextNeuron() {
		return neuronIndexes.at(++currentIndex);
	}
};

class Weights {
	std::vector<std::vector<Ne>> weights;
public:
	Weights() = default;

	std::vector<std::vector<short>>& getWeights(){ return weights;}

	Weights();
	short query(unsigned int indexX, unsigned int indexY) const;
	const std::vector<short>& queryRow(unsigned int index) const;
	void assign2(const short& value, unsigned int indexX, unsigned int indexY);
};


class NeuralNetwork {
	std::vector<short> m_neuronStates;
	const short m_shortRange[2] = { -10'000 , 10'000 };
	
	Weights m_neuronWeights;
	NeuronUpdateManager m_updateManager;

	// read what i write, where up
	const unsigned short noiseStrength = 0.01;

public:
	NeuralNetwork();

private:
	short dotProduct(const std::vector<short>& neuronStates, const std::array<short, neuronCount>& neuronWeights) const;
	void updateNetwork();

};