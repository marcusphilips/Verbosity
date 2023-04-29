#include "partOfSpeech.hpp"

/// @brief Converts string please strip quotes in the beginning and in the end
/// @param input 
/// @return PartOfSpeech state
PartOfSpeech PartOfSpeechInterpreter::fromString(const std::string input)
{
    /*
    NOUN,
    PRONOUN,
    VERB,
    ADJECTIVE,
    ADVERB,
    PREPOSITION,
    IRRELEVANT
    */
    // Apparently you can't use switch statements with strings or const char*
    if (input == "n.")
        return NOUN;
    if (input == "obj.")
        // don't ask me why; the data is scraped from a dictionary from 1910 or so
        return PRONOUN;
    if (input == "v. t." || input == "v. i.")
        return VERB;
    if (input == "a.")
        return ADJECTIVE;
    if (input == "adv.")
        return ADVERB;
    if (input == "prep.")
        return PREPOSITION;
    else
        // there are other parts of speech but they are too niche or I am too lazy to look up
        return IRRELEVANT;
}

std::string PartOfSpeechInterpreter::toString(const PartOfSpeech part)
{
    /*
    NOUN,
    PRONOUN,
    VERB,
    ADJECTIVE,
    ADVERB,
    PREPOSITION,
    IRRELEVANT
    */
    switch (part)
    {
    case NOUN:
        return "noun";
    case PRONOUN:
        return "pronoun";
    case VERB:
        return "verb";
    case ADJECTIVE:
        return "adjective";
    case ADVERB:
        return "adverb";
    case PREPOSITION:
        return "preposition";
    default:
        return "";
    }
}
