#include <iostream>
#include <string>
#include <sys/wait.h>
#include "utils.h"


namespace shell{
    class ShellClient{
    public:
        void view();
        std::string translateCommand(std::string command);
        void execute(std::string command);
    };
} // shell