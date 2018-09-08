/*
 * animatedSprite.cpp
 *
 *    Created on: Sep 7, 2018
 *    Author: minch.david
 */

#include "animatedSprite.h"
#include "graphics.h"


AnimatedSprite::AnimatedSprite()
{
}

AnimatedSprite::AnimatedSprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY, float timeToUpdate):
  Sprite(graphics, filePath, sourceX, sourceY, width, height, posX, posY),
  m_frameIndex(0),
  m_timeToUpdate(timeToUpdate),
  m_visible(true),
  m_currentAnimationOnce(false),
  m_currentAnimation("")
{
}

void AnimatedSprite::addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset)
{
  std::vector<SDL_Rect> rectangles;
  for(int i = 0; i < frames; i++)
  {
    SDL_Rect newRect = {(i + x) * width, y, width, height};
    rectangles.push_back(newRect);
  }
  m_animations[name] = rectangles;
  m_offsets[name] = offset;
}

void AnimatedSprite::resetAnimation()
{
  m_animations.clear();
  m_offsets.clear();
}

void AnimatedSprite::stopAnimation()
{
  m_frameIndex = 0;
  animationDone(m_currentAnimation);
}

void AnimatedSprite::setVisible(bool visible)
{
  m_visible = visible;
}

void AnimatedSprite::playeAnimation(std::string animation, bool once) 
{
  m_currentAnimationOnce = once;
  if(m_currentAnimation != animation)
  {
    m_currentAnimation = animation;
    m_frameIndex = 0;
  }
}

void AnimatedSprite::update(int elapsedTime)
{
  Sprite::update();
  m_timeElapsed += elapsedTime;
  if(m_timeElapsed > m_timeToUpdate)
  {
    m_timeElapsed -= m_timeToUpdate;
    if(m_frameIndex < m_animations[m_currentAnimation].size() - 1)
    {
      m_frameIndex++;
    }
    else
    {
      if(m_currentAnimationOnce)
        setVisible(false);
      
      m_frameIndex = 0;
      animationDone(m_currentAnimation);
    }
  }
}

void AnimatedSprite::draw(Graphics &graphics, int x, int y)
{
  if(m_visible)
  {
    SDL_Rect destRect;
    destRect.x = x + m_offsets[m_currentAnimation].x;
    destRect.y = y + m_offsets[m_currentAnimation].y;
    destRect.w = m_sourceRect.w * globals::SPRITE_SCALE;
    destRect.h = m_sourceRect.h * globals::SPRITE_SCALE;

    SDL_Rect sourceRect = m_animations[m_currentAnimation][m_frameIndex];
    graphics.blitSurface(m_spriteSheet, &sourceRect, &destRect);
  }
}

void AnimatedSprite::setupAnimation()
{
  addAnimation(3, 0, 0, "RunLeft", 16,16,Vector2(0,0));
  addAnimation(3, 0, 16, "RunRight", 16,16,Vector2(0,0));
}

void AnimatedSprite::animationDone(std::string currentAnimation)
{

}