#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "polar.h"
using namespace std;

class Sidebar {
public:
    Sidebar();
    Sidebar(float left, float width);
    void old_expression(string exp);
    int item_num();
    void save_expression(string exp, int item_num);
    void load_expression(string& exp, int item_num);
    void draw(sf::RenderWindow& window);
    string& operator [](int index);

private:
    sf::RectangleShape rect;
    vector<string> items;
    vector<Queue<sf::Vector2f>> expressions;
    sf::Font font;
    sf::Text sb_text;
    float _left, _width;
    string _exp;
};

#endif // SIDEBAR_H
