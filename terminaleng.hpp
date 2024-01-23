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


//funcoes principais
void showText(sf::RenderWindow& window, const std::string& mensagem, const sf::Font& font, unsigned int fontSize, float x, float y);
void limparRetangulo(sf::RenderWindow& window);
void limparRetanguloChat(sf::RenderWindow& window);
// muda somente a cor
void showTextChat(sf::RenderWindow& window, const std::string& mensagem, const sf::Font& font, unsigned int fontSize, float x, float y);
void exibirNome(sf::RenderWindow& window, int pessoa, const sf::Font& font, float x, float y);
void showManual(sf::RenderWindow& window, const sf::Font& font);

//funcoes inicio
void beginning(sf::RenderWindow& window, const sf::Font& font);
bool verifyEnterKey(sf::Event& evento, bool& enterPressed);

// dia 0
void showChatDay0(sf::RenderWindow& window, const sf::Font& font);
void showReportDay0(sf::RenderWindow& window, const sf::Font& font);
void showDay0(sf::RenderWindow& window, const sf::Font& font);

void mensagem2(sf::RenderWindow& window, const sf::Font& font);
void continuacaoMensagem2(sf::RenderWindow& window, const sf::Font& font);


void emptyPage(sf::RenderWindow& window, const sf::Font& font);
void mushroomManPage(sf::RenderWindow& window, const sf::Font& font);
void giantScorpionPage(sf::RenderWindow& window, const sf::Font& font);
void parasiteIvyPage(sf::RenderWindow& window, const sf::Font& font);
void finalPage(sf::RenderWindow& window, const sf::Font& font);