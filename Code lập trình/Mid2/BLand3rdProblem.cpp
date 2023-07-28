#include<bits/stdc++.h>

using namespace std;

const int MAX = 510;

int n;
int x[600], y[600];

struct Graph{
    int u;    
    int v;    
    int weight; 

    Graph(int _u, int _v, int _weight) : u(_u), v(_v), weight(_weight) {}
};

vector<Graph> Graphs;

void inputData(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
}

struct Union_Find{
    vector<int> iParent;
    Union_Find(int n){
        iParent = vector<int>(n);
        for (int i = 0; i < n; i++){
            iParent[i] = i;
        }
    }
    // toan tu Find va Union
    int find(int x){
        if (iParent[x] == x) return x;
        else{
            iParent[x] = find(iParent[x]); 
            return iParent[x];
        }
    }

    void unite(int x, int y){
        iParent[find(x)] = find(y);
    }
};

bool cmp(const Graph &a, const Graph &b){
    return a.weight < b.weight;
}

vector<Graph> KruskalAlgorithm(int n, vector<Graph> Graphs){
    Union_Find uf(n);
    sort(Graphs.begin(), Graphs.end(), cmp);
    vector<Graph> ans;
    for (int i = 0; i < Graphs.size(); i++){
        int u = Graphs[i].u;
        int v = Graphs[i].v;
        if (uf.find(u) != uf.find(v)){
            uf.unite(u, v);
            ans.push_back(Graphs[i]);
        }
    }
    return ans;
}

int main(int argc, const char** argv) {
    inputData();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            int dis = floor(sqrt((double)((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))));
            Graphs.push_back(Graph(i, j, dis));
        }
    }
    vector<Graph> gp = KruskalAlgorithm(n, Graphs);
    cout << gp.back().weight;
}
