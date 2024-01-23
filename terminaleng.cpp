#include "terminaleng.hpp"


//////////////////////////////// FUNCOES PRINCIPAIS /////////////////////////////

Fila* catalogue = cria_fila(); // variavel global para o catalogo
Player* you = cria_jogador();


void showText(sf::RenderWindow& window, const std::string& mensagem, const sf::Font& font, unsigned int fontSize, float x, float y) {
    // criação do texto
    sf::Text texto(mensagem, font, fontSize);
    texto.setPosition(x, y);

    // configura a cor do texto para verde
    texto.setFillColor(sf::Color::Green);

    window.draw(texto);
}

void showTextChat(sf::RenderWindow& window, const std::string& mensagem, const sf::Font& font, unsigned int fontSize, float x, float y) {
    // criação do texto
    sf::Text texto(mensagem, font, fontSize);
    texto.setPosition(x, y);

    // configura a cor do texto para verde
    texto.setFillColor(sf::Color::White);
    window.draw(texto);
}

void exibirNome(sf::RenderWindow& window, int pessoa, const sf::Font& font, float x, float y) {
    // criação das cores
    sf::Color light_grey(126, 126, 143, 255);
    sf::Color dark_blue(50, 41, 71, 255);

    if (pessoa == 1)
    {
        sf::Text nome("You: ", font, 20);
        nome.setFillColor(light_grey);
        nome.setPosition(x, y);
        window.draw(nome);
    }
    else if (pessoa == 2) {
        sf::Text nome("B4: ", font, 20);
        nome.setFillColor(dark_blue);
        nome.setPosition(x, y);
        window.draw(nome);
    }
    else {
        sf::Text nome("Company: ", font, 20);
        nome.setFillColor(dark_blue);
        nome.setPosition(x, y);
        window.draw(nome);
    }
}

//aparentemente vai ter um manual pra cada dia entao ignorem que esta nas funcoes principais
void limparRetangulo(sf::RenderWindow& window) {
    sf::RectangleShape retanguloLimpo(sf::Vector2f(655, 200));
    retanguloLimpo.setPosition(575, 460);
    retanguloLimpo.setFillColor(sf::Color::Black);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    window.draw(retanguloLimpo);
}
void limparRetanguloChat(sf::RenderWindow& window) {
    sf::RectangleShape retanguloLimpo(sf::Vector2f(658, 315));
    retanguloLimpo.setPosition(575, 80);
    retanguloLimpo.setFillColor(sf::Color::Black);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    window.draw(retanguloLimpo);
}

/////////////////////////////// FUNCOES INICIO /////////////////////////////////
bool verifyEnterKey(sf::Event& evento, bool& enterPressed) {
    if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Enter) {
        enterPressed = true;
        return true;
    }
    return false;
}

void beginning(sf::RenderWindow& window, const sf::Font& font) {

    sf::Event evento;
    bool textoVisible = true;
    bool enterPressed = false;

    sf::Texture textureBG;
    sf::Sprite spriteBG;
    if (!textureBG.loadFromFile("Assets/First screen no txt.png")) {
        std::cout << "background error\n";
        system("pause");
    }

    spriteBG.setTexture(textureBG);
    spriteBG.setPosition(10, 10);

    // som ao apertar enter

    sf::SoundBuffer bufferInicio;
    sf::Sound somInicio;
    if (!bufferInicio.loadFromFile("Assets/start software.wav")) {
        std::cout << "start sound error\n";
        system("pause");
    }
    somInicio.setBuffer(bufferInicio);

    // loop principal
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (verifyEnterKey(evento, enterPressed)) {
                // Se Enter for pressionado, mostra a nova janela com "DIA 1"
                somInicio.play();
                showReportDay0(window, font);
            }
            if (evento.type == sf::Event::Closed) window.close();
        }

        // limpa a janela
        window.clear();

        // desenha os elementos estáticos
        window.draw(spriteBG);

        // desenha o texto "Press ENTER to continue" apenas se estiver visível
        if (textoVisible) {
            showText(window, "Press ENTER to continue ", font, 30, 435, 550);
        }

        // atualiza o estado de visibilidade do texto
        textoVisible = !textoVisible;

        // exibe o conteúdo na janela
        window.display();
        sf::sleep(sf::milliseconds(500));
    }
}



///////////////////////////////////////////////////////////////////////////////
//////////////////////////////// DIAS /////////////////////////////////////////

// DIA 0

void showChatDay0(sf::RenderWindow& window, const sf::Font& font) {
    sf::Event evento;
    bool enterPressed = false;
    int opc[3] = { 0, 0, 0 };
    int index = 0; // marcador de dialogo do player, para salvar as opcoes
    int answer = 0;

    // botão de voltar
    sf::RectangleShape voltarButton(sf::Vector2f(50, 50));
    voltarButton.setPosition(15, 680);
    voltarButton.setFillColor(sf::Color::Transparent);



    // loop principal
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                // fecha a janela atual
                window.close();
            }
            if (verifyEnterKey(evento, enterPressed)) {
                if (opc[0] == 1 && enterPressed) {
                    mensagem2(window, font);
                    enterPressed = false;  // resetando a variável para evitar chamadas repetidas
                }
                else  if (opc[0] == 2 && enterPressed) {
                    mensagem2(window, font);
                    enterPressed = false;  // resetando a variável para evitar chamadas repetidas
                }
                else if (opc[0] == 3 && enterPressed) {
                    mensagem2(window, font);
                    enterPressed = false;  // resetando a variável para evitar chamadas repetidas
                }
            }

            if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Num1) {
                opc[index] = 1;
                std::cout << "botao apertado";
            }
            else if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Num2) opc[index] = 2;
            else if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Num3) opc[index] = 3;

            // verifica se o botão de voltar foi clicado
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
                sf::FloatRect buttonBounds = voltarButton.getGlobalBounds();

                if (buttonBounds.contains(worldPos)) {
                    // se o clique do mouse estiver dentro dos limites do botão de voltar
                    // faz a transição de volta para a janela showDay0
                    showDay0(window, font);
                }
            }
        }

        // o answer se atualiza conforme o index para marcar a ordem de cada fala
        // tem que estar antes das escolhas para nao dar problema devido ao loop principal
        answer = index;

        //limpa a janela

        window.clear();


        // desenha o botão de voltar
        window.draw(voltarButton);

        // fundo ////////

        sf::Texture chatBG;
        chatBG.loadFromFile("Assets/chat agent b4.png");
        sf::Sprite chatBG_sprite(chatBG);
        window.draw(chatBG_sprite);

        /////////////////////////////////////// textos /////////////////////////////////
         // mensagem 1
        exibirNome(window, 2, font, 580, 80);
        showTextChat(window, "Hey", font, 20, 630, 80);

        // opcoes player 1
        showTextChat(window, "1) Hello", font, 20, 580, 490);
        showTextChat(window, "2) ...", font, 20, 580, 545);
        showTextChat(window, "3) Who are you?", font, 20, 580, 600);


        //resposta  player 1
        exibirNome(window, 1, font, 580, 110);
        if (opc[0] == 1) {
            showTextChat(window, "Hello", font, 20, 650, 110);
            index = 1;
            insere_elemento(catalogue, 1); // teste catalogo

            //sf::sleep(sf::milliseconds(500)); // ISSO NAO FAZ SENTIDO NENHUMKKKKK
            //b4
            if (answer == 1) {
                sf::sleep(sf::milliseconds(500));
                exibirNome(window, 2, font, 580, 140);
                showTextChat(window, "Am I talking to the Relinquo mission controller?", font, 20, 630, 140);
                //player
                exibirNome(window, 1, font, 580, 170);
                showTextChat(window, "Yeah, thats me. I hope Im talking to Agent B4.", font, 20, 650, 170);

                //b4
                exibirNome(window, 2, font, 580, 200);
                showTextChat(window, "Great! Yes, we are a team.", font, 20, 630, 200);


                limparRetangulo(window);
            }
        }
        else if (opc[0] == 2) {
            showTextChat(window, "...", font, 20, 650, 110);
            index = 1;

            if (answer == 1) {
                sf::sleep(sf::milliseconds(500));
                //b4
                exibirNome(window, 2, font, 580, 140);
                showTextChat(window, "Is anyone there?", font, 20, 630, 140);
                //player
                exibirNome(window, 1, font, 580, 170);
                showTextChat(window, "Sorry, Im here. Are you Agent B4?", font, 20, 650, 170);

                //b4
                exibirNome(window, 2, font, 580, 200);
                showTextChat(window, "Thank god, I thought I was gonna be ghosted \nfor a moment. Yes, Im your new teammate.", font, 20, 630, 200);
                limparRetangulo(window);
            }

        }
        else if (opc[0] == 3) {
            showTextChat(window, "Who are you?", font, 20, 650, 110);
            index = 1;

            if (answer == 1) {
                sf::sleep(sf::milliseconds(500));
                //b4
                exibirNome(window, 2, font, 580, 140);
                showTextChat(window, "Im Agent B4. Did you not receive a message \nfrom the company about a new mission? Maybe I \ngot the wrong person.", font, 20, 630, 140);
                //player
                exibirNome(window, 1, font, 580, 225);
                showTextChat(window, "No, thats right. Im controlling the Relinquo \nmission.", font, 20, 650, 225);

                //b4
                exibirNome(window, 2, font, 580, 280);
                showTextChat(window, "I guess we are stuck together, then.", font, 20, 630, 280);
                limparRetangulo(window);
            }

        }


        // atualiza o conteúdo na janela

        window.display();
    }

}

void mensagem2(sf::RenderWindow& window, const sf::Font& font) {
    bool enterPressed = false;
    sf::Event eventoMensagem2;
    int opc[3] = { 0, 0, 0 };
    int index = 0; // marcador de dialogo do player, para salvar as opcoes

    // botão de voltar
    sf::RectangleShape voltarButton(sf::Vector2f(50, 50));
    voltarButton.setPosition(15, 680);
    voltarButton.setFillColor(sf::Color::Transparent);



    // loop principal
    while (window.isOpen()) {
        while (window.pollEvent(eventoMensagem2)) {
            if (verifyEnterKey(eventoMensagem2, enterPressed)) {
                if (opc[0] == 1 && enterPressed) {
                    continuacaoMensagem2(window, font);
                    enterPressed = false;  // resetando a variável para evitar chamadas repetidas
                }
                else  if (opc[0] == 2 && enterPressed) {
                    continuacaoMensagem2(window, font);
                    enterPressed = false;  // resetando a variável para evitar chamadas repetidas
                }
                else if (opc[0] == 3 && enterPressed) {
                    continuacaoMensagem2(window, font);
                    enterPressed = false;  // resetando a variável para evitar chamadas repetidas
                }
            }
            if (eventoMensagem2.type == sf::Event::Closed) {
                // fecha a janela atual
                window.close();
            }

            if (eventoMensagem2.type == sf::Event::KeyPressed && eventoMensagem2.key.code == sf::Keyboard::Num1) {
                opc[index] = 1;
                std::cout << "botao apertado";
            }
            else if (eventoMensagem2.type == sf::Event::KeyPressed && eventoMensagem2.key.code == sf::Keyboard::Num2) opc[index] = 2;
            else if (eventoMensagem2.type == sf::Event::KeyPressed && eventoMensagem2.key.code == sf::Keyboard::Num3) opc[index] = 3;

            // verifica se o botão de voltar foi clicado
            if (eventoMensagem2.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
                sf::FloatRect buttonBounds = voltarButton.getGlobalBounds();

                if (buttonBounds.contains(worldPos)) {
                    // se o clique do mouse estiver dentro dos limites do botão de voltar
                    // faz a transição de volta para a janela showDay0
                    showDay0(window, font);
                }
            }
        }

        //limpa a janela

        window.clear();


        // desenha o botão de voltar
        window.draw(voltarButton);

        // fundo ////////

        sf::Texture chatBG;
        chatBG.loadFromFile("Assets/chat agent b4.png");
        sf::Sprite chatBG_sprite(chatBG);
        window.draw(chatBG_sprite);


        /////////////////////////////////////// textos /////////////////////////////////

        // mensagem 2

        exibirNome(window, 2, font, 580, 80);
        showTextChat(window, "Well, I'm pretty close to arriving at Relinquo,\n but we still have some time before that.", font, 20, 630, 80);


        //opcoes do player 2
        showTextChat(window, "1) Contact me again later, then. I dont have time \nfor this.", font, 20, 580, 490);
        showTextChat(window, "2) I think we should get to know each other a \nlittle bit better. Tell me something about you", font, 20, 580, 550);
        showTextChat(window, "3) Oh, okay.", font, 20, 580, 610);


        // resposta 2
        exibirNome(window, 1, font, 580, 140);
        if (opc[0] == 1) {
            showTextChat(window, "Contact me again later, then. I dont have time \nfor this.", font, 20, 650, 140);
            //b4
            exibirNome(window, 2, font, 580, 200);
            showTextChat(window, "Geez... Okay, I guess. Great to talk to you too. \n[Agent B4 leaves for some time]", font, 20, 650, 200);
            index = 2;
            limparRetangulo(window);

        }
        else if (opc[0] == 2) {
            showTextChat(window, "I think we should get to know each other a \nlittle bit better. Tell me something about you.", font, 20, 650, 140);
            //b4
            exibirNome(window, 2, font, 580, 200);
            showTextChat(window, "Hmm... Im not good at this kind of thing, but Im \ngonna try. This is my first field mission. I feel \nquite nervous.", font, 20, 630, 200);
            index = 2;
            limparRetangulo(window);
        }
        else if (opc[0] == 3) {
            showTextChat(window, "Oh, okay.", font, 20, 650, 140);
            showTextChat(window, "[Silence]", font, 20, 630, 170);
            //player
            exibirNome(window, 1, font, 580, 200);
            showTextChat(window, "Well, this is awkward.", font, 20, 650, 200);
            //b4
            exibirNome(window, 2, font, 580, 230);
            showTextChat(window, "It really is.", font, 20, 630, 230);
            //player
            exibirNome(window, 1, font, 580, 260);
            showTextChat(window, "So... Are you scared?", font, 20, 650, 260);
            //b4
            exibirNome(window, 2, font, 580, 290);
            showTextChat(window, "Of what?", font, 20, 630, 290);

            //player
            exibirNome(window, 1, font, 580, 320);
            showTextChat(window, "Going to this planet knowing almost nothing \nabout it. It must be weird.", font, 20, 650, 320);

            index = 2;
            limparRetangulo(window);
        }


        // atualiza o conteúdo na janela

        window.display();
    }

}

void continuacaoMensagem2(sf::RenderWindow& window, const sf::Font& font) {
    sf::Event eventoMensagem2;
    int opc[3] = { 0, 0, 0 };
    int index = 0; // marcador de dialogo do player, para salvar as opcoes

    // botão de voltar
    sf::RectangleShape voltarButton(sf::Vector2f(50, 50));
    voltarButton.setPosition(15, 680);
    voltarButton.setFillColor(sf::Color::Transparent);



    // loop principal
    while (window.isOpen()) {
        while (window.pollEvent(eventoMensagem2)) {
            if (eventoMensagem2.type == sf::Event::Closed) {
                // fecha a janela atual
                window.close();
            }

            if (eventoMensagem2.type == sf::Event::KeyPressed && eventoMensagem2.key.code == sf::Keyboard::Num1) {
                opc[index] = 1;
                std::cout << "botao apertado";
            }
            else if (eventoMensagem2.type == sf::Event::KeyPressed && eventoMensagem2.key.code == sf::Keyboard::Num2) opc[index] = 2;
            else if (eventoMensagem2.type == sf::Event::KeyPressed && eventoMensagem2.key.code == sf::Keyboard::Num3) opc[index] = 3;

            // verifica se o botão de voltar foi clicado
            if (eventoMensagem2.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
                sf::FloatRect buttonBounds = voltarButton.getGlobalBounds();

                if (buttonBounds.contains(worldPos)) {
                    // se o clique do mouse estiver dentro dos limites do botão de voltar
                    // faz a transição de volta para a janela showDay0
                    showDay0(window, font);
                }
            }
        }

        //limpa a janela

        window.clear();


        // desenha o botão de voltar
        window.draw(voltarButton);

        // fundo ////////

        sf::Texture chatBG;
        chatBG.loadFromFile("Assets/chat agent b4.png");
        sf::Sprite chatBG_sprite(chatBG);
        window.draw(chatBG_sprite);


        /////////////////////////////////////// textos /////////////////////////////////

        // continuacao mensagem 2

        exibirNome(window, 2, font, 580, 80);
        showTextChat(window, "I wouldnt say scared is the word for it. Im just \nnot used to being all by myself on deadly pla-\nnets.", font, 20, 630, 80);

        // resposta player
        exibirNome(window, 1, font, 580, 160);
        showTextChat(window, "You are not all by yourself! Im here to help \nyou.", font, 20, 650, 160);

        //b4
        exibirNome(window, 2, font, 580, 220);
        showTextChat(window, "You are not the one wearing gas masks.", font, 20, 630, 220);

        showTextChat(window, "[Silence]", font, 20, 630, 250);

        // atualiza o conteúdo na janela

        window.display();
    }

}



void showReportDay0(sf::RenderWindow& window, const sf::Font& font) {
    sf::Event evento;


    // botão de avançar
    sf::Texture botaoDireita;
    if (!botaoDireita.loadFromFile("Assets/seta sprite dir.png"))
    {
        std::cout << "Erro seta";
        system("pause");
    }
    sf::Sprite nextButton(botaoDireita);
    nextButton.setScale(1.25, 1.25);
    nextButton.setPosition(1080, 550);

    // moldura do texto
    sf::RectangleShape moldura(sf::Vector2f(940, 530));

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
                sf::FloatRect buttonBounds = nextButton.getGlobalBounds();

                // som de clique
                sf::SoundBuffer mouse_click;
                mouse_click.loadFromFile("Assets/mouse click.wav");
                sf::Sound somMouse(mouse_click);
                somMouse.play();

                if (buttonBounds.contains(worldPos)) {
                    // se o clique do mouse estiver dentro dos limites do botão de voltar,
                    // faz a transição de volta para a janela showDay0
                    showDay0(window, font);
                }
            }
        }

        // limpa a janela
        window.clear();

        // desenha o botão de voltar
        moldura.setPosition(200, 60);
        moldura.setOutlineThickness(2);
        moldura.setFillColor(sf::Color::Black);
        moldura.setOutlineColor(sf::Color::Green);
        window.draw(moldura);
        window.draw(nextButton);


        // exibe o texto // OBS max de mais ou menos 70 chars por quebra de linha
        showText(window, "GALAXY B612 - 15/13/56XX", font, 18, 225, 80);
        showText(window, "[Company]", font, 18, 225, 100);
        showText(window, "SUBJECT: NEW SURVEYING MISSION", font, 18, 225, 120);
        showText(window, "Hello, Agent!", font, 18, 225, 170);


        showText(window, "We have recently discovered a small planet in an uncharted area using a\nnew radar system. For now, we call it Relinquo. As this discovery is of\ngreat significance, we must gather information about the planet as soon", font, 18, 225, 194);
        showText(window, "as possible. Unfortunately, there is only one field agent, Agent B4 as he", font, 18, 225, 266);
        showText(window, "records and reports all information about the planet's flora, fauna, climate,", font, 18, 225, 290);
        showText(window, "and geology; as well as sending the [Company] a daily report on the team\'s", font, 18, 225, 314);
        showText(window, "discoveries. Agent B4 will not be able to communicate with any other agent", font, 18, 225, 338);
        showText(window, "while he is on the planet. You will be held accountable for any loss of", font, 18, 225, 362);
        showText(window, "or labor that may occur due to negligence. You can find all the useful", font, 18, 225, 386);
        showText(window, "information that you will need in the PROTOCOL document and all the general", font, 18, 225, 410);
        showText(window, "recommendations for missions will be send daily to you in the MAIL application", font, 18, 225, 434);
        showText(window, "Agent B4 will contact you soon.", font, 18, 225, 458);
        showText(window, "\tBest wishes,", font, 18, 225, 482);
        showText(window, "\t\t[Company]: Unlocking the cosmos and enriching the future.", font, 18, 225, 506);


        // atualiza o conteúdo na janela
        window.display();
    }
}

void showDay0(sf::RenderWindow& window, const sf::Font& font) {
    // carrega a imagem de fundo
    sf::Texture fundoTexture;
    if (!fundoTexture.loadFromFile("Assets/Desktop.png")) {
        //exibe uma mensagem de erro caso o carregamento dê errado
    }

    // cria um sprite com a textura carregada
    sf::Sprite fundoSprite(fundoTexture);


    // cria três botão invisíveis
    sf::RectangleShape invisibleButton1(sf::Vector2f(96, 120)); // ajusta o tamanho do botão
    invisibleButton1.setPosition(68, 84); // posição do botão invisível na janela
    invisibleButton1.setFillColor(sf::Color::Transparent); // cor transparente

    sf::RectangleShape invisibleButton2(sf::Vector2f(96, 120));
    invisibleButton2.setPosition(68, 300);
    invisibleButton2.setFillColor(sf::Color::Transparent);

    sf::RectangleShape invisibleButton3(sf::Vector2f(96, 72));
    invisibleButton3.setPosition(68, 528);
    invisibleButton3.setFillColor(sf::Color::Transparent);

    // limpa a nova janela
    window.clear();

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

                // faz um som especial

                sf::SoundBuffer mouse_click;
                mouse_click.loadFromFile("Assets/mouse click.wav");
                sf::Sound somMouse(mouse_click);
                somMouse.play();

                // pega os limites do botao
                sf::FloatRect buttonBounds1 = invisibleButton1.getGlobalBounds();
                if (buttonBounds1.contains(worldPos)) {
                    // clica no primeiro botão invisível e faz a transição para outra janela
                    showReportDay0(window, font);
                }

                sf::FloatRect buttonBounds2 = invisibleButton2.getGlobalBounds();
                if (buttonBounds2.contains(worldPos)) {
                    // clica no segundo botão invisível e faz a transição para outra janela
                    if (consulta_fila(catalogue)) emptyPage(window, font);
                    else if (catalogue->inicio->num == 1) mushroomManPage(window, font);
                    else showDay0(window, font);
                }

                sf::FloatRect buttonBounds3 = invisibleButton3.getGlobalBounds();
                if (buttonBounds3.contains(worldPos)) {
                    // clica no terceiro botão invisível e faz a transição para outra janela
                    showChatDay0(window, font);
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

void emptyPage(sf::RenderWindow& window, const sf::Font& font)
{
    sf::Event evento;

    // moldura
    sf::RectangleShape moldura(sf::Vector2f(940, 560));

    // botão de voltar
    sf::Texture botaoEsquerda;
    if (!botaoEsquerda.loadFromFile("Assets/sprite seta esq.png"))
    {
        std::cout << "Erro seta";
        system("pause");
    }
    sf::Sprite backButton(botaoEsquerda);
    backButton.setScale(0.75, 0.75);
    backButton.setPosition(230, 60);

    // loop principal
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                //fecha a janela atual
                window.close();
            }
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

                // faz um som especial

                sf::SoundBuffer mouse_click;
                mouse_click.loadFromFile("Assets/mouse click.wav");
                sf::Sound somMouse(mouse_click);
                somMouse.play();

                sf::FloatRect buttonBounds = backButton.getGlobalBounds();
                if (buttonBounds.contains(worldPos)) {
                    showDay0(window, font);
                }
            }
        }

        // limpa a janela
        window.clear();


        // config moldura
        moldura.setPosition(200, 60);
        moldura.setOutlineThickness(2);
        moldura.setFillColor(sf::Color::Black);
        moldura.setOutlineColor(sf::Color::Green);
        window.draw(moldura);

        // linha
        sf::RectangleShape linha(sf::Vector2f(940, 1));
        linha.setPosition(200, 110);
        linha.setFillColor(sf::Color::Green);
        window.draw(linha);

        //texto
        showText(window, "CATALOGUE", font, 30, 550, 70);
        showText(window, ":(", font, 40, 280, 180);
        showText(window, "It seems like you don't have any scans yet.", font, 24, 280, 250);

        // botao
        window.draw(backButton);

        window.display();
    }
}

void finalPage(sf::RenderWindow& window, const sf::Font& font)
{
    sf::Event evento;

    // moldura
    sf::RectangleShape moldura(sf::Vector2f(940, 560));

    // botão de voltar
    sf::Texture botaoEsquerda;
    if (!botaoEsquerda.loadFromFile("Assets/sprite seta esq.png"))
    {
        std::cout << "Erro seta";
        system("pause");
    }
    sf::Sprite backButton(botaoEsquerda);
    backButton.setScale(0.75, 0.75);
    backButton.setPosition(230, 60);

    // loop principal
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                //fecha a janela atual
                window.close();
            }
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

                // faz um som especial

                sf::SoundBuffer mouse_click;
                mouse_click.loadFromFile("Assets/mouse click.wav");
                sf::Sound somMouse(mouse_click);
                somMouse.play();

                sf::FloatRect buttonBounds = backButton.getGlobalBounds();
                if (buttonBounds.contains(worldPos)) {
                    // if alguma coisa da lista, funcao diferente
                    mushroomManPage(window, font); //alterar pra ultima pagina do catalogo
                }
            }
        }

        // limpa a janela
        window.clear();


        // config moldura
        moldura.setPosition(200, 60);
        moldura.setOutlineThickness(2);
        moldura.setFillColor(sf::Color::Black);
        moldura.setOutlineColor(sf::Color::Green);
        window.draw(moldura);

        // linha
        sf::RectangleShape linha(sf::Vector2f(940, 1));
        linha.setPosition(200, 110);
        linha.setFillColor(sf::Color::Green);
        window.draw(linha);

        // botao
        window.draw(backButton);

        //texto
        showText(window, "CATALOGUE", font, 30, 550, 70);
        showTextChat(window, "You have reached the end of the catalogue.", font, 20, 370, 130);
        window.display();
    }
}

// CODIGO 1
void mushroomManPage(sf::RenderWindow& window, const sf::Font& font)
{
    sf::Event evento;

    // moldura
    sf::RectangleShape moldura(sf::Vector2f(940, 560));

    // botão de voltar //
    sf::Texture botaoEsquerda;
    if (!botaoEsquerda.loadFromFile("Assets/sprite seta esq.png"))
    {
        std::cout << "Erro seta";
        system("pause");
    }
    sf::Sprite backButton(botaoEsquerda);
    backButton.setScale(0.75, 0.75);
    backButton.setPosition(230, 60);

    // botão de avançar //
    sf::Texture botaoDireita;
    if (!botaoDireita.loadFromFile("Assets/seta sprite dir.png"))
    {
        std::cout << "Erro seta";
        system("pause");
    }
    sf::Sprite nextButton(botaoDireita);
    nextButton.setScale(0.75, 0.75);
    nextButton.setPosition(1070, 61);

    // loop principal
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                //fecha a janela atual
                window.close();
            }
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

                // faz um som especial

                sf::SoundBuffer mouse_click;
                mouse_click.loadFromFile("Assets/mouse click.wav");
                sf::Sound somMouse(mouse_click);
                somMouse.play();

                sf::FloatRect buttonBoundsBack = backButton.getGlobalBounds();
                if (buttonBoundsBack.contains(worldPos)) {
                    showDay0(window, font); //volta para a tela inicial
                }
                sf::FloatRect buttonBoundsNext = nextButton.getGlobalBounds();
                if (buttonBoundsNext.contains(worldPos)) {
                    finalPage(window, font); //alterar pra ultima pagina do catalogo
                }
            }
        }

        // limpa a janela
        window.clear();


        // config moldura
        moldura.setPosition(200, 60);
        moldura.setOutlineThickness(2);
        moldura.setFillColor(sf::Color::Black);
        moldura.setOutlineColor(sf::Color::Green);
        window.draw(moldura);


        // monster image
        sf::Texture monster;
        if (!monster.loadFromFile("Assets/mushroom man.png")) {
            std::cout << "error mushroom man";
            system("pause");
        }
        sf::Sprite monsterSprite(monster);
        monsterSprite.setPosition(200, 120);
        window.draw(monsterSprite);

        // linha
        sf::RectangleShape linha(sf::Vector2f(940, 1));
        linha.setPosition(200, 110);
        linha.setFillColor(sf::Color::Green);
        window.draw(linha);

        //texto
        showText(window, "MUSHROOM MAN", font, 30, 540, 70);
        showTextChat(window, "A bipedal creature that looks like a giant walking", font, 18, 530, 160);
        showTextChat(window, "Amanita phalloides, but with humanoid resemblances.", font, 18, 530, 180);
        showTextChat(window, "It's skin - if it can even be called that - is white", font, 18, 530, 200);
        showTextChat(window, "but covered with small orange and yellow mushrooms", font, 18, 530, 220);
        showTextChat(window, "It usually pretends to be a mushroom and ignores", font, 18, 530, 240);
        showTextChat(window, "everything until it gets hungry. Then, it's skin", font, 18, 530, 260);
        showTextChat(window, "starts leaking toxins into the air to to make nearby", font, 18, 530, 280);
        showTextChat(window, "possible victims slow and then embraces them to ", font, 18, 530, 300);
        showTextChat(window, "death. This entity can also touchthe ground with its", font, 18, 530, 320);
        showTextChat(window, "hands to create what looks like thick ropes of ", font, 18, 530, 340);
        showTextChat(window, "mycelium and uses them to take someone down as", font, 18, 530, 360);
        showTextChat(window, "they can travel underground with surprising speed.", font, 18, 530, 380);
        showTextChat(window, "If you encounter something like this, retreat", font, 18, 530, 440);
        showTextChat(window, "IMMEDIATELY and don't try to fight. Even if you can", font, 18, 530, 460);
        showTextChat(window, "kill it, you will pass out and be exposed to other", font, 18, 530, 480);
        showTextChat(window, "dangers for a long time.", font, 18, 530, 500);

        window.draw(backButton);
        window.draw(nextButton);

        window.display();
    }
}





// Indice 2
void giantScorpionPage(sf::RenderWindow& window, const sf::Font& font)
{
    sf::Event evento;

    // moldura
    sf::RectangleShape moldura(sf::Vector2f(940, 560));

    // botão de voltar //
    sf::Texture botaoEsquerda;
    if (!botaoEsquerda.loadFromFile("Assets/sprite seta esq.png"))
    {
        std::cout << "Erro seta";
        system("pause");
    }
    sf::Sprite backButton(botaoEsquerda);
    backButton.setScale(0.75, 0.75);
    backButton.setPosition(230, 60);

    // botão de avançar //
    sf::Texture botaoDireita;
    if (!botaoDireita.loadFromFile("Assets/seta sprite dir.png"))
    {
        std::cout << "Erro seta";
        system("pause");
    }
    sf::Sprite nextButton(botaoDireita);
    nextButton.setScale(0.75, 0.75);
    nextButton.setPosition(1070, 61);
    consulta_fila(catalogue);
    // loop principal
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                //fecha a janela atual
                esvazia_fila(catalogue);
                mata_jogador(you);
                window.close();
            }
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

                // faz um som especial

                sf::SoundBuffer mouse_click;
                mouse_click.loadFromFile("Assets/mouse click.wav");
                sf::Sound somMouse(mouse_click);
                somMouse.play();

                sf::FloatRect buttonBoundsBack = backButton.getGlobalBounds();

                if (buttonBoundsBack.contains(worldPos)) {
                    if (catalogue->inicio->num == 2) showDay0(window, font);
                }

                sf::FloatRect buttonBoundsNext = nextButton.getGlobalBounds();
                if (buttonBoundsNext.contains(worldPos)) {
                    if (catalogue->fim->num == 2) finalPage(window, font);        
                }             
            }
        }

        // limpa a janela
        window.clear();


        // config moldura
        moldura.setPosition(200, 60);
        moldura.setOutlineThickness(2);
        moldura.setFillColor(sf::Color::Black);
        moldura.setOutlineColor(sf::Color::Green);
        window.draw(moldura);


        // monster image
        sf::Texture monster;
        if (!monster.loadFromFile("Assets/giant scorpion.png")) {
            std::cout << "error giant scorpion";
            system("pause");
        }
        sf::Sprite monsterSprite(monster);
        monsterSprite.setPosition(200, 120);
        window.draw(monsterSprite);

        // linha
        sf::RectangleShape linha(sf::Vector2f(940, 1));
        linha.setPosition(200, 110);
        linha.setFillColor(sf::Color::Green);
        window.draw(linha);

        //texto
        showText(window, "GIANT SCORPION", font, 30, 540, 70);
        showTextChat(window, "As its name suggests, this creature is just", font, 18, 580, 160);
        showTextChat(window, "like an enormous scorpion. Surprisingly, it's", font, 18, 580, 180);
        showTextChat(window, "poison isn't very strong and rarely is enough", font, 18, 580, 200);
        showTextChat(window, "to kill a person, even though if you don't", font, 18, 580, 220);
        showTextChat(window, "treat the sting it may result in having to", font, 18, 580, 240);
        showTextChat(window, "amputate a member. The Scorpion's claws, on", font, 18, 580, 260);
        showTextChat(window, "the other hand, can easily cut through", font, 18, 580, 280);
        showTextChat(window, "protective clothing and human flesh altogether.", font, 18, 580, 300);
        showTextChat(window, "It may be worth it to try and kill it but only", font, 18, 580, 360);
        showTextChat(window, "if you're sure you have a good weapon.", font, 18, 580, 380);
        showTextChat(window, "Running from it may be a hard task because it", font, 18, 580, 400);
        showTextChat(window, "can move fast and climb on walls, trees, etc.", font, 18, 580, 420);
        showTextChat(window, "If you can't kill it and don't have an escape", font, 18, 580, 440);
        showTextChat(window, "route, pretend you're dead until it goes away.", font, 18, 580, 460);
        showTextChat(window, "Humans are not part of their diet, so they only", font, 18, 580, 480);
        showTextChat(window, "attack people when they feel in danger.", font, 18, 580, 500);

        window.draw(backButton);
        window.draw(nextButton);

        window.display();
    }
}

// Indice 3
void parasiteIvyPage(sf::RenderWindow& window, const sf::Font& font)
{
    sf::Event evento;

    // moldura
    sf::RectangleShape moldura(sf::Vector2f(940, 560));

    // botão de voltar //
    sf::Texture botaoEsquerda;
    if (!botaoEsquerda.loadFromFile("Assets/sprite seta esq.png"))
    {
        std::cout << "Erro seta";
        system("pause");
    }
    sf::Sprite backButton(botaoEsquerda);
    backButton.setScale(0.75, 0.75);
    backButton.setPosition(230, 60);

    // botão de avançar //
    sf::Texture botaoDireita;
    if (!botaoDireita.loadFromFile("Assets/seta sprite dir.png"))
    {
        std::cout << "Erro seta";
        system("pause");
    }
    sf::Sprite nextButton(botaoDireita);
    nextButton.setScale(0.75, 0.75);
    nextButton.setPosition(1070, 61);

    // loop principal
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                //fecha a janela atual
                esvazia_fila(catalogue);
                mata_jogador(you);
                window.close();
            }
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

                // faz um som especial

                sf::SoundBuffer mouse_click;
                mouse_click.loadFromFile("Assets/mouse click.wav");
                sf::Sound somMouse(mouse_click);
                somMouse.play();

                sf::FloatRect buttonBoundsBack = backButton.getGlobalBounds();
         
                if (buttonBoundsBack.contains(worldPos)) {
                    if (catalogue->inicio->num == 3) showDay0(window, font); //volta para a tela inicial                                             
                }

                sf::FloatRect buttonBoundsNext = nextButton.getGlobalBounds();
                if (buttonBoundsNext.contains(worldPos)) {
                    if (catalogue->fim->num == 3) finalPage(window, font);
                }
            }
        }

        // limpa a janela
        window.clear();


        // config moldura
        moldura.setPosition(200, 60);
        moldura.setOutlineThickness(2);
        moldura.setFillColor(sf::Color::Black);
        moldura.setOutlineColor(sf::Color::Green);
        window.draw(moldura);


        // monster image
        sf::Texture monster;
        if (!monster.loadFromFile("Assets/parasite ivy.png")) {
            std::cout << "error parasite ivy";
            system("pause");
        }
        sf::Sprite plantSprite(monster);
        plantSprite.setPosition(200, 130);
        window.draw(plantSprite);

        // linha
        sf::RectangleShape linha(sf::Vector2f(940, 1));
        linha.setPosition(200, 110);
        linha.setFillColor(sf::Color::Green);
        window.draw(linha);

        //texto
        showText(window, "Parasite Ivy", font, 30, 540, 70);
        showTextChat(window, "A giant red flower that lets out a rotten", font, 18, 625, 200);
        showTextChat(window, "smell to attract small insects and kills them", font, 18, 625, 220);
        showTextChat(window, "with its spikes to get nourishing from them.", font, 18, 625, 240); //meio redundante
        showTextChat(window, "As a parasite, it will often tangle itself", font, 18, 625, 260);
        showTextChat(window, "around other plants and kill them if in", font, 18, 625, 280);
        showTextChat(window, "need of more food. Trying to cut it - even", font, 18, 625, 300);
        showTextChat(window, "if just a petal - will result in it liberating", font, 18, 625, 320);
        showTextChat(window, "a cloud of toxic gas. Apart from that, it", font, 18, 625, 340);
        showTextChat(window, "can't do any harm. Do not try to eat or", font, 18, 625, 360);
        showTextChat(window, "touch it, it may take unexpected actions.", font, 18, 625, 380);

        window.draw(backButton);
        window.draw(nextButton);

        window.display();
    }
}



