#include <bits/stdc++.h>
using namespace std;

int conv(char c) {
    return (c == '1');
}

string doX(string X, char c) {
    string S = "";
    S += c;
    for (int i = 0; i < 18; i++) S += X[i];
    return S;
}

string doY(string Y, char c) {
    string S = "";
    S += c;
    for (int i = 0; i < 21; i++) S += Y[i];
    return S;
}

string doZ(string Z, char c) {
    string S = "";
    S += c;
    for (int i = 0; i < 22; i++) S += Z[i];
    return S;
}

void printVEC(vector <int> v) {
    cout << "FINAL ANS = ";
    for (int i = 0; i < v.size(); i++) cout << v[i];
    cout << endl;
}

void a5by1(string X, string Y, string Z, int n) {
    vector <int> vec;

    for (int i = 1; i <= n; i++) {
        int m = int( (conv(X[8]) + conv(Y[10]) + conv(Z[10])) >= 2);
        
        if (conv(X[8]) == m) {
            int Tx = conv(X[13]) ^ conv(X[16]) ^ conv(X[17]) ^ conv(X[18]);
            X = doX(X, Tx+'0');
        }

        if (conv(Y[10]) == m) {
            int Ty = conv(Y[20]) ^ conv(Y[21]);
            Y = doY(Y, Ty+'0');
        }

        if (conv(Z[10]) == m) {
            int Tz = conv(Z[7]) ^ conv(Z[20]) ^ conv(Z[21]) ^ conv(Z[22]);
            Z = doZ(Z, Tz+'0');
        }

        cout << "\nFor " << i << "-th bit:\n";
        cout << "---------------\n";
        cout << "M = " << m << endl;

        cout << "X = " << X << endl;
        cout << "Y = " << Y << endl;
        cout << "Z = " << Z << endl;

        int BIT = conv(X[18]) ^ conv(Y[21]) ^ conv(Z[22]);
        cout << "BIT: " << BIT << "\n\n";
        vec.push_back(BIT);
    }
    printVEC(vec);
}

bool ok(string X, string Y, string Z) {
    bool chk = 0;
    if (X.length() != 19) cout << "Invalid length of X\n", chk = 1;
    if (Y.length() != 22) cout << "Invalid length of Y\n", chk = 1;
    if (Z.length() != 23) cout << "Invalid length of Z\n", chk = 1;
    return chk;
} 

int main() {
    string X, Y, Z;
    cout << "Give X: ";
    cin >> X;
    cout << "Give Y: ";
    cin >> Y;
    cout << "Give Z: ";
    cin >> Z;

    if (ok(X, Y, Z)) return 0;
    
    int n;
    cout << "How many ketstream bit: ";
    cin >> n;
    a5by1(X, Y, Z, n);
}

/*
INPUT:
Give X: 1010101010101010101
Give Y: 1100110011001100110011
Give Z: 11100001111000011110000
How many ketstream bit: 4

OUTPUT:
For 1-th bit:
-------------
M = 1
X = 0101010101010101010
Y = 1100110011001100110011
Z = 11110000111100001111000
BIT: 1


For 2-th bit:
-------------
M = 0
X = 0010101010101010101
Y = 0110011001100110011001
Z = 11110000111100001111000
BIT: 0


For 3-th bit:
-------------
M = 1
X = 0001010101010101010
Y = 1011001100110011001100
Z = 01111000011110000111100
BIT: 0


For 4-th bit:
-------------
M = 1
X = 0001010101010101010
Y = 0101100110011001100110
Z = 10111100001111000011110
BIT: 0

FINAL ANS = 1000
*/