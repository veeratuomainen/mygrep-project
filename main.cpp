#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void printLines(string filename, string searchStr, int num) {
    ifstream newFile;
    string searchFrom;
    int lineNumber = 1;
    int lineCounter = 0;

    newFile.open(filename, ios::in);

    if (newFile.is_open()) {
        bool ans = false;

        while (getline(newFile, searchFrom)) {
            size_t isFound = searchFrom.find(searchStr);

            if (isFound != string::npos) {
                if (num == 1 || num == 4) {
                    cout << searchFrom << endl;
                    ans = true;
                }
                else if (num == 2 || num == 3) {
                    cout << lineNumber << ": " << searchFrom << endl;
                    ans = true;
                }
                lineCounter++;
            }
            lineNumber++;
        }

        if (num == 2 || num == 4) {
            cout << "\nOccurances of lines containing '" << searchStr << "': " << lineCounter << endl;
        }

        newFile.close();

        if (ans == false) {
            cout << searchStr << " not found.\n";
        }
    }
    else {
        cout << "Unable to open file.\n";
    }
}

int main(int argc, char* argv[]) {
    string searchFrom, searchThis, command;
    int number = 1;

    if(argc == 1) {
        // inkrementti 1

        cout << "Give a string to search from: ";
        getline(cin, searchFrom);

        cout << "Give search string: ";
        getline(cin, searchThis);

        size_t isFound = searchFrom.find(searchThis);

        if (isFound != string::npos) {
            cout << searchThis << " found in " << searchFrom << " in position " << isFound << endl;
        }
        else {
            cout << searchThis << " not found in " << searchFrom << endl;
        }
    }
    else if (argc == 3) {
        // inkrementti 2

        printLines(argv[2], argv[1], number);
    }
    else if (argc == 4) {
        // inkrementti 3

        command = argv[1];
        if (command == "-olo") {
            // rivinumerointi + löytyneiden rivien lukumäärä
            number = 2;
            printLines(argv[3], argv[2], number);
        }
        else if (command == "-ol") {
            // rivinumerointi
            number = 3;
            printLines(argv[3], argv[2], number);
        }
        else if (command == "-oo") {
            // löytyneiden rivien lukumäärä
            number = 4;
            printLines(argv[3], argv[2], number);
        }
    }


    return 0;
}
