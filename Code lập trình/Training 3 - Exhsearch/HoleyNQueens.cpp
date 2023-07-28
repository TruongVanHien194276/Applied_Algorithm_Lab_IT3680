#include <bits/stdc++.h>

using namespace std;

const int N = 20;

bool a[N+N], b[N+N], c[N], h[N][N];
int n, m, result;

void Holey(int k){
    if (k == n){
        result += 1;
        return;
    }
    
    for (int i = 0; i < n; i++){
        if (!c[i] && !a[k+i] && !b[k-i+N] && !h[k][i]){
            c[i] = a[k+i] = b[k-i+N] = true;
            Holey(k+1);
            c[i] = a[k+i] = b[k-i+N] = false;
        }
    }
}

int main(int argc, const char** argv) {
    while (cin >> n >> m){
        if (n == 0 && m == 0) break;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        memset(h, 0, sizeof(h));

        for (int i = 0; i < m; i++){
            int x, y;
            cin >> x >> y;
            if (x > 0 && y > 0) h[--x][--y] = true;
        }

        result = 0;
        Holey(0);
        cout << result << endl;
    }
    return 0;
}