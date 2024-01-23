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
void exibirTexto(sf::RenderWindow& window, const std::string& mensagem, const sf::Font& font, unsigned int fontSize, float x, float y, sf::Color cor);

//funcoes inicio
void inicio(sf::RenderWindow& window, const sf::Font& font);
bool verificaTeclaEnter(sf::Event& evento, bool& enterPressed);

// dia 0

void mostrarReportDia0(sf::RenderWindow& window, const sf::Font& font);
void mostrarDia0(sf::RenderWindow& window, const sf::Font& font);


void paginaVazia(sf::RenderWindow& window, const sf::Font& font);
void paginaCogumelo(sf::RenderWindow& window, const sf::Font& font);
void paginaEscorpiao(sf::RenderWindow& window, const sf::Font& font);
void paginaHera(sf::RenderWindow& window, const sf::Font& font);
void paginaFinal(sf::RenderWindow& window, const sf::Font& font);