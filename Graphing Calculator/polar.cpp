#include "polar.h"

Polar::Polar() : _radius(0.0), _theta(0.0) {

}

sf::Vector2f Polar::get_radius_theta(sf::Vector2f c, double t) {
    _theta += t / 32;
    c.x = c.x * cos(_theta) - c.y * sin(_theta);
    c.y = c.y * cos(_theta) + c.x * sin(_theta);
    return c;
}
