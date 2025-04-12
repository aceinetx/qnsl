#pragma once
#include "Node.h"
#include "Renderer.h"
#include <cassert>

namespace qn {
class PixelNode : public qn::Node {
public:
	char pixel;

	bool init();
	void visit();

	CREATE_FUNC(PixelNode);
	static PixelNode* create(char pixel);
};
} // namespace qn