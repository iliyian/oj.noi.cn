#include <iostream>
#include <list>
using namespace std;

int main() {
    int n, way;
    string name;
    list<string> friends;
    cin >> n;
    while (n--) {
        cin >> way >> name;
        if (way) {
            friends.push_back(name);
        } else {
            friends.push_front(name);
        }
    }
    for (list<string>::iterator i = friends.begin(); i != friends.end(); ++i) {
        cout << *i << endl;
    }
    return 0;
}