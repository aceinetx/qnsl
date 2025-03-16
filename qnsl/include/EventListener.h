#pragma once
#include "qnsl.h"

namespace qn {

	class EventListener {
	private:
		std::vector < std::function<void(int key)>> keyboardListeners;

		EventListener();
	public:
		~EventListener();
		static qn::EventListener* getInstance();
	};
}