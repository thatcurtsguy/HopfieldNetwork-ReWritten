#pragma once
#include <SFML/Graphics.hpp>

// wans made color xd

class Neural {
public:
	void some() const{}
	void draw() const{}
};

/*
Simulation GUI Settings // Windows title , screen size, fps limit, vsync
 */
typedef struct Simulation_GUI_Settings
{
	const sf::String windowTitle;
	const unsigned int screenWidth;
	const unsigned int screenHeight;
	const unsigned int FPS_Limit;
	const bool vSync;
	explicit Simulation_GUI_Settings(const sf::String& windowTitle = {}, const unsigned int& screenWidth = 0, const unsigned int& screenHeight = 0, const unsigned int& FPS_Limit = 0, const bool& vSync = false) :
		windowTitle(windowTitle), screenWidth(screenWidth), screenHeight(screenHeight), FPS_Limit(FPS_Limit), vSync(vSync) {}
}Simulation_GUI_Settings;



/*
Rendering everything in the Simulation
 */
class Simulation_GUI
{
	const std::unique_ptr<sf::RenderWindow> m_window = std::make_unique<sf::RenderWindow>();
	const std::unique_ptr<sf::Event> m_event = std::make_unique<sf::Event>();
	const std::unique_ptr<sf::Clock> m_clock = std::make_unique<sf::Clock>();

	int m_frames = 0;
protected:
	Neural obj;
public:
	virtual ~Simulation_GUI() {}
	virtual bool Init(const std::unique_ptr<Simulation_GUI_Settings>& neural_network_settings) const;

	virtual void Run();

private:
	void poolEvent() const;

	void Update();

	void Render() const;
};


/*


 */
class Simulation : public Simulation_GUI
{
public:
	Simulation() = default;

};
