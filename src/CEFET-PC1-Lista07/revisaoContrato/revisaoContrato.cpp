#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getUserInput(char *outProblematicNumber, string *outContractNumber);
void splitString(const string target, const char splitPoint, vector<string> *outVector);
string formattNumberInLine(const string line);
bool isStringOneSingleCharacter(const string line, const char referenceCharacter);
string removeCharacter(const string target, const char character);

int main() {
    char problematicNumber;
    string contractNumber = "";

    getUserInput(&problematicNumber, &contractNumber);

    while (problematicNumber != '0' && contractNumber != "0") {
        string result = removeCharacter(contractNumber, problematicNumber);
        result = formattNumberInLine(result);

        cout << result << "\n";        

        getUserInput(&problematicNumber, &contractNumber);
    }

    return 0;
}

void getUserInput(char *outProblematicNumber, string *outContractNumber) {
    string inputLine = "";
    vector<string> splitedLine;

    int problematicNumber = 0;
    unsigned long long contractNumber = 0;

    do {
        getline(cin, inputLine);

        splitString(inputLine, ' ', &splitedLine);

        problematicNumber = stoi(splitedLine[0]);
        contractNumber = stoull(splitedLine[1]);
    } while (problematicNumber < 0 || problematicNumber > 9 || contractNumber < 0);

    *outProblematicNumber = '0' + problematicNumber;
    *outContractNumber = to_string(contractNumber);

    return;
}

void splitString(const string target, const char splitPoint, vector<string> *outVector) {
    string temp = "";

    for (int i = 0; i < target.length(); i++) {
        char actualCharacter = target[i];

        if (actualCharacter == splitPoint && !temp.empty()) {
            outVector->push_back(temp);
            temp.clear();
        }
        else if (actualCharacter != splitPoint) {
            temp.push_back(actualCharacter);
        }
    }

    if (!temp.empty()) {
        outVector->push_back(temp);
    }

    return;
}

string formattNumberInLine(const string line) {
    string result = line;

    if (line.length() == 0) {
        result = "1";
    }
    else if (line.length() > 1 && isStringOneSingleCharacter(line, '0')) {
        result = "0";
    }

    return result;
}

bool isStringOneSingleCharacter(const string line, const char referenceCharacter) {
    for (int i = 1; i < line.length(); i++) {
        if (referenceCharacter != line[i]) {
            return false;
        }
    }
    
    return true;
}

string removeCharacter(const string target, const char character) {
    string result = "";

    for (int i = 0; i < target.length(); i++) {
        if (target[i] != character) {
            result.push_back(target[i]);
        }
    }

    return result;
}
