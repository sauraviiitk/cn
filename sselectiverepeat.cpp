#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int totalFrames, windowSize;

    cout << "Enter total number of frames: ";
    cin >> totalFrames;

    cout << "Enter window size: ";
    cin >> windowSize;

    srand(time(NULL));

    vector<bool> received(totalFrames, false);
    int base = 0;

    while (base < totalFrames) {

        cout << "\n--- Sending Window ---\n";
        for (int i = base; i < base + windowSize && i < totalFrames; i++) {
            cout << "Sending frame " << i << endl;
        }

        for (int i = base; i < base + windowSize && i < totalFrames; i++) {
            int x = rand() % 10;

            if (x < 2) {   // frame loss
                cout << "Frame " << i << " lost! Will retransmit later.\n";
            } else {
                cout << "Frame " << i << " received. Sending ACK...\n";
                received[i] = true;
            }
        }

        // Slide window only over acknowledged frames
        while (base < totalFrames && received[base])
            base++;
    }

    cout << "\nAll frames successfully transmitted (Selective Repeat)!\n";

    return 0;
}
