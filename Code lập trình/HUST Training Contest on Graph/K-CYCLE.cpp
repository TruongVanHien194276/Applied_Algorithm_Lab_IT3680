#include<bits/stdc++.h>

using namespace std;

const int N = 60;

long long n, m, k, q, res;
vector<int> Graph[N];
int visited[N];
map<vector<int>, int> mp;
int x[N];

void DFS(int u, int p){
    visited[u] = 1;
    x[p] = u;
    for (int v: Graph[u]){
        if (!visited[v]){
            if (p < k) DFS(v, p + 1);
        }else{
            if (p == k && v == x[1]){
                for (int r = 1; r <= k; r++){
                    vector<int> res(k);
                    for (int i = r; i <= k; i++){
                        res[i - r] = x[i];
                    }
                    for (int i = 1; i < r; i++){
                        res[k - r + i] = x[i];
                    }
                    mp[res] = 1;
                    reverse(res.begin(), res.end());
                    mp[res] = 1;
                }
            }
        }
    }
    visited[u] = 0;
}

void solve(){
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        int x, y, z;
        cin >> x >> y;
        Graph[x].push_back(y);
        Graph[y].push_back(x);
    }
    for (int i = 1; i <= n; i++){
        DFS(i, 1);
    }
    cout << int((mp).size()) / 2 / k;
}

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}