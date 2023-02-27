#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#define ROW 4
#define COL 4
#define WIDTH 1280
#define HEIGHT 720
using namespace std;
using namespace sf;
class Tile {
    public:
        RectangleShape shape;
        Text text;
        int value;
        Tile(float x, float y) {
            shape.setSize(Vector2f(150, 150));
            shape.setFillColor(Color::White);
            shape.setPosition(Vector2f(x, y));
            shape.setOutlineThickness(5);
            shape.setOutlineColor(Color(200, 200, 200));
            Font font;
            font.loadFromFile("arial.ttf");
            text.setFont(font);
            text.setCharacterSize(60);
            text.setFillColor(Color::Black);
            value = 0;
        }
        void setValue(int val) {
            value = val;
            if(value == 0) {
                text.setString("");
            }
            else {
                text.setString(to_string(value));
            }
            text.setOrigin(text.getLocalBounds().width/2, text.getLocalBounds().height/2);
            text.setPosition(shape.getPosition().x+shape.getLocalBounds().width/2, shape.getPosition().y+shape.getLocalBounds().height/2);
        }
};
Tile tiles[ROW][COL] = {{Tile(100, 100), Tile(275, 100), Tile(450, 100), Tile(625, 100)}, 
                        {Tile(100, 275), Tile(275, 275), Tile(450, 275), Tile(625, 275)},
                        {Tile(100, 450), Tile(275, 450), Tile(450, 450), Tile(625, 450)}, 
                        {Tile(100, 625), Tile(275, 625), Tile(450, 625), Tile(625, 625)}};
bool isGameOver = false;
void addRandomTile() {
    int x = rand()%ROW, y = rand()%COL;
    while(tiles[x][y].value != 0) {
        x = rand()%ROW;
        y = rand()%COL;
    }
    int val = (rand()%10 == 0) ? 4 : 2;
    tiles[x][y].setValue(val);
}
void init() {
    srand(time(NULL));
    addRandomTile();
    addRandomTile();
}
void move(int dir) {
    bool isMoved = false;
    if(dir == 0) {  // up
        for(int i = 1; i < ROW; i++) {
            for(int j = 0; j < COL; j++) {
                if(tiles[i][j].value != 0) {
                    int k = i-1;
                    while(k >= 0 && tiles[k][j].value == 0) {
                        k--;
                    }
                    if(k >= 0 && tiles[k][j].value == tiles[i][j].value) {
                        tiles[k][j].setValue(tiles[i][j].value*2);
                        tiles[i][j].setValue(0);
                        isMoved = true;
                    }
                    else {
                        k++;
                        if(k != i) {
                            tiles[k][j].setValue(tiles[i][j].value);
                            tiles[i][j].setValue(0);
                            isMoved = true
