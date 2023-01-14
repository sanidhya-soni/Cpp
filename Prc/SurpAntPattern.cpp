#include <iostream>
using namespace std;

int main() {

    int n = 7, i, j, x = 1;

    for (i = 1; i <= n; i++) {
        for (j = 0; j < n - i; j++) {
            cout << "  ";
        }
        for (j = 0; j < i * 2 - 1; j++) {
            if(i % 2 != 0) {
                cout << x++;
            } else {
                cout << x--;
            }
            if(x / 10 == 0) {
                cout << " ";
            }
        }
        x += i * 2;
        cout << endl;
    }

    if(n % 2 == 0) {
        x = n * n + 1;
    } else {
        x -= 4;
    }

    for (i = n - 1; i >= 1; i--) {
        for (j = i; j < n; j++) {
            cout << "  ";
        }
        for (j = 0; j < i * 2 - 1; j++) {
            if(i % 2 != 0) {
                cout << x++;
            } else {
                cout << x--;
            }
            if(x / 10 == 0) {
                cout << " ";
            }
        }
        if(i % 2 == 0) {
            x += i * 2;
        } else {
            x += (i - 1) * 2 - 2;
        }
        
        cout << endl;
    }

    return 0;
}
