#pragma once

#include "SDL.h"
#include "Vector2D.h"
#include <vector>

enum mouse_button {
  LEFT = 0,
  MIDDLE = 1,
  RIGHT = 2
};

class InputHandler{
public:
  ~InputHandler() {}
  static InputHandler* Instance(){
    if(s_pInstance == 0){
      s_pInstance = new InputHandler();
    }
    return s_pInstance;
  }
  bool isKeyDown(SDL_Scancode key);  
  bool getMouseButtonState(int buttonNumber);
  Vector2D* getMousePosition();

  void onMouseMove(SDL_Event event);
  void onMouseButtonDown(SDL_Event event);
  void onMouseButtonUp(SDL_Event  event);
  void onKeyDown();
  void onKeyUp();

  void update();
  void clean() {}

private:
  InputHandler();
  static InputHandler* s_pInstance;
  const Uint8* m_keystates;
  
  std::vector<bool> m_mouseButtonStates;
  Vector2D* m_mousePosition;
};

typedef InputHandler TheInputHandler;