#include "Node.h"

qn::Node::Node() {

}

bool qn::Node::init() {
	return true;
}

void qn::Node::addChild(qn::Node* child) {
	this->children.push_back(child);
}

void qn::Node::visit() {
	for (qn::Node* child : children) {
		child->visit();
	}
}

void qn::Node::setPosition(qn::Vec2 position) {
	this->position = position;
}

qn::Vec2 qn::Node::getPosition() {
	return this->position;
}