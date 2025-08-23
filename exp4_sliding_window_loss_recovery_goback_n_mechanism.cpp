#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>
using namespace std;
const int TOTAL_PACKETS = 10;
const int WINDOW_SIZE = 4;
const float LOSS_PROBABILITY = 0.2f;     // 20% chance a packet is lost

bool isPacketLost() {
    return (static_cast<float>(rand()) / RAND_MAX) < LOSS_PROBABILITY;
}
int main() {
    srand(static_cast<unsigned int>(time(0)));
    int base = 0;
    int nextSeqNum = 0;
    cout << "Simulating Go-Back-N ARQ Protocol\n";
    cout << "Total Packets    : " << TOTAL_PACKETS << "\n";
    cout << "Window Size      : " << WINDOW_SIZE << "\n";
    cout << "Loss Probability : " << LOSS_PROBABILITY * 100 << "%\n\n";
    while (base < TOTAL_PACKETS) {
        cout << "Sending window: [";
        for (int i = 0; i < WINDOW_SIZE && (base + i) < TOTAL_PACKETS; ++i) {
            cout << " " << base + i;
        }
        cout << " ]\n";
        bool lossOccurred = false;
        int i;
        for (i = 0; i < WINDOW_SIZE && (base + i) < TOTAL_PACKETS; ++i) {
            int pkt = base + i;
            if (isPacketLost()) {
                cout << "Packet " << pkt << " lost. Timeout.\n";
                lossOccurred = true;
                break;
            } else {
                cout << "Packet " << pkt << " acknowledged.\n";
            }
        }
        if (lossOccurred) {
            cout << "Go-Back-N: Resending from packet " << base + i << "\n\n";
            // Do not move base; resend from lost packet
        } else {
            // All packets in window acknowledged
            base += i;
            cout << " Window moved. New base = " << base << "\n\n";
        }
    }
    cout << "All packets sent and acknowledged successfully.\n";
    return 0;
}
