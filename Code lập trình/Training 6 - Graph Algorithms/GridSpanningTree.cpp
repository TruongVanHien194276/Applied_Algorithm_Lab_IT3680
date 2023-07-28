#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main(int argc, const char** argv) {
    int n;
    cin >> n;
    vector<long long> f;
    f.resize(n+1);
    f[1] = 1;
    for (int i = 2; i <= n; i++){
        f[i] = (4 * f[i-1] - f[i-2] + MOD) % MOD;
    }
    cout << f[n];
    return 0;
}