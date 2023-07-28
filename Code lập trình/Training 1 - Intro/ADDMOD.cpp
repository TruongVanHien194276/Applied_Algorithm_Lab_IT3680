#include<bits/stdc++.h>

using namespace std;

int main(int argc, const char** argv) {
    const int MOD = 1e9 + 7;
    unsigned long long a, b;
    cin >> a >> b;

    a = a % MOD;
    b = b % MOD;
    
    cout << (a+b) % MOD;
    return 0;
}