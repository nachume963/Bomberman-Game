#include "Explosion.h"
#include "GameBoard.h"
#include "Controller.h"


Explosion::Explosion(sf::Vector2f pos, sf::Vector2f size)
	:m_sheet_index(0)
{
	loadSheet(m_sheet);
	m_object.setPosition(sf::Vector2f(pos.x - size.x, pos.y - size.y));
	T.loadFromFile("Explosion.png");
	m_object.setTexture(T);
	m_object.scale(sf::Vector2f(float(size.x * 2.5) / (m_object.getGlobalBounds().width),
		float(size.y * 2.5) / (m_object.getGlobalBounds().width)));
}
Explosion::~Explosion()
{
}


void Explosion::draw(sf::RenderWindow & window) const
{
	sf::IntRect rectSourceSprite(0, 0, 100, 100);
	sf::Sprite sprite(T, rectSourceSprite);
	sprite.setTextureRect(m_sheet[m_sheet_index]);
	sprite.setPosition(m_object.getPosition());
	sprite.setScale(sf::Vector2f(m_object.getScale().x * 10, m_object.getScale().y * 10));
	window.draw(sprite);
}
void Explosion::move(float delta, GameBoard & board)
{
	if (m_sheet_index == 70)
	{
		m_active = false;
		return;
	}

	if (m_sheet_time += delta > 0.001f)
	{
		m_sheet_time = 0;
		m_sheet_index++;
	}

	bool xxx = board.Collision(*this);
}

void Explosion::loadSheet(std::vector< sf::IntRect >& m_sheet)
{
	int row_index = 0;
	int col_index = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++, col_index += 100)
		{
			sf::IntRect sourceSprite(col_index, row_index, 100, 100);
			m_sheet.push_back(sourceSprite);
		}
		col_index = 0;
		row_index += 100;
	}
}

bool Explosion::collide(Object & other, GameBoard & board)
{
	return other.collide(*this, board);
}
bool Explosion::collide(Robot & other, GameBoard & board)
{
	board.restartLevel();
	return false;
}
bool Explosion::collide(Rock & other, GameBoard & board)
{
	other.getSetActive() = false;
	return false;
}
bool Explosion::collide(Guard & other, GameBoard & board)
{
	Controller::sounds[1].play();
	
	board.setScore(false);
	other.getSetActive() = false;
	
	return false;
}
bool Explosion::collide(Bomb & other, GameBoard & board)
{
	return false;
}