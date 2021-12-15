#include <iostream>
#include <string>

using namespace std;

int countAlitarations(const string line);

int main() {
    do {
        string lineToTest = "";
        getline(cin, lineToTest);

        int amountAlitararions = countAlitarations(lineToTest);
        cout << amountAlitararions << "\n";
    } while(!cin.eof());

    return 0;
}

int countAlitarations(const string line) {
    int count = 0;
    char lastLetter = ' ';
    bool hasAlreadyIncremented = false;
    bool hasFoundFirstCharacter = false;

    for (int i = 0; i < line.length(); i++) {
        char actualLetter = tolower(line[i]);
        bool isTheFirstLetter = isalpha(actualLetter) && !hasFoundFirstCharacter;
        if (isTheFirstLetter) {
            hasFoundFirstCharacter = true;
            if (actualLetter != lastLetter) {
                hasAlreadyIncremented = false;
            }
            else if (!hasAlreadyIncremented) {
                count++;
                hasAlreadyIncremented = true;
            }
        }
        else if (actualLetter == ' ') {
            hasFoundFirstCharacter = false;
        }
    }

    return count;
}
