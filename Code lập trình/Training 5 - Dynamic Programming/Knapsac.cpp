#include<bits/stdc++.h>

using namespace std;

int n, b;
int a[50], c[50], f[1000100];
int result;

void inputData(){
    cin >> n >> b;
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
    }
}

int KNAPSAC(){
    for (int i = 1; i <= n; i++){
        for (int j = b; j >= a[i]; j--){
            f[j] = max(f[j], f[j - a[i]] + c[i]);
        }
    }
    result = f[0];
    for (int j = 1; j <= b; j++){
        result = max(result, f[j]);
    }
    return result;
}

int main(int argc, const char** argv) {
    inputData();
    cout << KNAPSAC();
    return 0;
}