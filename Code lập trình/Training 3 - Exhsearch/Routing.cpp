#include <bits/stdc++.h>

using namespace std;

const int N = 1001;
const int INF = 1e9;

int leng;
long c[N][N], place[N];
long x[N], xopt[N], fk, fopt, cmin = INF;

void init(){
    x[0] = place[0];
    x[leng] = place[leng];
    fk = 0;
    fopt = INF;
}

bool visit( int place, int k ){
    for (int i = 1; i <= k; i++){
        if (place == x[i]) return false;
    }
    return true;
}

void process(int k){
    for (int y = 1; y < leng; y++){
        if (!visit(place[y],k)) continue;
        if (!c[x[k-1]][place[y]]) continue;
        if (k + 1 == leng) {
            if (!c[place[y]][place[leng]]) continue;
        }

        x[k] = place[y];
        fk += c[x[k-1]][place[y]];

        if (k + 1 == leng){
            if (fk + c[place[y]][place[leng]] < fopt){
                fopt = fk + c[place[y]][place[leng]];
            }
        }else{
            if (fk + cmin * (leng - k - 1) < fopt) process(k + 1);
        }
        
        fk -= c[x[k-1]][place[y]];
        x[k] = 0;
    }
}

void print() {
    if (fopt == INF) fopt = 0;
    cout << fopt << endl;
}

int main(int argc, const char** argv) {
    int n, r;
    cin >> n >> r;
    string person[r + 1];
    for ( int i = 1 ; i <= n; i++)
    for ( int j = 1 ; j <= n; j++){
        cin >> c[i][j];
        if (c[i][j] != 0){
            cmin = (cmin > c[i][j]) ? c[i][j] : cmin;
        }
    }
    for (int j = 0; j <= r; j++) {
        getline(cin, person[j]);
    }
    for (int j = 1; j <= r; j++){
        stringstream ss;
            ss << person[j];
        vector<long> a;
        while(!ss.eof()){
            int x;
            ss >> x;
            a.push_back(x);
        }
        leng = a.size() - 1;
        for (int i = 0; i <= leng; i++){
            place[i] = a[i];
        }
        init();
        process(1);
        print();
    }
    return 0;
}