#include "transform.h"

Transform::Transform() : _theta(0.0), _pi(4*atan(1)) {

}

sf::Vector2f Transform::new_coords(double low, double high, sf::Vector2f c) { /* @return a coordinate that has been scaled to the size of the screen */
    c.x *= WORK_PANEL / (high - low);
    c.x += WORK_PANEL / 2;
    c.y *= SCREEN_HEIGHT / (high - low);
    c.y = SCREEN_HEIGHT / 2 - c.y;
    return c;
}

sf::Vector2f Transform::shift(double x, double y, sf::Vector2f c) { /* @return a coordinate that has been shifted by the pan in animate events */
    c.x += x;
    c.y += y;
    return c;
}

sf::Vector2f Transform::polar_cooords(double r, double t, sf::Vector2f c) {
    c.x = r * cos(t);
    c.y = r * sin(t);
    return c;
}

sf::Vector2f Transform::cool_coords(double pi, sf::Vector2f c) { /* I was playing around rotational transformation (I didn't actually do it, but I found that this makes a really cool graph!) */
    _theta += pi / 32;
    c.x = c.x * cos(_theta) - c.y * sin(_theta);
    c.y = c.y * cos(_theta) + c.x * sin(_theta);
    return c;
}
