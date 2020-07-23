#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#ifdef _DEBUG 
#pragma comment ( lib , "sfml-audio-d.lib" )
#pragma comment ( lib , "sfml-main-d.lib" ) 
#pragma comment ( lib , "sfml-system-d.lib" ) 
#pragma comment ( lib , "sfml-window-d.lib" ) 
#pragma comment ( lib , "sfml-graphics-d.lib" ) 
#elif defined (NDEBUG) 
#pragma comment ( lib , "sfml-audio.lib" )
#pragma comment ( lib , "sfml-main.lib" ) 
#pragma comment ( lib , "sfml-system.lib" ) 
#pragma comment ( lib , "sfml-window.lib" ) 
#pragma comment ( lib , "sfml-graphics.lib" ) 
#else 
#error "Unrecognized configuration!" 
#endif 

class GameBoard;
class DynamicObject;
class StaticObject;
class Robot;
class Door;
class Wall;
class Rock;
class Guard;
class Gift;
class Bomb;
class Explosion;


class Object
{
public:
	Object();
	Object(sf::Vector2f pos, sf::Vector2f size, std::string name_file);
	virtual ~Object();

	//draw
	virtual void draw(sf::RenderWindow & window) const;
	//move
	virtual void move(float delta, GameBoard & board) ;
	//Returns the blocking square of an object
	sf::FloatRect getObjectGlobalBounds();

	//Virtual functions that deal with conflicts between the various objects
	virtual bool collide(Object & other, GameBoard & board) = 0;
	virtual bool collide(Robot & other, GameBoard & board) = 0;
	virtual bool collide(Door & other, GameBoard & board) = 0;
	virtual bool collide(Wall & other, GameBoard & board) = 0;
	virtual bool collide(Rock & other, GameBoard & board) = 0;
	virtual bool collide(Guard & other, GameBoard & board) = 0;
	virtual bool collide(Bomb & other, GameBoard & board) = 0;
	virtual bool collide(Gift & other, GameBoard & board) = 0;
	virtual bool collide(Explosion & other, GameBoard & board) = 0;

	//Accepting and updating object activity
	bool & getSetActive();

protected:
	sf::Sprite m_object;
	sf::Texture T;
	bool m_active;//Object activity
};