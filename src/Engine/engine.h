#ifndef __GRAPHIX_ENGINE_INCLUDED__
#define __GRAPHIX_ENGINE_INCLUDED__

#include <irrKlang.h>
#include <ik_ISound.h>
using namespace irrklang;

#include <string>
#include <vector>

// GLEW -- Includes OGL headers
#define GLEW_STATIC
#include <GL/glew.h>

#include <GL/glu.h>

// GLFW
#include <GLFW/glfw3.h>

#include "Loaders/properties.h"
#include "Tools/flaghandler.h"

// Forward Declares
class GLFWwindow;
class State;

//*************************************************
//                 Engine Class
//*************************************************
class GrafixEngine {
public:
    void Init(std::string enginetitle,int argc,char *argv[]);
    void Cleanup();

    void ChangeState(State* state);
    void PushState(State* state);
    void PopState();

    void HandleEvents();
    void Update();
    void Draw();

    bool Running() {
        return m_running;
    };

    void Quit() {
        m_running = false;
    };

    /* GL Contexts */
    GLFWwindow* window;
    GLFWwindow* resource_context;

    ISoundEngine* audioengine;
    Properties props;
    flagHandler flaghandler;

private:
    // the stack of states
    std::vector<State*> states;

    bool m_running;
    bool m_fullscreen;
};

#endif
