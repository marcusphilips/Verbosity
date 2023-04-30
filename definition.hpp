#ifndef DEFINITION_HPP
#define DEFINITION_HPP
#include <string>
#include "partOfSpeech.hpp"

#define uchar unsigned char

/// @brief 
class Definition{
    // confusing I know but each line has multiple defintions 
    // seperated by semicolons
    std::string* definitions;
    // I don't think anyone line has more than 255 semicolons
    uchar numDefintions;
    PartOfSpeech pos;
    public:
    Definition();
    Definition(const std::string line, const PartOfSpeech pos);
    
    uchar size() const;
    std::string operator[](const uchar i) const;
    PartOfSpeech getPartOfSpeech() const;

    // rule of five

    ~Definition();
    Definition(const Definition& other);
    Definition& operator=(const Definition& rhs);
    Definition(Definition&& other);
    Definition& operator=(Definition&& rhs);
};

#endif