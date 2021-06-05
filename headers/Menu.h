#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "SDL.h"

#include "Common.h"

using namespace std;

class Menu
{
public:
    Menu();
    virtual ~Menu();
    SDL_Renderer* renderer;

    Button playButton;
    Button exitButton;

    SDL_Texture* m_menuTexture;
    SDL_Texture* m_backgroundMapTexture;

    int widthChange, heightChange;

    void init(string configFile);
    void draw();
    void update();
    void buttonHover(Button* button);
protected:

private:
};