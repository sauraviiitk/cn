#include <iostream>
#include <vector>
#include <string>
using namespace std;

class DHCPServer {
private:
    vector<string> ipPool;
    vector<bool> allocated;

public:
    DHCPServer(string networkPrefix, int startHost, int endHost) {
        for (int i = startHost; i <= endHost; i++) {
            ipPool.push_back(networkPrefix + to_string(i));
            allocated.push_back(false);
        }
    }

    string requestIP(int clientID) {
        cout << "Client " << clientID << " → DHCP Discover\n";

        for (int i = 0; i < ipPool.size(); i++) {
            if (!allocated[i]) {
                cout << "Server → DHCP Offer: " << ipPool[i] << endl;

                cout << "Client " << clientID << " → DHCP Request: " << ipPool[i] << endl;

                allocated[i] = true;
                cout << "Server → DHCP ACK: " << ipPool[i] << " assigned.\n";

                return ipPool[i];
            }
        }

        cout << "No free IP available!\n";
        return "NULL";
    }

    void releaseIP(string ip) {
        for (int i = 0; i < ipPool.size(); i++) {
            if (ipPool[i] == ip) {
                allocated[i] = false;
                cout << "IP released: " << ip << endl;
                return;
            }
        }
        cout << "IP not found!\n";
    }

    void displayStatus() {
        cout << "\n--- DHCP IP Pool Status ---\n";
        for (int i = 0; i < ipPool.size(); i++) {
            cout << ipPool[i] << " → " 
                 << (allocated[i] ? "Allocated" : "Free") << endl;
        }
        cout << "---------------------------\n";
    }
};

int main() {
    DHCPServer server("192.168.1.", 2, 10); // pool: 192.168.1.2 – 192.168.1.10

    string ip1 = server.requestIP(1);
    string ip2 = server.requestIP(2);

    server.displayStatus();

    server.releaseIP(ip1);

    server.displayStatus();

    return 0;
}
