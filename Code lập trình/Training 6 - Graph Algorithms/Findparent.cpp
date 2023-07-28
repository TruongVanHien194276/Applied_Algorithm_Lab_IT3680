#include<bits/stdc++.h>

using namespace std;

const int MAX = 100010;

int n;
vector<vector<int> > treeNode;
int p[MAX];

void inputData(){
    cin >> n;
    treeNode.resize(n+1);
    for (int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        treeNode[u].push_back(v);
        treeNode[v].push_back(u);
    }

    for (int i = 1; i <= n; i++){
        p[i] = 0;
    }
}

void findParent(){
    queue<int> Q;
    Q.push(1);
    p[1] = 1;

    while (!Q.empty()){
        int x = Q.front(); 
        Q.pop();

        for (int v : treeNode[x]){
            if (p[v] == 0){
                p[v] = x;
                Q.push(v);
            }
        }
    }

    for (int i = 2; i <= n; i++){
        cout << p[i] << " ";
    }
}

int main(int argc, const char** argv) {
    inputData();
    findParent();
    return 0;
}