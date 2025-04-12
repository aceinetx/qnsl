#pragma once
#include "Vec2.h"
#include <cassert>
#include <vector>

#define CREATE_FUNC(_class)                                                                                                                                                                                                                                    \
	static _class* create() {                                                                                                                                                                                                                                    \
		_class* res = new _class();                                                                                                                                                                                                                                \
		assert(res->init() == true);                                                                                                                                                                                                                               \
		return res;                                                                                                                                                                                                                                                \
	}

namespace qn {
class Node {
private:
	qn::Vec2 position;
	std::vector<Node*> children;

public:
	Node();

	virtual bool init();
	virtual void visit();
	qn::Vec2 getPosition();
	void setPosition(qn::Vec2 position);
	void addChild(Node* child);

	CREATE_FUNC(qn::Node);
};
} // namespace qn