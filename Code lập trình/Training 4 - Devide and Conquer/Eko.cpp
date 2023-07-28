#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000;

int n;
long long m;
long long height[MAX];
long long maxHeight = 0;

void inputData(){
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> height[i];
        maxHeight = max(height[i], maxHeight);
    }
}

// Tính toán tổng số mét gỗ được cắt
long long totalWood(long long cut){
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        long long temp = height[i] - cut;
        if (temp < 0) temp = 0;
        sum += temp;
    }
    return sum;
}

long long EKO(long long left, long long right){
    long long mid = (left + right)/2;
    long long total = totalWood(mid);

    if (right - left == 1 || total == m) return mid;
    else{
        if (total < m) return EKO(left, mid);
        else return EKO(mid, right);
    }
}

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    inputData();
    cout << EKO(0, maxHeight);
    return 0;
}