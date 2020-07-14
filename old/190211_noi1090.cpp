#include <iostream>
using namespace std;

struct Car {
    string S;
    int V, W, type;
    string name;
    int phone;
};

int main() {
    int n;
    cin >> n;
    string name, S;
    int type, V, W, phone;
    Car *cars = new Car[n];
    for (int i = 0; i < n; ++i) {
        cin >> S >> V >> W >> type;
        if (type) {
            cin >> phone;
            cars[i].type = 1;
            cars[i].phone = phone;
        } else {
            cin >> name;
            cars[i].type = 0;
            cars[i].name = name;
        }
        cars[i].S = S;
        cars[i].V = V;
        cars[i].W = W;
    }

    int op, Q, id, k;
    cin >> Q;
    while (Q--) {
        cin >> op;
        if (op == 1) {
            cin >> id;
            cout << cars[id - 1].S << endl;
        } else if (op == 2) {
            cin >> S;
            for (int i = 0; i < n; ++i) {
                if (cars[i].S == S) {
                    if (cars[i].type) {
                        cout << cars[i].phone << endl;
                    } else {
                        cout << cars[i].name << endl;
                    }
                    break;
                }
            }
        } else if (op == 3) {
            cin >> k;
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                if (double(cars[i].V) / double(cars[i].W) >= k) {
                    ++sum;
                }
            }
            cout << sum << endl;
        }
    }
    return 0;
}