#ifndef __EVENT_CALLBACK_INCLUDED__
#define __EVENT_CALLBACK_INCLUDED__

class GLFWwindow;

//*****************************************//
//             Event Callback              //
//*****************************************//
//This base allows for use of member       //
//functions to be used as glfw callback    //
//functions.                               //
//*****************************************//
class EventCallback {
    //Keyboard Functions
    virtual void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) = 0;

    //Mouse functions
    virtual void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) = 0;
    virtual void mouse_pos_callback(GLFWwindow* window, double xpos, double ypos) = 0;
    virtual void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) = 0;
    virtual void cursor_enter_callback(GLFWwindow* window, int entered) = 0;

    static EventCallback * event_handling_instance;
    // technically setEventHandling should be finalized so that it doesn't
    // get overwritten by a descendant class.

public:
    virtual void setEventHandling() {
        event_handling_instance = this;
    };

    //Key Callback Function
    static void keycallback_dispatch(GLFWwindow *window,int key,int scancode,int action,int mods);

    //Mouse Button Callback Function
    static void mousebuttoncallback_dispatch(GLFWwindow* window, int button, int action, int mods);

    //Mouse Position Callback Function
    static void mouseposcallback_dispatch(GLFWwindow* window, double xpos, double ypos);

    //Scroll Callback Function
    static void scrollcallback_dispatch(GLFWwindow* window, double xoffset, double yoffset);

    //Mouse enter/exit Callback Function
    static void mouseentercallback_dispatch(GLFWwindow* window, int entered);
};

#endif
