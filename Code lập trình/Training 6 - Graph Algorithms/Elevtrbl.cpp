#include<bits/stdc++.h>

using namespace std;

int f, s, g, u, d;
int dis[1000100];
queue<int> Q;

void check(int x, int y){
    if (y < 1 || y > f) return;
    if (dis[y] >= 0) return;

    dis[y] = dis[x] + 1;
    Q.push(y);
}

int main(int argc, const char** argv) {
    cin >> f >> s >> g >> u >> d;
    memset(dis, -1, sizeof(dis));
    dis[s] = 0;
    Q.push(s);

    while (!Q.empty()){
        int a = Q.front();
        Q.pop();
        check(a, a + u);
        check(a, a - d);
    }

    if (dis[g] == -1){
        cout << "use the stairs";
    }else{
        cout << dis[g];
    }
    return 0;
}