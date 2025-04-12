#include "PixelNode.h"

bool qn::PixelNode::init() {
	if (!Node::init())
		return false;

	return true;
}

void qn::PixelNode::visit() {
	Node::visit();

	Renderer::getInstance()->plotPixel(getPosition(), pixel);
}

qn::PixelNode* qn::PixelNode::create(char pixel) {
	PixelNode* res = new PixelNode();
	assert(res->init() != false);
	res->pixel = pixel;
	return res;
}
