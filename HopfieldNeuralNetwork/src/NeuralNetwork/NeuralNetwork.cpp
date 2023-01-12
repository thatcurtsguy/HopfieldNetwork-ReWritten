#include "NeuralNetwork.hpp"
// compile with: /openmp
//#include <omp.h>

/*  -------------------- functions -------------------- */
inline const short randshort(const short& start, const short& end) {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<short> dist6(start, end); // distribution in range [1, 6]

	return dist6(rng);
}


/*  -------------------- Weights Class -------------------- */
// wont this make the size of the nested array random? nop size its 100 its values its random
Weights::Weights()
{
	weights.resize(neuronCount, std::vector<short>());
	
}

short Weights::query(const unsigned int indexX, const unsigned int indexY) const
{
	// retriving a value from the weights to read or modify 
	return weights.at(indexX).at(indexY);
}

std::vector<short> Weights::queryRow(const unsigned int index) const
{
	return weights.at(index);
}

void Weights::assign2(const short value, const unsigned int indexX, const unsigned int indexY)
{
	// the size of weights is 0 so when we call .at we get an error
	weights.at(indexX).at(indexY) = value;
}


/*  -------------------- NeuralNetwork Class -------------------- */

NeuralNetwork::NeuralNetwork()
{
	m_neuronStates.reserve(neuronCount);

	// initilising the neuronStates
	for (int i = 0; i < neuronCount; i++) {
		m_neuronStates.emplace_back(randshort(m_shortRange[0], m_shortRange[1]));
	}

	// initilising the neuronWeights
	for (int x = 0; x < neuronCount; x++) {
		for (int y = 0; y < neuronCount; y++) {
			m_neuronWeights.assign2(randshort(m_shortRange[0], m_shortRange[1]), x, y);
		}
	}
}


short NeuralNetwork::dotProduct(const std::vector<short>& neuronStates, const std::vector<short>& neuronWeights) const
{
	return static_cast<short>(std::transform_reduce(neuronStates.begin(), neuronStates.end(), neuronWeights.begin(), 0));
}

void NeuralNetwork::updateNetwork()
{
	// get the neuron we want to update
	const unsigned int neuronIndex = m_updateManager.getNextNeuron();
	const short neuronState = m_neuronStates.at(neuronIndex);

	// getting the dot product
	const short dotState = dotProduct(m_neuronStates, m_neuronWeights.queryRow(neuronIndex));

	// noise
	if ()

	return;
}

