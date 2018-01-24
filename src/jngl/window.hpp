// Copyright 2012-2018 Jan Niklas Hasse <jhasse@bixense.com>
// For conditions of distribution and use, see copyright notice in LICENSE.txt

#pragma once

#include <string>

#include "dll.hpp"

#ifndef _MSC_VER
#pragma GCC visibility push(default)
#endif

namespace jngl {

void JNGLDLL_API showWindow(const std::string& title, int width, int height,
                            bool fullscreen = false);

void JNGLDLL_API hideWindow();

int JNGLDLL_API getWindowWidth();

int JNGLDLL_API getWindowHeight();

int JNGLDLL_API getDesktopWidth();

int JNGLDLL_API getDesktopHeight();

bool JNGLDLL_API getFullscreen();

void JNGLDLL_API setFullscreen(bool);

} // namespace jngl

#ifndef _MSC_VER
#pragma GCC visibility pop
#endif
