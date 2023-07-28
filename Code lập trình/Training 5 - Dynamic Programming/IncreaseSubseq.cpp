#include<bits/stdc++.h>

using namespace std;

const int MAX = 10010;

int n, a[MAX], S[MAX], result;

void inputData(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
}

void IncreaseSubseq(){
    S[0] = 1;
    result = S[0];
    for (int i = 1; i < n-1; i++){
        S[i] = 1;
        for (int j = 0; j < i; j++){
            if (a[i] > a[j]){
                if (S[i] < S[j] + 1) S[i] = S[j] + 1;
            }
        }
        result = max(result, S[i]);
    }
}

int main(int argc, const char** argv) {
    inputData();
    IncreaseSubseq();
    cout << result;
    return 0;
}