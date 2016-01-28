// GLFW
#include <GLFW/glfw3.h>

#include "eventcallback.h"

//*****************************************//
//          State Base Functions           //
//*****************************************//
EventCallback *EventCallback::event_handling_instance;

//Key Callback Function
void EventCallback::keycallback_dispatch(GLFWwindow *window,int key,int scancode,int action,int mods) {
    if(event_handling_instance)
        event_handling_instance->key_callback(window,key,scancode,action,mods);
};

//Mouse Button Callback Function
void EventCallback::mousebuttoncallback_dispatch(GLFWwindow* window, int button, int action, int mods) {
    if(event_handling_instance)
        event_handling_instance->mouse_button_callback(window,button,action,mods);
};

//Mouse Position Callback Function
void EventCallback::mouseposcallback_dispatch(GLFWwindow* window, double xpos, double ypos) {
    if(event_handling_instance)
        event_handling_instance->mouse_pos_callback(window,xpos,ypos);
};

//Scroll Callback Function
void EventCallback::scrollcallback_dispatch(GLFWwindow* window, double xoffset, double yoffset) {
    if(event_handling_instance)
        event_handling_instance->scroll_callback(window,xoffset,yoffset);
};

//Mouse enter/exit Callback Function
void EventCallback::mouseentercallback_dispatch(GLFWwindow* window, int entered) {
    if(event_handling_instance)
        event_handling_instance->cursor_enter_callback(window,entered);
};

