#include "audioManager.h"

audioManager::audioManager()
{
    SDL_Init(SDL_INIT_AUDIO);

    mainTheme = NULL;
    battleTheme = NULL;
    opTheme = NULL;

    boss1Theme=NULL;
    boss2Theme=NULL;
    boss3Theme=NULL;
    boss4Theme=NULL;

    deathTheme =NULL;

    click = NULL;
    save = NULL;
    flamethrower = NULL;
    curse = NULL;
    freeze = NULL;
    sword_sound = NULL;
    spell = NULL;
    hurt = NULL;
}

audioManager::~audioManager()
{
    Mix_FreeMusic(mainTheme);
    mainTheme = NULL;

    Mix_FreeMusic(battleTheme);
    battleTheme = NULL;

    Mix_FreeMusic(opTheme);
    opTheme = NULL;

    Mix_FreeMusic(boss1Theme);
    boss1Theme =NULL;

    Mix_FreeMusic(boss1Theme);
    boss1Theme =NULL;

    Mix_FreeMusic(boss1Theme);
    boss1Theme =NULL;

    Mix_FreeMusic(boss1Theme);
    boss1Theme =NULL;

    Mix_FreeChunk(deathTheme);
    deathTheme =NULL;

    Mix_FreeChunk(click);
    click = NULL;

    Mix_FreeChunk(save);
    save = NULL;

    Mix_FreeChunk(flamethrower);
    flamethrower = NULL;

    Mix_FreeChunk(curse);
    curse = NULL;

    Mix_FreeChunk(freeze);
    freeze = NULL;

    Mix_FreeChunk(sword_sound);
    sword_sound = NULL;

    Mix_FreeChunk(spell);
    spell = NULL;

    Mix_FreeChunk(hurt);
    hurt =NULL;
}

void audioManager::start()
{
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_VolumeMusic(6);

    
    mainTheme = Mix_LoadMUS("resource/music/mainTheme.ogg");
    battleTheme = Mix_LoadMUS("resource/music/battleTheme.mp3");
    opTheme = Mix_LoadMUS("resource/music/opTheme.ogg");

    boss1Theme = Mix_LoadMUS("resource/music/bossTheme1.mp3");
    boss2Theme = Mix_LoadMUS("resource/music/bossTheme2.mp3");
    boss3Theme = Mix_LoadMUS("resource/music/bossTheme3.mp3");
    boss4Theme = Mix_LoadMUS("resource/music/bossTheme3.mp3");

    deathTheme = Mix_LoadWAV("resource/music/deathTheme.mp3");
    

    click = Mix_LoadWAV("resource/sound/click.wav");
    save = Mix_LoadWAV("resource/sound/save.wav");
    flamethrower = Mix_LoadWAV("resource/sound/flamethrower.ogg");
    curse = Mix_LoadWAV("resource/sound/curse.ogg");
    freeze = Mix_LoadWAV("resource/sound/freeze.ogg");
    sword_sound = Mix_LoadWAV("resource/sound/sword_sound.wav");
    spell = Mix_LoadWAV("resource/sound/spell.ogg");
    hurt = Mix_LoadWAV("resource/sound/hurt.mp3");
}

void audioManager::stopMusic()
{
    Mix_FadeOutMusic(500);
}

void audioManager::playOpeningTheme()
{
    
   Mix_PlayMusic(opTheme, -1);
}

void audioManager::playMainTheme()
{
    Mix_PlayMusic(mainTheme, -1);
}

void audioManager::playBattleTheme()
{
    Mix_PlayMusic(battleTheme, -1);
}

void audioManager::playClick(){
    Mix_PlayChannel(-1,click,0);
}

void audioManager::playMelee(){
    Mix_PlayChannel(-1,sword_sound,0);
}

void audioManager::playFlame(){
    Mix_PlayChannel(-1,flamethrower,0);
}

void audioManager::playFreeze(){
    Mix_PlayChannel(-1,freeze,0);
}

void audioManager::playArcane(){
    Mix_PlayChannel(-1,spell,0);
}

void audioManager::playCurse(){
    Mix_PlayChannel(-1,curse,0);
}

void audioManager::playSave(){
    Mix_PlayChannel(-1,save,0);
}

void audioManager::playBossTheme(int nBoss){
    switch(nBoss){
        case 1:
        Mix_PlayMusic(boss1Theme,-1);
        break;
        case 2:
        Mix_PlayMusic(boss2Theme,-1);
        break;
        case 3:
        Mix_PlayMusic(boss3Theme,-1);
        break;
        case 4:
        Mix_PlayMusic(boss4Theme,-1);
        break;
        default:
        break;
    }
}

void audioManager::playDeathTheme(){
    Mix_PlayChannel(-1,deathTheme,0);
}

void audioManager::playHurt(){
    Mix_PlayChannel(-1,hurt,0);
}

