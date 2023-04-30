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
    public:
    static PartOfSpeech fromString(const std::string input);
    static std::string toString(const PartOfSpeech part);
};

#endif