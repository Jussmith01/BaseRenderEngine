// C/C++ Includes
#include <iostream>

// Engine Includes
#include "engine.h"
#include "state.h"

//***************************************
// GLFW Error Handling Callback Function
//***************************************
void glfw_error_callback(int error, const char* description) {
    std::cerr << "GLFW Error Detected: " << std::endl;
    std::cerr << description << std::endl;
};

//**********************************
//Initializes the GL Engine via GLFW
//**********************************
/*
This function initializes,

init flaghandler
init glfw
init props
init glew
create audioengine

This function initializes the gl window
via the glfwCreateWindow call. All the
window properties are set after this
using the parameters set in the props
class or just using default parameters.
*/
void GrafixEngine::Init(std::string enginetitle,int argc,char *argv[]) {
    m_running=true;

    std::cout << "Initializing Engine: " << enginetitle << std::endl;

    flaghandler.Init(argc,argv);

    // Init GLFW
    glfwInit();

    //Set error handling callback
    glfwSetErrorCallback(glfw_error_callback);

    //Initialize the Properties class. This loads all properties from the bin/config.cfg file.
    props.init();

    unsigned glmajv(3);
    unsigned glminv(3);

    std::cout << "Starting GLFW " << glfwGetVersionString() << " context, OpenGL " << glmajv << "." << glminv << std::endl;

    // Set all the required options for GLFW^M
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, glmajv);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, glminv);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_SAMPLES, props.MSAA);

    //Initialize Window
    switch(props.FullScreen) {
    case 0: {
        window = glfwCreateWindow(props.WinWidth, props.WinHeight, "OpenGL Engine", nullptr, nullptr);
        break;
    }
    case 1: {
        window = glfwCreateWindow(props.WinWidth, props.WinHeight, "OpenGL Engine", glfwGetPrimaryMonitor(), nullptr);
        break;
    }
    }

    if( window == NULL ) {
        std::cerr << "Failed to open GLFW window." << std::endl;
        glfwTerminate();
    }

    glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
    //offscreen_context1 = glfwCreateWindow(1, 1, "", nullptr, nullptr);

    glfwMakeContextCurrent(window);
    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions^M
    glewExperimental = GL_TRUE;

    // Initialize GLEW to setup the OpenGL Function pointers
    glewInit();

    // Define the viewport dimensions^M
    glViewport(0, 0, props.WinWidth, props.WinHeight);

    //Setup OpenGL Options
    //glEnable(GL_DEPTH_TEST);
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //Poly Fill Mode
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

    //Setup Audio Engine
    audioengine = createIrrKlangDevice();
    if (!audioengine) {
        std::cout << "IrrKlang Failed to Start..." << std::endl;
    } else {
        std::cout << "IrrKlang Started" << std::endl;
    }
};

//**********************************
//  Final Cleanup of States and GL
//**********************************
/*
This function cleans up all of the classes
*/
void GrafixEngine::Cleanup() {
    std::cout << "Engine Cleanup..." << std::endl;

    // cleanup all states
    while ( !states.empty() ) {
        states.back()->Cleanup();
        states.pop_back();
    }

    //Terminate Audio
    audioengine->drop();

    std::cout << "Exiting..." << std::endl;
    //Terminate GLFW
    glfwTerminate();
};

//****************************************
//Deletes current state and loads the next
//****************************************
void GrafixEngine::ChangeState(State* state) {
    // Cleanup the current states
    while ( !states.empty() ) {
        states.back()->Cleanup();
        states.pop_back();
    }

    // Store and Init the new state
    states.push_back(state);
    states.back()->Init(this);
};

//*****************************************
//Pause the current state and load the next
//*****************************************
void GrafixEngine::PushState(State* state) {
    // pause current state
    if ( !states.empty() ) {
        states.back()->Pause();
    }

    // store and init the new state
    states.push_back(state);
    states.back()->Init(this);
};

//******************************
//Pop back to the previous state
//******************************
void GrafixEngine::PopState() {
    // cleanup the current state
    if ( !states.empty() ) {
        states.back()->Cleanup();
        states.pop_back();
    }

    // resume previous state
    if ( !states.empty() ) {
        states.back()->Resume(this);
    }
};

//******************************
//Handle current state events
//******************************
void GrafixEngine::HandleEvents() {
    // let the state handle events
    states.back()->HandleEvents(this);
};

//******************************
//Update current states data
//******************************
void GrafixEngine::Update() {
    // let the state update the game
    states.back()->Update(this);
};

//**********************************
//Draw current states data to window
//**********************************
void GrafixEngine::Draw() {
    // let the state draw the screen
    states.back()->Draw(this);

    // Swap the screen buffers or NULL to remove the currently set callback.
    glfwSwapInterval(1); //Vsync this state
    glfwSwapBuffers(window);
};
