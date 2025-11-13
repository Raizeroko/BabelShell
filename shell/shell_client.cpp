#include "babel_shell.h"

int main(){
    shell::ShellClient* client = new shell::ShellClient;
    
    while(true){
        client->view();
        std::string command;
        getline(std::cin, command);
        // std::cout << command;
        client->translateCommand(command);
        client->execute(command);
    }
    return 0;
}