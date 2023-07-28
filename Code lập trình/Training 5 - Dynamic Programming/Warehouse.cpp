#include<bits/stdc++.h>

using namespace std;

const int MAX = 1000;

int N, T, D;
int a[MAX], t[MAX], res[MAX][MAX] = {0};

void inputData(){
	cin >> N >> T >> D;
	for (int i = 1; i <= N; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= N; i++){
		cin >> t[i];
	}
}

void Warehouse(){
	for (int i = 1; i <= N; i++){
		for (int k = 1; k <= T; k++){
			res[i][k] = a[i];
			if(k < t[i]){
				res[i][k] = 0;
				continue;
			}
			if(i>=D){
				int tmp = 0;
				for (int j = i-D; j < i; j++){
					tmp = max(res[j][k-t[i]] + a[i], tmp);
					res[i][k] = tmp;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= T; j++){
			ans = max(ans, res[i][j]);
		}
	}
	cout << ans;
}

int main(int argc, const char** argv) {
    inputData();
    Warehouse();
	return 0;
}