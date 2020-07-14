#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    while(n--) {
        cin >> k;
        if (k <= 2) {
            cout << k << endl;
            continue;
        } else {
            int *pell = new int[k + 1];
            pell[1] = 1;
            pell[2] = 2;
            for (int i = 3; i <= k; ++i) {
                pell[i] = (2 * pell[i - 1] + pell[i - 2]) % 32767;
            }
            cout << pell[k] << endl;
            delete[] pell;
        }
    }
    return 0;
}