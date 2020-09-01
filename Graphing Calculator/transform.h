#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "SFML/Graphics.hpp"
#include <cmath>
#include "constants.h"

class Transform {
public:
    Transform();
    sf::Vector2f new_coords(double low, double high, sf::Vector2f c);
    sf::Vector2f shift(double x, double y, sf::Vector2f c);
    sf::Vector2f polar_cooords(double r, double t, sf::Vector2f c);
    sf::Vector2f cool_coords(double pi, sf::Vector2f c);

private:
    double _theta;
    double _pi;
};

#endif // TRANSFORM_H
