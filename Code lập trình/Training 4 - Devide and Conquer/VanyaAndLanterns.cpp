/*#include<bits/stdc++.h>

using namespace std;

const int MAX = 1000;
long long n, m, k;
long long a[MAX];
int f[MAX], cnt[MAX];

void SOLVE(){
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    long long result = 0;
    for (int i = 1; i < n; i++) {
        result = max(result, a[i] - a[i-1]);
    }
    result = max(result, a[0]*2);
    result = max(result, (m - a[n-1])*2);
    cout << fixed << setprecision(10) << result/2.0 << endl;
}


int main(int argc, const char** argv) {
    SOLVE();
    return 0;
}*/

#include<bits/stdc++.h>

using namespace std;

const int MAX = 100;
long long F[MAX];

char Fibo(int n, long long k){
    if (n == 1) return 'A';
    if (n == 2) return 'B';
    if (k <= F[n-2]) return Fibo(n-2, k);
    return Fibo(n-1, k - F[n-2]);
}

int main(int argc, const char** argv) {
    F[1] = 1, F[2] = 1;
    for (int i = 3; i <= MAX; i++){
        F[i] = F[i-1] + F[i-2];
    }
    int n;
    long long k;
    cin >> n >> k;
    cout << Fibo(n, k); 
    return 0;
}


