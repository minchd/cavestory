/*
 * graphics.cpp
 *
 *    Created on: Sep 1, 2018
 *    Author: minch.david
 */


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "graphics.h"
#include "globals.h"


Graphics::Graphics()
{
  SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &m_window, &m_renderer);
  SDL_SetWindowTitle(m_window, "Cavestory");

}

Graphics::~Graphics()
{
  SDL_DestroyWindow(m_window);
}

SDL_Surface* Graphics::loadImage(const std::string &filePath)
{
  if(m_spriteSheets.count(filePath) == 0)
  {
    m_spriteSheets[filePath] = IMG_Load(filePath.c_str());
  }
  return m_spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRect, SDL_Rect* destRect)
{
  SDL_RenderCopy(m_renderer, texture, sourceRect, destRect);
}

void Graphics::flip()
{
  SDL_RenderPresent(m_renderer);
}

void Graphics::clear()
{
  SDL_RenderClear(m_renderer);
}

SDL_Renderer* Graphics::getRenderer() const
{
  return m_renderer;
}