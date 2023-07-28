#include <bits/stdc++.h>

using namespace std;

const int MAX = 20;

int N ,M;
set<int> A[MAX]; // Adj[v] la list cac dinh ke voi v
int X[MAX];
int best;// kich thuoc be lon nhat
int X_best[MAX];// luu tap dinh cua be cuc dai

void inputData(){
    cin >> N >> M;
    for (int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        A[u].insert(v);
        A[v].insert(u);
    }
}

bool check(int v, int k){
    for (int i = 1; i <= k-2; i++){
        if (A[X[i]].find(v) == A[X[i]].end()) return false;
    }
    return true;
}

void TRY(int k){
    // thu gia tri cho X[k]
    // da biet X[1,. . ., k-1]
    for (set<int>::iterator it = A[X[k-1]].begin(); it != A[X[k-1]].end(); it++){
        int v = *it;
        if (check(v,k)){
            X[k] = v;
            if (k > best){
                best = k;
                for (int i = 1; i <= k; i++){
                    X_best[i] = X[i];
                }
            }
            if (k < N) TRY(k+1);
        }
    }
}

void solve(){
    best = 1;
    for (int v = 1; v <= N; v++){
        X[1] = v;
        TRY(2);
    }
    cout << best;
}

int main(int argc, const char** argv) {
    inputData();
    solve();
    return 0;
}