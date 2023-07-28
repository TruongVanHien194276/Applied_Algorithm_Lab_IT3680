#include<bits/stdc++.h>

using namespace std;

const int MAX = 100010;

int n;
vector<vector<int> > vt;
int res = 0;
bool mark[MAX];

void inputData(){
    cin >> n;
    vt.resize(n+1);
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        vt[u].push_back(v);
        vt[v].push_back(u);
    }
}

void DFS(int u){
    int cnt = 0;
    mark[u] = false;
    for (int v : vt[u]){
        if (mark[v]){
            cnt += 1;
            DFS(v);
        }
    }
    if (cnt == 0) res += 1;
}

int main(int argc, const char** argv) {
    inputData();
    memset(mark, true, sizeof(mark) );
    for (int i = 1; i <= n; i++){
        if (mark[i]) DFS(i);
    }
    cout << res;
    return 0;
}

