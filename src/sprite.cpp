/*
 * sprite.cpp
 *
 *    Created on: Sep 3, 2018
 *    Author: minch.david
 */

#include "sprite.h"
#include "graphics.h"
#include "globals.h"

Sprite::Sprite()
{

}

Sprite::Sprite(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height, float posX, float posY):
    m_x(posX), m_y(posY)
{
    m_sourceRect.x = sourceX;
    m_sourceRect.y = sourceY;
    m_sourceRect.w = width;
    m_sourceRect.h = height;

    m_spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
    if(m_spriteSheet == NULL)
        printf("\nerror: Unable to load image\n");
}

Sprite::~Sprite()
{

}

void Sprite::draw(Graphics& graphics, int x, int y)
{
    SDL_Rect destRect = {x, y, m_sourceRect.w * globals::SPRITE_SCALE, m_sourceRect.h * globals::SPRITE_SCALE};
    graphics.blitSurface(m_spriteSheet, &m_sourceRect, &destRect);
}

void Sprite::update()
{

}