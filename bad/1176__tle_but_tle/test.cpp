#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
const int BASE = 10000;
const int WIDTH = 4;

struct Wint:std::vector<int> {
    Wint(int n = 0) {
        push_back(n);
        check();
    }
    Wint& check() {
        while (!empty() && back() == 0) pop_back();
        if (empty()) return *this;
        for (int i = 1; i < size(); i++) {
            (*this)[i] += (*this)[i-1] / BASE;
            (*this)[i-1] %= BASE;
        }
        while (back() >= BASE) {
            push_back(back() / BASE);
            (*this)[size()-2] %= BASE;
        }
        return *this;
    }
};

void print(Wint a) {
    printf("%d", a.back());
    for (int i = a.size()-2; i >= 0; i--) {
        printf(" %04d", a[i]);
    }
    printf("\n");
}

Wint operator + (Wint& a, Wint& b) {
    Wint c;
    c.assign(std::max(a.size(), b.size()), 0);
    for (int i = 0; i < c.size(); i++) {
        if (i < a.size()) c[i] += a[i];
        if (i < b.size()) c[i] += b[i];
    }
    return c.check();
}

Wint operator - (Wint& a, Wint& b) {
    Wint c = a;
    for (int i = 0; i < b.size(); c[i] -= b[i], i++) {
        if (c[i] < b[i]) {
            int j = i+1;
            while (c[i] == 0) j++;
            while (j > i) {
                c[j]--;
                c[--j] += BASE;
            }
        } 
    }
    return c.check();
}

Wint operator * (Wint a, Wint b) {
    Wint c;
    c.assign(a.size()+b.size(), 0);
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            c[i+j] += a[i] * b[j];
    return c.check();
}

bool operator >= (Wint& a, Wint& b) {
    if (a.size() != b.size()) return a.size() >= b.size();
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] < b[i]) return false;
    }
    return true;
}

Wint divmod(Wint& a, Wint& b) {
    Wint ans;
    for (int t = a.size() - b.size(); a >= b; t--) {
        Wint c;
        c.assign(t+1, 0);
        c.back() = 1;
        Wint d = b * c;
        while (a >= d) {
            a = a - d;
            ans = ans + c;
        }
    }
    return ans;
}

Wint operator % (Wint& a, Wint& b) {
    Wint c = a;
    divmod(c, b);
    return c;
}

Wint gcd(Wint a, Wint b) {
    return b.back() == 0 ? a : gcd(b, a % b);
}

void read(Wint& a) {
    std::string s;
    std::cin >> s;
    int len = (s.size() - 1) / WIDTH + 1, x;
    for (int i = 0; i < len; i++) {
        int end = s.size() - i * WIDTH;
        int start = std::max(0, end - WIDTH);
        sscanf(s.substr(start, end-start).c_str(), "%d", &x);
        a.push_back(x);
    }
}

Wint pow(Wint& a, int n) {
    if (n == 0) return 1;
    if (n == 1) return a;
    if (n == 2) return a * a;
    Wint t = pow(a, n/2);
    return n % 2 ? t*t*a : t*t;
}

int main() {
    Wint a, b;
    read(a);
    read(b);
    print(gcd(a, b));
    return 0;
}