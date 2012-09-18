/*
Copyright 2012 Jan Niklas Hasse <jhasse@gmail.com>
For conditions of distribution and use, see copyright notice in LICENSE.txt
*/

#include "input.hpp"

#include "../windowptr.hpp"

namespace jngl {
	void setKeyPressed(key::KeyType key, bool p) {
		pWindow->setKeyPressed(key, p);
	}

	void setKeyPressed(const std::string& key, bool p) {
		pWindow->setKeyPressed(key, p);
	}
}