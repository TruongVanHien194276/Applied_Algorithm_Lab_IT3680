#include<bits/stdc++.h>
 
using namespace std;
 
int n;
int x[100];
 
void solution(int x[]){
    for (int i = 1; i <= n; i++){
        cout << x[i];
    }
    cout << endl;
}
 
void TRY(int k){
    for (int i = 0; i <= 1; i++){
        x[k] = i;
        if (k == n) solution(x);
        else TRY(k+1);
    }
}

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    TRY(1);
    return 0;
}
