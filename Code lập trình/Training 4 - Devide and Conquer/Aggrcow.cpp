#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000;

int N, C;
long long x[MAX];
long long result;

void inputData(){
    result = 0;
    cin >> N >> C;
    for (int i = 0; i < N; i++){
        cin >> x[i];
    }
    sort(x, x + N);
}

void AGGRCOW(long long left, long long right){
    if (left > right) return;

    long long mid = (left + right)/2;
    long long f = x[0];
    int count = 1;
    for (int i = 1; i < N; i++){
        if (x[i] - f >= mid){
            f = x[i];
            count++;
        }
    }

    if (count < C) AGGRCOW(left, mid - 1);
    else{
        result = mid;
        AGGRCOW(mid + 1, right);
    }
}

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++){
        inputData();
        AGGRCOW(0, 1000000000);
        cout << result << endl;
    }
    return 0;
}