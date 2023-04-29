#ifndef WORD_HPP
#define WORD_HPP

#include "definition.hpp"

class Word{
    std::string word;
    Definition* majorDefintions;
    uchar numDefinitions;
    uchar capacity;
    public:
    Word(std::string word, Definition define);
    uchar addDefinition(Definition oneMoreDefinition);
    std::string getWord() const;
};

#endif