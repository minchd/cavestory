/*
 * graphics.cpp
 *
 *    Created on: Sep 1, 2018
 *    Author: minch.david
 */

#include <SDL2/SDL.h>
#include "graphics.h"


Graphics::Graphics()
{
  SDL_CreateWindowAndRenderer(640, 480, 0, &m_window, &m_renderer);
  SDL_SetWindowTitle(m_window, "Cavestory");

}

Graphics::~Graphics()
{
  SDL_DestroyWindow(m_window);
}
