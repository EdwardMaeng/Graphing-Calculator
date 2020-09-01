#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "SFML/Graphics.hpp"

/*
 * Author: Edward Maeng
 * Class: CS 3A
 * Professor: Sassan Barkeshli
 * Project: Graphing Calculator
 */


// Used for Virtual getType function
enum type {
    TOKEN,
    NUMBER,
    OPERATOR,
    LPAREN,
    RPAREN,
    VARIABLE,
    FUNCTION
};

// Used for SFML purposes
const float SCREEN_WIDTH = 1500;
const float SCREEN_HEIGHT = 900;
const float WORK_PANEL = SCREEN_WIDTH * 4/5;
const float SIDE_BAR = SCREEN_WIDTH * 1/5;
const int SB_INTERVAL_POSITION = 0;
const int SB_POINT_POSITION = SB_INTERVAL_POSITION + 1;
const int SB_MOUSE_POSITION = SB_POINT_POSITION + 1;
const int SB_KEY_PRESSED = SB_MOUSE_POSITION + 1;

#endif // CONSTANTS_H
