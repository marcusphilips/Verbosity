#include "definition.hpp"

/// @brief Default Constructor; Do Not Use
Definition::Definition() : definitions{nullptr}, numDefintions{0}, pos{IRRELEVANT}
{
}

/// @brief The good constructor
/// @param line
Definition::Definition(const std::string line, const PartOfSpeech pos) : numDefintions{1}, pos(pos)
{
    // count the number of semicolons ie subdefs
    for (size_t i = 0; i < line.size(); i++)
    {
        if (line[i] == ';')
            numDefintions++;
    }
    // allocate new memory
    definitions = new std::string[numDefintions];
    // just one definition
    if (numDefintions == 1)
    {
        definitions[0] = line;
        return;
    }
    std::string truncate = line;
    for (uchar i = 0; i < numDefintions; i++)
    {
        // at the last splice
        if (i + 1 == numDefintions)
            definitions[i] = truncate;
        else
        {
            definitions[i] = truncate.substr(0, truncate.find(';'));
            // skip the space that comes after the semicolon
            truncate = truncate.substr(truncate.find(';') + 2);
        }
    }
}

uchar Definition::size() const
{
    return numDefintions;
}

std::string Definition::operator[](const uchar i) const
{
    if (i >= numDefintions)
        throw std::invalid_argument("Out of bounds");
    return definitions[i];
}

PartOfSpeech Definition::getPartOfSpeech() const
{
    return this->pos;
}

/// @brief Destructor
Definition::~Definition()
{
    delete[] definitions;
}

/// @brief Copy Constructor
/// @param other
Definition::Definition(const Definition &other)
{
    this->numDefintions = other.numDefintions;
    this->definitions = new std::string[numDefintions];
    this->pos = other.pos;
    for (uchar i = 0; i < this->numDefintions; i++)
    {
        this->definitions[i] = other.definitions[i];
    }
}

/// @brief Assignment operator
/// @param rhs
/// @return
Definition &Definition::operator=(const Definition &rhs)
{
    // TODO: insert return statement here
    if (this != &rhs)
    {
        this->numDefintions = rhs.numDefintions;
        this->pos = rhs.pos;
        // delete old data
        delete[] this->definitions;
        this->definitions = new std::string[this->numDefintions];
        for (uchar i = 0; i < numDefintions; i++)
        {
            this->definitions[i] = rhs.definitions[i];
        }
    }
    return *this;
}

/// @brief Move Constructor
/// @param other
Definition::Definition(Definition &&other)
{
    this->definitions = other.definitions;
    this->numDefintions = other.numDefintions;
    this->pos = other.pos;
    other.definitions = nullptr;
}

/// @brief Move Assignment
/// @param rhs
/// @return
Definition &Definition::operator=(Definition &&rhs)
{
    if (this != &rhs)
    {
        this->numDefintions = rhs.numDefintions;

        delete[] this->definitions;
        this->pos = rhs.pos;
        this->definitions = rhs.definitions;
        rhs.definitions = nullptr;
    }
    return *this;
}
