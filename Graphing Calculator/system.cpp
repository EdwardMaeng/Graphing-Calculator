#include "system.h"

System::System() : _x(sf::LineStrip, 2), _y(sf::LineStrip, 2), _xPan(0), _yPan(0), _pi(4*atan(1)), _high(0) {
    _curve.setPrimitiveType(sf::Points);

    _x[0].position = sf::Vector2f(0, SCREEN_HEIGHT/2);
    _y[0].color = sf::Color::White;
    _x[1].position = sf::Vector2f(WORK_PANEL, SCREEN_HEIGHT/2);
    _y[0].color = sf::Color::White;

    _y[0].position = sf::Vector2f(WORK_PANEL/2, 0);
    _y[0].color = sf::Color::White;
    _y[1].position = sf::Vector2f(WORK_PANEL/2, SCREEN_HEIGHT);
    _y[0].color = sf::Color::White;
}

void System::Step(string exp, double low, double high, double inc, int graph) { /* graph either regular, polar, or cool depending the integer graph */
    if(graph == 1) {
        graph_rec(exp, low, high, inc);
    }
    else if(graph == 2) {
        graph_polar(exp, low, high, inc);
    }
    else {
        graph_cool(exp, low, high, inc);
    }
}

/*
 * Graph Rec:
 * Take an evaluate object which intakes a string of expression. It loops through low to high (the interval)
 * in each steps of increments. The intervals are the the values of x and the evaluated value is the y. The queue
 * pushes the vector (coordinates of x and y) and pops into system class.
 */

void System::graph_rec(string exp, double low, double high, double points) {
    Evaluate e(exp);
    _curve.resize(points);
    double step = (high - low) / points; // becomes the increment
    for(double i = low; i <= high; i += step) {
        _coords.x = i;
        _coords.y = e.eval(i); // eval(i) is the y-axis
        _coords = _t.new_coords(low, high, _coords); // transform into screen coords
        _coords = _t.shift(_yPan, _xPan, _coords); // shifts (x-axis, y-axis) the graph depending on animate event
        _curve.append(sf::Vertex(_coords, sf::Color(114, 147, 203)));
    }
}

/*
 * Graph Polar:
 * Take an evaluate object which intakes a string of expression. IIt loops through low to high (the interval)
 * in each steps of increments. The eval(i) basically is the radius and the loops i is the theta.
 * The x is found by the evaluated value mulitply by the cosine. (x = rcos(theta)) The y is found similarly
 * to x but by the sin. (y = rsin(theta). The transformation and the shifts on screen works similarly like the graph_rec.
 * low and high (the interval)
 */

void System::graph_polar(string exp, double low, double high, double points) {
    Evaluate e(exp);
    _curve.resize(points);
    double step = (high - low) / points; // becomes the increment
    for(double i = 0; i <= _high; i += step) { // i is the theta (which gets incremented by step) and eval(i) would be the radius
        _coords = _t.polar_cooords(e.eval(i), i, _coords); // x = r * cos(theta) and y = r * sin(theta)
        _coords = _t.new_coords(low, high, _coords);
        _coords = _t.shift(_yPan, _xPan, _coords);
        _curve.append(sf::Vertex(_coords, sf::Color(114, 147, 203)));
    }
}

/*
 * Graph Cool:
 * I was working on rotational transformation (I didn't actually do it), but found this cool way to
 * graph. Basically transforms the coordinate x to (x*cos(theta) - y*sin(theta)) and coordinate y to
 * (y*cos(theta) + x*sin(theta)). Other transformation and shift works the simiarly like the graph_rec
 * and graph_polar.
 */

void System::graph_cool(string exp, double low, double high, double points) {
    Evaluate e(exp);
    _curve.resize(points);
    double step = (high - low) / points; // becomes the increment
    for(double i = low; i <= high; i += step) {
        _coords.x = i;
        _coords.y = e.eval(i);
        _coords = _t.cool_coords(_pi, _coords); // x = x*cos(theta) - y*sin(theta) and y = y*cos(theta) + x*sin(theta) -> theta gets incremented by pi/32 everytime
        _coords = _t.new_coords(low, high, _coords);
        _coords = _t.shift(_yPan, _xPan, _coords);
        _curve.append(sf::Vertex(_coords, sf::Color(114, 147, 203)));
    }
}

void System::panUpdate(double x, double y) { /* updates the x-axis and y-axis by the shift given by shifting the graph */
    _xPan += x;
    _yPan += y;
    _x[0].position = sf::Vector2f(0, SCREEN_HEIGHT/2 + _xPan);
    _x[1].position = sf::Vector2f(WORK_PANEL, SCREEN_HEIGHT/2 + _xPan);
    _y[0].position = sf::Vector2f(WORK_PANEL/2 +_yPan, 0);
    _y[1].position = sf::Vector2f(WORK_PANEL/2 + _yPan, SCREEN_HEIGHT);
}

void System::panReset() { /* resets the x-axis and y-axis and sets xPan and yPan to zero */
    _xPan = 0;
    _yPan = 0;
    _x[0].position = sf::Vector2f(0, SCREEN_HEIGHT/2);
    _x[1].position = sf::Vector2f(WORK_PANEL, SCREEN_HEIGHT/2);
    _y[0].position = sf::Vector2f(WORK_PANEL/2, 0);
    _y[1].position = sf::Vector2f(WORK_PANEL/2, SCREEN_HEIGHT);
}

void System::Draw(sf::RenderWindow &window) { /* draws x-axis, y-axis, and the curve */
    window.draw(_x);
    window.draw(_y);
    window.draw(_curve);
}

void System::setHigh(double h) {
    _high = h;
}
