#include "Simulation.h"

// empyt
bool Simulation_GUI::Init(const std::unique_ptr<Simulation_GUI_Settings>& neural_network_settings) const
{
	// creating the m_window 
	m_window->create(sf::VideoMode(neural_network_settings->screenWidth, neural_network_settings->screenHeight), neural_network_settings->windowTitle, sf::Style::Titlebar | sf::Style::Close);

	m_window->setFramerateLimit(neural_network_settings->FPS_Limit);
	m_window->setVerticalSyncEnabled(neural_network_settings->vSync);
	m_window->resetGLStates();


	//draw not static lol
	obj.draw(); // use const and pointer that way i avoid coping i
	return true;
}

void Simulation_GUI::Run()
{
	while (m_window->isOpen())
	{
		poolEvent();
		Update();
		Render();
	}
}

void Simulation_GUI::poolEvent() const
{
	while (m_window->pollEvent(*m_event))
	{
		switch (m_event->type)
		{
		case sf::Event::Closed:
			m_window->close();
			break;
		case sf::Event::KeyPressed:
			switch (m_event->key.code)
			{
			case sf::Keyboard::Escape:
				m_window->close();
				break;
			case sf::Keyboard::R:

				break;
			case sf::Keyboard::C:

				break;
			case sf::Keyboard::I:

				break;
			case sf::Keyboard::Space:
				//u call in here
				//obj.some();
				break;
			case sf::Keyboard::S:

				break;
			default:
				break;
			}
		case sf::Event::MouseButtonPressed:
			break;
		case sf::Event::MouseButtonReleased:
			break;
		default:
			break;
		}
	}
}

void Simulation_GUI::Update()
{
	++m_frames;
	if (m_clock->getElapsedTime().asMilliseconds() >= 100)
	{
		const float fps = 1000.0f / (static_cast<float>(m_clock->getElapsedTime().asMilliseconds()) / static_cast<float>(m_frames));
		m_frames = 0;
		m_clock->restart();
		m_window->setTitle(std::to_string(fps));
	}
	// update your stuff

}

void Simulation_GUI::Render() const
{
	m_window->clear({ 15, 15, 31 });

	//for (const auto& x : NN_GUI.shape)
	m_window->draw(sf::CircleShape{ 50 });

	//draw your stuff by using
	//windows->draw(yourclassobj.context);

	// drawing to screen
	m_window->display();
}
