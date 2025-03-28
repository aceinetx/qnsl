#include "MainScene.h"
#include "PixelNode.h"

bool MainScene::init() {
	if (!qn::Scene::init())
		return false;

	auto node = qn::PixelNode::create('X');
	node->setPosition({1, 1});
	auto node1 = qn::PixelNode::create('Y');
	node1->setPosition({2, 1});

	this->addChild(node);
	this->addChild(node1);

	return true;
}
