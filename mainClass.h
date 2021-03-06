#pragma once

#include "mainClass.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Setup.h"
#include "sprite.h"
#include "mainCharacter.h"
#include "worldMap.h"
#include "startMenu.h"
#include "inGameMenu.h"
#include "battleScene.h"
#include "endScreen.h"
#include "audioManager.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 640

class mainClass
{
public:
  mainClass();
  ~mainClass();
  void gameLoop();
  void directionPlayAnimation(int passed_direction);

private:
  bool quit;

  float cameraX;
  float cameraY;

  int direction;
  int prevDirection;

  Setup *sdlSetup;

  startMenu *sMenu;

  mainCharacter *Lo;

  worldMap *wmap;

  inGameMenu *menu;
  battleScene *combatScene;
  endScreen *dScreen;

  audioManager *audio;

  componentState mainGameLoopState;
  componentState introState1;
  componentState introState2;
  componentState deathState;
  componentState endState;

  unsigned int introTimer;
  unsigned int deathTimer;
};
