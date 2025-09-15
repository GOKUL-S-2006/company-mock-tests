#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;
    const int max_cap = 10;

    while (true) {
        int ch;
        cin >> ch;

        switch (ch) {
            case 1: {  // Insert car
                int carNumber;
                cin >> carNumber;

                if (dq.size() >= max_cap) {
                    cout << "Parking lot is full." << endl;
                } else {
                    int spotIndex = dq.size();
                    dq.push_back(carNumber);
                    cout << "Car " << carNumber << " parked in spot " << spotIndex << "." << endl;
                }
                break;
            }

            case 2: {  // Retrieve car
                if (dq.empty()) {
                    cout << "Parking lot is empty." << endl;
                } else {
                    int carNumber = dq.front();
                    cout << "Car " << carNumber << " retrieved from spot 0." << endl;
                    dq.pop_front();
                }
                break;
            }

            case 3: {  // Exit program
                return 0;
            }

            default: {  // Invalid choice
                cout << "Invalid choice." << endl;
                break;
            }
        }
    }
}
