#include "word.hpp"

Word::Word(const std::string word, const Definition define): word{word}, size{1}, 
capacity{1}
{
    majorDefintions = new Definition[1];
    majorDefintions[0] = Definition(define);
}

/// @brief Adds a major defintion
/// @param oneMoreDefinition 
/// @return the new size of the object
uchar Word::addDefinition(const Definition oneMoreDefinition)
{
    if (this->capacity == this->size){
        uchar new_cap = this->capacity * 2;
        Definition* ns = new Definition[new_cap];
        for (uchar i = 0; i < capacity; i++){
            ns[i] = majorDefintions[i];
        }
        capacity = new_cap;
        Definition* temp = this->majorDefintions;
        majorDefintions = ns;
        delete[] temp;
    }else{
        majorDefintions[size] = oneMoreDefinition;
        size++;
    }
    return size;
}

std::string Word::getWord() const
{
    return word;
}

/// @brief Access a major definition. No bounds checking for minimum runtime.
/// @param i 
/// @return 
Definition Word::operator[](const uchar i) const
{
    return majorDefintions[i];
}

Word::~Word()
{
    delete[] majorDefintions;
}

Word::Word(const Word &other)
{
    this->capacity = other.capacity;
    this->size = other.size;
    this->majorDefintions = new Definition[this->capacity];
    for (uchar i = 0; i < this->size; i++){
        this->majorDefintions[i] = other.majorDefintions[i];
    }
}

Word &Word::operator=(const Word &rhs)
{
    if (this != &rhs){
        delete[] this->majorDefintions;
        
    }
    return *this;
}
