#include<bits/stdc++.h>

using namespace std;

int main(int argc, const char** argv) {
    int n, m, i, j;
	bool f = true;
	cin >> n >> m;
	int h[m];
	for (i = 0; i < m; i++) {
		cin >> h[i];
	}

	if (h[m-1] < n) {
		h[m-1]++;
		f = false;
	}else{
		for (i = m - 2; i >= 0; i--) {
			if (h[i] < h[i+1]-1){
				h[i]++;
				for (j = i+1; j<m; j++) h[j] = h[j-1] + 1;
				f = false;
				break;
			}
		}
	}
	
	if (!f) 
		for (i = 0; i < m; i++) cout << h[i] << " ";
	else cout << "-1";
}
