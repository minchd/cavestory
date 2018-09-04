/*
 * graphics.h
 *
 *    Created on: Sep 1, 2018
 *    Author: minch.david
 */

#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;

class Graphics
{
  public:
    Graphics();
    ~Graphics();

    /* work flow is as follows:
     * whatever is on m_renderer will get drawn when we update
     * So we call clear then blitSurface to put something on m_renderer
     * and finally flip to flip or draw the next screen
     */
    SDL_Surface* loadImage(const std::string &filePath);
    void blitSurface(SDL_Texture* texture, SDL_Rect* sourceRect, SDL_Rect* destRect);
    void flip();
    void clear();

    SDL_Renderer* getRenderer() const;

  private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    std::map<std::string, SDL_Surface*> m_spriteSheets;

};

#endif /* GRAPHICS_H_ */
