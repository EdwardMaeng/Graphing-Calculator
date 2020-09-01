#ifndef SYSTEM_H
#define SYSTEM_H

#include <SFML/Graphics.hpp>
#include "transform.h"
#include "evaluate.h"

class System {
public:
    System();
    void Step(string exp, double low, double high, double inc, int graph);
    void graph_rec(string exp, double low, double high, double points);
    void graph_polar(string exp, double low, double high, double points);
    void graph_cool(string exp, double low, double high, double points);
    void panUpdate(double x, double y);
    void panReset();
    void Draw(sf::RenderWindow& window);
    void setHigh(double h);

private:
    sf::VertexArray _x, _y;
    sf::VertexArray _curve;
    Queue<sf::Vector2f> _graph;
    Transform _t;
    sf::Vector2f _coords;
    double _xPan, _yPan, _pi, _high;
};

#endif // SYSTEM_H
