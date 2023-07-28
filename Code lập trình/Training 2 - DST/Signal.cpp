#include<bits/stdc++.h>
#define N 200000

using namespace std;

int n, b, a[N];
int maxLeft[N], maxRight[N];

void input(){
    cin >> n >> b;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

int Signal(){
    maxLeft[1] = a[1];
    for (int i = 2; i <= n; i++){
        maxLeft[i] = max(maxLeft[i-1], a[i]);
    }

    maxRight[n] = a[n];
    for (int i = n-1; i >= 1; i--){
        maxRight[i] = max(maxRight[i+1], a[i]);
    }

    int result = -1;
    for (int i = 1; i <= n; i++){
        if ((maxLeft[i] - a[i] >= b) && (maxRight[i] - a[i] >= b)){
            result = max(maxLeft[i] - a[i] + maxRight[i] - a[i], result);
        }
    }
    return result;
}

int main(int argc, const char** argv) {
    input();
    cout << Signal();
    return 0;
}