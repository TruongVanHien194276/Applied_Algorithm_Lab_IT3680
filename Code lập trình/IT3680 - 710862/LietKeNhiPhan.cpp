// Liệt kê các xâu nhị phân độ dài n

#include<bits/stdc++.h>
#define N 50

using namespace std;

int n;
int A[N];

void Print(){
    for (int i = 1; i <= n; i++){
        cout << A[i];
    }
    cout << endl;
}

void TRY(int k){
    for (int i = 0; i <= 1; i++){
        A[k] = i;
        if (k == n) Print();
        else TRY(k+1);
    }
}

int main(int argc, const char** argv) {
    cin >> n;
    TRY(1);
    return 0;
}