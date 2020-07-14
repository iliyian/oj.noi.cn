#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

const int BASE = 1000000000;
const int WIDTH = 9;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string a, b;
        cin >> a >> b;
        vector<int> A, B, C;
        int al = (a.size() - 1) / WIDTH + 1;
        int bl = (b.size() - 1) / WIDTH + 1;
        for (int i = 0; i < al; ++i) {
            int end = a.size() - i * WIDTH;
            int start = max(0, end - WIDTH);
            A.push_back(stoi(a.substr(start, end - start)));
        }
        for (int i = 0; i < bl; ++i) {
            int end = b.size() - i * WIDTH;
            int start = max(0, end - WIDTH);
            B.push_back(stoi(b.substr(start, end - start)));
        }
        for (int i = 0, g = 0;; ++i) {
            if (A.size() <= i && B.size() <= i && g == 0)
                break;
            if (A.size() > i) {
                g += A[i];
            }
            if (B.size() > i) {
                g += B[i];
            }
            C.push_back(g % BASE);
            g /= BASE;
        }
        for (int i = C.size() - 1; i >= 0; --i) {
            string s = to_string(C[i]);
            if (s.size() < WIDTH && i != C.size() - 1) {
                for (int j = 0; j < WIDTH - s.size(); ++j){
                    cout << "0";
                }
            }
            cout << s;
        }
        cout << endl;
    }
    return 0;
}