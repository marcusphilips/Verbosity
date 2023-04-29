#include "word.hpp"

Word::Word(const std::string word, const Definition define): word{word}, numDefinitions{1}, 
capacity{1}
{
    majorDefintions = new Definition[1];
    majorDefintions[0] = Definition(define);
}

std::string Word::getWord() const
{
    return word;
}