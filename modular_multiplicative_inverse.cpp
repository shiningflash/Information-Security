/*
    @author   : Amirul Islam (shiningflash)
    @topic    : Modular Multiplicative Inverse
*/

#include <bits/stdc++.h>
using namespace std;

int gcdExtended(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int gcd = gcdExtended(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - y1 * (a / b);
    return gcd;
}

void modInverse(int a, int m) {
    int x, y;
    int gcd = gcdExtended(a, m, &x, &y);

    if (gcd != 1) {
        cout << "Modular Multiplicative Inverse does not exist." << endl;
    }
    else {
        int inv = (x % m + m) % m;
        cout << "Modular Multiplicative Inverse is " << inv << endl;
    }
}

int main() {
    int m, n;
    cout << "M: "; cin >> m;
    cout << "N: "; cin >> n;
    modInverse(m, n);
}

/*
INPUT:
M: 31
N: 110

OUTPUT:
Modular Multiplicative Inverse is 71
*/