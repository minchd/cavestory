/*
 * input.h
 *
 *    Created on: Sep 1, 2018
 *    Author: minch.david
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <SDL2/SDL.h>
#include <map>



class Input
{
public:
  Input();
  ~Input();

  void beginNewFrame();
  void keyUpEvent(const SDL_Event& event);
  void keyDownEvent(const SDL_Event& event);

  bool wasKeyPressed(SDL_Scancode key);
  bool wasKeyReleased(SDL_Scancode key);
  bool isKeyHeld(SDL_Scancode key);


private:
  std::map<SDL_Scancode, bool> m_heldKeys;
  std::map<SDL_Scancode, bool> m_pressedKeys;
  std::map<SDL_Scancode, bool> m_releasedKeys;

};

#endif /* INPUT_H_ */
