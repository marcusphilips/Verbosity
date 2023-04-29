#ifndef DEFINITION_HPP
#define DEFINITION_HPP

#define uchar unsigned char

/// @brief 
class Definition{
    // confusing I know but each line has multiple defintions 
    // seperated by semicolons
    char** definitions;
    // I don't think anyone line has more than 255 semicolons
    uchar numDefintions;
    Definition(char* line);
    uchar getSize() const;
    char* operator[](uchar i);
};

#endif