#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include "definition.hpp"
#include "word.hpp"
#include "partOfSpeech.hpp"

using namespace std;

string *spliceSpecial(const string line)
{
    string *spliced = new string[4];
    string truncate = line;
    for (uchar i = 0; i < 3; i++)
    {
        spliced[i] = truncate.substr(0, truncate.find(','));
        truncate = truncate.substr(truncate.find(',') + 1);
    }
    spliced[3] = truncate;
    if (spliced[2].size() == 6)
        spliced[2] = "";
    else
        spliced[2] = spliced[2].substr(3, spliced[2].size() - 6);
    spliced[3] = spliced[3].substr(3, spliced[3].size() - 6);
    return spliced;
}

bool shouldDisqualify(const string *spliced)
{
    // word is too small
    if (spliced[0].size() < 4)
        return true;
    // word is too big
    if (spliced[0].size() > 16)
        return true;

    return false;
}

int main(/*int argc, char** argv*/)
{
    vector<Word> dictionary;
    dictionary.reserve(145000);
    ifstream ifs;
    // in retrospect maybe using a dictionary that was based off and printed in 1913
    // was not the best choiceh
    ifs.open("dictionary.csv");
    string line;
    // skips the first line which is just the column names
    getline(ifs, line);
    while (getline(ifs, line))
    {
        string *spliced = spliceSpecial(line);
        // do not add words that are less than 4 characters; too easy to brute force
        if (shouldDisqualify(spliced))
        {
            delete[] spliced;
            continue;
        }
        string part = spliced[2];
        if (part.find('&') != string::npos)
        {
            part = part.substr(0, part.find('&') - 1);
        }
        PartOfSpeech pos = PartOfSpeechInterpreter().fromString(part);
        if (pos == IRRELEVANT)
        {
            // cout << "Invalid Part of Speech: " << part << endl;
            delete[] spliced;
            continue;
        }
        Definition d(spliced[3], pos);
        // change the first character of the word to all lowercase
        spliced[0][0] += 32;
        if (!dictionary.empty() && dictionary.back().getWord() == spliced[0]){
            dictionary.back().addDefinition(d);
        }
        else{
            Word w = Word(spliced[0], d);
            dictionary.push_back(w);
        }
        delete[] spliced;
        // cout << dictionary.back().getWord() << endl;
    }
    sort(dictionary.begin(), dictionary.begin() + dictionary.size());
    // is our dictionary.csv out of sequence?
    // Yes, somewhat it is but it is too much work to sort the csv file so I'll just leave
    // the program to sort it even though it costs some runtime
    random_device rd;
    unsigned seed1 = chrono::system_clock::now().time_since_epoch().count();
    // some one on stack overflow said this was the better RNG
    mt19937 g1(seed1);
    const Word ANSWER = dictionary.at((int)(((double)g1() / (double)g1.max()) * dictionary.size()));
    cout << ANSWER.getWord() << endl;
    cout << "Here are some clues:\n"
         << "The word is a(n) " << PartOfSpeechInterpreter().toString(ANSWER[0].getPartOfSpeech())
         << "\nOne defintion of the word is " << ANSWER[0][0];
    for (uchar i = 1; i < ANSWER.getSize(); i++){
        cout << "\nAnother definition of the word is " << ANSWER[i][0] << endl;
    }
    cout << "\nThis word has " << (int)ANSWER.getSize() << " different meaning(s)."
         << "\nThe word begins with the letter \"" << ANSWER.getWord().at(0) << "\"" << endl;
    while (true)
    {
        cout << "Guess an answer:" << endl;
        string input;
        cin >> input;
        if (input == ANSWER.getWord())
        {
            cout << "You've found the answer!" << endl;
            break;
        }
        else if (input < ANSWER.getWord())
        {
            cout << "Go Down" << endl;
        }
        else
        {
            cout << "Go Up" << endl;
        }
    }
    return 0;
}