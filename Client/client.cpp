//Chat Client
#include "clientnetwork.hpp"
#include <SFML/Graphics.hpp>

void runGame()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}

int main(int argc, char * argv[]){
     ClientNetwork client_network;
     client_network.Connect("localHost", 2525);
     std::thread packetThread([&client_network]()
                              { client_network.ReceivePackets(&client_network.socket); });
     std::thread clientThread([&client_network]()
                              { client_network.Run(); });
     runGame();
     clientThread.detach();
     packetThread.detach();
     return 0;
}