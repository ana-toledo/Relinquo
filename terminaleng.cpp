#include "terminaleng.hpp"


//////////////////////////////// FUNCOES PRINCIPAIS /////////////////////////////

Fila* catalogue = cria_fila(); // variavel global para o catalogo
Player* you = cria_jogador();
sf::Color light_green(68, 209, 100);





void showText(sf::RenderWindow& window, const std::string& mensagem, const sf::Font& font, unsigned int fontSize, float x, float y) {
    // criação do texto
    sf::Text texto(mensagem, font, fontSize);
    texto.setPosition(x, y);

    // configura a cor do texto para verde
    texto.setFillColor(light_green);

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
            if (evento.type == sf::Event::Closed) {
                esvazia_fila(catalogue);
                mata_jogador(you);
                window.close();
            }
        }

        // limpa a janela
        window.clear();

        // desenha os elementos estáticos
        window.draw(spriteBG);
        // criação do texto
        sf::Text texto;
        texto.setString("Press ENTER to continue");
        texto.setPosition(440, 550);
        texto.setFont(font);
        texto.setCharacterSize(30);
        texto.setFillColor(sf::Color::Green);
        // desenha o texto "Press ENTER to continue" apenas se estiver visível
        if (textoVisible) {
            window.draw(texto);
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

////////////////////// DIA 1

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
                esvazia_fila(catalogue);
                mata_jogador(you);
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
                somMouse.setVolume(50.0);
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
        moldura.setOutlineColor(light_green);
        window.draw(moldura);
        window.draw(nextButton);


        // exibe o texto // OBS max de mais ou menos 70 chars por quebra de linha
        showText(window, "GALAXY B612 - 15/13/56XX", font, 18, 225, 80);
        showText(window, "[Company]", font, 18, 225, 100);
        showText(window, "SUBJECT: NEW SURVEYING MISSION", font, 18, 225, 120);
        showText(window, "Hello, Agent!", font, 18, 225, 170);


        showText(window, "We have recently discovered a small planet in an uncharted area using a\nnew radar system. For now, we call it Relinquo. As this discovery is of\ngreat significance, we must gather information about the planet as soon", font, 18, 225, 194);
        showText(window, "as possible. Unfortunately, there is only one field agent, Agent B4, who will", font, 18, 225, 266);
        showText(window, "record and report all information about the planet's flora, fauna, climate", font, 18, 225, 290);
        showText(window, "etc. Agent B4 will not be able to communicate with any other agent while he", font, 18, 225, 314);
        showText(window, "is on the planet. You will be held accountable for any loss of data or labor", font, 18, 225, 338);
        showText(window, "that may occur due to negligence. You can find all the useful information", font, 18, 225, 362);
        showText(window, "that you will need about the planet in the INFO document and anything", font, 18, 225, 386);
        showText(window, "relevant detected by your colleague in field can be found in CATALOGUE.", font, 18, 225, 410);
        showText(window, "Agent B4 will contact you soon.", font, 18, 225, 434);
        showText(window, "", font, 18, 225, 458);
        showText(window, "\tBest wishes,", font, 18, 225, 482);
        showText(window, "\t\t[Company]: Unlocking the cosmos and enriching the future.", font, 18, 225, 506);


        // atualiza o conteúdo na janela
        window.display();
    }
}
void showDay0(sf::RenderWindow& window, const sf::Font& font) {
    // carrega a imagem de fundo
    sf::Texture fundoTexture;
    if (!fundoTexture.loadFromFile("Assets/Desktop1.png")) {
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

    int count_secs = 0;
    sf::SoundBuffer notif_buf;
    notif_buf.loadFromFile("Assets/simple notification.wav");
    sf::Sound notif;
    notif.setBuffer(notif_buf);
    
   

    // limpa a nova janela
    window.clear();
    
    // aguarda até o fechamento da nova janela
    sf::Event evento;
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                // fecha a janela atual
                mata_jogador(you);
                esvazia_fila(catalogue);
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
                somMouse.setVolume(50.0);
                somMouse.play();

                // pega os limites do botao
                sf::FloatRect buttonBounds1 = invisibleButton1.getGlobalBounds();
                if (buttonBounds1.contains(worldPos)) {
                    // clica no primeiro botão invisível e faz a transição para outra janela
                    showInfo(window, font);
                }

                sf::FloatRect buttonBounds2 = invisibleButton2.getGlobalBounds();
                if (buttonBounds2.contains(worldPos)) {
                    // Clica no segundo botão invisível e faz a transição para outra janela

                    if (consulta_fila(catalogue)) {
                        emptyPage(window, font);
                    }
                    else if (catalogue->inicio->num == 1) {
                        parasiteIvyPage(window, font);
                    }
                    else {
                        showDay0(window, font);
                    }
                }

                sf::FloatRect buttonBounds3 = invisibleButton3.getGlobalBounds();
                if (buttonBounds3.contains(worldPos)) {
                    // clica no terceiro botão invisível e faz a transição para outra janela
                    showMailDay1(window, font);
                }
            }
        }

        // desenha o fundo primeiro
        window.draw(fundoSprite);
        // desenha os botoes invisíveis 
        window.draw(invisibleButton1);
        window.draw(invisibleButton2);
        window.draw(invisibleButton3);


        count_secs++;
        if (you->read_info && count_secs == 70) {
            notif.play(); // barulho de notificação
        }
        
        // exiba o conteúdo na nova janela
        window.display();
        if (you->read_info == true) {
            update_read_info(you);
        }
    }
}
void showInfo(sf::RenderWindow& window, const sf::Font& font) {
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
                somMouse.setVolume(50.0);
                somMouse.play();

                sf::FloatRect buttonBounds = backButton.getGlobalBounds();
                if (buttonBounds.contains(worldPos)) {
                    // if alguma coisa da lista, funcao diferente
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
        moldura.setOutlineColor(light_green);
        window.draw(moldura);

        // linha
        sf::RectangleShape linha(sf::Vector2f(940, 1));
        linha.setPosition(200, 110);
        linha.setFillColor(light_green);
        window.draw(linha);

        // botao
        window.draw(backButton);

        //update
        update_read_info(you);
        //texto
        showText(window, "INFORMATIONS", font, 30, 535, 70);
        showText(window, "RELINQUO PLANET", font, 20, 240, 150);
        showText(window, "Relinquo has absurd levels of multiple acids in it's atmosphere. The", font, 20, 240, 210);
        showText(window, "appropriate protective gear must be worn whenever Agent B4 leaves", font, 20, 240, 240);
        showText(window, "his spaceship. This should include gloves, chemical-resistant", font, 20, 240, 270);
        showText(window, "overalls, and, most importantly, a gas mask.", font, 20, 240, 300);
        showText(window, "Even with all this on, we don't recommend exploring during climate", font, 20, 240, 360);
        showText(window, "events. There may be more dangerous aspects to the planets natural", font, 20, 240, 390);
        showText(window, "ambiance that havent been detected by the radars, so you must be", font, 20, 240, 420);
        showText(window, "prepared for anything.", font, 20, 240, 450);

        window.display();
    }
}
// telas de notificacoes emails
void showMailDay1(sf::RenderWindow& window, const sf::Font& font) {
    sf::Texture blank_mail;

    // Check if the player has seen the window

    sf::RectangleShape invisibleButton(sf::Vector2f(20, 20)); // ajusta o tamanho do botão
    invisibleButton.setPosition(1200, 50); // posição do botão invisível na janela
    invisibleButton.setFillColor(sf::Color::Transparent); // cor transparente

    // botão de clicar mensagem
    sf::RectangleShape clickMsg1(sf::Vector2f(1140, 30));
    clickMsg1.setPosition(50, 150);
    clickMsg1.setFillColor(sf::Color::Transparent);
    sf::RectangleShape clickMsg2(sf::Vector2f(1140, 30));
    clickMsg2.setPosition(50, 180);
    clickMsg2.setFillColor(sf::Color::Transparent);
    sf::RectangleShape clickMsg3(sf::Vector2f(1140, 30));
    clickMsg3.setPosition(50, 210);
    clickMsg3.setFillColor(sf::Color::Transparent);

    sf::Sprite BG;


    // carregamento das imagens
    if (you->read_info == false) {
        blank_mail.loadFromFile("Assets/mail1 blank full.png");
    }
    else {
        // se a primeira msg n for respondida
        if (you->reply_mail[0][0] == 0) {
            blank_mail.loadFromFile("Assets/mail1 full.png");
        }
        // se a primeira foi respondida, mas a segunda n
        else if (you->reply_mail[0][0] != 0 && you->reply_mail[0][1] == 0) {
            if (you->reply_mail[0][0] == 1 && !you->has_replied[0][1]) { // respondeu 1 com 1
                blank_mail.loadFromFile("Assets/mail 1.1.png");
            }
            else if (you->reply_mail[0][0] == 2 && !you->has_replied[0][1]) { // respondeu 1 com 2
                blank_mail.loadFromFile("Assets/mail 1.2.png");
            }
        }
        else if (you->has_replied[0][0] && you->has_replied[0][1] && !you->has_replied[0][2]) {
            if (you->reply_mail[0][0] == 1) {
                blank_mail.loadFromFile("Assets/mail 1.1co.png");
            }
            else if (you->reply_mail[0][0] == 2) {
                blank_mail.loadFromFile("Assets/mail 1.2co.png");
            }
        }

    }
    BG.setTexture(blank_mail);


    sf::Event evento;
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                esvazia_fila(catalogue);
                mata_jogador(you);
                window.close();
            }
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

                sf::FloatRect buttonBounds = invisibleButton.getGlobalBounds();
                if (buttonBounds.contains(worldPos)) {
                    showDay0(window, font);
                }

                // se a primeira msg n for respondida
                if (you->read_info && you->reply_mail[0][0] == 0) {
                    // botao para msg
                    if (clickMsg1.getGlobalBounds().contains(worldPos)) mailDay1Text(window, font, 1); // a primeira é base
                }
                // se a primeira foi respondida, mas a segunda n
                else if (you->reply_mail[0][0] != 0 && you->reply_mail[0][1] == 0) {
                    if (you->reply_mail[0][0] == 1) { // respondeu 1 com 1
                        if (clickMsg1.getGlobalBounds().contains(worldPos)) mailDay1Text(window, font, 1);
                        if (clickMsg2.getGlobalBounds().contains(worldPos)) mailDay1Text(window, font, 1.1);
                    }
                    else if (you->reply_mail[0][0] == 2) { // respondeu 1 com 2
                        if (clickMsg1.getGlobalBounds().contains(worldPos)) mailDay1Text(window, font, 1);
                        if (clickMsg2.getGlobalBounds().contains(worldPos)) mailDay1Text(window, font, 1.2);
                    }
                }
                // respondeu 1 e 2, mas n o 3
                else if (you->reply_mail[0][0] != 0 && you->reply_mail[0][1] != 0 && you->reply_mail[0][2] == 0) {
                    if (you->reply_mail[0][0] == 1) {
                        if (clickMsg1.getGlobalBounds().contains(worldPos)) mailDay1Text(window, font, 1);
                        if (clickMsg2.getGlobalBounds().contains(worldPos)) mailDay1Text(window, font, 1.1);
                        if (clickMsg3.getGlobalBounds().contains(worldPos)) mailDay1Text(window, font, 1.9);
                    }
                    else if (you->reply_mail[0][0] == 2) {
                        if (clickMsg1.getGlobalBounds().contains(worldPos)) mailDay1Text(window, font, 1);
                        if (clickMsg2.getGlobalBounds().contains(worldPos)) mailDay1Text(window, font, 1.2);
                        if (clickMsg3.getGlobalBounds().contains(worldPos)) mailDay1Text(window, font, 1.9);
                    }
                }

            }
        }

        window.clear();
        // desenha a tela de mail

        window.draw(BG);

        // Show clickMsg button only if read_info is true
        if (you->read_info) {
            window.draw(clickMsg1);
        }
        if (you->reply_mail[0][0] != 0) { // primeira respondida aparece o 2
            window.draw(clickMsg2);
        }
        if (you->reply_mail[0][1] != 0) { // segunda respondida, aparece o 3
            window.draw(clickMsg3);
        }

        //update
        window.draw(invisibleButton);
        window.display();
    }

    // Update the player's state after closing the window

}

void mailDay1Text(sf::RenderWindow& window, const sf::Font& font, double msg) {
    sf::Texture text_mail;
    sf::Texture botaoReply;

    if (!botaoReply.loadFromFile("Assets/reply button.png"))
    {
        std::cout << "Erro seta";
        system("pause");
    }
    sf::Sprite reply(botaoReply);
    reply.setScale(1.25, 1.25);
    reply.setPosition(40, 655);


    if (msg == 1) {
        text_mail.loadFromFile("Assets/mail 1 text.png");
        insere_elemento(catalogue, 1);
    }
    else if (msg == 1.1) {
        text_mail.loadFromFile("Assets/mail 1.1 text.png");
        insere_elemento(catalogue, 2);
        //replied(you, 0, 1);
        //resp_jogador(you, 0, 1, -1); // nao possui escolha
    }
    else if (msg == 1.2) {
        text_mail.loadFromFile("Assets/mail 1.2 text.png");
        insere_elemento(catalogue, 2);
        //replied(you, 0, 1);
        //resp_jogador(you, 0, 1, -1); // nao possui escolha
    }
    else if (msg == 1.9) {
        text_mail.loadFromFile("Assets/mail 1 co text no cd.png");
    }

    sf::RectangleShape invisibleButton(sf::Vector2f(20, 20)); // ajusta o tamanho do botão
    invisibleButton.setPosition(1200, 50); // posição do botão invisível na janela
    invisibleButton.setFillColor(sf::Color::Transparent); // cor transparente

    sf::RectangleShape replyButton(sf::Vector2f(170, 50)); // ajusta o tamanho do botão
    replyButton.setPosition(40, 655); // posição do botão invisível na janela
    replyButton.setFillColor(sf::Color::Transparent);


    sf::Sprite mail;
    mail.setTexture(text_mail);

    sf::Event evento;
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                esvazia_fila(catalogue);
                mata_jogador(you);
                window.close();
            }
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

                sf::FloatRect buttonBounds = invisibleButton.getGlobalBounds();
                if (buttonBounds.contains(worldPos)) {
                    showDay0(window, font);
                }

                sf::FloatRect replyButtonBounds = replyButton.getGlobalBounds();
                if (replyButtonBounds.contains(worldPos)) {
                    // opções diferentes de resposta baseado na msg
                    replymailDay1Text(window, font, msg);
                }
            }
        }

        window.clear();
        window.draw(mail);

        // se o primeiro n tiver sido respondido
        if (!you->has_replied[0][0] && msg == 1) {
            window.draw(reply); // casos de resposta
        }
        // se o segundo n tiver sido respondido
        else if (!you->has_replied[0][1] && msg == 1.1) window.draw(reply);
        else if (!you->has_replied[0][1] && msg == 1.2) window.draw(reply);
        // se o ultimo
        else if (!you->has_replied[0][2] && msg == 1.9) window.draw(reply);

        window.draw(invisibleButton);

        // se o primeiro n tiver sido respondido
        if (!you->has_replied[0][0] && msg == 1) {
            window.draw(replyButton); // casos de resposta
        }
        // se o segundo n tiver sido respondido
        else if (!you->has_replied[0][1] && msg == 1.1) window.draw(replyButton);
        else if (!you->has_replied[0][1] && msg == 1.2) window.draw(replyButton);
        // se o ultimo
        else if (!you->has_replied[0][2] && msg == 1.9) window.draw(replyButton);
        window.display();
    }

}
void replymailDay1Text(sf::RenderWindow& window, const sf::Font& font, double msg) {
    sf::Texture text_mail;

    sf::RectangleShape invisibleButton(sf::Vector2f(20, 20)); // ajusta o tamanho do botão
    invisibleButton.setPosition(1200, 50); // posição do botão invisível na janela
    invisibleButton.setFillColor(sf::Color::Transparent); // cor transparente

    if (msg == 1 || msg == 1.1 || msg == 1.2) text_mail.loadFromFile("Assets/mail reply b4.png");
    else if (msg == 1.9) text_mail.loadFromFile("Assets/mail reply company.png");

    sf::Sprite reply;
    reply.setTexture(text_mail);

    int number = 0; // numero pressionado 

    sf::Event evento;
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                esvazia_fila(catalogue);
                mata_jogador(you);
                window.close();
            }
            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

                sf::FloatRect buttonBounds = invisibleButton.getGlobalBounds();
                if (buttonBounds.contains(worldPos)) {
                    if (you->has_replied[0][2]) {
                        // Se o jogador respondeu à mensagem, vá para a tela final
                        showFinalScreen(window);
                    }
                    else {
                        // Se o jogador não respondeu, vá para o showDay0
                        showDay0(window, font);
                    }
                }

            }
            if (evento.type == sf::Event::KeyPressed) {
                if (evento.key.code == sf::Keyboard::Num1) {
                    // Tecla 1 pressionada 
                    number = 1;
                }
                else if (evento.key.code == sf::Keyboard::Num2) {
                    // tecla 2
                    number = 2;
                }
                else if (evento.key.code == sf::Keyboard::Num3) number = 3;
                else if (evento.key.code == sf::Keyboard::Num4) number = 4;
            }
        }

        window.clear();
        window.draw(reply);

        window.draw(invisibleButton);

        if (msg == 1) {
            showText(window, "Type the number to select your answer:\n\n\n1) Enter the cave\n2) Don't enter the cave", font, 20, 70, 200);
            if (number == 1 && !you->has_replied[0][0]) {
                replied(you, 0, 0);
                resp_jogador(you, 0, 0, 1); // salva que respondeu 
                showTextChat(window, "Your reply has been sent", font, 16, 520, 600);
            }
            else if (number == 2 && !you->has_replied[0][0]) {
                replied(you, 0, 0);
                resp_jogador(you, 0, 0, 2);
                showTextChat(window, "Your reply has been sent", font, 16, 520, 600);
            }
            if (you->has_replied[0][0]) showTextChat(window, "Your reply has been sent", font, 16, 520, 600);
        }

        else if (msg == 1.1) {
            showText(window, "1) Fight with the creature\n\n2) Run away immediately", font, 20, 70, 200);
            if (number == 1 && !you->has_replied[0][1]) {
                final1(window, font);
            }
            else if (number == 2 && !you->has_replied[0][1]) {
                replied(you, 0, 1);
                resp_jogador(you, 0, 1, 2);
                showTextChat(window, "Your reply has been sent", font, 16, 520, 600);
            }
            if (you->has_replied[0][1]) showTextChat(window, "Your reply has been sent", font, 16, 520, 600);
        }

        else if (msg == 1.2) {
            showText(window, "1) Fight with the creature\n\n2) Run away immediately", font, 20, 70, 200);
            if (number == 1 && !you->has_replied[0][1]) {
                final1(window, font);
            }
            else if (number == 2 && !you->has_replied[0][1]) {
                replied(you, 0, 1);
                resp_jogador(you, 0, 1, 2);
                showTextChat(window, "Your reply has been sent", font, 16, 520, 600);
            }
            if (you->has_replied[0][1]) showTextChat(window, "Your reply has been sent", font, 16, 520, 600);
        }

        else if (msg == 1.9) {
            showText(window, "Type the index of the item you'd like to purchase.", font, 20, 70, 200);
            showText(window, "You have a total of a 100$ to spend, choose wisely.", font, 20, 70, 230);
            showText(window, "1) Gas mask", font, 20, 80, 280);
            showText(window, "2) Laser gun", font, 20, 80, 310);
            showText(window, "3) Medkit", font, 20, 80, 340);
            showText(window, "4) Grappling hook", font, 20, 80, 370);
            replied(you, 0, 2);
            if (number == 1 && !you->has_replied[0][2]) {
                resp_jogador(you, 0, 2, 1);
                sf::sleep(sf::milliseconds(200));
                replied(you, 0, 2);
                bought_mask(you);
            }
            if (number == 2 && !you->has_replied[0][2]) {
                resp_jogador(you, 0, 2, 2);
                sf::sleep(sf::milliseconds(200));
                replied(you, 0, 2);
                bought_laser(you);
            }
            if (number == 3 && !you->has_replied[0][2]) {
                resp_jogador(you, 0, 2, 3);
                sf::sleep(sf::milliseconds(200));
                replied(you, 0, 2);
                bought_medkit(you);
            }
            if (number == 4 && !you->has_replied[0][2]) {
                resp_jogador(you, 0, 2, 4);
                sf::sleep(sf::milliseconds(200));
                replied(you, 0, 2);
                bought_hook(you);
            }
            if (you->has_replied[0][2] && number == 1) {
                showTextChat(window, "You bought a gas mask", font, 16, 520, 600);


            }
            else if (you->has_replied[0][2] && number == 2) showTextChat(window, "You bought a laser gun", font, 16, 520, 600);
            else if (you->has_replied[0][2] && number == 3) showTextChat(window, "You bought a medkit", font, 16, 520, 600);
            else if (you->has_replied[0][2] && number == 4) showTextChat(window, "You bought a grappling hook", font, 16, 520, 600);

        }

        window.display();
    }
}


void final1(sf::RenderWindow& window, const sf::Font& font) {
    sf::Texture background;
    sf::Sprite BG;

    background.loadFromFile("Assets/death by mushman.png");
    BG.setTexture(background);

    //music_on = false;
    sf::SoundBuffer deathbuffer;
    deathbuffer.loadFromFile("Assets/death mushroom.wav");
    sf::Sound som;
    som.setBuffer(deathbuffer);
    som.play();

    int count_secs = 0;

    sf::Event evento;
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                mata_jogador(you);
                esvazia_fila(catalogue);
                window.close();
            }

        }

        count_secs++;
        if(count_secs < 40)
            window.clear(sf::Color::Black);
       
       
        if (count_secs == 40) {
            window.draw(BG);  
        }
        window.display();
    }
}

void showFinalScreen(sf::RenderWindow& window) {

    sf::Texture finalTexture;
    if (!finalTexture.loadFromFile("Assets/end scene.png")) {
        std::cerr << "Erro ao carregar a imagem final." << std::endl;
        return;
    }

    sf::Sprite finalSprite(finalTexture);

    sf::Music endmusic;
    endmusic.openFromFile("Assets/space music.ogg");
    endmusic.setVolume(80);
    endmusic.play();

    int count_secs = 0;

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                esvazia_fila(catalogue);
                mata_jogador(you);
                window.close();
            }
        }
        count_secs++;
        if(count_secs < 40)
            window.clear(sf::Color::Black);
        else 
            window.draw(finalSprite);
        window.display();
        
    }
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
                somMouse.setVolume(50.0);
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
        moldura.setOutlineColor(light_green);
        window.draw(moldura);

        // linha
        sf::RectangleShape linha(sf::Vector2f(940, 1));
        linha.setPosition(200, 110);
        linha.setFillColor(light_green);
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
                somMouse.setVolume(50.0);
                somMouse.play();

                sf::FloatRect buttonBounds = backButton.getGlobalBounds();
                if (buttonBounds.contains(worldPos)) {
                    // if alguma coisa da lista, funcao diferente
                    if (catalogue->fim->num == 1) parasiteIvyPage(window, font);
                    if (catalogue->fim->num == 2) mushroomManPage(window, font);
                    if (catalogue->fim->num == 3) giantScorpionPage(window, font);
                }
            }
        }

        // limpa a janela
        window.clear();


        // config moldura
        moldura.setPosition(200, 60);
        moldura.setOutlineThickness(2);
        moldura.setFillColor(sf::Color::Black);
        moldura.setOutlineColor(light_green);
        window.draw(moldura);

        // linha
        sf::RectangleShape linha(sf::Vector2f(940, 1));
        linha.setPosition(200, 110);
        linha.setFillColor(light_green);
        window.draw(linha);

        // botao
        window.draw(backButton);

        //texto
        showText(window, "CATALOGUE", font, 30, 550, 70);
        showTextChat(window, "You have reached the end of the catalogue.", font, 20, 400, 130);
        window.display();
    }
}

// CODIGO 1
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
                somMouse.setVolume(50.0);
                somMouse.play();

                sf::FloatRect buttonBoundsBack = backButton.getGlobalBounds();

                if (buttonBoundsBack.contains(worldPos)) {
                    showDay0(window, font); //volta para a tela inicial                                             
                }

                sf::FloatRect buttonBoundsNext = nextButton.getGlobalBounds();
                if (buttonBoundsNext.contains(worldPos)) {
                    if (catalogue->fim->num == 1) finalPage(window, font);
                    else mushroomManPage(window, font);
                }
            }
        }

        // limpa a janela
        window.clear();


        // config moldura
        moldura.setPosition(200, 60);
        moldura.setOutlineThickness(2);
        moldura.setFillColor(sf::Color::Black);
        moldura.setOutlineColor(light_green);
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
        linha.setFillColor(light_green);
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

// CODIGO 2
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
                somMouse.setVolume(50.0);
                somMouse.play();

                sf::FloatRect buttonBoundsBack = backButton.getGlobalBounds();
                if (buttonBoundsBack.contains(worldPos)) {
                    parasiteIvyPage(window, font); //volta para a a flor
                }
                sf::FloatRect buttonBoundsNext = nextButton.getGlobalBounds();
                if (buttonBoundsNext.contains(worldPos)) {
                    if (catalogue->fim->num == 2)
                        finalPage(window, font); //alterar pra ultima pagina do catalogo
                    else giantScorpionPage(window, font);
                }
            }
        }

        // limpa a janela
        window.clear();


        // config moldura
        moldura.setPosition(200, 60);
        moldura.setOutlineThickness(2);
        moldura.setFillColor(sf::Color::Black);
        moldura.setOutlineColor(light_green);
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
        linha.setFillColor(light_green);
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


// CODIGO 3
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
                somMouse.setVolume(50.0);
                somMouse.play();

                sf::FloatRect buttonBoundsBack = backButton.getGlobalBounds();

                if (buttonBoundsBack.contains(worldPos)) {
                    mushroomManPage(window, font);
                }

                sf::FloatRect buttonBoundsNext = nextButton.getGlobalBounds();
                if (buttonBoundsNext.contains(worldPos)) {
                    finalPage(window, font);
                }
            }
        }

        // limpa a janela
        window.clear();


        // config moldura
        moldura.setPosition(200, 60);
        moldura.setOutlineThickness(2);
        moldura.setFillColor(sf::Color::Black);
        moldura.setOutlineColor(light_green);
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
        linha.setFillColor(light_green);
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
