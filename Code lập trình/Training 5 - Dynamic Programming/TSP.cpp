#include<bits/stdc++.h>

using namespace std;

const int N = 21;
const int INF = 1e9;

int n, m;
int C[N][N];
int f[N][1 << N];

int getbit(int bit, int t){
    return (bit >> t) & 1;
}

void inputData(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            C[i][j] = INF;
        }
    }
    
    for (int k = 1; k <= m; k++){
        int i, j, c;
        cin >> i >> j >> c;
        C[i][j] = c;
    }
}

int TSP(int t, int bit){
    if (f[t][bit] != -1) return f[t][bit];
    if (bit == (1 << n)-1) return f[t][bit] = C[t][1];

    f[t][bit] = INF;
    for (int i = 2; i <= n; i++){
        if (getbit(bit, i-1) == 0){
            f[t][bit] = min(f[t][bit], TSP(i, bit + (1 << (i-1))) + C[t][i]);
        }
    }
    return f[t][bit];
}

int main(int argc, const char** argv) {
    inputData();
    memset(f, -1, sizeof(f));
    cout << TSP(1, 1);
    return 0;
}
