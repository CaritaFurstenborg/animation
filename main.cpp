#include <SFML/Graphics.hpp>


int main()
{
	float moveSpeed = 0.05;
	int counterAnim = 0;
	sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");


	//sprite create
	sf::Texture pTexture;
	pTexture.loadFromFile("kks.png");
	sf::Sprite pSprite(pTexture);
	pSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	pSprite.setPosition(window.getSize().x / 2, window.getSize().y / 2);


	while (window.isOpen())
	{	
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			pSprite.move(0, -moveSpeed);
			pSprite.setTextureRect(sf::IntRect(counterAnim * 32, 32 * 1, 32, 32));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			pSprite.move(0, moveSpeed);
			pSprite.setTextureRect(sf::IntRect(counterAnim * 32, 32 * 0, 32, 32));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			pSprite.move(-moveSpeed, 0);
			pSprite.setTextureRect(sf::IntRect(counterAnim * 32, 32 * 3, 32, 32));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			pSprite.move(moveSpeed, 0);
			pSprite.setTextureRect(sf::IntRect(counterAnim * 32, 32 * 2, 32, 32));
		}

		
		counterAnim++;
		if (counterAnim == 3)
		{
			counterAnim = 0;
		}
		

		window.draw(pSprite);
		window.display();
	}

	return 0;
}