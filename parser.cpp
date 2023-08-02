#include "parser.h"

void DataBase::Parser::parse()
{
    do {    
        std::string line;
        std::getline(std::cin, line);
        
        auto CommandPos = line.find(' ');
        std::string command = line.substr(0, CommandPos);


        line.erase(0, ++CommandPos);
        auto FileNamePos = line.find(' ');
        std::string fileName = line.substr(0, FileNamePos);
        

        line.erase(0, ++FileNamePos);


        std::vector<std::string> parameters;
        
        std::string parameter;

        std::stringstream ss(line);
        std::string word;

        while (ss >> word) {
            parameters.push_back(word);
        }


        if (command == "create") {
            system.create(fileName, parameters);
        }
        else if (command == "insert") {
            system.insert(fileName, parameters);
        }
        else if (command == "delete") {
            system.clear(fileName, std::stoi(parameters[0]));   
        }
        else if (command == "exit") {
            std::cout << "see your tables\n";
            return;
        }
        else {
            std::cerr << "command not found\n";
        }
    } while (1);
    
}
