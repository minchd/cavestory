/*
 * graphics.h
 *
 *    Created on: Sep 1, 2018
 *    Author: minch.david
 */

#ifndef GRAPHICS_H_
#define GRAPHICS_H_

struct SDL_Window;
struct SDL_Renderer;

class Graphics
{
  public:
    Graphics();
    ~Graphics();

  private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;

};

#endif /* GRAPHICS_H_ */
