#include <iostream>
using namespace std;

int powd(int n, int x) {
    if (!x) {
        return 1;
    }
    int s = n;
    while (--x) {
        n *= s;
    }
    return n;
}

int toTen(int n, int x) {
    int result = 0;
    for (int i = 0; n; ++i, n /= 10) {
        int p = powd(x, i);
        result += p * (n % 10);
    }
    return result;
}

int main() {
    int p, q, r;
    cin >> p >> q >> r;
    int m = -12345;
    int a = p, b = q, c = r;
    while (a) {
        int s = a % 10;
        if (s > m) {
            m = s;
        }
        a /= 10;
    } while (b) {
        int s = b % 10;
        if (s > m) {
            m = s;
        }
        b /= 10;
    } while (c) {
        int s = c % 10;
        if (s > m) {
            m = s;
        }
        c /= 10;
    }
    for (int i = m + 1; i <= 16; ++i) {
        if (toTen(p, i) * toTen(q, i) == toTen(r, i)) {
            cout << i;
            return 1;
        }
    }
    cout << 0;
    return 0;
}