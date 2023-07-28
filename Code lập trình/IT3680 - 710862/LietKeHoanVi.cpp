// Liệt kê các hoán vị của n phần tử

#include<bits/stdc++.h>
#define N 100

using namespace std;

int A[N];
bool bMark[N];
int n;

void Print(){
    for (int i = 1; i <= n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

void TRY(int k){
    for (int i = 1; i <= n; i++){
        if (!bMark[i]){
            A[k] = i;
            bMark[i] = true;
            // Đánh dấu bMarki] = 1 (0) nếu i đã xuất hiện (chưa xuất hiện)
            if (k == n) Print();
            else TRY(k+1);
            bMark[i] = false; // Khôi phục
        }
    }
}

int main(int argc, const char** argv) {
    cin >> n;
    for (int i = 1; i <= n; i++){
        bMark[i] = false;
    }
    TRY(1);
    return 0;
}