#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "terminaleng.hpp"
#include "jogoptbr.hpp"
#include <iostream>

/*OBS: TODA VEZ QUE TIVER FUN��O DE FECHAR O JOGO TEM QUE DESALOCAR O CATALOGO E O PLAYER*/
/*pensar na logica das paginas*/


int main()
{
    // cria��o da janela
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Relinquo", sf::Style::Default);
    window.setFramerateLimit(60);


    // cria��o da fonte
    sf::Font font;
    if (!font.loadFromFile("Assets/Retro Gaming.ttf")) {
        std::cerr << "Erro ao carregar a fonte" << std::endl;
        return EXIT_FAILURE;
    }

    // cria��o m�sica
    sf::Music music;
    music.openFromFile("Assets/tudo bem ficar triste nos te amamos.ogg");
    music.setVolume(10.0);
    music.play();
    music.setPlayingOffset(sf::seconds(804));
    music.setLoop(true);
    //if (!music_on) music.pause();
    // criar sinal para a musica parar


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
        beginning(window, font);
        
        ///////////////////////////////////////////////////

        // exibe tudo na janela
        window.display();
    }

    return 0;
}