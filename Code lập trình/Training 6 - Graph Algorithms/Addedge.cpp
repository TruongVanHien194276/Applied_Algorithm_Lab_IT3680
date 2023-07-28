#include<bits/stdc++.h>

using namespace std;

const int MAX = 100010;
typedef pair<int, int> pii;

int n, m;
vector<int> b[MAX];
vector<pii> Bridge, a[MAX];
int low[MAX], num[MAX], dir[MAX];
bool c[MAX];
int cnt = 0;
long long ans = 0;

void inputData(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(pii(y, i));
        a[y].push_back(pii(x, i));
    }
}

void DFS(int x){
    num[x] = low[x] = ++cnt;
    for (pii w : a[x]){
        int y = w.first;
        int i = w.second;
        
        if (dir[i] != 0) continue;
        dir[i] = y;

        if (num[y] == 0){
            DFS(y);
            low[x] = min(low[x], low[y]);
            if (num[y] <= low[y]) Bridge.push_back(pii(x, y));
        }else{
            low[x] = min(low[x], num[y]);
        }
    }
}

void DFS1(int x){
    cnt++;
    c[x] = true;
    for (int y : b[x]){
        if (c[y]) continue;
        DFS1(y);
    }
}

int main(int argc, const char** argv) {
    inputData();
    for (int i = 1; i <= n; i++){
        if (num[i] == 0) DFS(i);
    }

    for (pii x : Bridge){
        int y = x.first;
        int z = x.second;
        b[z].push_back(y);
        b[y].push_back(z);
    }

    for (int i = 1; i <= n; i++){
        if (!c[i]){
            cnt = 0;
            DFS1(i);
            ans += 1LL * cnt*(cnt - 1)/2 - (cnt-1);
        }
    }
    cout << ans;
    return 0;
}