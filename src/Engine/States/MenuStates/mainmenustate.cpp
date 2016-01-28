#include <string>
#include <vector>

// GLEW -- Includes OGL headers
#define GLEW_STATIC
#include <GL/glew.h>

#include <GL/glu.h>

// GLFW
#include <GLFW/glfw3.h>

// Loaders
#include "../../Loaders/properties.h"

// Tools
#include "../../Tools/flaghandler.h"
//#include "../../Tools/tools.hpp"
#include "../../Tools/inputcontrol.h"

// Engine and Bases
#include "../../state.h"
#include "../../eventcallback.h"
#include "../../engine.h"

// States
#include "../introstate.h"

#include "mainmenustate.h"

MainMenuState MainMenuState::m_MainMenuState;

void MainMenuState::Init(GrafixEngine *game) {
    MainMenuState::stateID = "MainMenu";

    input.Init(game);

    // Setup Cursor
    //cursor.Init("Cursors/testcursor.png",0.05f,0.05f,game->props.WinWidth,game->props.WinHeight);

    // glfwSetKeyCallback(window, key_callback);
    setEventHandling();

    glfwSetKeyCallback(game->window, EventCallback::keycallback_dispatch);
    glfwSetMouseButtonCallback(game->window, EventCallback::mousebuttoncallback_dispatch);
    glfwSetCursorPosCallback(game->window, EventCallback::mouseposcallback_dispatch);
    glfwSetScrollCallback(game->window, EventCallback::scrollcallback_dispatch);
    glfwSetCursorEnterCallback(game->window, EventCallback::mouseentercallback_dispatch);

    dt=glfwGetTime();
    //Disable Cursor
    //glfwSetInputMode(game->window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

    //Save point to the audio engine
    audioengine=game->audioengine;
};

void MainMenuState::Cleanup() {
    //cursor.Cleanup (); // Cleanup Cursor
};

void MainMenuState::Pause() {

};

void MainMenuState::Resume(GrafixEngine* game) {
    setEventHandling();

    glfwSetKeyCallback(game->window, EventCallback::keycallback_dispatch);
    glfwSetMouseButtonCallback(game->window, EventCallback::mousebuttoncallback_dispatch);
    glfwSetCursorPosCallback(game->window, EventCallback::mouseposcallback_dispatch);
    glfwSetScrollCallback(game->window, EventCallback::scrollcallback_dispatch);
    glfwSetCursorEnterCallback(game->window, EventCallback::mouseentercallback_dispatch);

    input.SetMouseGLFW();
};

void MainMenuState::HandleEvents(GrafixEngine* game) {
    glfwPollEvents();

    if (input.GetKey(256)) {
        game->Quit();
    }
};

void MainMenuState::Update(GrafixEngine* game) {
    dt=glfwGetTime()-dt;
};

void MainMenuState::Draw(GrafixEngine* game) {
    // Render
    glClearColor(0.33f, 0.33f, 0.33f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT);

    // Draw Mouse Cursor
    //cursor.DrawImagePos(input.mx,input.my);

    // Swap the screen buffers
    //glfwSwapBuffers(game->window);
    //glFlush();
    //glFinish();
};

//Function handles key callbacks
void MainMenuState::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if(action == GLFW_PRESS)
        input.SetKeyTrue(key);
    else if(action == GLFW_RELEASE)
        input.SetKeyFalse(key);
};

//Function handles mouse button callbacks
void MainMenuState::mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if(action == GLFW_PRESS)
        input.SetMouseKeyTrue(button);
    else if(action == GLFW_RELEASE)
        input.SetMouseKeyFalse(button);
};

//Function handles mouse movement callbacks
void MainMenuState::mouse_pos_callback(GLFWwindow* window, double xpos, double ypos) {
    //Save mouse position for rendering
    //std::cout << "MOUSE x: " << xpos << " y: " << ypos << std::endl;
    input.SetMousePosPDC(xpos,ypos); // Set mouse pos in input struct.
};

//Function handles mouse scroll callbacks
void MainMenuState::scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    //std::cout << "SCROLL x: " << xoffset << " y: " << yoffset << std::endl;
    input.SetScrollPos(xoffset,yoffset); // Set scroll pos in input struct
};

//Function handles mouse enter and exit
void MainMenuState::cursor_enter_callback(GLFWwindow* window, int entered) {

};
