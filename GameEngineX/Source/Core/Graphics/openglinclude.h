#ifndef OPENGLINCLUDE_H
#define OPENGLINCLUDE_H

#ifdef OPEN_GL_DESKTOP
#include <GL/glew.h>
//#include <GL/gl.h>
#else
#include <OpenGLES/ES3/gl.h>
#include <OpenGLES/ES3/glext.h>
#endif
#endif // OPENGLINCLUDE_H
