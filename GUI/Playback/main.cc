#include "App.h"

using namespace SideCar::GUI;
using namespace SideCar::GUI::Playback;

int
main(int argc, char** argv)
{
    App* app = new App(argc, argv);
    app->restoreWindows();
    return app->exec();
}
