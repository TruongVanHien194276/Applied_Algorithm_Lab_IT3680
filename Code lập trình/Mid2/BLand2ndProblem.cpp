#include<bits/stdc++.h>

using namespace std;

const int MAX = 510;

int n, k;
int x[MAX], y[MAX];
vector<pair<int, int> > Graph[5000];

void inputData(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }
}

void Dijkstra(int u, int v){
    vector<int> iDist(5000, -1);
    queue<int> Q;
    Q.push(u);
    iDist[u] = 0;

    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        for (int i = 0; i < Graph[u].size(); i++){
            int v = Graph[u][i].first;
            int w = Graph[u][i].second;

            if (iDist[v] == -1){
                Q.push(v);
                iDist[v] = w + iDist[u];
            }
            if (w + iDist[u] < iDist[v]){
                iDist[v] = w + iDist[u];
            }
        }
    }
    cout << iDist[v];
}

int main(int argc, const char** argv) {
    inputData();
    for (int i = 1; i <= n; i++){
        for (int j = 1; j < i; j++){
            int dis = floor(sqrt((double)((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))));
            if (dis <= k){
                Graph[i].push_back(make_pair(j, dis));
                Graph[j].push_back(make_pair(i, dis));
            }
        }
    }

    for (int i = 1; i <= n; i++){
        sort(Graph[i].begin(), Graph[i].end());
    }

    Dijkstra(1, n);
    return 0;
}