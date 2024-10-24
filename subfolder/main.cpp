#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main() {
    // Setting up the window with OpenGL settings
    ofGLFWWindowSettings settings;
    settings.setSize(1024, 768);         // Set window size
    settings.windowMode = OF_WINDOW;     // Window mode can be OF_WINDOW or OF_FULLSCREEN

    // Create the window using the settings
    shared_ptr<ofAppBaseWindow> window = ofCreateWindow(settings);

    // Start the application
    ofRunApp(window, make_shared<ofApp>());
    ofRunMainLoop();
}

