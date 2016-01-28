#include <string>
#include <vector>

// GLEW -- Includes OGL headers
#define GLEW_STATIC
#include <GL/glew.h>

#include <GL/glu.h>

// GLFW
#include <GLFW/glfw3.h>

// Loaders
#include "../Loaders/properties.h"

// Tools
#include "../Tools/flaghandler.h"
#include "../Tools/inputcontrol.h"

// Engine and bases
#include "../state.h"
#include "../eventcallback.h"
#include "../engine.h"

#include "MenuStates/mainmenustate.h"

#include "introstate.h"

// Instance of state
IntroState IntroState::m_IntroState;

void IntroState::Init(GrafixEngine *game)
{
    IntroState::stateID = "Intro";
    EntChk=false;

    //Disable Cursor
    glfwSetInputMode(game->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    //glfwSetKeyCallback(window, key_callback);
    setEventHandling();

    //glfwSetKeyCallback(game->window, EventStateBase::keycallback_dispatch);
    glfwSetKeyCallback(game->window, EventCallback::keycallback_dispatch);
};

void IntroState::Cleanup()
{

};

void IntroState::Pause()
{

};

void IntroState::Resume(GrafixEngine* game)
{

};

void IntroState::HandleEvents(GrafixEngine* game)
{
    glfwPollEvents();

    // Move to next state after 5 seconds
    if (glfwGetTime() > 5.0)
    {
        game->ChangeState( MainMenuState::Instance() );
    };

    // Move to next state if enter is pressed
    if (EntChk)
    {
        game->ChangeState( MainMenuState::Instance() );
    };
};

void IntroState::Update(GrafixEngine* game)
{

};

void IntroState::Draw(GrafixEngine* game)
{
    // Render
    // Clear the colorbuffer
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT);

    // Swap the screen buffers or NULL to remove the currently set callback.
    //glfwSwapInterval(1); //Vsync this state
    //glfwSwapBuffers(game->window);
};

//Function handles key callbacks
void IntroState::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if(key == GLFW_KEY_SPACE && action == GLFW_PRESS)
        EntChk=true;
};

//Function handles mouse button callbacks
void IntroState::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{

};

//Function handles mouse movement callbacks
void IntroState::mouse_pos_callback(GLFWwindow* window, double xpos, double ypos)
{

};

//Function handles mouse scroll callbacks
void IntroState::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{

};

//Function handles mouse enter and exit
void IntroState::cursor_enter_callback(GLFWwindow* window, int entered)
{

};
