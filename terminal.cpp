#include "terminal.hpp"

//////////////////////////////// FUNCOES PRINCIPAIS /////////////////////////////

void exibirTexto(sf::RenderWindow& window, const std::string& mensagem, const sf::Font& font, unsigned int fontSize, float x, float y) {
    // criação do texto
    sf::Text texto(mensagem, font, fontSize);
    texto.setPosition(x, y);

    // configura a cor do texto para verde
    texto.setFillColor(sf::Color::Green);

    window.draw(texto);
}
void mostrarManual(sf::RenderWindow& window, const sf::Font& font) {
    sf::Event evento;

    // Criando um botão de voltar
    sf::RectangleShape voltarButton(sf::Vector2f(50, 50));
    voltarButton.setPosition(0, 0);
    voltarButton.setFillColor(sf::Color::Green);

    // Loop principal
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                // Fecha a janela atual
                window.close();
            }

            // Verifica se o botão de voltar foi clicado
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
                sf::FloatRect buttonBounds = voltarButton.getGlobalBounds();

                if (buttonBounds.contains(worldPos)) {
                    // Se o clique do mouse estiver dentro dos limites do botão de voltar,
                    // faz a transição de volta para a janela mostrarDia0
                    mostrarDia0(window, font);
                }
            }
        }

        // Limpa a janela
        window.clear();

        // Desenha o botão de voltar
        window.draw(voltarButton);

        // Exibe o texto
        exibirTexto(window, "manual", font, 24, 20, 100);

        // Atualiza o conteúdo na janela
        window.display();
    }
}
//aparentemente vai ter um manual pra cada dia entao ignorem que esta nas funcoes principais

/////////////////////////////// FUNCOES INICIO /////////////////////////////////
bool verificaTeclaEnter(sf::Event& evento) {
    return (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Enter);
}

void inicio(sf::RenderWindow& window, const sf::Font& font) {

    sf::Event evento;
    bool textoVisible = true;

    // loop principal
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (verificaTeclaEnter(evento)) {
                // Se Enter for pressionado, mostra a nova janela com "DIA 1"
                mostrarDia0(window, font);
            }
        }

        // limpa a janela
        window.clear();

        // desenha os elementos estáticos

        //janelinha

        exibirTexto(window, "----------------------------------------------------", font, 15, 35, 35);
        exibirTexto(window, "|", font, 15, 30, 42);
        exibirTexto(window, "|", font, 15, 30, 59);
        exibirTexto(window, "|", font, 15, 30, 76);
        exibirTexto(window, "|", font, 15, 30, 93);
        exibirTexto(window, "|", font, 15, 30, 110);
        exibirTexto(window, "|", font, 15, 30, 127);
        exibirTexto(window, "|", font, 15, 30, 144);
        exibirTexto(window, "|", font, 15, 30, 161);
        exibirTexto(window, "|", font, 15, 30, 178);

        exibirTexto(window, "|", font, 15, 555, 42);
        exibirTexto(window, "|", font, 15, 555, 59);
        exibirTexto(window, "|", font, 15, 555, 76);
        exibirTexto(window, "|", font, 15, 555, 93);
        exibirTexto(window, "|", font, 15, 555, 110);
        exibirTexto(window, "|", font, 15, 555, 127);
        exibirTexto(window, "|", font, 15, 555, 144);
        exibirTexto(window, "|", font, 15, 555, 161);
        exibirTexto(window, "|", font, 15, 555, 178);

        exibirTexto(window, "----------------------------------------------------", font, 15, 35, 187);

        //COMPANY SA
        exibirTexto(window, "Company SA © 1968 ", font, 50, 50, 88);

        //texto adicional

        exibirTexto(window, "Welcome to the Company’s guide lines. In this document you will learn what is your part in the big ", font, 10, 30, 235);
        exibirTexto(window, "scheme of things. We are all a happy to have you in our family. (Creepy old carnival music playing)", font, 10, 30, 255);

        // desenha o texto "Press ENTER to continue" apenas se estiver visível
        if (textoVisible) {
            exibirTexto(window, "Press ENTER to continue ", font, 10, 30, 290);
        }

        // atualiza o estado de visibilidade do texto
        textoVisible = !textoVisible;

        // exibe o conteúdo na janela
        window.display();
        sf::sleep(sf::milliseconds(400));
    }

}


///////////////////////////////////////////////////////////////////////////////
//////////////////////////////// DIAS /////////////////////////////////////////

// DIA 0

void mostrarChatDia0(sf::RenderWindow& window, const sf::Font& font) {
    sf::Event evento;

    // botão de voltar
    sf::RectangleShape voltarButton(sf::Vector2f(50, 50));
    voltarButton.setPosition(0, 0);
    voltarButton.setFillColor(sf::Color::Green);

    // loop principal
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                // fecha a janela atual
                window.close();
            }

            // verifica se o botão de voltar foi clicado
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
                sf::FloatRect buttonBounds = voltarButton.getGlobalBounds();

                if (buttonBounds.contains(worldPos)) {
                    // se o clique do mouse estiver dentro dos limites do botão de voltar
                    // faz a transição de volta para a janela mostrarDia0
                    mostrarDia0(window, font);
                }
            }
        }

        //limpa a janela
        window.clear();

        // desenha o botão de voltar
        window.draw(voltarButton);

        // exibe o texto
        exibirTexto(window, "chat dia 0", font, 24, 20, 100);

        // atualiza o conteúdo na janela
        window.display();
    }
}

void mostrarReportDia0(sf::RenderWindow& window, const sf::Font& font) {
    sf::Event evento;

    // botão de voltar
    sf::RectangleShape voltarButton(sf::Vector2f(50, 50));
    voltarButton.setPosition(0, 0);
    voltarButton.setFillColor(sf::Color::Green);

    // loop principal
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                //fecha a janela atual
                window.close();
            }

            // verifica se o botão de voltar foi clicado
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
                sf::FloatRect buttonBounds = voltarButton.getGlobalBounds();

                if (buttonBounds.contains(worldPos)) {
                    // se o clique do mouse estiver dentro dos limites do botão de voltar,
                    // faz a transição de volta para a janela mostrarDia0
                    mostrarDia0(window, font);
                }
            }
        }

        // limpa a janela
        window.clear();

        // desenha o botão de voltar
        window.draw(voltarButton);

        // exibe o texto
        exibirTexto(window, "reports dia 0", font, 10, 20, 100);
        exibirTexto(window, "GALAXY B612 - 15/13/56XX", font, 10, 20, 50);
        exibirTexto(window, "[Company]", font, 10, 20, 80);
        exibirTexto(window, "SUBJECT: NEW SURVEYING MISSION", font, 10, 20, 110);
        exibirTexto(window, "Hello, Agent X!", font, 10, 20, 140);
        exibirTexto(window, " We have recently discovered a small planet in an uncharted area using a new radar system. ", font, 10, 60, 150);
        exibirTexto(window, "For now, we call it Ignotus. As this discovery is of great significance, we must gather ", font, 10, 20, 160);
        exibirTexto(window, "information about the planet as soon as possible. Unfortunately, there is only one field agent, Agent Y, ", font, 10, 20, 170);
        exibirTexto(window, "nearby who can take up this mission. Therefore, you will be responsible for guiding Agent Y ", font, 10, 20, 180);
        exibirTexto(window, "as he records and reports all information about the planet's flora, fauna, climate, and geology;  ", font, 10, 20, 190);
        exibirTexto(window, "as well as sending the [Company] a daily report on the team’s discoveries. Agent Y will not be able ", font, 10, 20, 200);
        exibirTexto(window, " to communicate with any other agent while he is on the planet. You will be held accountable for any", font, 10, 20, 210);
        exibirTexto(window, " loss of data or labor that may occur due to negligence. You can find all the useful information that ", font, 10, 20, 220);
        exibirTexto(window, " the radars have detected in the INSTRUCTIONS document and all the general recommendations for missions ", font, 10, 20, 230);
        exibirTexto(window, " in the PROTOCOL document, which are both attached to this message. Agent Y will contact you soon.", font, 10, 20, 240);
        exibirTexto(window, " Best wishes,", font, 10, 60, 230);
        exibirTexto(window, " [Company]: Unlocking the cosmos and enriching the future.", font, 10, 90, 240);

        // atualiza o conteúdo na janela
        window.display();
    }
}

void mostrarDia0(sf::RenderWindow& window, const sf::Font& font) {
    // carrega a imagem de fundo
    sf::Texture fundoTexture;
    if (!fundoTexture.loadFromFile("Desktop with icons 320 180.png")) {
        //exibe uma mensagem de erro caso o carregamento dê errado
    }

    // cria um sprite com a textura carregada
    sf::Sprite fundoSprite(fundoTexture);

    // define a escala do sprite para cobrir toda a janela
    float escalaX = static_cast<float>(window.getSize().x) / fundoTexture.getSize().x;
    float escalaY = static_cast<float>(window.getSize().y) / fundoTexture.getSize().y;
    fundoSprite.setScale(escalaX, escalaY);


    // cria três botão invisíveis
    sf::RectangleShape invisibleButton1(sf::Vector2f(100, 80)); // ajusta o tamanho do botão
    invisibleButton1.setPosition(20, 20); // posição do botão invisível na janela
    invisibleButton1.setFillColor(sf::Color::Transparent); // cor transparente

    sf::RectangleShape invisibleButton2(sf::Vector2f(100, 80));
    invisibleButton2.setPosition(20, 110);
    invisibleButton2.setFillColor(sf::Color::Transparent);

    sf::RectangleShape invisibleButton3(sf::Vector2f(100, 80));
    invisibleButton3.setPosition(20, 230);
    invisibleButton3.setFillColor(sf::Color::Transparent);

    // limpa a nova janela
    window.clear();

    // exibe o conteúdo na nova janela
    window.display();

    // aguarda até o fechamento da nova janela
    sf::Event evento;
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                // fecha a janela atual
                window.close();
            }

            // verifica se o botão invisível foi clicado
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos); //para o botao funcionar com a tela maximizada

                sf::FloatRect buttonBounds1 = invisibleButton1.getGlobalBounds();
                if (buttonBounds1.contains(worldPos)) {
                    // clica no primeiro botão invisível e faz a transição para outra janela
                    mostrarManual(window, font);
                }

                sf::FloatRect buttonBounds2 = invisibleButton2.getGlobalBounds();
                if (buttonBounds2.contains(worldPos)) {
                    // clica no segundo botão invisível e faz a transição para outra janela
                    mostrarChatDia0(window, font);
                }

                sf::FloatRect buttonBounds3 = invisibleButton3.getGlobalBounds();
                if (buttonBounds3.contains(worldPos)) {
                    // clica no terceiro botão invisível e faz a transição para outra janela
                    mostrarReportDia0(window, font);
                }
            }
        }

        // desenha o fundo primeiro
        window.draw(fundoSprite);

        // desenha os botoes invisíveis 
        window.draw(invisibleButton1);
        window.draw(invisibleButton2);
        window.draw(invisibleButton3);

        // exiba o conteúdo na nova janela
        window.display();
    }
}



// DIA 1
void mostrarChatDia1(sf::RenderWindow& window, const sf::Font& font) {
    sf::Event evento;

    // botão de voltar
    sf::RectangleShape voltarButton(sf::Vector2f(50, 50));
    voltarButton.setPosition(0, 0);
    voltarButton.setFillColor(sf::Color::Green);

    // loop principal
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                // fecha a janela atual
                window.close();
            }

            // verifica se o botão de voltar foi clicado
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
                sf::FloatRect buttonBounds = voltarButton.getGlobalBounds();

                if (buttonBounds.contains(worldPos)) {
                    // se o clique do mouse estiver dentro dos limites do botão de voltar
                    // faz a transição de volta para a janela mostrarDia0
                    mostrarDia0(window, font);
                }
            }
        }

        //limpa a janela
        window.clear();

        // desenha o botão de voltar
        window.draw(voltarButton);

        // exibe o texto
        exibirTexto(window, "chat dia 1", font, 24, 20, 100);

        // atualiza o conteúdo na janela
        window.display();
    }
}

void mostrarReportDia1(sf::RenderWindow& window, const sf::Font& font) {
    sf::Event evento;

    // botão de voltar
    sf::RectangleShape voltarButton(sf::Vector2f(50, 50));
    voltarButton.setPosition(0, 0);
    voltarButton.setFillColor(sf::Color::Green);

    // loop principal
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                //fecha a janela atual
                window.close();
            }

            // verifica se o botão de voltar foi clicado
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
                sf::FloatRect buttonBounds = voltarButton.getGlobalBounds();

                if (buttonBounds.contains(worldPos)) {
                    // se o clique do mouse estiver dentro dos limites do botão de voltar,
                    // faz a transição de volta para a janela mostrarDia0
                    mostrarDia0(window, font);
                }
            }
        }

        // limpa a janela
        window.clear();

        // desenha o botão de voltar
        window.draw(voltarButton);

        // exibe o texto
        //exibirTexto(window, "reports dia 0", font, 24, 20, 100);
        exibirTexto(window, "GALAXY B612 - 15/13/56XX", font, 24, 20, 50);
        exibirTexto(window, "[Company]", font, 24, 20, 80);
        exibirTexto(window, "SUBJECT: NEW SURVEYING MISSION", font, 24, 20, 110);
        exibirTexto(window, "Hello, Agent X!", font, 24, 20, 140);
        exibirTexto(window, " We have recently discovered a small planet in an uncharted area using a new radar system. For now, we call it Ignotus. As this ", font, 24, 60, 170);
        exibirTexto(window, "discovery is of great significance, we must gather information about the planet as soon as possible. Unfortunately, there is only one field ", font, 24, 20, 200);
        exibirTexto(window, "agent, Agent Y, nearby who can take up this mission. Therefore, you will be responsible for guiding Agent Y as he records and reports all ", font, 24, 20, 230);
        exibirTexto(window, "information about the planet's flora, fauna, climate, and geology; as well as sending the [Company] a daily report on the team’s discoveries. ", font, 24, 20, 260);
        exibirTexto(window, "Agent Y will not be able to communicate with any other agent while he is on the planet. You will be held accountable for any loss of data or ", font, 24, 20, 290);
        exibirTexto(window, "labor that may occur due to negligence. You can find all the useful information that the radars have detected in the INSTRUCTIONS document ", font, 24, 20, 320);
        exibirTexto(window, "and all the general recommendations for missions in the PROTOCOL document, which are both attached to this message. Agent Y will contact you soon.", font, 24, 20, 350);
        exibirTexto(window, " Best wishes,", font, 24, 60, 380);
        exibirTexto(window, " [Company]: Unlocking the cosmos and enriching the future.", font, 24, 90, 420);

        // atualiza o conteúdo na janela
        window.display();
    }
}

void mostrarDia1(sf::RenderWindow& window, const sf::Font& font) {
    // carrega a imagem de fundo
    sf::Texture fundoTexture;
    if (!fundoTexture.loadFromFile("dia1.png")) {
        //exibe uma mensagem de erro caso o carregamento dê errado
    }

    // cria um sprite com a textura carregada
    sf::Sprite fundoSprite(fundoTexture);

    // define a escala do sprite para cobrir toda a janela
    float escalaX = static_cast<float>(window.getSize().x) / fundoTexture.getSize().x;
    float escalaY = static_cast<float>(window.getSize().y) / fundoTexture.getSize().y;
    fundoSprite.setScale(escalaX, escalaY);


    // cria três botão invisíveis
    sf::RectangleShape invisibleButton1(sf::Vector2f(100, 80)); // ajusta o tamanho do botão
    invisibleButton1.setPosition(20, 20); // posição do botão invisível na janela
    invisibleButton1.setFillColor(sf::Color::Transparent); // cor transparente

    sf::RectangleShape invisibleButton2(sf::Vector2f(100, 80));
    invisibleButton2.setPosition(20, 110);
    invisibleButton2.setFillColor(sf::Color::Transparent);

    sf::RectangleShape invisibleButton3(sf::Vector2f(100, 80));
    invisibleButton3.setPosition(20, 230);
    invisibleButton3.setFillColor(sf::Color::Transparent);

    // limpa a nova janela
    window.clear();

    // exibe o conteúdo na nova janela
    window.display();

    // aguarda até o fechamento da nova janela
    sf::Event evento;
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                // fecha a janela atual
                window.close();
            }

            // verifica se o botão invisível foi clicado
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos); //para o botao funcionar com a tela maximizada

                sf::FloatRect buttonBounds1 = invisibleButton1.getGlobalBounds();
                if (buttonBounds1.contains(worldPos)) {
                    // clica no primeiro botão invisível e faz a transição para outra janela
                    mostrarManual(window, font);
                }

                sf::FloatRect buttonBounds2 = invisibleButton2.getGlobalBounds();
                if (buttonBounds2.contains(worldPos)) {
                    // clica no segundo botão invisível e faz a transição para outra janela
                    mostrarChatDia1(window, font);
                }

                sf::FloatRect buttonBounds3 = invisibleButton3.getGlobalBounds();
                if (buttonBounds3.contains(worldPos)) {
                    // clica no terceiro botão invisível e faz a transição para outra janela
                    mostrarReportDia1(window, font);
                }
            }
        }

        // desenha o fundo primeiro
        window.draw(fundoSprite);

        // desenha os botoes invisíveis 
        window.draw(invisibleButton1);
        window.draw(invisibleButton2);
        window.draw(invisibleButton3);

        // exiba o conteúdo na nova janela
        window.display();
    }
}

// DIA 2
void mostrarChatDia2(sf::RenderWindow& window, const sf::Font& font) {
    sf::Event evento;

    // botão de voltar
    sf::RectangleShape voltarButton(sf::Vector2f(50, 50));
    voltarButton.setPosition(0, 0);
    voltarButton.setFillColor(sf::Color::Green);

    // loop principal
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                // fecha a janela atual
                window.close();
            }

            // verifica se o botão de voltar foi clicado
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
                sf::FloatRect buttonBounds = voltarButton.getGlobalBounds();

                if (buttonBounds.contains(worldPos)) {
                    // se o clique do mouse estiver dentro dos limites do botão de voltar
                    // faz a transição de volta para a janela mostrarDia0
                    mostrarDia0(window, font);
                }
            }
        }

        //limpa a janela
        window.clear();

        // desenha o botão de voltar
        window.draw(voltarButton);

        // exibe o texto
        exibirTexto(window, "chat dia 2", font, 24, 20, 100);

        // atualiza o conteúdo na janela
        window.display();
    }
}

void mostrarReportDia2(sf::RenderWindow& window, const sf::Font& font) {
    sf::Event evento;

    // botão de voltar
    sf::RectangleShape voltarButton(sf::Vector2f(50, 50));
    voltarButton.setPosition(0, 0);
    voltarButton.setFillColor(sf::Color::Green);

    // loop principal
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                //fecha a janela atual
                window.close();
            }

            // verifica se o botão de voltar foi clicado
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
                sf::FloatRect buttonBounds = voltarButton.getGlobalBounds();

                if (buttonBounds.contains(worldPos)) {
                    // se o clique do mouse estiver dentro dos limites do botão de voltar,
                    // faz a transição de volta para a janela mostrarDia0
                    mostrarDia0(window, font);
                }
            }
        }

        // limpa a janela
        window.clear();

        // desenha o botão de voltar
        window.draw(voltarButton);

        // exibe o texto
        exibirTexto(window, "reports dia 2", font, 24, 20, 100);

        // atualiza o conteúdo na janela
        window.display();
    }
}

void mostrarDia2(sf::RenderWindow& window, const sf::Font& font) {
    // carrega a imagem de fundo
    sf::Texture fundoTexture;
    if (!fundoTexture.loadFromFile("dia1.png")) {
        //exibe uma mensagem de erro caso o carregamento dê errado
    }

    // cria um sprite com a textura carregada
    sf::Sprite fundoSprite(fundoTexture);

    // define a escala do sprite para cobrir toda a janela
    float escalaX = static_cast<float>(window.getSize().x) / fundoTexture.getSize().x;
    float escalaY = static_cast<float>(window.getSize().y) / fundoTexture.getSize().y;
    fundoSprite.setScale(escalaX, escalaY);


    // cria três botão invisíveis
    sf::RectangleShape invisibleButton1(sf::Vector2f(100, 80)); // ajusta o tamanho do botão
    invisibleButton1.setPosition(20, 20); // posição do botão invisível na janela
    invisibleButton1.setFillColor(sf::Color::Transparent); // cor transparente

    sf::RectangleShape invisibleButton2(sf::Vector2f(100, 80));
    invisibleButton2.setPosition(20, 110);
    invisibleButton2.setFillColor(sf::Color::Transparent);

    sf::RectangleShape invisibleButton3(sf::Vector2f(100, 80));
    invisibleButton3.setPosition(20, 230);
    invisibleButton3.setFillColor(sf::Color::Transparent);

    // limpa a nova janela
    window.clear();

    // exibe o conteúdo na nova janela
    window.display();

    // aguarda até o fechamento da nova janela
    sf::Event evento;
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                // fecha a janela atual
                window.close();
            }

            // verifica se o botão invisível foi clicado
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos); //para o botao funcionar com a tela maximizada

                sf::FloatRect buttonBounds1 = invisibleButton1.getGlobalBounds();
                if (buttonBounds1.contains(worldPos)) {
                    // clica no primeiro botão invisível e faz a transição para outra janela
                    mostrarManual(window, font);
                }

                sf::FloatRect buttonBounds2 = invisibleButton2.getGlobalBounds();
                if (buttonBounds2.contains(worldPos)) {
                    // clica no segundo botão invisível e faz a transição para outra janela
                    mostrarChatDia2(window, font);
                }

                sf::FloatRect buttonBounds3 = invisibleButton3.getGlobalBounds();
                if (buttonBounds3.contains(worldPos)) {
                    // clica no terceiro botão invisível e faz a transição para outra janela
                    mostrarReportDia2(window, font);
                }
            }
        }

        // desenha o fundo primeiro
        window.draw(fundoSprite);

        // desenha os botoes invisíveis 
        window.draw(invisibleButton1);
        window.draw(invisibleButton2);
        window.draw(invisibleButton3);

        // exiba o conteúdo na nova janela
        window.display();
    }
}

// DIA 3
void mostrarChatDia3(sf::RenderWindow& window, const sf::Font& font) {
    sf::Event evento;

    // botão de voltar
    sf::RectangleShape voltarButton(sf::Vector2f(50, 50));
    voltarButton.setPosition(0, 0);
    voltarButton.setFillColor(sf::Color::Green);

    // loop principal
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                // fecha a janela atual
                window.close();
            }

            // verifica se o botão de voltar foi clicado
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
                sf::FloatRect buttonBounds = voltarButton.getGlobalBounds();

                if (buttonBounds.contains(worldPos)) {
                    // se o clique do mouse estiver dentro dos limites do botão de voltar
                    // faz a transição de volta para a janela mostrarDia0
                    mostrarDia0(window, font);
                }
            }
        }

        //limpa a janela
        window.clear();

        // desenha o botão de voltar
        window.draw(voltarButton);

        // exibe o texto
        exibirTexto(window, "chat dia 3", font, 24, 20, 100);

        // atualiza o conteúdo na janela
        window.display();
    }
}

void mostrarReportDia3(sf::RenderWindow& window, const sf::Font& font) {
    sf::Event evento;

    // botão de voltar
    sf::RectangleShape voltarButton(sf::Vector2f(50, 50));
    voltarButton.setPosition(0, 0);
    voltarButton.setFillColor(sf::Color::Green);

    // loop principal
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                //fecha a janela atual
                window.close();
            }

            // verifica se o botão de voltar foi clicado
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
                sf::FloatRect buttonBounds = voltarButton.getGlobalBounds();

                if (buttonBounds.contains(worldPos)) {
                    // se o clique do mouse estiver dentro dos limites do botão de voltar,
                    // faz a transição de volta para a janela mostrarDia0
                    mostrarDia0(window, font);
                }
            }
        }

        // limpa a janela
        window.clear();

        // desenha o botão de voltar
        window.draw(voltarButton);

        // exibe o texto
        exibirTexto(window, "reports dia 3", font, 24, 20, 100);

        // atualiza o conteúdo na janela
        window.display();
    }
}

void mostrarDia3(sf::RenderWindow& window, const sf::Font& font) {
    // carrega a imagem de fundo
    sf::Texture fundoTexture;
    if (!fundoTexture.loadFromFile("dia1.png")) {
        //exibe uma mensagem de erro caso o carregamento dê errado
    }

    // cria um sprite com a textura carregada
    sf::Sprite fundoSprite(fundoTexture);

    // define a escala do sprite para cobrir toda a janela
    float escalaX = static_cast<float>(window.getSize().x) / fundoTexture.getSize().x;
    float escalaY = static_cast<float>(window.getSize().y) / fundoTexture.getSize().y;
    fundoSprite.setScale(escalaX, escalaY);


    // cria três botão invisíveis
    sf::RectangleShape invisibleButton1(sf::Vector2f(100, 80)); // ajusta o tamanho do botão
    invisibleButton1.setPosition(20, 20); // posição do botão invisível na janela
    invisibleButton1.setFillColor(sf::Color::Transparent); // cor transparente

    sf::RectangleShape invisibleButton2(sf::Vector2f(100, 80));
    invisibleButton2.setPosition(20, 110);
    invisibleButton2.setFillColor(sf::Color::Transparent);

    sf::RectangleShape invisibleButton3(sf::Vector2f(100, 80));
    invisibleButton3.setPosition(20, 230);
    invisibleButton3.setFillColor(sf::Color::Transparent);

    // limpa a nova janela
    window.clear();

    // exibe o conteúdo na nova janela
    window.display();

    // aguarda até o fechamento da nova janela
    sf::Event evento;
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                // fecha a janela atual
                window.close();
            }

            // verifica se o botão invisível foi clicado
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos); //para o botao funcionar com a tela maximizada

                sf::FloatRect buttonBounds1 = invisibleButton1.getGlobalBounds();
                if (buttonBounds1.contains(worldPos)) {
                    // clica no primeiro botão invisível e faz a transição para outra janela
                    mostrarManual(window, font);
                }

                sf::FloatRect buttonBounds2 = invisibleButton2.getGlobalBounds();
                if (buttonBounds2.contains(worldPos)) {
                    // clica no segundo botão invisível e faz a transição para outra janela
                    mostrarChatDia3(window, font);
                }

                sf::FloatRect buttonBounds3 = invisibleButton3.getGlobalBounds();
                if (buttonBounds3.contains(worldPos)) {
                    // clica no terceiro botão invisível e faz a transição para outra janela
                    mostrarReportDia3(window, font);
                }
            }
        }

        // desenha o fundo primeiro
        window.draw(fundoSprite);

        // desenha os botoes invisíveis 
        window.draw(invisibleButton1);
        window.draw(invisibleButton2);
        window.draw(invisibleButton3);

        // exiba o conteúdo na nova janela
        window.display();
    }
}

// DIA 4
void mostrarChatDia4(sf::RenderWindow& window, const sf::Font& font) {
    sf::Event evento;

    // botão de voltar
    sf::RectangleShape voltarButton(sf::Vector2f(50, 50));
    voltarButton.setPosition(0, 0);
    voltarButton.setFillColor(sf::Color::Green);

    // loop principal
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                // fecha a janela atual
                window.close();
            }

            // verifica se o botão de voltar foi clicado
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
                sf::FloatRect buttonBounds = voltarButton.getGlobalBounds();

                if (buttonBounds.contains(worldPos)) {
                    // se o clique do mouse estiver dentro dos limites do botão de voltar
                    // faz a transição de volta para a janela mostrarDia0
                    mostrarDia0(window, font);
                }
            }
        }

        //limpa a janela
        window.clear();

        // desenha o botão de voltar
        window.draw(voltarButton);

        // exibe o texto
        exibirTexto(window, "chat dia 4", font, 24, 20, 100);

        // atualiza o conteúdo na janela
        window.display();
    }
}

void mostrarReportDia4(sf::RenderWindow& window, const sf::Font& font) {
    sf::Event evento;

    // botão de voltar
    sf::RectangleShape voltarButton(sf::Vector2f(50, 50));
    voltarButton.setPosition(0, 0);
    voltarButton.setFillColor(sf::Color::Green);

    // loop principal
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                //fecha a janela atual
                window.close();
            }

            // verifica se o botão de voltar foi clicado
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
                sf::FloatRect buttonBounds = voltarButton.getGlobalBounds();

                if (buttonBounds.contains(worldPos)) {
                    // se o clique do mouse estiver dentro dos limites do botão de voltar,
                    // faz a transição de volta para a janela mostrarDia0
                    mostrarDia0(window, font);
                }
            }
        }

        // limpa a janela
        window.clear();

        // desenha o botão de voltar
        window.draw(voltarButton);

        // exibe o texto
        exibirTexto(window, "reports dia 4", font, 24, 20, 100);

        // atualiza o conteúdo na janela
        window.display();
    }
}

void mostrarDia4(sf::RenderWindow& window, const sf::Font& font) {
    // carrega a imagem de fundo
    sf::Texture fundoTexture;
    if (!fundoTexture.loadFromFile("dia1.png")) {
        //exibe uma mensagem de erro caso o carregamento dê errado
    }

    // cria um sprite com a textura carregada
    sf::Sprite fundoSprite(fundoTexture);

    // define a escala do sprite para cobrir toda a janela
    float escalaX = static_cast<float>(window.getSize().x) / fundoTexture.getSize().x;
    float escalaY = static_cast<float>(window.getSize().y) / fundoTexture.getSize().y;
    fundoSprite.setScale(escalaX, escalaY);


    // cria três botão invisíveis
    sf::RectangleShape invisibleButton1(sf::Vector2f(100, 80)); // ajusta o tamanho do botão
    invisibleButton1.setPosition(20, 20); // posição do botão invisível na janela
    invisibleButton1.setFillColor(sf::Color::Transparent); // cor transparente

    sf::RectangleShape invisibleButton2(sf::Vector2f(100, 80));
    invisibleButton2.setPosition(20, 110);
    invisibleButton2.setFillColor(sf::Color::Transparent);

    sf::RectangleShape invisibleButton3(sf::Vector2f(100, 80));
    invisibleButton3.setPosition(20, 230);
    invisibleButton3.setFillColor(sf::Color::Transparent);

    // limpa a nova janela
    window.clear();

    // exibe o conteúdo na nova janela
    window.display();

    // aguarda até o fechamento da nova janela
    sf::Event evento;
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                // fecha a janela atual
                window.close();
            }

            // verifica se o botão invisível foi clicado
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos); //para o botao funcionar com a tela maximizada

                sf::FloatRect buttonBounds1 = invisibleButton1.getGlobalBounds();
                if (buttonBounds1.contains(worldPos)) {
                    // clica no primeiro botão invisível e faz a transição para outra janela
                    mostrarManual(window, font);
                }

                sf::FloatRect buttonBounds2 = invisibleButton2.getGlobalBounds();
                if (buttonBounds2.contains(worldPos)) {
                    // clica no segundo botão invisível e faz a transição para outra janela
                    mostrarChatDia4(window, font);
                }

                sf::FloatRect buttonBounds3 = invisibleButton3.getGlobalBounds();
                if (buttonBounds3.contains(worldPos)) {
                    // clica no terceiro botão invisível e faz a transição para outra janela
                    mostrarReportDia4(window, font);
                }
            }
        }

        // desenha o fundo primeiro
        window.draw(fundoSprite);

        // desenha os botoes invisíveis 
        window.draw(invisibleButton1);
        window.draw(invisibleButton2);
        window.draw(invisibleButton3);

        // exiba o conteúdo na nova janela
        window.display();
    }
}

// DIA 5
void mostrarChatDia5(sf::RenderWindow& window, const sf::Font& font) {
    sf::Event evento;

    // botão de voltar
    sf::RectangleShape voltarButton(sf::Vector2f(50, 50));
    voltarButton.setPosition(0, 0);
    voltarButton.setFillColor(sf::Color::Green);

    // loop principal
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                // fecha a janela atual
                window.close();
            }

            // verifica se o botão de voltar foi clicado
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
                sf::FloatRect buttonBounds = voltarButton.getGlobalBounds();

                if (buttonBounds.contains(worldPos)) {
                    // se o clique do mouse estiver dentro dos limites do botão de voltar
                    // faz a transição de volta para a janela mostrarDia0
                    mostrarDia0(window, font);
                }
            }
        }

        //limpa a janela
        window.clear();

        // desenha o botão de voltar
        window.draw(voltarButton);

        // exibe o texto
        exibirTexto(window, "chat dia 5", font, 24, 20, 100);

        // atualiza o conteúdo na janela
        window.display();
    }
}

void mostrarReportDia5(sf::RenderWindow& window, const sf::Font& font) {
    sf::Event evento;

    // botão de voltar
    sf::RectangleShape voltarButton(sf::Vector2f(50, 50));
    voltarButton.setPosition(0, 0);
    voltarButton.setFillColor(sf::Color::Green);

    // loop principal
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                //fecha a janela atual
                window.close();
            }

            // verifica se o botão de voltar foi clicado
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
                sf::FloatRect buttonBounds = voltarButton.getGlobalBounds();

                if (buttonBounds.contains(worldPos)) {
                    // se o clique do mouse estiver dentro dos limites do botão de voltar,
                    // faz a transição de volta para a janela mostrarDia0
                    mostrarDia0(window, font);
                }
            }
        }

        // limpa a janela
        window.clear();

        // desenha o botão de voltar
        window.draw(voltarButton);

        // exibe o texto
        exibirTexto(window, "reports dia 5", font, 24, 20, 100);

        // atualiza o conteúdo na janela
        window.display();
    }
}

void mostrarDia5(sf::RenderWindow& window, const sf::Font& font) {
    // carrega a imagem de fundo
    sf::Texture fundoTexture;
    if (!fundoTexture.loadFromFile("dia1.png")) {
        //exibe uma mensagem de erro caso o carregamento dê errado
    }

    // cria um sprite com a textura carregada
    sf::Sprite fundoSprite(fundoTexture);

    // define a escala do sprite para cobrir toda a janela
    float escalaX = static_cast<float>(window.getSize().x) / fundoTexture.getSize().x;
    float escalaY = static_cast<float>(window.getSize().y) / fundoTexture.getSize().y;
    fundoSprite.setScale(escalaX, escalaY);


    // cria três botão invisíveis
    sf::RectangleShape invisibleButton1(sf::Vector2f(100, 80)); // ajusta o tamanho do botão
    invisibleButton1.setPosition(20, 20); // posição do botão invisível na janela
    invisibleButton1.setFillColor(sf::Color::Transparent); // cor transparente

    sf::RectangleShape invisibleButton2(sf::Vector2f(100, 80));
    invisibleButton2.setPosition(20, 110);
    invisibleButton2.setFillColor(sf::Color::Transparent);

    sf::RectangleShape invisibleButton3(sf::Vector2f(100, 80));
    invisibleButton3.setPosition(20, 230);
    invisibleButton3.setFillColor(sf::Color::Transparent);

    // limpa a nova janela
    window.clear();

    // exibe o conteúdo na nova janela
    window.display();

    // aguarda até o fechamento da nova janela
    sf::Event evento;
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                // fecha a janela atual
                window.close();
            }

            // verifica se o botão invisível foi clicado
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos); //para o botao funcionar com a tela maximizada

                sf::FloatRect buttonBounds1 = invisibleButton1.getGlobalBounds();
                if (buttonBounds1.contains(worldPos)) {
                    // clica no primeiro botão invisível e faz a transição para outra janela
                    mostrarManual(window, font);
                }

                sf::FloatRect buttonBounds2 = invisibleButton2.getGlobalBounds();
                if (buttonBounds2.contains(worldPos)) {
                    // clica no segundo botão invisível e faz a transição para outra janela
                    mostrarChatDia5(window, font);
                }

                sf::FloatRect buttonBounds3 = invisibleButton3.getGlobalBounds();
                if (buttonBounds3.contains(worldPos)) {
                    // clica no terceiro botão invisível e faz a transição para outra janela
                    mostrarReportDia5(window, font);
                }
            }
        }

        // desenha o fundo primeiro
        window.draw(fundoSprite);

        // desenha os botoes invisíveis 
        window.draw(invisibleButton1);
        window.draw(invisibleButton2);
        window.draw(invisibleButton3);

        // exiba o conteúdo na nova janela
        window.display();
    }
}