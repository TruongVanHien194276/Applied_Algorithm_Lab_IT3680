// Liệt kê các tổ hợp chập m của n phần tử {1, 2, ..., n}

#include<bits/stdc++.h>
#define N 50

using namespace std;

int m, n;
int A[N];

void Print(){
    for (int i = 1; i <= m; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

void TRY(int k){
    for (int i = A[k-1] + 1; i <= n-m+k; i++){
        A[k] = i;
        if (k == m) Print();
        else TRY(k+1);
    }
}

int main(int argc, const char** argv) {
    cin >> m >> n;
    TRY(1);
    return 0;
}