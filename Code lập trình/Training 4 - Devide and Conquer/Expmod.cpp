#include<bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;

unsigned long long sqr(unsigned long long x) {
    return x*x;
}
 
unsigned long long power(unsigned long long a, unsigned long long b) {
    if (b == 0) return 1 % MOD;
    else
        if (b % 2 == 0)
            return sqr(power(a, b/2)) % MOD;
        else    
            return a * (sqr(power(a, b/2)) % MOD) % MOD;
}
 
int main(int argc, const char** argv) {
    unsigned long long a, b;
    cin >> a >> b;
    a %= MOD;
    b %= MOD-1;
    cout << power(a, b);
    return 0;
}
