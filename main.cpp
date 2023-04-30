#include <iostream>
#include <fstream>
#include <vector>
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

bool shouldDisqualify(const string* spliced){
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
    ifstream ifs;
    ifs.open("small.csv");
    string line;
    // skips the first line which is just the column names
    getline(ifs, line);
    while(getline(ifs, line)){
        string *spliced = spliceSpecial(line);
        // do not add words that are less than 4 characters; too easy to brute force
        if (shouldDisqualify(spliced))
        {
            delete[] spliced;
            continue;
        }
        PartOfSpeech pos = PartOfSpeechInterpreter().fromString(spliced[2]);
        Definition d(spliced[3], pos);
        for (uchar i = 0; i < d.size(); i++){
            cout << d[i] << "$";
        }
        cout << endl;
    }
    ifs.close();
    return 0;
}