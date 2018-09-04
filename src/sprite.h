/*
 * sprite.h
 *
 *    Created on: Sep 3, 2018
 *    Author: minch.david
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include <SDL2/SDL.h>
#include <string>

class Graphics;


class Sprite
{
public:
  Sprite();
  Sprite(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);

  virtual ~Sprite();
  virtual void update();
  void draw(Graphics& graphics, int x, int y);
private:
  SDL_Rect m_sourceRect;
  SDL_Texture* m_spriteSheet;
  float m_x, m_y;
};


#endif