#pragma once
#include "Node.h"

namespace qn {
class Scene : public qn::Node {
public:
	bool init() override;

	CREATE_FUNC(Scene);
};
} // namespace qn