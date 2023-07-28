#include<bits/stdc++.h>

using namespace std;

int main(int argc, const char** argv) {
    const int MOD = 1e9 + 7;
    int n;
    cin >> n;
    int a[n];
    unsigned long long S = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        S = S + a[i] % MOD;
    }
    cout << S % MOD;
    return 0;
}