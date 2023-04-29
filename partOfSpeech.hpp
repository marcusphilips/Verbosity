#ifndef PARTOFSPEECH_HPP
#define PARTOFSPEECH_HPP
#include <string>

enum PartOfSpeech{
    NOUN,
    PRONOUN,
    VERB,
    ADJECTIVE,
    ADVERB,
    PREPOSITION,
    IRRELEVANT
};

class PartOfSpeechInterpreter{
    static PartOfSpeech fromString(const char* input);
    static std::string toString(PartOfSpeech part);
};

#endif