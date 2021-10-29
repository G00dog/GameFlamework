#pragma once

#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject 
{
public:
  SDLGameObject(const LoaderParams* pParams);
  virtual void draw();
  virtual void update();// 원래 update() {}임 오류떠서 임시수정
  virtual void clean() {}
  virtual ~SDLGameObject() {}

protected:
  Vector2D m_position;

  int m_width;
  int m_height;
  int m_currentRow;
  int m_currentFrame;
  std::string m_textureID;
};