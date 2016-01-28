#include "../engine.h"
#include "tools.hpp"

#include "inputcontrol.h"

//************************************
//      The Key Handler Functions
//************************************

/* Constructor */
keyhandler::keyhandler() {
    for(int i=0; i<1024; ++i)
        chkset[i]=false;
};

/* Check the state of a key */
bool keyhandler::CheckKeyState(bool keyval,int keyidx) {
    bool rtn;
    if(!chkset[keyidx]) {
        if(keyval) {
            chkset[keyidx]=true;
        }
        rtn=false;
    } else {
        if(keyval) {
            rtn=false;
        } else {
            rtn=true;
            chkset[keyidx]=false;
        }
    }
    return rtn;
};

//************************************
//      The Input Controller Functions
//************************************

void InputStruct::Init(GrafixEngine *game) {
    // Register the game Engine with the clasee
    this->game=game;

    // Initialize all keys to false
    for (int i=0; i<1024; ++i) {
        keys[i]=false;
    }

    // Initialize all mouse keys to false
    for (int i=0; i<8; ++i) {
        mousekeys[i]=false;
    }

    //Initialize positions
    mx=0.0f;
    my=0.0f;
    sx=0.0f;
    sy=0.0f;
};

//***********************
// Keyboard Key Handling
//***********************
/*
SetKeyTrue - Sets the given key(i) to true
SetKeyFalse - Sets the given key(i) to false
GetKey - Get the truth value of the given key(i)
GetKeyAndReset - Get the truth value of the
                 given key and reset it. Good
                 for non-repeat buttons.
*/
void InputStruct::SetKeyTrue(int i) {
    keys[i]=true;
};

void InputStruct::SetKeyFalse(int i) {
    keys[i]=false;
};

bool InputStruct::GetKey(int i) {
    return keys[i];
};

bool InputStruct::GetKeyAndReset(int i) {
    bool rtn=keys[i];
    keys[i]=false;
    return rtn;
};

//********************
// Mouse Key Handling
//********************
/*
SetMouseKeyTrue - Sets the given key(i) to true
SetMouseKeyFalse - Sets the given key(i) to false
GetMouseKey - Get the truth value of the given key(i)
GetMouseKeyAndReset - Get the truth value of the
                      given key and reset it. Good
                      for non-repeat buttons.
*/
void InputStruct::SetMouseKeyTrue(int i) {
    mousekeys[i]=true;
};

void InputStruct::SetMouseKeyFalse(int i) {
    mousekeys[i]=false;
};

bool InputStruct::GetMouseKey(int i) {
    return mousekeys[i];
};

bool InputStruct::GetMouseKeyAndReset(int i) {
    bool rtn=mousekeys[i];
    mousekeys[i]=false;
    return rtn;
};


//**********************
// Mouse Input Handling
//**********************
/*
SetMouseGLFW - Sets the position of the mouse in
               Normalized Device Coordinates using
               glfwGetCursorPos() function.
SetMousePosPDC - Sets the mouse pos given Pixel
                 Device Coordinates(PDC), converts
                 to Normalized Device Coordinates
                 NDC.
SetMousePosNDC - Sets the mouse pos given NDC.
ReturnMousePos - Returns the mouse pos, always
                 works in NDC.

*/
void InputStruct::SetMouseGLFW() {
    double xpos;
    double ypos;
    glfwGetCursorPos(game->window,&xpos,&ypos);
    tools::normal_device_coordinate(xpos,ypos,game->props.WinWidth,game->props.WinHeight); // Convert mouse coords to NDC
    mx=xpos;
    my=ypos;
};

void InputStruct::SetMousePosPDC(double x,double y) {
    double xpos=x;
    double ypos=y;
    //std::cout << xpos << " " << ypos <<  std::endl;
    tools::check_mouse_reset(game->window,xpos,ypos,game->props.WinWidth,game->props.WinHeight,0.0f); // Prevent mouse from leaving window
    tools::normal_device_coordinate(xpos,ypos,game->props.WinWidth,game->props.WinHeight); // Convert mouse coords to NDC
    mx=xpos;
    my=ypos;
};

void InputStruct::SetMousePosNDC(double x,double y) {
    mx=x;
    my=y;
};

void InputStruct::ReturnMousePos(double &x,double &y) {
    x=mx;
    y=my;
};

//*********************
//Scroll Input Handling
//*********************
/*
SetScrollPos - Sets the position of the scrolling
ReturnScrollPos - Returns the position of the scrolling
*/
void InputStruct::SetScrollPos(double x,double y) {
    sx+=x;
    sy+=y;
};

void InputStruct::ReturnScrollPos(double &x,double &y) {
    x=sx;
    y=sy;
};
