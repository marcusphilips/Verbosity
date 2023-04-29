#include "definition.hpp"

/// @brief Default Constructor; Do Not Use
Definition::Definition() : definitions{nullptr}, numDefintions{0}
{
}

/// @brief The good constructor
/// @param line 
Definition::Definition(const std::string line) : numDefintions{1}
{
    for (size_t i = 0; i < line.size(); i++){
        if (line[i] == ';')
            numDefintions++;
    }
    // allocate new memory
    definitions = new std::string[numDefintions];
    // just one definition 
    if (numDefintions == 1){
        definitions[0] = line;
        return;
    }
    std::string truncate = line;
    for (uchar i = 0; i < numDefintions; i++){
        // at the last splice
        if (i + 1 == numDefintions)
            definitions[i] = truncate;
        else {
            definitions[i] = truncate.substr(0, truncate.find(';'));
            truncate = truncate.substr(truncate.find(';') + 1);
        }
    }
}

uchar Definition::size() const
{
    return numDefintions;
}

std::string Definition::operator[](const uchar i) const
{
    return definitions[i];
}

Definition::~Definition()
{
    delete[] definitions;
}

Definition::Definition(const Definition &other)
{
    this->numDefintions = other.numDefintions;
    this->definitions = new std::string[numDefintions];
    for(uchar i = 0; i < this->numDefintions; i++){
        this->definitions[i] = other.definitions[i];
    }
}

Definition &Definition::operator=(const Definition &rhs)
{
    // TODO: insert return statement here
    if (this != &rhs){
        
    }
    return *this;
}
