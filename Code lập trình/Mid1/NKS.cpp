#include<bits/stdc++.h>

using namespace std;

const int MAX = 50;

int n, k, s, result;
int a[MAX], x[MAX], c[MAX];

void NKS(int b, int cnt, int sum){
    if (cnt > k) return;
    if (cnt + n - b + 1 < k) return;
    if (b > n){
        if (sum == s) result++;
        return;
    }

    x[b] = 0; 
    NKS(b + 1, cnt, sum);
    x[b] = 1; 
    NKS(b + 1, cnt + 1, sum + a[b]);
}

int main(int argc, const char** argv) {
    cin >> n >> k >> s;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    result = 0;
    NKS(1, 0, 0);
    cout << result;
}