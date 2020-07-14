#include <iostream>
#include <set>
using namespace std;

int main() {
    char ch;
    set<char> s;
    int p = 0;
    while (cin.get(ch) && ch != '\n') {
        if (ch == 'p') {
            ++p;
        } else {
            s.insert(ch);
        }
    }
    if (s.count('h') && s.count('a') && s.count('y') && p >= 2) {
        cout << "Yes!" << endl;
    } else {
        cout << "No!" << endl;
    }
    return 0;
}