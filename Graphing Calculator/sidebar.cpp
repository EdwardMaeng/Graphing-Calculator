#include "sidebar.h"
#include "constants.h"
#include <cstring>

Sidebar::Sidebar() {

}

Sidebar::Sidebar(float left, float width) : _left(left), _width(width) {
    cout << "Sidebar CTOR: TOP" << endl;
    items.reserve(50);

    rect.setFillColor(sf::Color(42, 37, 41));
    rect.setPosition(sf::Vector2f(left, 0));
    rect.setSize(sf::Vector2f(width, SCREEN_HEIGHT));
    cout << "Sidebar CTOR: about to load font." << endl;

    if(!font.loadFromFile("arial.ttf")) {
        cout << "Sidebar() CTOR: Font failed to load" << endl;
        cin.get();
        exit(-1);
    }

    cout << "Sidebar CTOR: loaded font." << endl;

    cout << "Sidebar CTOR: Text object initialized." << endl;
    sb_text.setFont(font);
    sb_text.setCharacterSize(20);
    sb_text.setStyle(sf::Text::Bold);
    sb_text.setColor(sf::Color(114, 147, 203));

    for(int i = 0; i < 30; i++) {
        items.push_back("");
    }

    for(int i = 5; i < 15; i++) {
        load_expression(_exp, i);
        items[i] = _exp;
    }

    cout << "Sidebar: CTOR: Exit." << endl;
}

void Sidebar::save_expression(string exp, int item_num) { /* saves different string of expressions */
    ofstream outFile;
    switch(item_num) {
    case 5:
        outFile.open("file5.txt");
        break;
    case 6:
        outFile.open("file6.txt");
        break;
    case 7:
        outFile.open("file7.txt");
        break;
    case 8:
        outFile.open("file8.txt");
        break;
    case 9:
        outFile.open("file9.txt");
        break;
    case 10:
        outFile.open("file10.txt");
        break;
    case 11:
        outFile.open("file11.txt");
        break;
    case 12:
        outFile.open("file12.txt");
        break;
    case 13:
        outFile.open("file13.txt");
        break;
    case 14:
        outFile.open("file14.txt");
        break;
    }

    if (outFile.fail()) {
        cout << endl << "***** could not open file for output. ****" << endl;
        exit(0);
    }

    outFile << exp;
    items[item_num] = exp;

    outFile.close();
    cout << "the expression was written to the file." << endl << endl;
}

void Sidebar::load_expression(string& exp, int item_num) { /* loads different string of expressions */
    ifstream inFile;
    switch (item_num) {
    case 5:
        inFile.open("file5.txt");
        break;
    case 6:
        inFile.open("file6.txt");
        break;
    case 7:
        inFile.open("file7.txt");
        break;
    case 8:
        inFile.open("file8.txt");
        break;
    case 9:
        inFile.open("file9.txt");
        break;
    case 10:
        inFile.open("file10.txt");
        break;
    case 11:
        inFile.open("file11.txt");
        break;
    case 12:
        inFile.open("file12.txt");
        break;
    case 13:
        inFile.open("file13.txt");
        break;
    case 14:
        inFile.open("file14.txt");
        break;
    }

    if (inFile.fail()) {
        cout << endl << "***** could not open file for input. ****" << endl;
        exit(0);
    }

    inFile >> exp;

    inFile.close();
    cout << "-- end of file --" << endl << endl;
}

/*
    This would be using one file, which doesn't allow me to freely save file (but a lot more efficient and saves more memory)

void Sidebar::save_expression(string exp, int item_num) {
    ofstream outFile;

    outFile.open("file1.txt");

    if (outFile.fail()) {
        cout << endl << "***** could not open file for output. ****" << endl;
        exit(0);
    }

    outFile << exp << endl;
    items[item_num] = exp;

    outFile.close();
    cout << "the expression was written to the file." << endl << endl;
}

void Sidebar::load_expression(string& exp, int item_num) {
    ifstream inFile;
    string str;

    inFile.open("file1.txt");

    if (inFile.fail()) {
        cout << endl << "***** could not open file for input. ****" << endl;
        exit(0);
    }

    inFile >> exp;

    for(int i = 1; i<= item_num; i++) {
        if(i == item_num) {
            getline(inFile, exp);
        }
        else {
            getline(inFile, str);
        }
    }

    inFile.close();
    cout << "-- end of file --" << endl << endl;
}

void Sidebar::clear_history(int item_num) {
    ofstream outFile;
    string str = "";

    outFile.open("file1.txt");

    if (outFile.fail()) {
        cout << endl << "***** could not open file for output. ****" << endl;
        exit(0);
    }

    for(int i = 0; i <= item_num; i++) {
        outFile << str << endl;
        items[i] = exp;
    }

    outFile.close();
    cout << "the expression was written to the file." << endl << endl;


}
*/

void Sidebar::draw(sf::RenderWindow& window) {
    const double VERTICAL_LINE_SPACING = 20.0;
    const double LEFT_MARGIN = 10.0;

    window.draw(rect);
    float height = 10;

    for(vector<string>::iterator it = items.begin(); it!= items.end(); it++){
        bool blank = false;
        if(strlen(it->c_str()) == 0) {
            blank = true;
            sb_text.setString("BLANK");
        }
        else {
            sb_text.setString(it->c_str());
        }
        sb_text.setPosition(sf::Vector2f(_left+LEFT_MARGIN, height));
        height += sb_text.getLocalBounds().height+VERTICAL_LINE_SPACING;
        if (!blank) {
            window.draw(sb_text);
        }
    }
}

string& Sidebar::operator [](int index) {
    return items[index];
}
