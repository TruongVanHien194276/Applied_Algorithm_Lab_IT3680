// Liệt kê tất cả các cách chia m kẹo cho n em bé sao cho em bé nào cũng có kẹo

#include<bits/stdc++.h>
#define N 100

using namespace std;

int m, n;
int x[N];

void Print(){
    for (int i = 1; i <= n; i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

void TRY(int k){
    int f = 0;
    int m0 = m - f - (n-k);
    if (k == n){
        x[k] = m0 - f;
        Print();
    }
    for (int i = 1; i <= m0; i++){
        x[k] = i;
        f = f + i;
        TRY(k+1);
        f = f - i;
    }
}

int main(int argc, const char** argv) {
    cin >> m >> n;
    TRY(1);
    return 0;
}