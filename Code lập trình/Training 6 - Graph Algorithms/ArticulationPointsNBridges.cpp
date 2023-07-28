#include<bits/stdc++.h>

using namespace std;

const int MAX = 100010;

int n, m;
vector<vector<int> > Graph;
int num[MAX], low[MAX];
int cnt = 0, Count = 0;
bool numc[MAX];

void inputData(){
    cin >> n >> m;
    Graph.resize(n+1);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
}

void DFS(int u, int p){
    cnt++;
    int numChill = 0;
    num[u] = low[u] = cnt;
    for (int v : Graph[u]){
        if (v != p){
            if (num[v] != 0){
                low[u] = min(low[u], num[v]);
            }else{
                DFS(v, u);
                numChill++;
                low[u] = min(low[u], low[v]);

                if (low[v] >= num[v]) Count++;
                
                if (u == p){
                    if (numChill >= 2) numc[u] = true;
                }else{
                    if (low[v] >= num[u]) numc[u] = true;
                }
            }
        }
    }
}

int main(int argc, const char** argv) {
    inputData();
    for (int i = 1; i <= n; i++){
        if (!num[i]) DFS(i, i);
    }
    int numcc = 0;
    for (int i = 1; i <= n; i++){
        if (numc[i]) numcc++;
    }

    cout << numcc << " " << Count << endl;
    return 0;
}