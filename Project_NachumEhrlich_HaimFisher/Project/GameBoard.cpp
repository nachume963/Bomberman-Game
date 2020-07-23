#include "GameBoard.h"
#include "Controller.h"

int GameBoard::level_number = 1;//Static initialization
float GameBoard::timer = 0;//Static initialization


GameBoard::GameBoard(std::vector<std::string> & matrix_board)
	:m_matrix_board(matrix_board), m_num_guards(0), m_bombs_limit(0)
{
	setBoard();//Organized board
}
GameBoard::~GameBoard()
{
}


void GameBoard::Moves(sf::Clock & clock)
{
	float delta = clock.restart().asSeconds();//get time from clock

	timeLimit(delta);//chek time limit

	for (int i = 0; i < m_objects.size(); i++)
		m_objects[i]->move(delta, *this);//if object active move

	clock.restart();
}

void GameBoard::draw(sf::RenderWindow & window) const
{
	for (size_t i = m_objects.size(); i > 0; i--)
		if (m_objects[i - 1]->getSetActive())//chek if object active
			m_objects[i - 1]->draw(window);

	drawData(window); //drow data under board
}
void GameBoard::drawData(sf::RenderWindow & window) const
{
	sf::Font aaa;
	aaa.loadFromFile("aaa.ttf");

	std::string life = "life: " + std::to_string(Robot::life);
	std::string score = " || score: " + std::to_string(Robot::score);
	std::string level = " || level num: " + std::to_string(level_number);
	std::string bomb = " ";
	std::string timer = " ";
	if (m_bombs_limit > 0)
		bomb = " || bombs: " + std::to_string(Robot::bombs);
	if (GameBoard::timer > 0)
		timer = " || timer: " + std::to_string(int(GameBoard::timer));

	std::string line = life + std::string(score) + std::string(level)
		+ std::string(bomb) + std::string(timer);

	sf::Text Line(line, aaa, 45);
	Line.setPosition(sf::Vector2f(20, 925));
	Line.setFillColor(sf::Color::Black);
	window.draw(Line);
}

bool GameBoard::Collision(Object & object)
{
	for (size_t i = 0; i < m_objects.size(); i++)
	{
		if (object.getObjectGlobalBounds().intersects(m_objects[i]->getObjectGlobalBounds()))//chek if it is intersects
			if (object.collide(*m_objects[i], *this))//do collision
			{
				if (!m_objects[i]->getSetActive())//chek if object not active
					m_objects.erase(m_objects.begin() + i);// if object not active erase
				return false;
			}
		//Check whether the object is still in the array, and whether it is active
		if (m_objects.size() > i && !m_objects[i]->getSetActive())
			m_objects.erase(m_objects.begin() + i);// if object not active erase
	}
	return true;
}

void GameBoard::restartLevel()
{
	Robot::life--;
	setBoard();
}
void GameBoard::moveToNextLevel()
{
	level_number++;
	setScore(true);
	m_next_level = true;
}
bool GameBoard::nextLevel() const
{
	return m_next_level;
}

void GameBoard::timeLimit(float delta)
{
	//static to save data from call to call (Relying on having one board at a time)
	static int level = 0;
	static float time = -1;

	if (level_number > level)//Updating the time (Checks if we've entered in this level)
	{
		level++;
		time = timer;
	}
	if (time > 0 && (timer -= delta) <= 0)//chek time Limit
	{
		timer = time;
		restartLevel();
	}
}
void GameBoard::setScore(bool finis_level)
{
	if (!finis_level)
		Robot::score += (m_num_guards * 5);
	if (finis_level)
		Robot::score += (m_num_guards * 20);
}

void GameBoard::setBoard()
{
	m_objects.clear();
	int H = 0, W = 0;

	std::istringstream iss;
	iss.str(m_matrix_board[0]);
	iss >> H >> W >> m_bombs_limit >> timer;

	m_object_size = { BOARD_SIZE.x / W, BOARD_SIZE.y / H };
	Robot::bombs = m_bombs_limit;

	for (int j = 1; j <= H; j++)//Switch from referring to the i first to the j first
		for (int i = 0; i < W; i++)
			if (m_matrix_board[j][i] != ' ')
			{
				setObject(sf::Vector2f((m_object_size.x * i) + POSITON_BOARD.x,
					(m_object_size.y * (j - 1)) + POSITON_BOARD.y), m_matrix_board[j][i]);
			}
}
void GameBoard::setObject(sf::Vector2f pos, char c)
{
	switch (c)
	{
	case '/':
		m_objects.push_back(std::make_unique<Robot>(pos, m_object_size));
		break;
	case '!':
		if ((m_num_guards++) % 4)//The ratio is 1 to 4 in favor of stupid guards
			m_objects.push_back(std::make_unique<FoolGuard>(pos, m_object_size));
		else
			m_objects.push_back(std::make_unique<SmartGuard>(pos, m_object_size));
		break;
	case '#':
		m_objects.push_back(std::make_unique<Wall>(pos, m_object_size));
		break;
	case '@':
		m_objects.push_back(std::make_unique<Rock>(pos, m_object_size));
		break;
	case 'D':
		m_objects.push_back(std::make_unique<Door>(pos, m_object_size));
		break;
	case '+':
		if (m_bombs_limit > 0)//chek What a gift to give
			m_objects.push_back(std::make_unique<BombGift>(pos, m_object_size));
		else
			m_objects.push_back(std::make_unique<LifeGift>(pos, m_object_size));
		break;
	case '&':
		m_objects.push_back(std::make_unique<Rock>(pos, m_object_size));
		m_objects.push_back(std::make_unique<LifeGift>(pos, m_object_size));
		break;
	case 'B':
		Robot::bombs--;//chek if left bomb to use
		m_objects.push_back(std::make_unique<Bomb>(pos, m_object_size));
		break;
	case 'E':
		m_objects.push_back(std::make_unique<Explosion>(pos, m_object_size));
		break;
	case ' ':
	default:
		break;
	}
}