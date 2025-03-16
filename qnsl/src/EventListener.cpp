#include "EventListener.h"

qn::EventListener::EventListener() {

}

qn::EventListener::~EventListener() {

}

qn::EventListener* qn::EventListener::getInstance() {
	static qn::EventListener instance;
	return &instance;
}