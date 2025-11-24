#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int totalFrames;
    cout << "Enter total number of frames: ";
    cin >> totalFrames;

    srand(time(NULL));

    for (int i = 0; i < totalFrames; ) {

        cout << "\nSending Frame " << i << endl;

        // Simulate 20% chance of loss
        int x = rand() % 10;

        if (x < 2) {
            cout << "Frame " << i << " lost! Retransmitting...\n";
            continue;  // resend same frame
        }

        cout << "Frame " << i << " received. Sending ACK...\n";

        // Simulate ACK loss
        x = rand() % 10;

        if (x < 2) {
            cout << "ACK for Frame " << i << " lost! Retransmitting frame...\n";
            continue;
        }

        cout << "ACK received for Frame " << i << ".\n";
        i++;  // move to next frame
    }

    cout << "\nAll frames sent successfully!\n";
    return 0;
}
