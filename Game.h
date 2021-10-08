#ifndef __Game__
#define __Game__

#include "SDL.h"
#include "TextureManager.h"

class Game{
public:
  Game() {}
  ~Game() {}

  bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
  void render();
  void update();
  bool running();
  void handleEvents();
  void clean();

private:
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  SDL_Texture* m_pTexture;
  //SDL_Rect m_sourceRectangle; //원본 사각형
  //SDL_Rect m_destinationRectangle; //대상 사각형

  TextureManager m_textureManager;
  int m_currentFrame;
  
  bool m_bRunning;
};

#endif