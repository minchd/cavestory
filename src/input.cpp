/*
 * input.cpp
 *
 *    Created on: Sep 1, 2018
 *    Author: minch.david
 */

#include "input.h"

Input::Input ()
{
  // TODO Auto-generated constructor stub

}

Input::~Input ()
{
  // TODO Auto-generated destructor stub
}

void Input::beginNewFrame()
{
  this->m_pressedKeys.clear();
  this->m_releasedKeys.clear();
}

void Input::keyUpEvent(const SDL_Event& event)
{
  this->m_releasedKeys[event.key.keysym.scancode] = true;
  this->m_releasedKeys[event.key.keysym.scancode] = true;
}

void Input::keyDownEvent(const SDL_Event& event)
{
  this->m_pressedKeys[event.key.keysym.scancode] = true;
  this->m_heldKeys[event.key.keysym.scancode] = false;
}

bool Input::wasKeyPressed(SDL_Scancode key)
{
  return this->m_pressedKeys[key];
}

bool Input::wasKeyReleased(SDL_Scancode key)
{
  return this->m_releasedKeys[key];
}

bool Input::isKeyHeld(SDL_Scancode key)
{
  return this->m_heldKeys[key];
}

