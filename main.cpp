#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;
/*
 * Note: for some reason I can only use only cin>> to obtain input or only getline();
 * using both of them in the same file for some reason does not work...using cin>> followed by getline() completely
 * skipped over prompting me for input
 *
 */

int main() {
    ifstream inputFileStream;
    string userPhrase;
    string fileLine;
    string fileName;
    int phraseFreq=0;
    bool run=true;


    while(run) {

        try {
            cout << "Enter the name of the file you would like to open: " << endl;

            getline(cin, fileName);

            inputFileStream.open(fileName); //open the file
            if (!inputFileStream.is_open()) { //make sure file was successfully opened
                throw runtime_error("Could not open file, ");
            }

            cout << "Enter user phrase to search for: " << endl;
            getline(cin, userPhrase);


            while (inputFileStream.good()) {
                getline(inputFileStream, fileLine); //

                if (fileLine.substr(0, userPhrase.length()) == userPhrase) {
                    phraseFreq += 1;
                }

            }
            cout << "The phrase " << "\"" << userPhrase << "\"" << " appears in the file " << phraseFreq << " times."
                 << endl;


            inputFileStream.close();

        } catch(runtime_error& except){
            cout<<except.what();
            cout<<"please try again"<<endl;
        }
    }





    return 0;
}
