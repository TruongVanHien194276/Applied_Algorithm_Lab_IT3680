#include<bits/stdc++.h>

using namespace std;

const int MAX = 1001;

int n, m;
int X[MAX], Y[MAX];
int s[MAX][MAX];

void inputData(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> X[i];
    }
    for (int j = 1; j <= m; j++){
        cin >> Y[j];
    }
}

int LCS(){
    for (int i = 0; i <= n; i++) s[i][0] = 0;
    for (int j = 0; j <= m; j++) s[0][j] = 0;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (X[i] == Y[j]) s[i][j] = 1 + s[i-1][j-1];
            else{
                if (s[i-1][j] > s[i][j-1]) s[i][j] = s[i-1][j];
                else s[i][j] = s[i][j-1];
            }
        }
    }
    return s[n][m];
}

int main(int argc, const char** argv) {
    inputData();
    cout << LCS();
    return 0;
}