#include<bits/stdc++.h>

using namespace std;

const int MAX = 100000;
int n, m;
int d[MAX], t[MAX];
vector<int> Graph[MAX];
int result;

void DFS(int x){
    t[x] = 0;
    for (int y : Graph[x]){
        if (t[y] == -1) DFS(y);
        t[x] = max(t[x], t[y]);
    }
    t[x] += d[x];
    result = max(result, t[x]);
}

int main(int argc, const char** argv) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> d[i];
    }
    while (m--){
        int x, y;
        cin >> x >> y;
        Graph[y].push_back(x);
    }

    memset(t, -1, sizeof(t));
    for (int i = 1; i <= n; i++){
        if (t[i] == -1) DFS(i);
    }
    cout << result;
    return 0;
}