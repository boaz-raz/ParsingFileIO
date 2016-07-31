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

    ifstream myFile("input.txt");
    ofstream outFile("sum.txt");

    if (myFile.is_open())
    {
        while ( getline (myFile,line, ','))
        {

            if (line.empty()) continue;

            ss.clear();
            ss.str ("");
            while (ss << line)   // while we read more lines sum the ints and print the words * int
            {
                ss << line << '\n';
                ss >> a >> b >> c >> word;
                sum = a + b +c;

                // This is for testing
                cout << " this is a: " << a << endl;
                cout << " this is b: " << b << endl;
                cout << " this is c: " << c << endl;
                cout << " sum: " << sum << endl;
                // end testing print out

                outFile << endl << endl << "Sum of: " << word << ": is "<< sum;
                outFile << endl;
                for (int i = 0; i < sum ; ++i) {
                    cout << word << ",";
                    outFile << word  << ",";

                }

            } //

        } // end while getline

        myFile.close();
        outFile.close();
    } // end if file is open

    else cout << "Unable to open file";

    return 0;
} // end main