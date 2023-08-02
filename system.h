#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <cstdarg>
#include <sstream>

namespace DataBase {
    
    class System
    {
    private:
        std::map<std::string, int> tables;
    public:
        System() {};
        ~System() {};
        
        
        void create(const std::string& name, std::vector<std::string> parametrs);
        void insert(const std::string& name, std::vector<std::string> parametrs);
        void clear(const std::string& name, int index);
    };

}
#endif