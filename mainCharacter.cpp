#include "mainCharacter.h"

mainCharacter::mainCharacter(Setup *passed_setup, float *passed_cameraX, float *passed_cameraY, worldMap *passed_Map)
{
    Map = passed_Map;

    cameraX = passed_cameraX;
    cameraY = passed_cameraY;

    sdlSetup = passed_setup;

    Lo = new sprite(sdlSetup->getRenderer(), "resource/image/Lo.png", 1200, 900, 50, 75, cameraX, cameraY, collisionRectangle(0, 50, 50, 25));
    Lo->setUpAnimation(4, 4);
    direction = STILL;

    level = 1;
    experience = 0;
    maxHP = 60;
    maxMP = 20;
    hp = maxHP;
    mp = maxMP;
    attack = 10;
    defense = 5;
    gold = 100;
    intelligence = 8;

    loTextRect.x = 10;
    loTextRect.y = 550;
    loTextRect.w = 40;
    loTextRect.h = 60;

    hpTextRect.x = 60;
    hpTextRect.y = 550;
    hpTextRect.w = 80;
    hpTextRect.h = 30;

    mpTextRect.x = 60;
    mpTextRect.y = 572;
    mpTextRect.w = 80;
    mpTextRect.h = 30;

    goldTextRect.x = 680;
    goldTextRect.y = 550;
    goldTextRect.w = 80;
    goldTextRect.h = 30;

    levelTextRect.x = 680;
    levelTextRect.y = 572;
    levelTextRect.w = 80;
    levelTextRect.h = 30;
}

mainCharacter::~mainCharacter()
{
    delete sdlSetup;

    delete Lo;
    delete Map;

    delete cameraX;
    delete cameraY;
}

void mainCharacter::draw()
{
    Lo->draw();
}

void mainCharacter::update()
{
    directionPlayAnimation(direction);

    if (sdlSetup->getMainEvent()->type == SDL_KEYUP)
    {
        direction = STILL;
    }

    if (sdlSetup->getMainEvent()->type == SDL_KEYDOWN)
    {
        colliding = false;
        for (int i = 0; i < 10; i++)
        {
            if (Lo->isCollide(Map->getTrees()[i]->getTrunk()->getCollisionRect()))
            {
                colliding = true;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            if (Lo->isCollide(Map->getCliff()[i]->getCollisionRect()))
            {
                colliding = true;
            }
        }

        if (Lo->isCollide(Map->getWaterfall()->getCollisionRect()))
        {
            colliding = true;
        }

        for (int i = 0; i < 4; i++)
        {
            if (Lo->isCollide(Map->getRiver1()[i]->getCollisionRect()))
            {
                colliding = true;
            }
        }

        if (step <= 200)
        {
            if (!colliding)
            {
                switch (sdlSetup->getMainEvent()->key.keysym.sym)
                {
                case SDLK_w:
                    Lo->setY(Lo->getY() - 5);
                    direction = UP;
                    prevDirection = UP;
                    *cameraY += 5;
                    step++;
                    break;
                case SDLK_a:
                    Lo->setX(Lo->getX() - 5);
                    direction = LEFT;
                    prevDirection = LEFT;
                    *cameraX += 5;
                    step++;
                    break;
                case SDLK_s:
                    Lo->setY(Lo->getY() + 5);
                    direction = DOWN;
                    prevDirection = DOWN;
                    *cameraY -= 5;
                    step++;
                    break;
                case SDLK_d:
                    Lo->setX(Lo->getX() + 5);
                    direction = RIGHT;
                    prevDirection = RIGHT;
                    *cameraX -= 5;
                    step++;
                    break;
                default:
                    break;
                }
            }
            else
            {
                switch (prevDirection)
                {
                case RIGHT:
                    Lo->setX(Lo->getX() - 1);
                    *cameraX += 1;
                    break;
                case LEFT:
                    Lo->setX(Lo->getX() + 1);
                    *cameraX -= 1;
                    break;
                case UP:
                    Lo->setY(Lo->getY() + 1);
                    *cameraY -= 1;
                    break;
                case DOWN:
                    Lo->setY(Lo->getY() - 1);
                    *cameraY += 1;
                    break;
                default:
                    break;
                }
            }
        }
    }
}

void mainCharacter::directionPlayAnimation(int passed_direction)
{
    if (passed_direction == DOWN)
    {
        Lo->playAnimation(0, 3, 0, 500.00);
    }
    else if (passed_direction == RIGHT)
    {
        Lo->playAnimation(0, 3, 1, 500.00);
    }
    else if (passed_direction == UP)
    {
        Lo->playAnimation(0, 3, 2, 500.00);
    }
    else if (passed_direction == LEFT)
    {
        Lo->playAnimation(0, 3, 3, 500.00);
    }
    else if (passed_direction == STILL)
    {
        switch (prevDirection)
        {
        case LEFT:
            Lo->playAnimation(0, 0, 3, 500.00);
            break;
        case DOWN:
            Lo->playAnimation(0, 0, 0, 500.00);
            break;
        case RIGHT:
            Lo->playAnimation(0, 0, 1, 500.00);
            break;
        case UP:
            Lo->playAnimation(0, 0, 2, 500.00);
            break;
        default:
            Lo->playAnimation(0, 0, 0, 500.00);
            break;
        }
    }
}

int mainCharacter::getATK()
{
    return attack;
}

int mainCharacter::getDEF()
{
    return defense;
}

void mainCharacter::drawHUD()
{
    sdlSetup->loadFromRenderedText("Lo", white, BAHNSCHRIFT);
    SDL_RenderCopy(sdlSetup->getRenderer(), sdlSetup->getTextTexture(), NULL, &loTextRect);
    sdlSetup->clearText();

    std::string hpString = std::to_string(hp);
    std::string maxHpString = std::to_string(maxHP);
    sdlSetup->loadFromRenderedText("HP " + hpString + '/' + maxHpString, white, BAHNSCHRIFT);
    SDL_RenderCopy(sdlSetup->getRenderer(), sdlSetup->getTextTexture(), NULL, &hpTextRect);
    sdlSetup->clearText();

    std::string mpString = std::to_string(mp);
    std::string maxMpString = std::to_string(maxMP);
    sdlSetup->loadFromRenderedText("MP " + mpString + '/' + maxMpString, white, BAHNSCHRIFT);
    SDL_RenderCopy(sdlSetup->getRenderer(), sdlSetup->getTextTexture(), NULL, &mpTextRect);
    sdlSetup->clearText();

    std::string goldString = std::to_string(gold);
    sdlSetup->loadFromRenderedText("GOLD " + goldString, white, BAHNSCHRIFT);
    SDL_RenderCopy(sdlSetup->getRenderer(), sdlSetup->getTextTexture(), NULL, &goldTextRect);
    sdlSetup->clearText();

    std::string levelString = std::to_string(level);
    sdlSetup->loadFromRenderedText("LEVEL " + levelString, white, BAHNSCHRIFT);
    SDL_RenderCopy(sdlSetup->getRenderer(), sdlSetup->getTextTexture(), NULL, &levelTextRect);
    sdlSetup->clearText();
}

int mainCharacter::getHP()
{
    return hp;
}

void mainCharacter::setHP(int passed_hp)
{
    hp = passed_hp;
}

int mainCharacter::getMP()
{
    return mp;
}

int mainCharacter::getGold()
{
    return gold;
}

void mainCharacter::setGold(int passed_gold)
{
    gold = passed_gold;
}

int mainCharacter::getExp()
{
    return experience;
}

void mainCharacter::setExp(int passed_exp)
{
    experience = passed_exp;
}

void mainCharacter::setMP(int passed_mp)
{
    mp = passed_mp;
}

int mainCharacter::getStep()
{
    return step;
}

void mainCharacter::setStep()
{
    step = 0;
}

int mainCharacter::getINT(){
    return intelligence;
}

int mainCharacter::getMaxHP(){
    return maxHP;
}

int mainCharacter::getMaxMP(){
    return maxMP;
}

int mainCharacter::getLVL(){
    return level;
}

int mainCharacter::getPotionAmout(){
    return potion.itemAmout;
}

void mainCharacter::setPotionAmout(int passed_amout){
    potion.itemAmout = passed_amout;
}

int mainCharacter::getElixirAmout(){
    return elixir.itemAmout;
}

void mainCharacter::setElixirAmout(int passed_amout){
    elixir.itemAmout = passed_amout;
}