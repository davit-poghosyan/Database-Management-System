# Database-Management-System


This is a basic implementation of a Database Management System (DBMS) in C++. The system allows users to create tables, insert data into tables, and clear data from tables.
Files

## Compilation

To compile the database management system, use the following command:



    g++ system.cpp parser.cpp main.cpp -o dbms_executable

## Usage

  Run the compiled executable (dbms_executable) in the terminal.

  The program will prompt you to enter commands. Available commands are:
        
        create <table_name> <column1> <column2> ...: Create a new table with the given name and columns.
        insert <table_name> <value1> <value2> ...: Insert data into an existing table.
        delete <table_name> <index>: Clear data at the specified index from an existing table.
        exit: Exit the program.

Enter your commands as per the provided format. For example:


    create employees name age salary
    insert employees John 30 50000
    insert employees Alice 28 45000
    delete employees 1
    exit

The program will execute your commands accordingly and display any relevant messages.

## Notes

    This DBMS is a simple implementation and does not support advanced features like data types, constraints, indexing, etc.
    The data is stored in plain text files, one file for each table, in the same directory as the executable.
