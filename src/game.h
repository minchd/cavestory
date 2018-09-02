/*
 * game.h
 *
 *    Created on: Sep 1, 2018
 *    Author: minch.david
 */

#ifndef GAME_H_
#define GAME_H_

class Graphics;

class Game
{
public:
  Game();
  ~Game();
private:
  void gameLoop();
  void draw(Graphics &graphics);
  void update(float elapsedTime);
};

#endif /* GAME_H_ */
