#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x, a, b;
    cin >> n;
    vector<int> s;
    while (n--) {
        cin >> x;
        s.push_back(x);
    }
    cin >> n;
    while (n--) {
        cin >> x;
        switch (x) {
            case 1:
                cin >> a;
                cout << s[a - 1] << endl;
            break;
            case 2:
                cin >> a >> b;
                s.insert(s.begin() + a - 1, b);
            break;
            case 3:
                cin >> a;
                s.erase(s.begin() + a - 1);
            break;
        }
    }
    return 0;
}