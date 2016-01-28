#ifndef __INPUT_CONTROL_INCLUDED__
#define __INPUT_CONTROL_INCLUDED__

class GrafixEngine;

//************************************
//      The Key Handler Struct
//************************************
/*
This type can be used to return when a
key has been press has been pressed then
released. It works by calling

        CheckKeyState(bool arg)

with an argument (arg) of type bool. This
function returns false until the following
occurs: arg=true then at a later time
arg=false, upon reading the latter arg=false
the function returns true then resets. This
prevents holding a button and getting multiple
trues with just a single press of the button,
while at the same time allowing this to be
fixed within a class of your choice rather
than at the event handler level.
*/
struct keyhandler
{
    private:

    bool chkset[1024];

    public:
    keyhandler();

    /* Check The Keys State */
    bool CheckKeyState(bool keyval,int keyidx);
};

//************************************
//      The Input Handler Struct
//************************************
/*
This stuct is used for passing input data
around the program so that event handling
can be carried out centrally within a
given state.
*/
class InputStruct
{
    // Basic Variables
    bool keys[1024]; // Keyboard Keys
    bool mousekeys[8]; //Mouse Keys
    double mx,my; // Mouse Position
    double sx,sy; // Scroll Position

    // Basic Motion Tracking

    GrafixEngine *game;

public:

    InputStruct() {};

    void Init(GrafixEngine *game);

    void SetKeyTrue(int i);

    void SetKeyFalse(int i);

    bool GetKey(int i);

    bool GetKeyAndReset(int i);

    void SetMouseKeyTrue(int i);

    void SetMouseKeyFalse(int i);

    bool GetMouseKey(int i);

    bool GetMouseKeyAndReset(int i);

    void SetMouseGLFW();

    void SetMousePosPDC(double x,double y);

    void SetMousePosNDC(double x,double y);

    void ReturnMousePos(double &x,double &y);

    void SetScrollPos(double x,double y);

    void ReturnScrollPos(double &x,double &y);
};

#endif
