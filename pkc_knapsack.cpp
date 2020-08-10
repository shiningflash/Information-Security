/*
    @author   : Amirul Islam (shiningflash)
    @topic    : Public Key Cryptography (Knapsack)
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

int modInverse(int a, int m) {
    int x, y;
    int gcd = gcdExtended(a, m, &x, &y);

    if (gcd != 1) {
        cout << "\nModular Multiplicative Inverse does not exist." << endl;
        return -1;
    }
    else {
        int inv = (x % m + m) % m;
        cout << "\nModular Multiplicative Inverse: " << inv << endl;
        return inv;
    }
}

int main() {
    int len, x, m, n;
    vector <int> sik;
    string enc;

    cout << "SIK length: "; cin >> len;
    cout << "Enter SIK: ";
    for (int i = 0; i < len; i++) cin >> x, sik.push_back(x);
    cout << "Enter M: "; cin >> m;
    cout << "Enter N: "; cin >> n;
    cout << "Enter ENCRYPT code: "; cin >> enc;

    int MI = modInverse(m, n);

    vector <int> gk;
    for (int i = 0; i < len; i++) {
        gk.push_back((sik[i] * m) % n);
    }
    cout << "General Knapsack: ";
    for (int i = 0; i < len; i++) cout << gk[i] << " ";
    cout << endl;

    cout << "Encrypt value: ";
    int sum = 0;
    for (int i = 0; i < enc.length(); i++) if (enc[i] == '1') sum += gk[i];
    cout << sum << "\n\n";

    int S = (sum * MI) % n;
    cout << "S = " << S << endl;

    string dec = "";
    for (int i = len-1; i >= 0; i--) {
        if (S >= sik[i]) dec += '1', S -= sik[i];
        else dec += '0';
    }
    reverse(dec.begin(), dec.end());
    cout << "Decrypt code: " << dec << endl;
}


/*
INPUT:
SIK length: 6
Enter SIK: 1 2 4 10 20 40
Enter M: 31
Enter N: 110
Enter ENCRYPT code: 100100

OUTPUT:
Modular Multiplicative Inverse: 71
General Knapsack: 31 62 14 90 70 30 
Encrypt value: 121

S = 11
Decrypt code: 100100

-------------------------

INPUT:
SIK length: 8
Enter SIK: 2 3 7 14 30 57 120 251
Enter M: 41
Enter N: 491
Enter ENCRYPT code: 10010110

OUTPUT:
Modular Multiplicative Inverse: 12
General Knapsack: 82 123 287 83 248 373 10 471 
Encrypt value: 548

S = 193
Decrypt code: 10010110
*/