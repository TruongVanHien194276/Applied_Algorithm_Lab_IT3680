#include<bits/stdc++.h>

using namespace std;

const int MAX = 1000010;

int n, a[MAX], m;
int start[MAX], finish[MAX];
int M[20][MAX];

void inputData(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        start[i] = tmp1;
        finish[i] = tmp2;
    }
}

void pre_processing(){
    for (int i = 0; i < n; i++) M[0][i] = i;

    for (int j = 1; (1<<j) <= n; j++){
        for (int i = 0; i+(1<<j)-1 < n; i++){
            if (a[M[j-1][i]] < a[M[j-1][i+(1<<(j-1))]]) M[j][i] = M[j-1][i];
            else M[j][i] = M[j-1][i + (1<<(j-1))];
        }
    }
}

int rmq(int i, int j){
    int k = floor(log2(j-i+1));

    if (a[M[k][i]] <= a[M[k][j-(1<<k)+1]]) return a[M[k][i]];
    else return a[M[k][j-(1<<k)+1]];
}

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    inputData();
    pre_processing();
    int res = 0;
    for (int i = 0; i < m; i++){
        res += rmq(start[i], finish[i]);
    }
    cout << res;
    return 0;
}