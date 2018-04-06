#include "App.h"
using namespace std;

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;
    t = 0;
    lastT = 0;
    delta = 0.0;

    game = new Game();
}

void App::idle(){
    t = glutGet(GLUT_ELAPSED_TIME);
    
    delta = t - lastT;

    // Update and redraw the scene when specified timestep passed
    if(delta >= 1000/TARGET_FPS){
        // Uncomment to cout fps to console
        //cout << "FPS: " << 1000/delta << endl; 

        lastT = t;
        game->update(delta);
        redraw();
    }

}

void App::draw() {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //Draw gamepieces
    game->draw();

    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();

}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }
}