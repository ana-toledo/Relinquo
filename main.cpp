#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "terminal.hpp"
#include <iostream>


int main()
{

    // criação da janela
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Jogo");

    // criação da fonte
    sf::Font font;
    if (!font.loadFromFile("Retro gaming.ttf")) {
        std::cerr << "Erro ao carregar a fonte" << std::endl;
        return EXIT_FAILURE;
    }

    // criação música
    sf::Music music;
    music.openFromFile("seus bracos sao como amor paterno.flac");
    music.setVolume(70.0f);
    music.play();

    // loop principal
    while (window.isOpen()) {
        // processamento de eventos
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }


        // limpa a janela
        window.clear();

        ////////////////////////// chamada de funcoes ///////////////////////////
        inicio(window, font);

        ///////////////////////////////////////////////////

        // exibe tudo na janela
        window.display();
    }
    /*sf::RenderWindow window(sf::VideoMode(1250, 720), "Infestara");
    sf::Font font;
    sf::Texture texture;
    sf::RectangleShape line(sf::Vector2f(1000.f, 5.f));
    sf::Sprite sprite;
    sf::Music music;
    if (!music.openFromFile("seus bracos sao como amor paterno.flac")) {
        std::cout << "falha audio";
        system("pause");
    }
    if (!texture.loadFromFile("document icon.png"))
    {
        std::cout << "falha na textura";
        system("pause");
    }

    if (!font.loadFromFile("hieroglifos.ttf"))
    {
        std::cout << "Erro fonte";
        system("pause");
    }
    sf::Text text;
    window.setFramerateLimit(60);
    music.play();

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        text.setFont(font);
        text.setString("You have slaughtered our people");
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Green);
        text.setPosition(150, 200);
        line.setPosition(150, 300);
        line.setFillColor(sf::Color::Green);
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(150.f, 350.f));
        window.draw(text);
        window.draw(line);
        window.draw(sprite);
        window.display();
    }*/

    return 0;
}