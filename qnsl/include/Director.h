#pragma once
#include "Application.h"
#include "Scene.h"

namespace qn
{
	class Application;
	class Director
	{
	private:
		qn::Scene* runningScene;
		Director();

	public:
		qn::Application* app;

		~Director();
		static Director* getInstance();
		qn::Scene* getRunningScene();
		void run(qn::Scene* scene);
	};
}