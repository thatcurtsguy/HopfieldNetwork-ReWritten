#include "Simulation/Simulation.h"
#include <memory>



int main()
{
    //constexpr NeuralNetwork_Settings neural_network_settings{ 120, 120 ,0 , false };
    static const std::unique_ptr<Simulation_GUI_Settings> simulation_settings = std::make_unique<Simulation_GUI_Settings>("Hopfield Neural Netowork", 1280, 1024, 0, false);
    static const std::unique_ptr<Simulation> simulation = std::make_unique<Simulation>();

    if (simulation->Init(simulation_settings))
		simulation->Run();
    else throw "some error !!";

    return 0;
}