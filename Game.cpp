#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

    if(m_pWindow != 0)
    {
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

      if(m_pRenderer != 0)
      {
        SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
      }
      else
      {
        return false;
      }
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }

  m_bRunning = true;

  //texture 생성
  SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/rider.bmp");

  m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
  
  SDL_FreeSurface(pTempSurface);

  SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);//원본상자 너비, 넓이 설정
  m_sourceRectangle.x = 0;
  m_sourceRectangle.y = 0;

  m_sourceRectangle.w = 50;
  m_sourceRectangle.h = 50;

  m_destinationRectangle.w = m_sourceRectangle.w;
  m_destinationRectangle.h = m_sourceRectangle.h;

  m_destinationRectangle.x = 0;
  m_destinationRectangle.y = 0;

  return true;
}

void Game::update()
{
}

void Game::render()
{
  SDL_RenderClear(m_pRenderer);
  
  SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);

  SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
  return m_bRunning;
}

void Game::handleEvents()
{
  SDL_Event event;
  if (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_QUIT:
        m_bRunning = false;
        break;
      defaault:
        break;
    }
  }
}

void Game::clean()
{
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}