#include "QtOpenGL/QGLFormat"
#include "QtOpenGL/QGLFramebufferObject"
#include "QtOpenGL/QGLPixelBuffer"

#include "App.h"

using namespace SideCar::GUI::ESScope;

int
main(int argc, char* argv[])
{
    App* app = new App(argc, argv);

    // Must have OpenGL to do anything useful
    //
    if (! QGLFormat::hasOpenGL()) {
	qWarning("This system has no OpenGL support.");
	return -1;
    }

    app->restoreWindows();
    return app->exec();
}
