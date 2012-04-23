/*
Copyright 2009-2011 Jan Niklas Hasse <jhasse@gmail.com>
For conditions of distribution and use, see copyright notice in LICENSE.txt
*/


#pragma once

#ifdef WIZ
	#include <GLES/gl.h>
	#include <GLES/egl.h>
	#include <libogl.h>
#else
	#ifdef IOS
		#include <OpenGLES/ES1/gl.h>
		#include <OpenGLES/ES1/glext.h>
		#include "ios/glew.h"
	#else
		#include <GL/glew.h>
	#endif
#endif

#include <boost/function.hpp>

#ifndef GL_BGR
#define GL_BGR 0x80e0
#endif

namespace opengl
{
	inline void Translate(float x, float y) { glTranslatef(x, y, 0); }
	inline void Scale(float x, float y) { glScalef(x, y, 0); }
#ifdef GL_DOUBLE
	template<class T, class U>
	inline void Translate(T x, U y) { glTranslated(static_cast<double>(x), static_cast<double>(y), 0); }
	template<class T, class U>
	inline void Scale(T x, U y) { glScaled(static_cast<double>(x), static_cast<double>(y), 0); }
#else
	template<class T, class U>
	inline void Translate(T x, U y) { Translate(static_cast<float>(x), static_cast<float>(y)); }
	template<class T, class U>
	inline void Scale(T x, U y) { Scale(static_cast<float>(x), static_cast<float>(y)); }
#endif

	template<class T> struct Type {};

	template<>
	struct Type<float>
	{
		const static GLenum constant = GL_FLOAT;
	};

	template<>
	struct Type<double>
	{
#ifdef GL_DOUBLE
		const static GLenum constant = GL_DOUBLE;
		typedef GLdouble type;
#else
		const static GLenum constant = GL_FLOAT;
		typedef GLfloat type;
#endif
	};

#ifdef GL_DOUBLE
	typedef GLdouble CoordType;
#else
	typedef GLfloat CoordType;
#endif

	// This function gets the first power of 2 >= the int that we pass it.
	int NextPowerOf2(int);

	void BindArrayBuffer(GLuint);
}
