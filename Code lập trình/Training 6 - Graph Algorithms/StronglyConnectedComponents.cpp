#include<bits/stdc++.h>

using namespace std;

const int MAX = 100010;

int n, m;
vector<vector<int> > a;
vector<vector<int> > b;
bool mark[MAX], check[MAX];
vector<int> c;

void DFS1(int u){
    mark[u] = false;
    for (int v : a[u]){
        if (mark[v]) {
            DFS1(v);
            c.push_back(v);
        }
    }
}

void DFS2(int u){
    mark[u] = false;
    for (int v : b[u]){
        if (mark[v]) DFS2(v);
    }
}

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
	cin.tie(0); 
    cout.tie(0);
    
    cin >> n >> m;
    a.resize(n+1);
    b.resize(n+1);
    memset(mark, true, sizeof(mark));
    memset(check, true, sizeof(check));
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        b[v].push_back(u);
    }

    for (int i = 1; i <= n; i++){
        if (mark[i]){
            DFS1(i);
            c.push_back(i);
        }
    }

    memset(mark, true, sizeof mark);
    int res = 0;
    for (int i = c.size() - 1; i >= 0; i--){
        if (mark[c[i]]) {
            DFS2(c[i]);
            res++;
        }
    }
    cout << res;
    return 0;
}