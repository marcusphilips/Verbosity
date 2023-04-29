#include <iostream>
#include <fstream>
#include "definition.hpp"

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
        spliced[2] = spliced->substr(3, spliced->size() - 6);
    spliced[3] = spliced->substr(3);
    return spliced;
}

int main(/*int argc, char** argv*/)
{
    ifstream ifs;
    ifs.open("small.csv");
    string line;
    getline(ifs, line);
    string *spliced = spliceSpecial(line);
    for (uchar i = 0; i < 4; i++)
    {
        cout << spliced[i] << endl;
    }
    return 0;
}