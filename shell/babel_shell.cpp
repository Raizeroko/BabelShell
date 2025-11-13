#include "babel_shell.h"

void shell::ShellClient::view(){
    std::cout << "welcome to use NLP_Shell!!!!" << std::endl;
    std::cout << "NLP_Shell >>>";
}

std::string shell::ShellClient::translateCommand(std::string command){
}

void shell::ShellClient::execute(std::string command){
    std::vector<std::string> args_list = utils::StringUtils::parseCommand(command);
    if (args_list.empty())
    {
        return;
    }
    std::vector<char *> argv;
    for (const std::string &s : args_list)
    {
        argv.push_back(const_cast<char *>(s.c_str()));
    }
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("fork");
        return;
    }

    if (pid == 0)
    {
        execvp(argv[0], argv.data());
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    else
    {
        int status;
        waitpid(pid, &status, 0);
    }
}