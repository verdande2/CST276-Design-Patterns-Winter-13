#include "Game.h"
#include <string>
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
#include "ImageManager.h"
#include <math.h>
using std::sqrt;

TheSkyIsFallingGame::TheSkyIsFallingGame()
	: m_window(sf::VideoMode(RESOLUTION_WIDTH, RESOLUTION_HEIGHT, COLOR_MODE), "The Sky Is Falling! by Andrew Sparkes"),
	m_player(CHARACTER_MOVE_SPEED),
	m_rockSpawnRate(12),
	m_rockBaseSize(20),
	m_rockVelocity(300),
	m_rockSizeVariation(20)
{

}

TheSkyIsFallingGame::~TheSkyIsFallingGame()
{

}

void TheSkyIsFallingGame::Start()
{
	Init();
	StartBackgroundMusic();
	//ShowWelcomeScreen();

	DrawMenuBar();
	MainGameLoop();
}

void TheSkyIsFallingGame::Init()
{
	// set up background music
	std::string backgroundMusicFilename("music/theme.wav");
	if(!m_backgroundMusic.openFromFile(backgroundMusicFilename)){
		cout << "Unable to open background music: '" << backgroundMusicFilename << "'." << endl;
	}
	m_backgroundMusic.setLoop(true);

	m_window.setVerticalSyncEnabled(true); // enable vsync for easy 60hz framerate

	RegisterClockUpdatableObject(&m_player);
	m_player.GetSprite().setPosition(m_window.getSize().x/2, m_window.getSize().y-85-m_player.GetSprite().getTextureRect().height);
}

void TheSkyIsFallingGame::DrawMenuBar()
{
	unsigned int menuHeight = 85; // px
	
	//GenerateMenuTexture();

	sf::Texture repeatingBgTexture;
	repeatingBgTexture.setRepeated(true);
	repeatingBgTexture.setSmooth(true);
	repeatingBgTexture.loadFromImage(ImageManager::GetImage("images/MenuRepeatingBg.png")); //, sf::IntRect(0,0,RESOLUTION_WIDTH,50));
	
	sf::Sprite repeatingBgSprite(repeatingBgTexture);
	repeatingBgSprite.scale(1.0f, (float)menuHeight / repeatingBgTexture.getSize().y);
	repeatingBgSprite.setPosition(0,RESOLUTION_HEIGHT-repeatingBgTexture.getSize().y);
	repeatingBgSprite.setTextureRect(sf::IntRect(0,0,RESOLUTION_WIDTH,repeatingBgTexture.getSize().y));
	

	sf::Texture menuEdgeTexture;
	menuEdgeTexture.loadFromImage(ImageManager::GetImage("images/MenuEdge.png"));
	menuEdgeTexture.setSmooth(true);

	sf::Sprite menuEdgeSprite(menuEdgeTexture);
	menuEdgeSprite.scale(1.0f, (float)menuHeight / menuEdgeTexture.getSize().y);
	menuEdgeSprite.setPosition(0,RESOLUTION_HEIGHT-menuEdgeTexture.getSize().y);
	
	sf::Texture rightMenuEdgeTexture(menuEdgeTexture);
	
	sf::Sprite rightMenuEdgeSprite(rightMenuEdgeTexture);
	rightMenuEdgeSprite.setPosition(RESOLUTION_WIDTH-rightMenuEdgeSprite.getTextureRect().width,RESOLUTION_HEIGHT-rightMenuEdgeTexture.getSize().y);
	rightMenuEdgeSprite.scale(1.0f, (float)menuHeight / rightMenuEdgeTexture.getSize().y);
	
	
	rightMenuEdgeSprite.setPosition(RESOLUTION_WIDTH-rightMenuEdgeSprite.getTextureRect().width,RESOLUTION_HEIGHT-rightMenuEdgeTexture.getSize().y);
	
	// flip over y axis
	rightMenuEdgeSprite.setTextureRect(sf::IntRect(rightMenuEdgeSprite.getTextureRect().width, 0, -rightMenuEdgeSprite.getTextureRect().width, rightMenuEdgeSprite.getTextureRect().height));
	
	m_window.draw(menuEdgeSprite);
	m_window.draw(repeatingBgSprite);
	m_window.draw(rightMenuEdgeSprite);
}

void TheSkyIsFallingGame::HandleEvent(sf::Event event)
{
	switch (event.type)
	{
		case sf::Event::Closed:
			m_window.close();
			break;
		case sf::Event::KeyPressed:
			if(event.key.code == sf::Keyboard::Escape) // outside of the below switch statement because I can't break 2 levels in
			{
				cout << "Exiting now..." << endl;
				m_window.close();
				break;
			}
			switch(event.key.code)
			{
				case sf::Keyboard::Up:
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::RControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
					{
						//IncreaseRockVelocity();
						cout << "detected control+up "<< endl;
					}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt) || sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt)){
						//IncreaseRockVariation();
					}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
						//IncreaseRockSpawnRate();
					}else{
						//IncreaseRockSize();
					}
					break;
				case sf::Keyboard::Down:
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::RControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
					{
						//DecreaseRockVelocity();
					}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt) || sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt)){
						//DecreaseRockVariation();
					}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
						//DecreaseRockSpawnRate();
					}else{
						//DecreaseRockSize();
					}
					break;
			}
			break;
		case sf::Event::MouseButtonPressed:
			if(event.mouseButton.button == sf::Mouse::Button::Left) // hooking only left click
			{
				cout << "Handling leftclick @ (" << event.mouseButton.x << "," << event.mouseButton.y << ")" << endl;
			}
			break;
		case sf::Event::JoystickButtonPressed:
			cout << "Joystick button event! " << event.joystickButton.button << endl;
			break;
		case sf::Event::JoystickConnected:
			cout << "Joystick connected event! " << event.JoystickConnected << endl;
			break;
		case sf::Event::JoystickMoved:
			cout << "Joystick move event! " << event.joystickMove.axis << endl;
			break;


	}
}
void TheSkyIsFallingGame::MainGameLoop()
{
	sf::Event event;
	
	m_clock.restart();
	unsigned int timeElapsed = 0; // represents the time (in ms) that has elapsed during each loop iteration

	sf::Clock currentGameTimer;
	// debug
	//RockSprite rock(50, 300);
	//RegisterClockUpdatableObject(&rock);

	while(m_window.isOpen())
	{
        while (m_window.pollEvent(event))
        {
			HandleEvent(event);	
        }

		if(!m_window.isOpen())
		{
			// the event above may have triggered a window close, so if it is no longer open, do not continue
			break;
		}

		// this if statement houses all elements dependent on time (anything with a movement speed or animation speed)
		if(timeElapsed = m_clock.restart().asMilliseconds())
		{
			for(auto i = m_clockObservers.begin(); i != m_clockObservers.end(); i++)
			{
				(*i)->Update(timeElapsed);
			}

			// add some more rocks to the playing field
			ThrowRocks(timeElapsed);

			//rock.MoveDown(timeElapsed);
			//cout << "Rock Position: " << rock.GetSprite().getPosition().x << "x" << rock.GetSprite().getPosition().y << endl;

			// and let all the rocks fall
			for(auto i = m_rocks.begin(); i != m_rocks.end(); i++)
			{
				(*i)->MoveDown(timeElapsed);
				//std::cout << "Rock at (" << (*i)->GetSprite().getPosition().x << "," << (*i)->GetSprite().getPosition().y << ")" << std::endl;
			}

			//int amt = 5; // TODO: refactor this into a configurable setting somewhere
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				if(m_player.GetSprite().getPosition().x >= 0){
					m_player.MoveLeft(timeElapsed);
				}
			}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
				if(m_player.GetSprite().getPosition().x <= m_window.getSize().x-m_player.GetSprite().getTextureRect().width){
					m_player.MoveRight(timeElapsed);
				}
			}
		}
		

		// Clear screen
         m_window.clear();

		 //cout << "# of rocks: " << m_rocks.size() << endl;

		 CleanUpRocks();

		 if(CheckForCollisions())
		 {
			cout << "Detected hitbox collision." << endl;
			cout << "Your streak was: " << currentGameTimer.restart().asSeconds() << endl;
			ResetAfterDeath();
			//system("pause");
			//return;
			
		 }
 
         // Draw the sprites
		 for(auto i = m_rocks.begin(); i != m_rocks.end(); i++)
		 {
			m_window.draw((*i)->GetSprite());
		 }
		 m_window.draw(m_player.GetSprite());



		 DrawMenuBar();
 
         // Update the window
         m_window.display();

		 
	}
}
bool TheSkyIsFallingGame::CheckForCollisions()
{
	unsigned playerX = m_player.GetSprite().getPosition().x;
	unsigned playerY = m_player.GetSprite().getPosition().y;
	float playerRadius = m_player.GetSprite().getTextureRect().width / 2.0f; // this is okay because player sprite is square

	float playerCenterX = playerX + playerRadius;
	float playerCenterY = playerY + playerRadius;

	// for collision detection, we'll consider each rock to be a circle (more or less)
	// and for simplicity, the character as a circle also, this means hit detection is trivial w/ euclidean distance
	for(auto i = m_rocks.begin(); i != m_rocks.end(); i++)
	{
		// determine if current object and player hitbox are colliding
		unsigned rockX = (*i)->GetSprite().getPosition().x;
		unsigned rockY = (*i)->GetSprite().getPosition().y;
		unsigned rockRadius = (*i)->GetWidth() / 2.0f; // this is okay because player sprite is square

		float rockCenterX = rockX + (float)rockRadius;
		float rockCenterY = rockY + (float)rockRadius;

		if(abs(sqrt(pow((playerCenterX - rockCenterX), 2) + pow((playerCenterY - rockCenterY), 2))) <= playerRadius+rockRadius)
		{
			//cout << "Collided with rock at address " << (*i) << endl;
			return true;
		}
	}
	return false;
}
void TheSkyIsFallingGame::StartBackgroundMusic()
{
	m_backgroundMusic.play();
}

void TheSkyIsFallingGame::ThrowRocks(unsigned int elapsedTime)
{
	static unsigned int timeSinceLastRockThrown = 0;
	timeSinceLastRockThrown += elapsedTime;
	if(timeSinceLastRockThrown/1000.0f > 1.0f / m_rockSpawnRate)
	{
		if(m_rocks.size() > 100){
			cout << "Rock count too high! Current Count: " << m_rocks.size() << endl;
			return;
		}
		RockSprite* newRock = new RockSprite(m_rockFactory.GetRock(m_rockBaseSize, m_rockSizeVariation, m_rockVelocity));
		newRock->GetSprite().setPosition(rand()%m_window.getSize().x, -100); // all rocks spawn 100px above top of screen
		m_rocks.insert(newRock);

		RegisterClockUpdatableObject(newRock);

		//std::cout << "New Rock added at position (" << newRock->GetSprite().getPosition().x << "," << newRock->GetSprite().getPosition().y << ")." << std::endl;
		timeSinceLastRockThrown = 0;
	}
}

void TheSkyIsFallingGame::CleanUpRocks()
{
	std::vector<RockSprite*> deleteList;
	for(auto i = m_rocks.begin(); i != m_rocks.end(); i++)
	{
		if((*i)->GetSprite().getPosition().y > m_window.getSize().y)
		{
			deleteList.push_back(*i);
		}
	}

	for(auto i = deleteList.begin(); i != deleteList.end(); i++)
	{
		UnregisterClockUpdatableObject(*i);
		m_rocks.erase(find(m_rocks.begin(), m_rocks.end(), *i));
		delete (*i);
	}
}

void TheSkyIsFallingGame::RegisterClockUpdatableObject(iUpdatable* obj)
{
	m_clockObservers.push_back(obj);
}

void TheSkyIsFallingGame::UnregisterClockUpdatableObject(iUpdatable* obj)
{
	m_clockObservers.erase(find(m_clockObservers.begin(), m_clockObservers.end(), obj));
}

void TheSkyIsFallingGame::ResetAfterDeath()
{
	// remove all rocks
	for(auto i = m_rocks.begin(); i != m_rocks.end(); i++)
	{
		UnregisterClockUpdatableObject(*i);
		delete *i;
	}
	m_rocks.clear();

	// reset player to middle
	m_player.GetSprite().setPosition(m_window.getSize().x/2, m_window.getSize().y-85-m_player.GetSprite().getTextureRect().height);
}