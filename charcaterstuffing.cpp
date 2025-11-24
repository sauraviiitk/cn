#include <iostream>
#include <string>
using namespace std;

string DLE = "DLE";
string STX = "STX";
string ETX = "ETX";

// Sender side: Character Stuffing
string charStuff(string data) {
    string stuffed = DLE + STX;  // starting flag

    for (int i = 0; i < data.length(); i++) {
        if (data.substr(i, 3) == "DLE") {
            stuffed += "DLE";   // stuff extra DLE
        }
        stuffed += data[i];
    }

    stuffed += DLE + ETX; // ending flag
    return stuffed;
}

// Receiver side: De-stuffing
string charDeStuff(string data) {
    string destuff = "";

    // remove starting DLE STX and ending DLE ETX
    int i = 3; // skip DLE STX

    while (i < data.length() - 6) { // stop before DLE ETX
        if (data.substr(i, 3) == "DLE" && data.substr(i + 3, 3) == "DLE") {
            i += 3; // skip stuffed DLE
        }
        destuff += data[i];
        i++;
    }

    return destuff;
}

int main() {
    string data;
    cout << "Enter data string: ";
    getline(cin, data);

    string stuffed = charStuff(data);
    cout << "Stuffed Data: " << stuffed << endl;

    string destuffed = charDeStuff(stuffed);
    cout << "De-stuffed Data: " << destuffed << endl;

    return 0;
}
