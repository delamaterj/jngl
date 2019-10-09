// Copyright 2017-2019 Jan Niklas Hasse <jhasse@bixense.com>
// For conditions of distribution and use, see copyright notice in LICENSE.txt

#pragma once

#include "input.hpp"

namespace jngl {

/// Object representing one Gamepad controller
class JNGLDLL_API Controller {
public:
	virtual ~Controller() = default;

	/// Returns a value between 0.0f (not pressed) and 1.0f (pressed)
	float state(controller::Button) const;

	/// Returns true when the button is down
	virtual bool down(controller::Button) const = 0;

	/// Returns true only once for every button press
	bool pressed(controller::Button);

	/// 0 = no vibration, 1 = maximum
	virtual void setVibration(float);

private:
	virtual float stateImpl(controller::Button) const = 0;

	bool buttonPressed[jngl::controller::Last];
};

} // namespace jngl
