#pragma once

#include "worldMap.h"
#include "SDL.h"
#include "SDL_image.h"
#include "sprite.h"
#include "Setup.h"
#include "tree.h"
#include "npc.h"
#include <vector>


class worldMap
{
public:
  worldMap(Setup *sdlSetup, float *cameraX, float *cameraY);
  ~worldMap();

  void drawFront();
  void drawBack();

  std::vector<tree*> getTrees() {return trees;}
  std::vector<npc*> getSoldiers(){return soldiers;}
  std::vector<npc*> getOldMan(){return oldMan;}
  sprite** getCliff(){return cliff;}
  sprite** getRiver1(){return river1Background;}
  sprite* getWaterfall(){return waterfallBackground;}

  sprite* getSummonCircleGreen(){return summonCircleGreen;}
  sprite* getSummonCircleBlue(){return summonCircleBlue;}
  sprite* getSummonCirclePurple(){return summonCirclePurple;}
  sprite* getSummonCircleRed(){return summonCircleRed;}

  sprite** getSea1(){return sea1;}
  sprite** getSea2(){return sea2;}

private:
  Setup *sdlSetup;

  float *cameraX;
  float *cameraY;

  sprite *grass[4][4];
  sprite *cliff[4];

  sprite *waterfallBackground;
  sprite *waterfall;

  sprite *river1Background[4];
  sprite *river1Sprite[4];

  sprite *summonCircleGreen;
  sprite *summonCircleRed;
  sprite *summonCirclePurple;
  sprite *summonCircleBlue;

  sprite *sea1[5];
  sprite *sea2[6];
  

  int treePosition[20]={
                800,730,
                3000,3000,
                2500,2455,
                2100,2499,
                1256,3458,
                900,4568,
                985,2333,
                1054,1000,
                1459,1000,
                1400,890
                        };
  std::vector<tree*> trees;

  std::vector <npc*> soldiers;
  std::vector <npc*> adult;
  std::vector <npc*> oldMan;
};