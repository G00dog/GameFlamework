//완료된 실습
//상속, 다향성, 유일객체 Game, 추상 Class

#include "Game.h"
#include <iostream>

Game* g_game = 0;

int main(int argc, char* argv[])
{
  if(TheGame::Instance()->init("Chapter 1", 100, 100, 640, 480, false))
  {
    while(TheGame::Instance()->running())
    {
      TheGame::Instance()->handleEvents();
      TheGame::Instance()->update();
      TheGame::Instance()->render();
      SDL_Delay(10);
    }
  }
  else
  {
    std::cout<<"game init failure "<<SDL_GetError()<<"\n";
    return -1;
  }
  TheGame::Instance()->clean();
  return 0;
}