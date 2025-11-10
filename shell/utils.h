#include <string>
#include <vector>
#include <sstream>
namespace utils{
    class StringUtils{
    public:
        // 解析命令参数
        static std::vector<std::string> parseCommand(const std::string& command) {
            std::vector<std::string> args;
            std::stringstream ss(command);
            std::string token;
            while (ss >> token) {
                args.push_back(token); 
            }
            return args;
        }
    };


} // utils
