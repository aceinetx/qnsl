#include "Director.h"

qn::Director::Director()
{
	this->app = nullptr;
}

qn::Director::~Director()
{
}

qn::Director *qn::Director::getInstance()
{
	static Director instance;
	return &instance;
}

qn::Scene *qn::Director::getRunningScene()
{
	return this->runningScene;
}

void qn::Director::run(qn::Scene *scene)
{
	this->runningScene = scene;
	assert(this->app != nullptr);

	auto renderer = Renderer::getInstance();

	while (true)
	{
		// clear();

		renderer->render();

		refresh();
	}
}