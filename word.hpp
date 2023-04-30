#ifndef WORD_HPP
#define WORD_HPP

#include "definition.hpp"

class Word
{
    std::string word;
    Definition *majorDefintions;
    uchar size;
    uchar capacity;

public:
    Word(const std::string word, const Definition &define);
    uchar addDefinition(const Definition oneMoreDefinition);
    std::string getWord() const;
    Definition operator[](const uchar i) const;

    // rule of five
    ~Word();
    Word(const Word &other);
    Word &operator=(const Word &rhs);
    Word(Word &&other);
    Word &operator=(Word &&rhs);
};

#endif