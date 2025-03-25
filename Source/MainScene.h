#pragma once
#include "Scene.h"

class MainScene : public qn::Scene {
public:
	bool init() override;

	CREATE_FUNC(MainScene);
};
