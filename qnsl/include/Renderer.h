#pragma once
#include "Director.h"
#include "Vec2.h"

namespace qn {
class Renderer {
public:
	static Renderer *getInstance();
	~Renderer();

	void plotPixel(Vec2 coords, char pixel);
	void render();

private:
	Renderer();
};
} // namespace qn
