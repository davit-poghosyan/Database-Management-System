#ifndef PARSER_H
#define PARER_H

#include "system.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <cstdarg>
#include <sstream>

namespace DataBase {

    class Parser
    {
    private:
        std::vector<std::string> functons;
        DataBase::System system;
    public:
        explicit Parser(DataBase::System sys) {
            functons.push_back("create");
            functons.push_back("insert");
            functons.push_back("clear");
            system = sys;
        }
        void parse();
        
    };
}


#endif