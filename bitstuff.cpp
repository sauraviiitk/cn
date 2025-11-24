#include <iostream>
#include <string>
using namespace std;

// Sender side: Bit Stuffing
string bitStuff(string data) {
    string stuffed = "";
    int count = 0;

    for (char bit : data) {
        stuffed += bit;

        if (bit == '1') count++;
        else count = 0;

        if (count == 5) {
            stuffed += '0'; // stuff a 0
            count = 0;
        }
    }
    return stuffed;
}

// Receiver side: Bit De-stuffing
string bitDeStuff(string data) {
    string destuff = "";
    int count = 0;

    for (int i = 0; i < data.size(); i++) {
        destuff += data[i];

        if (data[i] == '1') count++;
        else count = 0;

        if (count == 5) {
            i++; // skip stuffed 0
            count = 0;
        }
    }
    return destuff;
}

int main() {
    string data;
    cout << "Enter binary data: ";
    cin >> data;

    string stuffed = bitStuff(data);
    cout << "Stuffed Data: " << stuffed << endl;

    string destuffed = bitDeStuff(stuffed);
    cout << "De-stuffed Data: " << destuffed << endl;

    return 0;
}
