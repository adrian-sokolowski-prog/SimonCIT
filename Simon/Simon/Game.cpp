/// <summary>
/// @author Adrian Sokolowski
///
/// 
/// </summary>

#include "Game.h"
#include <iostream>



/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 800U, 600U, 32U }, "SFML Game" },
	
	m_exitGame{false} //when true game will exit
{
	setupFontAndText(); // load font 
	setupButtons(); // load texture
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}


/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);
	m_window.draw(m_redSquare);
	m_window.draw(m_greenSquare);
	m_window.draw(m_yellowSquare);
	m_window.draw(m_blueSquare);
	m_window.draw(m_titleText);
	m_window.draw(m_redTextInstruction);
	m_window.draw(m_greenTextInstruction);
	m_window.draw(m_yellowTextInstruction);
	m_window.draw(m_blueTextInstruction);
	m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ariel.loadFromFile("ASSETS/FONTS/ariblk.ttf"))
	{
		std::cout << "font did not load" << std::endl;
	}

	m_titleText.setFillColor(sf::Color::Magenta);
	m_titleText.setPosition(sf::Vector2f(400.0f, 30.0f));
	m_titleText.setFont(m_ariel);
	m_titleText.setCharacterSize(30);
	m_titleText.setString("Simon Game");

	m_redTextInstruction.setFillColor(RED);
	m_redTextInstruction.setPosition(sf::Vector2f(20.0f, 20.0f));
	m_redTextInstruction.setFont(m_ariel);
	m_redTextInstruction.setCharacterSize(30);
	m_redTextInstruction.setString("Press Red for\n Easy Game");

	m_greenTextInstruction.setFillColor(GREEN);
	m_greenTextInstruction.setPosition(sf::Vector2f(20.0f, 170.0f));
	m_greenTextInstruction.setFont(m_ariel);
	m_greenTextInstruction.setCharacterSize(30);
	m_greenTextInstruction.setString("Press Green for\n Normal Game");

	m_yellowTextInstruction.setFillColor(YELLOW);
	m_yellowTextInstruction.setPosition(sf::Vector2f(20.0f, 320.0f));
	m_yellowTextInstruction.setFont(m_ariel);
	m_yellowTextInstruction.setCharacterSize(30);
	m_yellowTextInstruction.setString("Press Yellow for\n Hard Game");

	m_blueTextInstruction.setFillColor(BLUE);
	m_blueTextInstruction.setPosition(sf::Vector2f(20.0f, 470.0f));
	m_blueTextInstruction.setFont(m_ariel);
	m_blueTextInstruction.setCharacterSize(30);
	m_blueTextInstruction.setString("Press Blue Too\n Exit Game");
}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupButtons()
{
	m_redSquare.setFillColor(RED);
	m_redSquare.setPosition(sf::Vector2f(300.0f, 120.0f));
	m_redSquare.setSize(sf::Vector2f(200.0f, 200.0f));

	m_greenSquare.setFillColor(GREEN);
	m_greenSquare.setPosition(sf::Vector2f(530.0f, 120.0f));
	m_greenSquare.setSize(sf::Vector2f(200.0f, 200.0f));

	m_yellowSquare.setFillColor(YELLOW);
	m_yellowSquare.setPosition(sf::Vector2f(300.0f, 350.0f));
	m_yellowSquare.setSize(sf::Vector2f(200.0f, 200.0f));

	m_blueSquare.setFillColor(BLUE);
	m_blueSquare.setPosition(sf::Vector2f(530.0f, 350.0f));
	m_blueSquare.setSize(sf::Vector2f(200.0f, 200.0f));
	
	
}
