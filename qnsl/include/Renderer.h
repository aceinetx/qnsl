#pragma once
#include <curses.h>
#include "Vec2.h"
#include "Director.h"

namespace qn
{
  class Renderer
  {
  public:
    static Renderer *getInstance();
    ~Renderer();

    void plotPixel(Vec2 coords, char pixel);
    void render();

  private:
    Renderer();
  };
}