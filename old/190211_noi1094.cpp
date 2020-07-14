#include <iostream>
using namespace std;

int strange (int a, char c, int b) {
    switch (c) {
        case '+':
            return a * b + b * a;
        case '-':
            return a + b + a * b;
        case '*':
            return b * b + a * a;
        case '/':
            return b - a + b * a;
    }
};

int main() {
    int a = 0, b, n;
    char c;
    cin >> n;
    while (n--) {
        cin >> c >> b;
        a = strange(a, c, b) % 12345;
        cout << a << endl;
    }
    return 0;
}