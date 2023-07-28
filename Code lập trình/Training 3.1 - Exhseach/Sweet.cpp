#include <iostream>

const int MOD = 1e9 + 7;

using namespace std;

long long a[999][999];
long long tohop(long long k, long long n){
    if (k == 0|| k == n) return 1;
    if (a[k][n] != 0) return a[k][n] % MOD;
    a[k][n] = (tohop(k-1, n-1)%MOD + tohop(k, n-1)%MOD) % MOD;
    return a[k][n] % MOD;
}

int main(int argc, const char** argv) {
    long long n, k;
    cin >> n >> k;
    n = n+k-1;
    k--;
    if (k > n/2) k = n-k;
    cout << tohop(k, n);
    return 0;
}