#include<bits/stdc++.h>

using namespace std;

const int maxN = 1000005;

int n, L1, L2, a[maxN], dp[maxN];
vector<int> b[maxN];

void inputData(){
    cin >> n >> L1 >> L2;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

void GoalMiningHard(){
    for (int i = 1; i <= L1; i++){
        dp[i] = a[i];
    }

    priority_queue<int> Q;
    Q.push(a[1]);
    for (int i = L1 + 1; i <= n; i++){
        int t = Q.top();
        dp[i] = t + a[i];
        Q.push(dp[i-L1+1]);
    }
    int result = 0;
    for(int i = n - L2; i <= n; i++){
        result = max(result, dp[i]);
    }
    cout << result;
}

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    inputData();
    GoalMiningHard();
}

