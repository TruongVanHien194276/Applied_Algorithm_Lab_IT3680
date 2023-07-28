#include<bits/stdc++.h>

using namespace std;

const int MAX = 1000010;

struct Plant{
    int start;
    int en;
};

int n;
int t[MAX];
Plant t_time[MAX];

void inputData(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> t[i];
    }

    sort(t, t+n, [] (int a, int b) {
        return a > b;
    });
}

void solve(){
    int time = 0;
    for (int i = 0; i < n; i++){
        t_time[i].start = time;
        t_time[i].en = time + t[i] + 1;
        time += 1;
    }

    int maxTime = 0;
    for (int i = 0; i < n; i++){
        maxTime = max(maxTime, t_time[i].en);
    }

    cout << maxTime + 1;
}

int main(int argc, const char** argv) {
    inputData();
    solve();
    return 0;
}