#ifndef __INTROSTATE_INCLUDED__
#define __INTROSTATE_INCLUDED__

class IntroState : public State,public EventCallback {
private:
    //*****************
    // State Variables
    //*****************
    bool EntChk;

    //***********************
    // UI Call Back Handling
    //***********************
    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
    void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    void mouse_pos_callback(GLFWwindow* window, double xpos, double ypos);
    void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
    void cursor_enter_callback(GLFWwindow* window, int entered);

    //*********************
    // IntroState Instance
    //*********************
    static IntroState m_IntroState;

public:
    //*****************
    // State Functions
    //*****************
    /*
    The Engine virtual functions inherit
    these functions for every state.
    */
    void Init(GrafixEngine* game);
    void Cleanup();

    void Pause();
    void Resume(GrafixEngine* game);

    void HandleEvents(GrafixEngine* game);
    void Update(GrafixEngine* game);
    void Draw(GrafixEngine* game);

    static IntroState* Instance()
    {
        return &m_IntroState;
    }

protected:

    IntroState() {};
};

#endif
