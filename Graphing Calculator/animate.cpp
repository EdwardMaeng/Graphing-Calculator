#include "animate.h"

Animate::Animate() : sidebar(WORK_PANEL, SIDE_BAR), _interval(-10, 10), _exp(" "), _tempexp(" "), _pan(0), _point(5000), _num(0), _graph(1), _theta(0), _high(0) {
    cout << "animate CTOR: TOP" << endl;

    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Edward's Graphing Calculator");

    window.setFramerateLimit(60);

    cout << "Geme CTOR. preparing to load the font." << endl;

    if(!font.loadFromFile("arial.ttf")) {
        cout << "animate() CTOR: Font failed to load" << endl;
        cin.get();
        exit(-1);
    }

    myText = sf::Text("", font);
    myText.setStyle(sf::Text::Italic);
    myText.setColor(sf::Color(114, 147, 203));
    myText.setPosition(sf::Vector2f(20, 20));

    myTextLabel = sf::Text("", font);
    myTextLabel.setCharacterSize(25);
    myTextLabel.setStyle(sf::Text::Italic);
    myTextLabel.setColor(sf::Color(175, 115, 190));
    myTextLabel.setPosition(sf::Vector2f(1215, 155));

    _count = (abs(_interval.x) + abs(_interval.y)) / 2;  // for zooming in and out (to make sure the interval doesn't become [0, 0])

    _input = "f(x) = ";

    cout << "animate instantiated successfully." << endl << endl;
}

void Animate::Draw() { /* draws system(curve, x, y), sidebar, and texts */
    system.Draw(window);
    sidebar.draw(window);
    window.draw(myTextLabel);
    window.draw(myText);
}

void Animate::update() { /* keeps updating system step (graphs) and sidebar (interval, points, coordinates of the mouse) */
   try {
       system.Step(_exp, _interval.x, _interval.y, _point, _graph);
   }
   catch(...) {
       cout << "Throw has been caught (Animate Class)" << endl << endl;
       _exp = " ";
   }
   sidebar[SB_INTERVAL_POSITION] = "INTERVAL: " + Interval(_interval);
   sidebar[SB_POINT_POSITION] = "POINTS: " + Point(_point);
   sidebar[SB_MOUSE_POSITION] = "Coords: " + mouse_pos_string(window);
}

void Animate::render() {
   window.clear(sf::Color(54, 53, 54));
   Draw();
   window.display();
}

void Animate::processEvents() {
   sf::Event event;
   string str;
   while (window.pollEvent(event)) {
       switch (event.type) {
       case sf::Event::Closed: /* closes window */
           window.close();
           break;
       case sf::Event::KeyPressed: /* events for key pressing */
           switch(event.key.code) {
            case sf::Keyboard::Left: /* shifts the graph left when pressed Left Arrow */
               sidebar[SB_KEY_PRESSED] = "SHIFT LEFT";
               _interval.x++;
               _interval.y++;
               _pan = WORK_PANEL/(_interval.y - _interval.x);
               system.panUpdate(0, -_pan);
               break;
           case sf::Keyboard::Right: /* shifts the graph right when pressed Right Arrow */
               sidebar[SB_KEY_PRESSED] = "SHIFT RIGHT";
               _interval.x--;
               _interval.y--;
               _pan = WORK_PANEL/(_interval.y -_interval.x);
               system.panUpdate(0, _pan);
               break;
           case sf::Keyboard::Up: /* shifts the graph up when pressed Up Arrow */
               sidebar[SB_KEY_PRESSED] = "SHIFT UP";
               system.panUpdate(-_pan, 0);
               break;
           case sf::Keyboard::Down: /* shifts the graph down when pressed Down Arrow */
               sidebar[SB_KEY_PRESSED] = "SHIFT DOWN";
               system.panUpdate(_pan, 0);
               break;
           case sf::Keyboard::F: /* resets everything from points, position of x and y, and the interval when pressed F */
               sidebar[SB_KEY_PRESSED] = "F: RESET";
               _interval.x = -10;
               _interval.y = 10;
               _high = 0;
               system.setHigh(_high);
               _pan = 0;
               _point = 5000;
               system.panReset();
               break;
           case sf::Keyboard::Escape: /* exits the program when pressed Escape */
               sidebar[SB_KEY_PRESSED] = "ESC: EXIT";
               window.close();
               break;
           case sf::Keyboard::Z: /* zooms into the graph when pressed Z */
               sidebar[SB_KEY_PRESSED] = "Z: Zooming in";
               if(_count > 1) {
                   _interval.x++;
                   _interval.y--;
                   _count = (abs(_interval.x) + abs(_interval.y)) / 2;
               }
               break;
           case sf::Keyboard::M: /* zooms out the graph when pressed X */
               sidebar[SB_KEY_PRESSED] = "M: Zooming out";
               _interval.x--;
               _interval.y++;
               _count++;
               break;
           case sf::Keyboard::W: /* increases the points by (points * 2) when pressed W */
               sidebar[SB_KEY_PRESSED] = "W: Increase Points";
               _point += 500;
               break;
           case sf::Keyboard::P: /* decreases the points by (points / 2) when pressed P */
               sidebar[SB_KEY_PRESSED] = "P: Decrease Points";
               _point -= 500;
               break;
           case sf::Keyboard::V: /* changes to regular graph when pressed V */
               sidebar[SB_KEY_PRESSED] = "V: Regular Graph";
               _graph = 1;
               _input = "f(x) = ";
               break;
           case sf::Keyboard::B: /* changes to polar graph when pressed B */
               sidebar[SB_KEY_PRESSED] = "B: Polar Graph";
               _graph = 2;
               _input = "r = ";
               break;
           case sf::Keyboard::J: /* changes to COOL graph when pressed J */
               sidebar[SB_KEY_PRESSED] = "J: COOL Graph";
               _graph = 3;
               _input = "f(x) = ";
               break;
           case sf::Keyboard::RBracket: /* increase theta (high) to pi/16 for polar graph */
               sidebar[SB_KEY_PRESSED] = "LBRACKET: Increase High";
               _high += 4*atan(1) / 16;
               system.setHigh(_high);
               break;
           case sf::Keyboard::LBracket: /* decrease theta (high) to pi/16 for polar graph */
               sidebar[SB_KEY_PRESSED] = "RBRACKET: Decrease High";
               _high -= 4*atan(1) / 16;
               system.setHigh(_high);
               break;
           }
           break;

       case sf::Event::TextEntered: /* whenever a text is entered (ignores keypressed) then it gets added to a string until Enter is pressed (the string becomes the new expression) */
           if(event.text.unicode < 128) {
               if(event.text.unicode == 102 || event.text.unicode == 122 || event.text.unicode == 109 || event.text.unicode == 112 || event.text.unicode == 91) {
                   break;
               }
               else if(event.text.unicode == 119 || event.text.unicode == 118 || event.text.unicode == 98 || event.text.unicode == 106 || event.text.unicode == 93) {
                   break;
               }
               else if(event.text.unicode == 13) { /* enter clears the string and sets the expression to the string */
                   _exp = _tempexp;
                   if(_graph != 2) {
                       _input = "f(x) = ";
                   }
                   else {
                       _input = "r = ";
                   }
                   _tempexp = " ";
                   if(_num > 0) { /* if a file number is given it saves the file in that location */
                       sidebar.save_expression(_exp, _num);
                       _num = 0;
                   }
               }
               else if(event.text.unicode == 8) { /* backspace => erase the last character */
                   if(!_tempexp.empty()) {
                       _input.erase(_input.getSize() - 1, _input.getSize());
                       _tempexp.pop_back();
                   }
               }
               else {
                   _input += event.text.unicode;
                   _tempexp += static_cast<char>(event.text.unicode);
               }
               myText.setString(_input);
               myTextLabel.setString(_exp);
           }
           break;

       case sf::Event::MouseButtonPressed: /* Being able to click on the saved expressions */
           if(event.mouseButton.button == sf::Mouse::Right) {
               if(sf::Mouse::getPosition(window).x >= 1205 && sf::Mouse::getPosition(window).x <= 1305) {
                   if(sf::Mouse::getPosition(window).y >= 195 && sf::Mouse::getPosition(window).y <= 215) {
                       sidebar[SB_KEY_PRESSED] = "Expression 1";
                       sidebar.load_expression(_exp, 5);
                       myTextLabel.setString(_exp);
                       _num = 5;
                   }
                   if(sf::Mouse::getPosition(window).y >= 230 && sf::Mouse::getPosition(window).y <= 250) {
                       sidebar[SB_KEY_PRESSED] = "Expression 2";
                       sidebar.load_expression(_exp, 6);
                       myTextLabel.setString(_exp);
                       _num = 6;
                   }
                   if(sf::Mouse::getPosition(window).y >= 265 && sf::Mouse::getPosition(window).y <= 290) {
                       sidebar[SB_KEY_PRESSED] = "Expression 3";
                       sidebar.load_expression(_exp, 7);
                       myTextLabel.setString(_exp);
                       _num = 7;
                   }
                   if(sf::Mouse::getPosition(window).y >= 305 && sf::Mouse::getPosition(window).y <= 330) {
                       sidebar[SB_KEY_PRESSED] = "Expression 4";
                       sidebar.load_expression(_exp, 8);
                       myTextLabel.setString(_exp);
                       _num = 8;
                   }
                   if(sf::Mouse::getPosition(window).y >= 345 && sf::Mouse::getPosition(window).y <= 370) {
                       sidebar[SB_KEY_PRESSED] = "Expression 5";
                       sidebar.load_expression(_exp, 9);
                       myTextLabel.setString(_exp);
                       _num = 9;
                   }
                   if(sf::Mouse::getPosition(window).y >= 385 && sf::Mouse::getPosition(window).y <= 410) {
                       sidebar[SB_KEY_PRESSED] = "Expression 6";
                       sidebar.load_expression(_exp, 10);
                       myTextLabel.setString(_exp);
                       _num = 10;
                   }
                   if(sf::Mouse::getPosition(window).y >= 420 && sf::Mouse::getPosition(window).y <= 445) {
                       sidebar[SB_KEY_PRESSED] = "Expression 7";
                       sidebar.load_expression(_exp, 11);
                       myTextLabel.setString(_exp);
                       _num = 11;
                   }
                   if(sf::Mouse::getPosition(window).y >= 460 && sf::Mouse::getPosition(window).y <= 485) {
                       sidebar[SB_KEY_PRESSED] = "Expression 8";
                       sidebar.load_expression(_exp, 12);
                       myTextLabel.setString(_exp);
                       _num = 12;
                   }
                   if(sf::Mouse::getPosition(window).y >= 495 && sf::Mouse::getPosition(window).y <= 520) {
                       sidebar[SB_KEY_PRESSED] = "Expression 9";
                       sidebar.load_expression(_exp, 13);
                       myTextLabel.setString(_exp);
                       _num = 13;
                   }
                   if(sf::Mouse::getPosition(window).y >= 530 && sf::Mouse::getPosition(window).y <= 560) {
                       sidebar[SB_KEY_PRESSED] = "Expression 10";
                       sidebar.load_expression(_exp, 14);
                       myTextLabel.setString(_exp);
                       _num = 14;
                   }
               }
           }
           break;

       default:
           break;
       }
   }
}

void Animate::run() { /* keeps animate class running while window is opened */
   while (window.isOpen()) {
       processEvents();
       update();
       render();
   }
   cout << endl << "------------ ANIMATE MAIN LOOP EXITING ------------" << endl;
}

string Interval(sf::Vector2f c) { /* Ouputs the interval on screen (top of sidebar) */
    return "[" + to_string(static_cast<int>(c.x)) + ", " + to_string(static_cast<int>(c.y)) + "]";
}

string Point(float p) { /* Outputs the points on screen (after interval) */
    return to_string(static_cast<int>(p));
}

string mouse_pos_string(sf::RenderWindow& window) { /* Outputs the coordinates of x and y on screen mouse (getPosition) */
    return "(" + to_string(sf::Mouse::getPosition(window).x) + ", " + to_string(sf::Mouse::getPosition(window).y) + ")";
}
