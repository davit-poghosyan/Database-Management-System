#include "system.h"

void DataBase::System::create(const std::string& name, std::vector<std::string> parametrs) {
    std::ofstream fout;
    fout.open(name);
    if (!fout.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return;
    }

    fout << "#\t";

    for (int i = 0; i < parametrs.size(); ++i) {
        fout << parametrs[i] << "\t\t\t\t\t\t\t";
    }
    
    fout.close();
    tables[name] = 0;
}

void DataBase::System::insert(const std::string& name, std::vector<std::string> parametrs)
{
    auto it = tables.find(name);
    if (it == tables.end()) {
        std::cerr << "missing filename\n";
        return;
    }

    std::ofstream fout;
    fout.open(name, std::ios::app);
    if (!fout.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return;
    }

    fout << "\n";


    fout << ++tables[name] << "\t";

    for (int i = 0; i < parametrs.size(); ++i) {
        
        fout << parametrs[i] << "\t\t\t\t\t\t\t";
    }
     //fout << "\n";

    fout.close();
    
   
}


void DataBase::System::clear(const std::string& name, int index)
{
    auto it = tables.find(name);
    if (it != tables.end()) {
        if (index > tables[name]) {
            std::cerr << "file name not found\n"; 
            return;
        }
        std::ifstream fin;
        fin.open(name);
        if (!fin.is_open()) {
            std::cerr << "Error opening the file." << std::endl;
            return;
        }
        std::map<std::string, std::string> content;
        std::string line;
        while(std::getline(fin, line)) {
            size_t pos = line.find('\t');

            std::string key = line.substr(0, pos);
            content[key] = line;
        }

        std::string id = std::to_string(index);
        auto chlp = content.find(id);    
     
        std::ofstream fout;
        fout.open(name, std::ios::out);
        if (!fout.is_open()) {
            std::cerr << "file filed to open";
        }

 
        for (const auto& it : content) {
            if (it.first == id) {
                continue;
            }   
            fout << it.second << "\n";
        }
        fout.close();
    }

}
