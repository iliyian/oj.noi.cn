#include <iostream>
#include <set>
using namespace std;

typedef set<char> Set;
typedef set<char>::iterator si;

Set toSet(const string & a) {
    Set s;
    for (int i = 0; i < a.size(); ++i) {
        s.insert(a[i]);
    }
    return s;
}

string toString(const set<char> & s) {
    string str;
    for (si x = s.begin(); x != s.end(); ++x) {
        str = str + *x;
    }
    return str;
}

string count(string a, char w, string b) {
    if (w == '+') {
        Set rel;
        Set sa = toSet(a), sb = toSet(b);
        rel.insert(sa.begin(), sa.end());
        rel.insert(sb.begin(), sb.end());
        return toString(rel);
    } else if (w == '-') {
        Set sa = toSet(a), sb = toSet(b);
        for (si i = sb.begin(); i != sb.end(); ++i) {
            if (sa.find(*i) != sa.end()) {
                sa.erase(*i);
            }
        }
        return toString(sa);
    } else if (w == '*') {
        Set rel;
        Set sa = toSet(a), sb = toSet(b);
        for (si i = sa.begin(); i != sa.end(); ++i) {
            if (sb.find(*i) != sb.end()) {
                rel.insert(*i);
            }
        }
        return toString(rel);
    }
}

int main() {
    int m, ki;
    string a, b;
    char way;
    cin >> m;
    while (m--) {
        cin >> ki >> a;
        for (int i = 0; i < ki - 1; ++i) {
            cin >> way >> b;
            a = count(a, way, b);
        }
        cout << a << endl;
    }
    return 0;
}