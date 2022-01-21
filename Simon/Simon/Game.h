/// <summary>
/// Author: Adrian Sokolowski
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>

const sf::Color RED{ 180,0,0,255 };

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();
	void setupButtons();

	

	sf::RenderWindow m_window; // main SFML window
	sf::RectangleShape m_redSquare; // red square creation
	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP

