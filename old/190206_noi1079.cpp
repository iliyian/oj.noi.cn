#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string s;
    char ch;
    while (cin.get(ch) && ch != '\n') {
        s = s + ch;
    }
    if (isdigit(s[0])) {
        cout << "no" << endl;
        exit(0);
    }
    for (int i = 0; i < s.size(); ++i) {
        if (!isalpha(s[i]) && !isdigit(s[i]) && s[i] != '_') {
            cout << "no" << endl;
            exit(0);
        }
    }
    cout << "yes" << endl;
    return 0;
}