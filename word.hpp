#ifndef WORD_HPP
#define WORD_HPP

#include "definition.hpp"

class Word{
    std::string word;
    Definition* majorDefintions;
    uchar numDefinitions;
    uchar capacity;
    public:
    Word(const std::string word, const Definition define);
    uchar addDefinition(const Definition oneMoreDefinition);
    std::string getWord() const;
    
    // rule of five
    ~Word();
    Word(const Word& other);
    Word& operator=(const Word& rhs);
    Word(const Word&& other);
    Word& operator=(const Word&& rhs);
};

#endif