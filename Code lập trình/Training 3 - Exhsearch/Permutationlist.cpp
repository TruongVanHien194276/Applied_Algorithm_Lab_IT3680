#include<bits/stdc++.h>

using namespace std;

int main(int argc, const char** argv) {
	long long n, i, j = 1, k, l, g, s = 1;
	cin >> n >> k;
	bool f = false;
	for (s = 1; s < n+1; s++) {
		j = j * s;
		if (j >= k) {			
			f = true;
			break;
		}
	}
	if (!f) cout << "-1";
	else {
		int h[n];
		for (i = 0; i < n; i++) h[i] = i + 1;
		if (k == 1) {
			for (i = 0; i < n; i++) 
				cout << h[i] << " ";
		}else if (k == j && s == n){
			for (i = n; i > 0; i--)
				cout << i << " ";
		}else {
			while (k > 1) {
				j = 1;
				for (s = 1; s < n+1; s++) {
					j = j * s;
					if (j > k) break;
				}
				j = j / s;
				for (l = n-s+1; l <= n-s+k/j; l++)
					swap(h[n-s], h[l]);
				k = k % j;
				
				if (k == 0) prev_permutation(h+n-s, h+n);
			}
			
		    for (int i = 0; i < n; i++) 
				cout << h[i] << " ";
		}
	}
}