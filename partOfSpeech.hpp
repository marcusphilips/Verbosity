#ifndef PARTOFSPEECH_HPP
#define PARTOFSPEECH_HPP

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
    static char* toString(const PartOfSpeech part);
};

#endif