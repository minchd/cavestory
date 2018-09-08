/*
 * game.cpp
 *
 *    Created on: Sep 1, 2018
 *    Author: minch.david
 */
#include <SDL2/SDL.h>
#include "game.h"
#include "graphics.h"
#include "input.h"


const int FPS = 50;
const int MAX_FRAME_TIME = 5*1000 / FPS;

Game::Game ()
{
  SDL_Init(SDL_INIT_EVERYTHING);
  this->gameLoop();

}

Game::~Game ()
{
  // TODO Auto-generated destructor stub
}

void Game::gameLoop()
{
  Graphics graphics;
  Input input;
  SDL_Event event;

  m_player = AnimatedSprite(graphics, "./content/sprites/MyChar.png", 0, 0, 16, 16, 100, 100, 100);
  m_player.setupAnimation();
  m_player.playeAnimation("RunRight");

  int LAST_UPDATE_TIME = SDL_GetTicks();

  while(true)
  {
    input.beginNewFrame();
    if(SDL_PollEvent(&event))
    {
      if(event.type == SDL_KEYDOWN)
      {
        if(event.key.repeat == false)
          input.keyDownEvent(event);
      }
      else if(event.type == SDL_KEYUP)
        input.keyUpEvent(event);
      else if(event.type == SDL_QUIT) return;
    }
    if(input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true)
      return;

    const int CURRENT_TIME_MS = SDL_GetTicks();
    int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
    this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
    LAST_UPDATE_TIME = CURRENT_TIME_MS;

    draw(graphics);
  }

}


void Game::draw(Graphics &graphics)
{
  graphics.clear();
  m_player.draw(graphics, 100, 100);
  graphics.flip();
}


void Game::update(float elapsedTime)
{
  m_player.update(elapsedTime);
}
