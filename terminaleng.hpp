#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <chrono> // piscar enter
#include <thread> //piscar enter
#include <iostream>
#include <ctime>
#include "fila.hpp"
#include "jogador.hpp"

//bool music_on = true;

//funcoes principais
void showText(sf::RenderWindow& window, const std::string& mensagem, const sf::Font& font, unsigned int fontSize, float x, float y);
void showTextChat(sf::RenderWindow& window, const std::string& mensagem, const sf::Font& font, unsigned int fontSize, float x, float y);

//funcoes inicio
void beginning(sf::RenderWindow& window, const sf::Font& font);
bool verifyEnterKey(sf::Event& evento, bool& enterPressed);


void showInfo(sf::RenderWindow& window, const sf::Font& font);
void showReportDay0(sf::RenderWindow& window, const sf::Font& font);
void showDay0(sf::RenderWindow& window, const sf::Font& font);

// dia 1
void showMailDay1(sf::RenderWindow& window, const sf::Font& font);
void mailDay1Text(sf::RenderWindow& window, const sf::Font& font, double msg);
void replymailDay1Text(sf::RenderWindow& window, const sf::Font& font, double msg);
void final1(sf::RenderWindow& window, const sf::Font& font);


void showFinalScreen(sf::RenderWindow& window);


// catalogue
void emptyPage(sf::RenderWindow& window, const sf::Font& font);
void mushroomManPage(sf::RenderWindow& window, const sf::Font& font);
void giantScorpionPage(sf::RenderWindow& window, const sf::Font& font);
void parasiteIvyPage(sf::RenderWindow& window, const sf::Font& font);
void finalPage(sf::RenderWindow& window, const sf::Font& font);