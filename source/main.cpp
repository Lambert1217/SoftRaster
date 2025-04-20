#include "application.h"
#include "config.h"

int main(int argc, char **argv)
{
    SoftRaster::Application app("SoftRaster", WINDOW_WIDTH, WINDOW_HEIGHT);
    app.run();
}
