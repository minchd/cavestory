/*
 * animatedSprite.h
 *
 *    Created on: Sep 1, 2018
 *    Author: minch.david
 */

#ifndef ANIMATEDSPRITE_H_
#define ANIMATEDSPRITE_H_

#include <map>
#include <vector>
#include <string>
#include "sprite.h"
#include "globals.h"

class Graphics;

class AnimatedSprite : public Sprite
{
public:
  AnimatedSprite();
  AnimatedSprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY, float timeToUpdate);

  void playeAnimation(std::string animation, bool once = false);
  void update(int elapsedTime);
  void draw(Graphics &graphics, int x, int y);
  virtual void setupAnimation();

protected:
  double m_timeToUpdate;
  bool m_currentAnimationOnce;
  std::string m_currentAnimation;

  void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);

  void resetAnimation();

  void stopAnimation();

  void setVisible(bool visible);

  virtual void animationDone(std::string currentAnimation);



private:
  std::map<std::string, std::vector<SDL_Rect> > m_animations;
  std::map<std::string, Vector2> m_offsets;
  int m_frameIndex;
  double m_timeElapsed;
  bool m_visible;
};

#endif