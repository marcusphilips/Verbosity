#include "word.hpp"

Word::Word(const std::string word, const Definition &define) : word(word), size{1},
                                                               capacity{1}
{
    // make first letter lowercase
    majorDefintions = new Definition[1];
    majorDefintions[0] = Definition(define);
}

/// @brief Adds a major defintion
/// @param oneMoreDefinition
/// @return the new size of the object
uchar Word::addDefinition(const Definition& oneMoreDefinition)
{
    if (this->capacity == this->size)
    {
        uchar new_cap = this->capacity * 2;
        Definition *ns = new Definition[new_cap];
        for (uchar i = 0; i < capacity; i++)
        {
            ns[i] = majorDefintions[i];
        }
        capacity = new_cap;
        Definition *temp = this->majorDefintions;
        majorDefintions = ns;
        delete[] temp;
        size++;
    }
    else
    {
        majorDefintions[size] = oneMoreDefinition;
        size++;
    }
    return size;
}

uchar Word::getSize() const
{
    return this->size;
}

std::string Word::getWord() const
{
    return word;
}

/// @brief Access a major definition.
/// @param i
/// @return
Definition Word::operator[](const uchar i) const
{
    if (i >= size)
        throw std::invalid_argument("Out of bounds");
    return majorDefintions[i];
}

bool Word::operator<(const Word &rhs) const
{
    return this->word < rhs.word;
}

Word::~Word()
{
    delete[] majorDefintions;
}

Word::Word(const Word &other)
{
    this->word = other.word;
    this->capacity = other.capacity;
    this->size = other.size;
    this->majorDefintions = new Definition[this->capacity];
    for (uchar i = 0; i < this->size; i++)
    {
        this->majorDefintions[i] = other.majorDefintions[i];
    }
}

/// @brief Assignment Constructor
/// @param rhs
/// @return
Word &Word::operator=(const Word &rhs)
{
    if (this != &rhs)
    {
        delete[] this->majorDefintions;
        this->word = rhs.word;
        this->capacity = rhs.capacity;
        this->size = rhs.size;
        this->majorDefintions = new Definition[rhs.capacity];
        for (uchar i = 0; i < this->size; i++)
        {
            this->majorDefintions[i] = rhs.majorDefintions[i];
        }
    }
    return *this;
}

Word::Word(Word &&other)
{
    this->word = other.word;
    this->capacity = other.capacity;
    this->size = other.size;
    this->majorDefintions = other.majorDefintions;
    other.majorDefintions = nullptr;
}

Word &Word::operator=(Word &&rhs)
{
    if (this != &rhs)
    {
        this->majorDefintions = rhs.majorDefintions;
        this->capacity = rhs.capacity;
        this->size = rhs.size;
        this->word = rhs.word;
        rhs.majorDefintions = nullptr;
    }
    return *this;
}
