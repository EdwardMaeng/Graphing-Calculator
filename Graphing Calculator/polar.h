#ifndef POINT_H
#define POINT_H

#include "SFML/Graphics.hpp"
#include "evaluate.h"
#include "constants.h"

class Polar {
public:
    Polar();
    sf::Vector2f get_radius_theta(sf::Vector2f c, double t);

    double _theta;
    double _radius;
};

#endif // POINT_H
