// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main () {
    stringstream ss;
    string line;
    int a = 0;
    int b = 0;
    int c = 0;

    string word;
    int sum = 0;

    ifstream myfile ("/Users/boazraz/Code/CSCI-240/ParsingFileIO/input.txt");
    ofstream outFile("/Users/boazraz/Code/CSCI-240/ParsingFileIO/sum.txt");

    if (myfile.is_open())
    {
        while ( getline (myfile,line, ','))
        {

            if (line.empty()) continue;

            ss.clear();
            ss.str ("");
            while (ss << line)      //if not at end of file, continue reading numbers
            {
                ss << line << '\n';
                ss >> a >> b >> c >> word;
                sum = a + b +c;
                cout << " this is a: " << a << endl;
                cout << " this is b: " << b << endl;
                cout << " this is c: " << c << endl;
                cout << " sum: " << sum << endl;
                for (int i = 0; i < sum ; ++i) {
                    cout << word << ",";
                    outFile << word  << ",";

                }

            }

        }

        myfile.close();
        outFile.close();
    }

    else cout << "Unable to open file";

    return 0;
}