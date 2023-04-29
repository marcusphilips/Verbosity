#include <iostream>
#include <fstream>
#include <vector>
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
        spliced[2] = spliced[2].substr(3, spliced[2].size() - 6);
    spliced[3] = spliced[3].substr(3, spliced[3].size() - 7);
    return spliced;
}

int main(/*int argc, char** argv*/)
{
    ifstream ifs;
    ifs.open("dictionary.csv");
    string line;
    while(getline(ifs, line)){
        string *spliced = spliceSpecial(line);
        Definition d(spliced[3]);
                  
        for (uchar i = 0; i < d.size(); i++){
            cout << d[i] << "$ ";
        }
        cout << endl;
        
    }
    return 0;
}