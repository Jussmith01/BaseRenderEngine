#ifndef __MENUSTATE_INCLUDED__
#define __MENUSTATE_INCLUDED__

class MainMenuState : public State,public EventCallback
{
private:

    //********************
    //  Global Variables
    //********************
    int swidth;
    int sheight;

    //********************
    //  State Variables
    //********************
    InputStruct input;
    double dt;

    //********************
    //    State Tools
    //********************
    keyhandler kh;

    ISoundEngine* audioengine;

    //********************
    //   State Instance
    //********************
    static MainMenuState m_MainMenuState;

public:
    //***********************
    //    State Functions
    //***********************
    void Init(GrafixEngine* game);
    void Cleanup();

    void Pause();
    void Resume(GrafixEngine* game);

    void HandleEvents(GrafixEngine* game);
    void Update(GrafixEngine* game);
    void Draw(GrafixEngine* game);

    static MainMenuState* Instance()
    {
        return &m_MainMenuState;
    }

protected:

    MainMenuState() {};

private:
    //******************************
    //    Event Call Back Handling
    //******************************

    //Functions
    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
    void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    void mouse_pos_callback(GLFWwindow* window, double xpos, double ypos);
    void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
    void cursor_enter_callback(GLFWwindow* window, int entered);
};

#endif
