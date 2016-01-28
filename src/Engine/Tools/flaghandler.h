#ifndef __FLAGHANDLER_INCLUDED__
#define __FLAGHANDLER_INCLUDED__

#include <vector>
#include <string>

//      *************************************************************     //
//                            Flag Handler Class
//                  	    Handles all input flags
//      *************************************************************     //
/*

*/
class flagHandler
{
    //--------------------------
    //   Vector to hold flags
    //--------------------------
    std::vector<std::string> flags;

    //------------------------------
    //Private Member Class Functions
    //------------------------------
    void m_flagParser()
    {
        //Set Defaults
        nosplash=false;

        for (int i=1; i<(int)flags.size(); ++i)
        {
            // -ns flag causes the launch to skip the splash screen
            if (flags[i].compare("-ns")==0) {nosplash=true;}
        }
    };

public:
    //--------------------------
    //     Public Variable
    //--------------------------
    bool nosplash;

    //-----------------------------
    //	Class Constructor
    //-----------------------------
    flagHandler () {};

    void Init(int argc, char *argv[])
    {
        for (int i=0; i<argc; ++i)
        {
            flags.push_back(argv[i]);
        }

        m_flagParser();
    };
};
#endif

