#include <iostream>
using namespace std;

int main() {
    int n, Q;
    cin >> n >> Q;
    int **pics = new int *[n];
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c == 'R') {
            pics[i] = new int[3];
            cin >> pics[i][1] >> pics[i][2];
        } else {
            pics[i] = new int[2];
            cin >> pics[i][1];
        }
        pics[i][0] = (int)c;
    }

    int id;
    for (int i = 0; i < Q; ++i) {
        cin >> id;
        int pid = id - 1;
        if (pics[pid][0] == 'R') {
            cout << "Rectangle" << " " << pics[pid][1] << " " << pics[pid][2] << endl;
        } else {
            if (pics[pid][0] == 'T') {
                cout << "Triangle" << " ";
            } else {
                cout << "Circle" << " ";
            }
            cout << pics[pid][1] << endl;
        }
    }

    return 0;
}