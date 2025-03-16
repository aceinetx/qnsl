#include "main.h"

int main() {
	AppDelegate app = AppDelegate();
	qn::Director *director = qn::Director::getInstance();
	director->app = &app;
	director->run(MainScene::create());
}