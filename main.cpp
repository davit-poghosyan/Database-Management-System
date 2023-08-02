#include "parser.h"

int main()
{
    DataBase::System sys;
    DataBase::Parser parser(sys);
    parser.parse();
}