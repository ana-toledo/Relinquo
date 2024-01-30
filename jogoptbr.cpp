#include "jogoptbr.hpp"


//////////////////////////////// FUNCOES PRINCIPAIS /////////////////////////////

Fila* catalogo = cria_fila(); // variavel global para o catalogo
Player* voce = cria_jogador();


void exibirTexto(sf::RenderWindow& window, const std::string& mensagem, const sf::Font& font, unsigned int fontSize, float x, float y, sf::Color cor) {
    // criação do texto
    sf::Text texto(mensagem, font, fontSize);
    texto.setPosition(x, y);

    // configura a cor do texto para verde
    texto.setFillColor(cor);

    window.draw(texto);
}


/////////////////////////////// FUNCOES INICIO /////////////////////////////////
bool verificaTeclaEnter(sf::Event& evento, bool& enterPressed) {
    if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Enter) {
        enterPressed = true;
        return true;
    }
    return false;
}

void inicio(sf::RenderWindow& window, const sf::Font& font) {

    sf::Event evento;
    bool textoVisible = true;
    bool enterPressed = false;

    sf::Texture textureBG;
    sf::Sprite spriteBG;
    if (!textureBG.loadFromFile("Assets/mail1day1 text.png")) {
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
            if (verificaTeclaEnter(evento, enterPressed)) {
                // Se Enter for pressionado, mostra a nova janela com "DIA 1"
                somInicio.play();
                mostrarReportDia0(window, font);
            }
            if (evento.type == sf::Event::Closed) window.close();
        }

        // limpa a janela
        window.clear();

        // desenha os elementos estáticos
        window.draw(spriteBG);

        // desenha o texto "Press ENTER to continue" apenas se estiver visível
        if (textoVisible) {
            exibirTexto(window, "Pressione ENTER para continuar", font, 30, 360, 570, sf::Color::Green);
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

void mostrarReportDia0(sf::RenderWindow& window, const sf::Font& font) {
    sf::Event evento;


    // botão de avançar
    sf::Texture botaoDireita;
    if (!botaoDireita.loadFromFile("Assets/seta sprite dir.png"))
    {
        std::cout << "Erro seta";
        system("pause");
    }
    sf::Sprite nextButton(botaoDireita);
    nextButton.setScale(1.05, 1.05);
    nextButton.setPosition(1080, 580);

    // moldura do texto
    sf::RectangleShape moldura(sf::Vector2f(1040, 600));

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
                    // faz a transição de volta para a janela mostrarDia0
                    mostrarDia0(window, font);
                }
            }
        }

        // limpa a janela
        window.clear();

        // desenha o botão de voltar
        moldura.setPosition(130, 60);
        moldura.setOutlineThickness(2);
        moldura.setFillColor(sf::Color::Black);
        moldura.setOutlineColor(sf::Color::Green);
        window.draw(moldura);
        window.draw(nextButton);


        // exibe o texto // OBS max de mais ou menos 70 chars por quebra de linha
        exibirTexto(window, "GALAXIA B612 - 15/13/56XX", font, 20, 165, 80, sf::Color::Green);
        exibirTexto(window, "[Corporação]", font, 20, 165, 100, sf::Color::Green);
        exibirTexto(window, "Assunto: NOVA MISSÃO DE INSPEÇÃO", font, 20, 165, 120, sf::Color::Green);

        exibirTexto(window, "Olá, Agente!", font, 20, 165, 168, sf::Color::Green);
        exibirTexto(window, "Recentemente descobrimos um pequeno planeta em uma área não mapeada", font, 20, 165, 192, sf::Color::Green);
        exibirTexto(window, "usando um novo sistema de radar. Por enquanto, o chamamos de Relinquo.", font, 20, 165, 216, sf::Color::Green);
        exibirTexto(window, "Como essa descoberta é de grande significado, devemos reunir informações", font, 20, 165, 242, sf::Color::Green);
        exibirTexto(window, "sobre o planeta o mais rápido possível. Infelizmente, há apenas um agente", font, 20, 165, 266, sf::Color::Green);
        exibirTexto(window, "no campo, o Agente B4, que pode assumir esta missão. Portanto, você será", font, 20, 165, 290, sf::Color::Green);
        exibirTexto(window, "responsável por orientar o Agente B4 enquanto ele registra e reporta todas", font, 20, 165, 314, sf::Color::Green);
        exibirTexto(window, "as informações sobre a flora, fauna, clima e geologia do planeta; bem", font, 20, 165, 338, sf::Color::Green);
        exibirTexto(window, "como enviar um relatório diário para a [Corporação] sobre as descobertas", font, 20, 165, 362, sf::Color::Green);
        exibirTexto(window, "da equipe. O Agente B4 não poderá se comunicar com nenhum outro agente", font, 20, 165, 386, sf::Color::Green);
        exibirTexto(window, "enquanto estiver no planeta. Você será responsabilizado por qualquer perda", font, 20, 165, 410, sf::Color::Green);
        exibirTexto(window, "de dados ou trabalho que possa ocorrer devido a negligência. Você pode", font, 20, 165, 434, sf::Color::Green);
        exibirTexto(window, "encontrar todas as informações úteis que os radares detectaram e todas as", font, 20, 165, 458, sf::Color::Green);
        exibirTexto(window, "recomendações gerais para a missão no documento INSTRUÇÕES.", font, 20, 165, 482, sf::Color::Green);
        exibirTexto(window, "O Agente B4 entrará em contato com você em breve.", font, 18, 165, 506, sf::Color::Green);
        exibirTexto(window, "\tBoa sorte,", font, 20, 165, 554, sf::Color::Green);
        exibirTexto(window, "\t\t[Corporação]: Desbloqueando o cosmos e enriquecendo o futuro.", font, 20, 165, 574, sf::Color::Green);


        // atualiza o conteúdo na janela
        window.display();
    }
}

void mostrarDia0(sf::RenderWindow& window, const sf::Font& font) {
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
                    mostrarReportDia0(window, font);
                }

                sf::FloatRect buttonBounds2 = invisibleButton2.getGlobalBounds();
                if (buttonBounds2.contains(worldPos)) {
                    // clica no segundo botão invisível e faz a transição para outra janela
                    if (consulta_fila(catalogo)) paginaVazia(window, font);
                    else if (catalogo->inicio->num == 1) paginaCogumelo(window, font);
                    else mostrarDia0(window, font);
                }

                sf::FloatRect buttonBounds3 = invisibleButton3.getGlobalBounds();
                if (buttonBounds3.contains(worldPos)) {
                    // clica no terceiro botão invisível e faz a transição para outra janela
                    //mostrar email
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

void paginaVazia(sf::RenderWindow& window, const sf::Font& font)
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
                    mostrarDia0(window, font);
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
        exibirTexto(window, "CATÁLOGO", font, 30, 550, 70, sf::Color::Green);
        exibirTexto(window, ":(", font, 40, 280, 180, sf::Color::Green);
        exibirTexto(window, "Parece que você não possui scans ainda.", font, 24, 280, 250, sf::Color::Green);

        // botao
        window.draw(backButton);

        window.display();
    }
}

void paginaFinal(sf::RenderWindow& window, const sf::Font& font)
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
                    paginaCogumelo(window, font); //alterar pra ultima pagina do catalogo
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
        exibirTexto(window, "CATÁLOGO", font, 30, 550, 70, sf::Color::Green);
        exibirTexto(window, "Você chegou no fim do catálogo.", font, 20, 370, 130, sf::Color::White);
        window.display();
    }
}

// CODIGO 1
void paginaCogumelo(sf::RenderWindow& window, const sf::Font& font)
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
                    mostrarDia0(window, font); //volta para a tela inicial
                }
                sf::FloatRect buttonBoundsNext = nextButton.getGlobalBounds();
                if (buttonBoundsNext.contains(worldPos)) {
                    paginaFinal(window, font); //alterar pra ultima pagina do catalogo
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
        exibirTexto(window, "MUSHROOM MAN", font, 30, 540, 70, sf::Color::Green);
        exibirTexto(window, "A bipedal creature that looks like a giant walking", font, 18, 530, 160, sf::Color::White);
        exibirTexto(window, "Amanita phalloides, but with humanoid resemblances.", font, 18, 530, 180, sf::Color::White);
        exibirTexto(window, "It's skin - if it can even be called that - is white", font, 18, 530, 200, sf::Color::White);
        exibirTexto(window, "but covered with small orange and yellow mushrooms", font, 18, 530, 220, sf::Color::White);
        exibirTexto(window, "It usually pretends to be a mushroom and ignores", font, 18, 530, 240, sf::Color::White);
        exibirTexto(window, "everything until it gets hungry. Then, it's skin", font, 18, 530, 260, sf::Color::White);
        exibirTexto(window, "starts leaking toxins into the air to to make nearby", font, 18, 530, 280, sf::Color::White);
        exibirTexto(window, "possible victims slow and then embraces them to ", font, 18, 530, 300, sf::Color::White);
        exibirTexto(window, "death. This entity can also touchthe ground with its", font, 18, 530, 320, sf::Color::White);
        exibirTexto(window, "hands to create what looks like thick ropes of ", font, 18, 530, 340, sf::Color::White);
        exibirTexto(window, "mycelium and uses them to take someone down as", font, 18, 530, 360, sf::Color::White);
        exibirTexto(window, "they can travel underground with surprising speed.", font, 18, 530, 380, sf::Color::White);
        exibirTexto(window, "If you encounter something like this, retreat", font, 18, 530, 440, sf::Color::White);
        exibirTexto(window, "IMMEDIATELY and don't try to fight. Even if you can", font, 18, 530, 460, sf::Color::White);
        exibirTexto(window, "kill it, you will pass out and be exposed to other", font, 18, 530, 480, sf::Color::White);
        exibirTexto(window, "dangers for a long time.", font, 18, 530, 500, sf::Color::White);

        window.draw(backButton);
        window.draw(nextButton);

        window.display();
    }
}





// Indice 2
void paginaEscorpiao(sf::RenderWindow& window, const sf::Font& font)
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
                esvazia_fila(catalogo);
                mata_jogador(voce);
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
                    if (catalogo->inicio->num == 2) mostrarDia0(window, font);
                }

                sf::FloatRect buttonBoundsNext = nextButton.getGlobalBounds();
                if (buttonBoundsNext.contains(worldPos)) {
                    if (catalogo->fim->num == 2) paginaFinal(window, font);
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
        exibirTexto(window, "GIANT SCORPION", font, 30, 540, 70, sf::Color::Green);
        exibirTexto(window, "As its name suggests, this creature is just", font, 18, 580, 160, sf::Color::White);
        exibirTexto(window, "like an enormous scorpion. Surprisingly, it's", font, 18, 580, 180, sf::Color::White);
        exibirTexto(window, "poison isn't very strong and rarely is enough", font, 18, 580, 200, sf::Color::White);
        exibirTexto(window, "to kill a person, even though if you don't", font, 18, 580, 220, sf::Color::White);
        exibirTexto(window, "treat the sting it may result in having to", font, 18, 580, 240, sf::Color::White);
        exibirTexto(window, "amputate a member. The Scorpion's claws, on", font, 18, 580, 260, sf::Color::White);
        exibirTexto(window, "the other hand, can easily cut through", font, 18, 580, 280, sf::Color::White);
        exibirTexto(window, "protective clothing and human flesh altogether.", font, 18, 580, 300, sf::Color::White);
        exibirTexto(window, "It may be worth it to try and kill it but only", font, 18, 580, 360, sf::Color::White);
        exibirTexto(window, "if you're sure you have a good weapon.", font, 18, 580, 380, sf::Color::White);
        exibirTexto(window, "Running from it may be a hard task because it", font, 18, 580, 400, sf::Color::White);
        exibirTexto(window, "can move fast and climb on walls, trees, etc.", font, 18, 580, 420, sf::Color::White);
        exibirTexto(window, "If you can't kill it and don't have an escape", font, 18, 580, 440, sf::Color::White);
        exibirTexto(window, "route, pretend you're dead until it goes away.", font, 18, 580, 460, sf::Color::White);
        exibirTexto(window, "Humans are not part of their diet, so they only", font, 18, 580, 480, sf::Color::White);
        exibirTexto(window, "attack people when they feel in danger.", font, 18, 580, 500, sf::Color::White);

        window.draw(backButton);
        window.draw(nextButton);

        window.display();
    }
}

// Indice 3
void paginaHera(sf::RenderWindow& window, const sf::Font& font)
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
                esvazia_fila(catalogo);
                mata_jogador(voce);
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
                    if (catalogo->inicio->num == 3) mostrarDia0(window, font); //volta para a tela inicial                                             
                }

                sf::FloatRect buttonBoundsNext = nextButton.getGlobalBounds();
                if (buttonBoundsNext.contains(worldPos)) {
                    if (catalogo->fim->num == 3) paginaFinal(window, font);
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
        exibirTexto(window, "Hera Parasita", font, 30, 540, 70, sf::Color::Green);
        exibirTexto(window, "Uma flor vermelha gigante que exala um", font, 18, 625, 200, sf::Color::White);
        exibirTexto(window, "cheiro podre para atrair pequenos insetos", font, 18, 625, 220, sf::Color::White);
        exibirTexto(window, "e os matar com seus espinhos. Como parasita,", font, 18, 625, 240, sf::Color::White);
        exibirTexto(window, "muitas vezes se enrolará em outras plantas", font, 18, 625, 260, sf::Color::White);
        exibirTexto(window, "e as matará se precisar de mais comida.", font, 18, 625, 280, sf::Color::White);
        exibirTexto(window, "Tentar cortá-la, mesmo que seja apenas uma", font, 18, 625, 300, sf::Color::White);
        exibirTexto(window, "pétala resultará na liberação de uma nuvem", font, 18, 625, 320, sf::Color::White);
        exibirTexto(window, "de gás tóxico. Além disso, não pode fazer", font, 18, 625, 340, sf::Color::White);
        exibirTexto(window, "nenhum mal. Não tente comê-la ou tocá-la,", font, 18, 625, 360, sf::Color::White);
        exibirTexto(window, "considerando que isso pode tomar ações", font, 18, 625, 380, sf::Color::White);
        exibirTexto(window, "inesperadas.", font, 18, 625, 400, sf::Color::White);

        window.draw(backButton);
        window.draw(nextButton);

        window.display();
    }
}



