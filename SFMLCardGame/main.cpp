//Guessing Game Project for CS M135 by Julian Nemo
#include <iostream>
#include <SFML\Graphics.hpp>
#include "SFML/Audio.hpp"
#include <windows.h>
#include <time.h>
#include <sstream>
//Features on website
// Moves, Rounds Played, Levels, Knowledge Points(?????), Accuracy, Set Speed, Show Number

char layers;


class Card
{
private:
	int x, y;
	

	void getX(int xx) { xx = x; };
	void getY(int yy) { yy = y; };
public:
	std::string Type;
	bool BackOn = true;
	int FF = 0;

	sf::Texture tCard;
	void setTextureCard(std::string texture) { if (!tCard.loadFromFile(texture)) { std::cout << "Error" << texture; } };

	sf::Sprite sCard;

	void setX(int xx) { getX(xx); }
	void setY(int yy) { getY(yy); }



	

	Card(int x, int y, std::string texture)
	{

		setTextureCard(texture);
		sCard.setTexture(tCard);
		sCard.setPosition(x, y);

	}




};


class Menu
{
private:
	int x, y;
	int moves, rounds;
	float accuracy;
	bool shownumber;
	int speed;
	int score;

	void getX(int xx) { xx = x; };
	void getY(int yy) { yy = y; };
	void getMoves(int i) { i = moves; };
	void getRounds(int i) { i = rounds; };
	void getAccuracy(float i) { i = accuracy; };
	void getShowNumber(bool i) { i = shownumber; };
	void getSpeed(int i) { i = speed; };
	void getScore(int i) { i = score; };
public:
	void setMoves(int i) { getMoves(i); };
	void setRounds(int i) { getRounds(i); };
	void setAccuracy(float i) { getAccuracy(i); };
	void setShowNumber(bool i) { getShowNumber(i); };
	void setSpeed(int i) { getSpeed(i); };
	void setScore(int i) { getScore(i); };

	sf::Texture tPressEnter;
	sf::Texture tTitle;
	void setTexturePressEnter(std::string texturestring) { tPressEnter.loadFromFile(texturestring); };

	sf::Sprite sPressEnter;
	sf::Sprite sTitle;
	void setTextureTitle(std::string texturestring) { tTitle.loadFromFile(texturestring); };


	sf::Texture tB;
	sf::Sprite sB;
	void setTextureB(std::string texturestring) { tB.loadFromFile(texturestring); };
	void setX(int xx) { getX(xx); }
	void setY(int yy) { getY(yy); }

	sf::Texture tTY;
	sf::Sprite sTY;
	void setTextureTY(std::string texturestring) { tTY.loadFromFile(texturestring); };

	sf::Text scoreText;
	std::stringstream ss;
	
	Menu()
	{


		setTexturePressEnter("assets/GuessingGameStart.png");
		sPressEnter.setTexture(tPressEnter);
		sPressEnter.setPosition(230, 220);

		setTextureTitle("assets/GuessingGameTitle.png");

		sTitle.setTexture(tTitle);
		sTitle.setPosition(0, 0);
		sTitle.setPosition(235, 0);

		setTextureB("assets/background.png");

		setTextureTY("assets/TYForPlaying.png");
		sTY.setTexture(tTY);
		sTY.setPosition(210, 75);

		sB.setTexture(tB);


		

	}







};




class Run
{
private:


public: 




	int r;
	int y;
	int randomX;
	int randomY1;

	int random(int random)
	{


		randomX = rand() % 3 + 1;
		switch (randomX)
		{
		case 1:

			{
				random = 0;
				
				std::cout << "returned 0" << std::endl;
				return random;
			}
		case 2:
			
			{

				random = 265;
				
				std::cout << "returned 265" << std::endl;
				return random;

			}
		case 3:
			
			{

				random = 541;
				std::cout << "returned 541" << std::endl;
				return random;
			}
		
		}
	}

	int randomY(int randomY)
	{
		
		
		randomY1 = rand() % 4 + 1;
		
		switch (randomY1)
		{
		case 1:
			
			{
				randomY = 0;
				std::cout << "returned Y0" << std::endl;
				return randomY;
			}
		case 2:
			
			{

				randomY = 110;
				std::cout << "returned Y110" << std::endl;
				return randomY;

			}
		case 3:
			
			{
				randomY = 220;
				std::cout << "returned Y220" << std::endl;
				return randomY;
			}
		case 4:
			
			{
				randomY = 330;
				std::cout << "returned Y330" << std::endl;
				return randomY;


			}
	
			
		}
	}

	int posX[12];
	int posY[12];
	void CoordInitialize()
	{
		for (int i = 0; i < 12; i++)
		{
			r = random(r);
			posX[i] = r;
			y = randomY(y);
			posY[i] = y;



		}


	}

	void CoordTracker()
	{

		CoordInitialize();

			for (int u = 0; u < 12; u++)
			{
				for (int h = 1; h < 12; h++)
				{

					if (posX[u] == posX[h] && posY[u] == posY[h])
					{
						r = random(r); y = randomY(y);
						
						posX[u] = r; posY[u] = y;
						
					} 
					
				}

			}
		
	}



	Run()
	{
		
		int flag = 0;
		layers = 'A';
		int score = 0;
		sf::Font font;
		font.loadFromFile("pixelfont.ttf");

		sf::Text accText;
		accText.setFont(font);
		accText.setCharacterSize(30);
		accText.setFillColor(sf::Color::White);
		accText.setPosition(445, 450);
		std::string accString = "Moves";

		sf::Text accTextNum;
		accTextNum.setFont(font);
		accTextNum.setCharacterSize(30);
		accTextNum.setFillColor(sf::Color::White);
		accTextNum.setPosition(545, 450);
		
		sf::Text scoreText;
		scoreText.setFont(font);
		scoreText.setCharacterSize(30);
		scoreText.setFillColor(sf::Color::White);
		scoreText.setPosition(250, 450);
		std::string stScore = "Score";
		sf::Text scoreString;
		scoreString.setFont(font);
		scoreString.setCharacterSize(30);
		scoreString.setFillColor(sf::Color::White);
		scoreString.setPosition(150, 450);
		
		int moves = 0;
		double acc = 0;


		sf::RenderWindow w(sf::VideoMode(720, 500), "Guessing Game by Julian Nemo", sf::Style::Titlebar | sf::Style::Close);
		Menu menu;
		Card Orange1(541, 330, "cards/nemoCardOrange.png");
		
		Card Orange2(265, 220, "cards/nemoCardOrange.png");

		Card Apple1(541, 110, "cards/nemoCardApple.png");
	
		Card Apple2(0, 110, "cards/nemoCardApple.png");
		
		Card Durian1(265, 110, "cards/nemoCardDurian.png");
		
		Card Durian2(541, 0, "cards/nemoCardDurian.png");
		
		Card Banana1(0, 220, "cards/nemoCardBanana.png");

		Card Banana2(0, 0, "cards/nemoCardBanana.png");
		
		Card Peach1(541,  220, "cards/nemoCardPeach.png");
	
		Card Peach2(0,  330, "cards/nemoCardPeach.png");
	
		Card Pear1(265, 330, "cards/nemoCardPear.png");
	
		Card Pear2(265, 0, "cards/nemoCardPear.png");
		
		
		
		Card Cover1(0, 0, "cards/nemoCardBack.png");
		Card Cover2(265, 0, "cards/nemoCardBack.png");
		Card Cover3(541, 0, "cards/nemoCardBack.png");
		Card Cover4(0, 110, "cards/nemoCardBack.png");
		Card Cover5(265, 110, "cards/nemoCardBack.png");
		Card Cover6(541, 110, "cards/nemoCardBack.png");
		Card Cover7(0, 220, "cards/nemoCardBack.png");
		Card Cover8(265, 220, "cards/nemoCardBack.png");
		Card Cover9(541, 220, "cards/nemoCardBack.png");
		Card Cover10(0, 330, "cards/nemoCardBack.png");
		Card Cover11(265, 330, "cards/nemoCardBack.png");
		Card Cover12(541, 330, "cards/nemoCardBack.png");

		
		
		sf::Music mainOST;
		sf::Music Pop;

		if (!mainOST.openFromFile("sounds/cat.ogg"))
		{
			std::cout << "song error" << std::endl;

		}
		mainOST.setVolume(20);
		mainOST.play();



		if (!Pop.openFromFile("sounds/pop.wav"))
		{
			std::cout << "song error" << std::endl;

		}
		Pop.setVolume(20);

		while (w.isOpen())
		{
			if (score >= 1 && moves >= 1)
				acc = score / moves;
			
			
			sf::Event event;
			while (w.pollEvent(event))
			{

				if (event.type == sf::Event::Closed)
					w.close();
				
				switch (event.type) {
				case sf::Event::MouseButtonPressed:
					std::cout << "Button " << event.mouseButton.button << " @ "
						<< sf::Mouse::getPosition(w).x << ", "
						<< sf::Mouse::getPosition(w).y << "\n";
					
					if (layers == 'B')
					{
						if (sf::Mouse::getPosition(w).x > 1 && sf::Mouse::getPosition(w).x < 176 && sf::Mouse::getPosition(w).y > 3 && sf::Mouse::getPosition(w).y < 97)
						{

							Cover1.sCard.setPosition(1000, 1000);
							flag = flag + 1;
							if (Banana1.FF != 1)
								Banana1.Type = "Banana";

						}

						if ((sf::Mouse::getPosition(w).x > 268 && sf::Mouse::getPosition(w).x < 447) && (sf::Mouse::getPosition(w).y > 3 && sf::Mouse::getPosition(w).y < 97))
						{

							Cover2.sCard.setPosition(1000, 1000);
							flag = flag + 1;
							Pear1.Type = "Pear";

						}

						if ((sf::Mouse::getPosition(w).x > 545 && sf::Mouse::getPosition(w).x < 717) && (sf::Mouse::getPosition(w).y > 3 && sf::Mouse::getPosition(w).y < 97))
						{

							Cover3.sCard.setPosition(1000, 1000);
							flag = flag + 1;
							Durian1.Type = "Durian";

						}

						if ((sf::Mouse::getPosition(w).x > 1 && sf::Mouse::getPosition(w).x < 176) && (sf::Mouse::getPosition(w).y > 112 && sf::Mouse::getPosition(w).y < 203))
						{

							Cover4.sCard.setPosition(1000, 1000);
							flag = flag + 1;
							Apple1.Type = "Apple";
						}

						if ((sf::Mouse::getPosition(w).x > 268 && sf::Mouse::getPosition(w).x < 447) && (sf::Mouse::getPosition(w).y > 112 && sf::Mouse::getPosition(w).y < 203))
						{

							Cover5.sCard.setPosition(1000, 1000);
							flag = flag + 1;
							Durian2.Type = "Durian2";

						}

						if ((sf::Mouse::getPosition(w).x > 545 && sf::Mouse::getPosition(w).x < 717) && (sf::Mouse::getPosition(w).y > 112 && sf::Mouse::getPosition(w).y < 203))
						{

							Cover6.sCard.setPosition(1000, 1000);
							flag = flag + 1;
							Apple2.Type = "Apple2";

						}

						if ((sf::Mouse::getPosition(w).x > 1 && sf::Mouse::getPosition(w).x < 176) && (sf::Mouse::getPosition(w).y > 222 && sf::Mouse::getPosition(w).y < 316))
						{

							Cover7.sCard.setPosition(1000, 1000);
							flag = flag + 1;
							if (Banana2.FF != 1)
								Banana2.Type = "Banana2";

						}

						if ((sf::Mouse::getPosition(w).x > 268 && sf::Mouse::getPosition(w).x < 447) && (sf::Mouse::getPosition(w).y > 222 && sf::Mouse::getPosition(w).y < 316))
						{

							Cover8.sCard.setPosition(1000, 1000);
							flag = flag + 1;
							Orange1.Type = "Orange";

						}

						if ((sf::Mouse::getPosition(w).x > 545 && sf::Mouse::getPosition(w).x < 717) && (sf::Mouse::getPosition(w).y > 222 && sf::Mouse::getPosition(w).y < 316))
						{

							Cover9.sCard.setPosition(1000, 1000);
							flag = flag + 1;
							Peach1.Type = "Peach";

						}

						if ((sf::Mouse::getPosition(w).x > 1 && sf::Mouse::getPosition(w).x < 176) && (sf::Mouse::getPosition(w).y > 330 && sf::Mouse::getPosition(w).y < 421))
						{
							Cover10.sCard.setPosition(1000, 1000);
							flag = flag + 1;
							Peach2.Type = "Peach2";

						}

						if ((sf::Mouse::getPosition(w).x > 268 && sf::Mouse::getPosition(w).x < 447) && (sf::Mouse::getPosition(w).y > 330 && sf::Mouse::getPosition(w).y < 421))
						{

							Cover11.sCard.setPosition(1000, 1000);
							flag = flag + 1;
							Pear2.Type = "Pear2";


						}

						if ((sf::Mouse::getPosition(w).x > 545 && sf::Mouse::getPosition(w).x < 717) && (sf::Mouse::getPosition(w).y > 330 && sf::Mouse::getPosition(w).y < 421))
						{
							Cover12.sCard.setPosition(1000, 1000);
							flag = flag + 1;
					
							Orange2.Type = "Orange2";
						}


						break;
					}
				}
				
				}
			
			if (layers == 'B') 
			{
				if (flag >= 3)
				{
					Cover1.sCard.setPosition(0, 0);
					Cover2.sCard.setPosition(265, 0);
					Cover3.sCard.setPosition(541, 0);
					Cover4.sCard.setPosition(0, 110);
					Cover5.sCard.setPosition(265, 110);
					Cover6.sCard.setPosition(541, 110);
					Cover7.sCard.setPosition(0, 220);
					Cover8.sCard.setPosition(265, 220);
					Cover9.sCard.setPosition(541, 220);
					Cover10.sCard.setPosition(0, 330);
					Cover11.sCard.setPosition(265, 330);
					Cover12.sCard.setPosition(541, 330);
					Pear1.Type = "N2";
					Pear2.Type = "N2";
					Banana1.Type = "N";
					Banana2.Type = "NU";
					Apple1.Type = "NU";
					Apple2.Type = "NU";
					Orange1.Type = "NU";
					Orange2.Type = "NU";
					Durian1.Type = "NU";
					Durian2.Type = "NU";
					Peach1.Type = "NU";
					Peach2.Type = "NU";

					flag = 0;
					moves++;
				}

				if (Banana1.Type == "Banana" && Banana2.Type == "Banana2" && flag == 2)
				{
					score++;
					Banana1.FF = 1;
					Banana2.FF = 1;
					Banana1.Type = "NA";
					Banana2.Type = "NA";
					std::cout << "Score: " << score << std::endl;
					flag = 0;


				}

				if (Orange1.Type == "Orange" && Orange2.Type == "Orange2" && flag == 2)
				{
					score++;
					Orange1.FF = 1;
					Orange2.FF = 1;
					Orange1.Type = "NA";
					Orange2.Type = "NA";
					std::cout << "Score: " << score << std::endl;
					flag = 0;


				}

				if (Pear1.Type == "Pear" && Pear2.Type == "Pear2" && flag == 2)
				{
					score++;
					Pear1.FF = 1;
					Pear2.FF = 1;
					Pear1.Type = "NA";
					Pear1.Type = "NA";
					std::cout << "Score: " << score << std::endl;
					flag = 0;


				}

				if (Apple1.Type == "Apple" && Apple2.Type == "Apple2" && flag == 2)
				{
					score++;
					Apple1.FF = 1;
					Apple2.FF = 1;
					Apple1.Type = "NA";
					Apple1.Type = "NA";
					std::cout << "Score: " << score << std::endl;
					flag = 0;


				}

				if (Peach1.Type == "Peach" && Peach2.Type == "Peach2" && flag == 2)
				{
					score++;
					Peach1.FF = 1;
					Peach2.FF = 1;
					Peach1.Type = "NA";
					Peach2.Type = "NA";
					std::cout << "Score: " << score << std::endl;
					flag = 0;


				}

				if (Durian1.Type == "Durian" && Durian2.Type == "Durian2" && flag == 2)
				{
					score++;
					Durian1.FF = 1;
					Durian2.FF = 1;
					Durian1.Type = "NA";
					Durian2.Type = "NA";
					std::cout << "Score: " << score << std::endl;
					flag = 0;


				}
			}

			w.clear();

			if (score == 6)
			{

				layers = 'C';

			}

			if (layers == 'C')
			{
				w.draw(menu.sB);
				w.draw(menu.sTY);


			}



			if (layers == 'A')
			{
				w.draw(menu.sB);
				w.draw(menu.sPressEnter);
				w.draw(menu.sTitle);

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
				{
					Pop.play();
					layers = 'B';

				}
			}
			if (layers == 'B')
			{
				
				
				w.draw(menu.sB);
				
				if (Banana1.FF != 1 && Banana2.FF != 1)
				{
					w.draw(Cover1.sCard);
					
					w.draw(Banana1.sCard);
					w.draw(Banana2.sCard);
					w.draw(Cover1.sCard);
					w.draw(Cover7.sCard);
				}
				if (Pear1.FF != 1 && Pear2.FF != 1)
				{

					
					w.draw(Pear1.sCard);
					w.draw(Pear2.sCard);
					w.draw(Cover2.sCard);
					w.draw(Cover11.sCard);
					

				}
				if (Apple1.FF != 1 && Apple2.FF != 1)
				{
					w.draw(Apple1.sCard);
					w.draw(Apple2.sCard);

					w.draw(Cover4.sCard);
					w.draw(Cover6.sCard);
				}

				if (Orange1.FF != 1 && Orange2.FF != 1)
				{
					w.draw(Orange1.sCard);
					w.draw(Orange2.sCard);
					w.draw(Cover8.sCard);
					w.draw(Cover12.sCard);

				}

				if (Peach1.FF != 1 && Peach2.FF != 1)
				{
					w.draw(Peach1.sCard);
					w.draw(Peach2.sCard);
					w.draw(Cover9.sCard);
					w.draw(Cover10.sCard);
				}

				if (Durian1.FF != 1 && Durian2.FF != 1)
				{
					w.draw(Durian1.sCard);
					w.draw(Durian2.sCard);
					w.draw(Cover3.sCard);

					w.draw(Cover5.sCard);
				}
				
				std::stringstream ss;
				ss << score;
				scoreText.setString(ss.str());
				
			
				scoreString.setString("Score");

				accText.setString("Moves");
				std::stringstream vv;
				vv << moves;
				accTextNum.setString(vv.str().c_str());

				w.draw(accTextNum);
				w.draw(accText);
				w.draw(scoreText);
				w.draw(scoreString);
				
			}






			w.display();



		}
	}
};




int main()
{
	FreeConsole();
	srand(time(0));
	Run game;
	

	return 0;
}