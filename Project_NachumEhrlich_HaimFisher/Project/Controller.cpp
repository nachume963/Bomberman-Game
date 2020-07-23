#include "Controller.h"
#include "Robot.h"

//Static initialization
sf::SoundBuffer Controller::buffers[6];
sf::Sound Controller::sounds[6];

Controller::Controller()
	:m_window(sf::VideoMode(int(WINDOE_SIZE.x), int(WINDOE_SIZE.y)),
		"Bombermen. prod by. Haim Fisher & Nachum Ehrlich", sf::Style::Default)
{
	//Loading music
	buffers[0].loadFromFile("Explosion.ogg");
	sounds[0].setBuffer(buffers[0]);
	sounds[0].setVolume(100);
	buffers[1].loadFromFile("GuardS.ogg");
	sounds[1].setBuffer(buffers[1]);
	sounds[1].setVolume(100);
	buffers[2].loadFromFile("GameMusic.ogg");
	sounds[2].setBuffer(buffers[2]);
	sounds[2].setVolume(50);
	buffers[3].loadFromFile("youlos.ogg");
	sounds[3].setBuffer(buffers[3]);
	sounds[3].setVolume(100);
	buffers[4].loadFromFile("levelwin.ogg");
	sounds[4].setBuffer(buffers[4]);
	sounds[4].setVolume(100);
	buffers[5].loadFromFile("applause-3.ogg");
	sounds[5].setBuffer(buffers[5]);
	sounds[5].setVolume(100);
}
Controller::~Controller()
{
}

void Controller::run()
{
	std::ifstream in;//to reed from file
	in.open("Board.txt");
	sf::Clock clock;

	sounds[2].play();//game music play
	sounds[2].setLoop(true);//play in loop
	beforeGame();//print befor game screen

	while (m_window.isOpen())
	{
		readFromFile(in);//reed from file
		betweenStages();//print between Stages screen
		while (m_window.isOpen() && !nextLevel())
		{
			HandleEvents();
			m_board->Moves(clock);//move objects
			draw(m_window);//drow objects

			if (!Robot::life)//if life of robot == 0
				afterGame(false);//false Because player lose
		}
	}
	in.close();
}

void Controller::finishGame()
{
	m_window.close();
}
bool Controller::nextLevel()
{
	if (m_board)//if is a board
		return m_board->nextLevel();//active fanction nextLevel() in board

	else return false;//gast to be Sure
}
void Controller::resetLevel()
{
	m_board->restartLevel();//active fanction restartLevel() in board
}

void Controller::beforeGame()
{
	//before Game screen
	T.loadFromFile("beforeGame.png");
	A.setTexture(T);
	A.setPosition(sf::Vector2f(0, 0));
	A.scale(sf::Vector2f(WINDOE_SIZE.x / (A.getGlobalBounds().width),
		WINDOE_SIZE.y / A.getGlobalBounds().height));

	while (true)
	{
		m_window.clear(sf::Color(203, 187, 160));
		m_window.draw(A);
		m_window.display();

		sf::Event event;
		while (m_window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				finishGame();
				return;
			case sf::Event::MouseButtonPressed:
				return;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					finishGame();
				return;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
					return;
			}
		}
	}

}
void Controller::afterGame(bool win)
{
	//after Game screen
	if (win)//if win
	{
		sounds[5].play();
		T.loadFromFile("win.png");
	}
	else if (!win)//if lose
	{
		sounds[3].play();
		T.loadFromFile("lose.png");
	}
	A.setTexture(T);
	A.setPosition(sf::Vector2f(0, 0));
	A.scale(sf::Vector2f(WINDOE_SIZE.x / (A.getGlobalBounds().width),
		WINDOE_SIZE.y / A.getGlobalBounds().height));

	//for new game
	Robot::life = 5;
	GameBoard::level_number = 1;
	while (true)
	{
		m_window.clear(sf::Color(203, 187, 160));
		m_window.draw(A);
		m_window.display();

		sf::Event event;
		while (m_window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				finishGame();
				return;
			case sf::Event::MouseButtonPressed:
				run();
				return;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					finishGame();
					return;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
				{
					run();
					return;
				}
			}
		}
	}
}
void Controller::betweenStages()
{
	sounds[4].play();

	T.loadFromFile("betweenStages.png");
	A.setTexture(T);
	A.setPosition(sf::Vector2f(0, 0));
	A.scale(sf::Vector2f(WINDOE_SIZE.x / (A.getGlobalBounds().width),
		WINDOE_SIZE.y / A.getGlobalBounds().height));

	sf::Font aaa;
	aaa.loadFromFile("aaa.ttf");
	std::string line = "level: " + std::to_string(GameBoard::level_number);
	sf::Text Line(line, aaa, 145);
	Line.setPosition(sf::Vector2f(500, 550));
	Line.setFillColor(sf::Color::Black);

	int wait_a_second = 1;
	while (true)
	{
		m_window.clear(sf::Color(203, 187, 160));
		m_window.draw(A);
		m_window.draw(Line);
		m_window.display();

		if (((wait_a_second++) % 50) == 0)
			return;
	}
}

void Controller::readFromFile(std::ifstream & in)
{
	if (in.fail())//if faild to open file
	{
		std::cerr << "Unable to open file" << std::endl;
		finishGame();

		int to_make_shur_that_yuo_see_the_meseg;
		std::cin >> to_make_shur_that_yuo_see_the_meseg;
		return;
	}
	else
	{
		std::vector<std::string> matrix_board;
		std::string line;

		while (std::getline(in, line) && !line.size());//Loade first line
		matrix_board.push_back(line);

		///////////
		if (in.eof())//if has come to end of file
		{
			afterGame(true);
			return;
		}
		///////////

		int H = std::stoi(matrix_board[0]);//read first line
		for (int i = 0; i < H; i++)
		{
			getline(in, line);
			matrix_board.push_back(line);
		}
		m_board = std::make_unique <GameBoard>(matrix_board);
	}
}

void Controller::draw(sf::RenderWindow & window) const
{
	//draw teh board himself
	window.clear(sf::Color(203, 187, 160));
	m_menu.draw(window);
	m_board->draw(window);
	window.display();
}
void Controller::HandleEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			finishGame();
			break;
		case sf::Event::MouseButtonPressed:
			m_menu.click(*this, event);
			break;
		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				finishGame();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
				if (Robot::bombs)
					m_board->setObject(Robot::pos, 'B');
			break;
		}
	}
}