#include<bits/stdc++.h>

using namespace std;

const int MAX = 100;

int B[MAX];
int n, m, cnt = 0;

void solution(){
    for (int i = 1; i <= m; i++){
        cout << B[i] << " ";
    }
    cout << endl;
}

void TRY(int k){
    for (int i = B[k-1]+1; i <= n-m+k; i++){
        B[k] = i;
        if (k == m) solution();
        else TRY(k+1);
    }
}

int main(int argc, const char** argv) {
    cin >> n >> m;
    TRY(1);
    return 0;
}
