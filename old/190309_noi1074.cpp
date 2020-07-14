#include <iostream>
using namespace std;

void two(int N) {
    int t = 0;
    while (N >> t) {
        ++t;
    }
    bool plus = false;
    for (int i = t - 1; i >= 0; --i) {
        int n = ((N >> i) % 2) << i;
        if (n == 0) {
            continue;
        }

        if (plus) {
            cout << "+";
        } else {
            plus = true;
        }

        switch (n) {
            case 1:
                cout << "2(0)";
                break;
            case 2:
                cout << "2";
                break;
            case 4:
                cout << "2(2)";
                break;
            default:
                cout << "2(";
                two(i);
                cout << ")";
                break;
        }
    }
}

int main() {
    int n;
    cin >> n;
    two(n);
    return 0;
}