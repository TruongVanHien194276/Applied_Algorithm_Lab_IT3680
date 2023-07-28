#include<bits/stdc++.h>

using namespace std;

const int MAX = 100000;
int n, L1, L2;
long long a[100001];

void GoalMining(){
	long long result = 0;
	long long x[MAX] = {0};
	for(int i = 0; i < L1; i++){
		x[i] = a[i];
	}

	for(int i = L1; i < n; i++){
		for(int j = i - L2; j <= i - L1; j++){
			if(j >= 0) x[i] = max(x[i], a[i] + x[j]);
		}
	}

	for(int i = n - L1; i < n; i++){
		result = max(result, x[i]);
	}
	cout << result;
}

int main(int argc, const char** argv) {
    cin >> n >> L1 >> L2;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	GoalMining();
	return 0;
}