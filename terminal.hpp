#pragma once

#include <SFML/Graphics.hpp>
#include <chrono> // piscar enter
#include <thread> //piscar enter
#include <iostream>

//funcoes principais
void exibirTexto(sf::RenderWindow& window, const std::string& mensagem, const sf::Font& font, unsigned int fontSize, float x, float y);
void mostrarManual(sf::RenderWindow& window, const sf::Font& font);

//funcoes inicio
void inicio(sf::RenderWindow& window, const sf::Font& font);
bool verificaTeclaEnter(sf::Event& evento);

// dia 0
void mostrarChatDia0(sf::RenderWindow& window, const sf::Font& font);
void mostrarReportDia0(sf::RenderWindow& window, const sf::Font& font);
void mostrarDia0(sf::RenderWindow& window, const sf::Font& font);

//dia 1
void mostrarChatDia1(sf::RenderWindow& window, const sf::Font& font);
void mostrarReportDia1(sf::RenderWindow& window, const sf::Font& font);
void mostrarDia1(sf::RenderWindow& window, const sf::Font& font);

//dia 2
void mostrarChatDia2(sf::RenderWindow& window, const sf::Font& font);
void mostrarReportDia2(sf::RenderWindow& window, const sf::Font& font);
void mostrarDia2(sf::RenderWindow& window, const sf::Font& font);

//dia 3
void mostrarChatDia3(sf::RenderWindow& window, const sf::Font& font);
void mostrarReportDia3(sf::RenderWindow& window, const sf::Font& font);
void mostrarDia3(sf::RenderWindow& window, const sf::Font& font);

//dia 4
void mostrarChatDia4(sf::RenderWindow& window, const sf::Font& font);
void mostrarReportDia4(sf::RenderWindow& window, const sf::Font& font);
void mostrarDia4(sf::RenderWindow& window, const sf::Font& font);

//dia 5
void mostrarChatDia5(sf::RenderWindow& window, const sf::Font& font);
void mostrarReportDia5(sf::RenderWindow& window, const sf::Font& font);
void mostrarDia5(sf::RenderWindow& window, const sf::Font& font);
