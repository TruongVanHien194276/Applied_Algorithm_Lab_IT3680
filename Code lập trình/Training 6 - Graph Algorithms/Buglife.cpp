#include<bits/stdc++.h>

using namespace std;

const int MAX = 100000;

int n, m;
vector<int> Edge[MAX];
int color[MAX];
bool result;

void DFS(int x){
    for (int y : Edge[x]){
        if (color[y] == -1){
            color[y] = 1 - color[x];
            DFS(y);
        }else{
            if (color[y] == color[x]) result = false;
        }
    }
}


int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++){
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            Edge[i].clear();
            color[i] = -1;
        }
        for (int i = 1; i <= m; i++){
            int x, y;
            cin >> x >> y;
            Edge[x].push_back(y);
            Edge[y].push_back(x);
        }
        result = true;
        for (int i = 1; i <= n; i++){
            if (color[i] == -1){
                color[i] = 0;
                DFS(i);
            }
        }
        cout << "Scenario #" << t << ":" << endl;
        if (result){
            cout << "No suspicious bugs found!";
        }else{
            cout << "Suspicious bugs found!";
        }
        cout << endl;
    }
    return 0;
}