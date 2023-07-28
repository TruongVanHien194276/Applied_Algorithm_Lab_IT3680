#include<bits/stdc++.h>

using namespace std;

const int MAX = 100;

int n, k, m;
int x[MAX];
bool visited[MAX][MAX];
int result = 0;
int countVT;

void inputData(){
    cin >> n >> k >> m;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            visited[i][j] = false;
        }
    }
    
    vector<pair<int, int> > vt;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        vt.push_back(make_pair(u, v)); // Lưu trữ cặp đỉnh (u, v) kề nhau có cạnh đi
    }

    for (int i = 0; i < m; i++){
        visited[vt[i].first][vt[i].second] = true;
        visited[vt[i].second][vt[i].first] = true;
    }
}

bool check(int point, int h){
    for (int i = 1; i < h; i++){
        if (point == x[i]) return true;
    }
    return false;
}

void TRY(int h){
    for (int i = 1; i <= n; i++){
        if (!visited[x[h-1]][i]) continue;
        if (check(i, h)) continue;

        x[h] = i;
        countVT += 1;

        if (countVT == k) result++;
        else TRY(h+1);

        countVT -= 1;
        x[h] = 0;
    }
}

int main(int argc, const char** argv) {
    inputData();
    for (int i = 1; i <= n; i++) {
        x[1] = i;
        countVT = 0;
        TRY(2);
    }
    cout << result/2;
    return 0;
}