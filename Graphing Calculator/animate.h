#ifndef ANIMATE_H
#define ANIMATE_H

#include <SFML/Graphics.hpp>
#include "system.h"
#include "sidebar.h"

class Animate{
public:
    Animate();
    void run();
    void processEvents();
    void update();
    void render();
    void Draw();

private:
    sf::RenderWindow window;
    sf::CircleShape mousePoint;
    System system;
    sf::Font font;
    sf::String _input;
    sf::Text myTextLabel;
    sf::Text myText;
    int _num, _graph;
    Sidebar sidebar;
    string _exp, _tempexp;
    sf::Vector2f _interval;
    double _pan, _point, _count, _theta, _high;
};

string Interval(sf::Vector2f c);
string Point(float p);
string mouse_pos_string(sf::RenderWindow& window);

#endif // ANIMATE_H
