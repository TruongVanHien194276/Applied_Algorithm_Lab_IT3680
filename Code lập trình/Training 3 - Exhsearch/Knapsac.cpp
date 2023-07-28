#include<bits/stdc++.h>

using namespace std;

const int N = 100;

int n, b;
int a[N], c[N], p[N];
int sumA, sumC, result = 0;

void KNAPSAC(int k){
    if (sumA > b) return; // Trọng lượng quá cho phép thì dừng
    if (k > n){
        result = max(result, sumC);
        return; // dừng
    }

    for (int i = 0; i <= 1; i++){
        p[k] = i;
        sumA += p[k]*a[k];
        sumC += p[k]*c[k];
        KNAPSAC(k+1);
        sumA -= p[k]*a[k];
        sumC -= p[k]*c[k];
    }
}

int main(int argc, const char** argv) {
    cin >> n >> b;
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
    }
    KNAPSAC(1);
    cout << result;
    return 0;
}