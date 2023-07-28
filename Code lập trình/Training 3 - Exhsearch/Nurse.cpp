#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
int n, k1, k2;
int d = 0;

void NURSE(int a[], int x) {
	int i;
	if (x == n) {
		if ((a[x - 1] >= k1 && a[x - 1] <= k2) || a[x - 1] == 0) {
			d = (d + 1) % MOD;
		}
	} else {
		if (a[x - 1] < k2) {
			a[x] = a[x - 1] + 1;
			NURSE(a, x + 1);
		}
		if (a[x - 1] >= k1) {
			a[x] = 0;
			NURSE(a, x + 1);
		}
	}
}

int main(int argc, const char** argv) {
	cin >> n >> k1 >> k2;
	int a[n];
	a[0] = 1;
	NURSE(a, 1);
	a[0] = 0;
	NURSE(a, 1);
	cout << d;
    return 0;
}