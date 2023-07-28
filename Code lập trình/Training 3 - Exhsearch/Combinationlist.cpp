#include<bits/stdc++.h>

using namespace std;

int main(int argc, const char** argv) {
    int n, m, i, j, d = 1, k;
	bool f = false;
	cin >> n >> m >> k;
	int h[m];
	for (i = 0; i < m; i++) {
		h[i] = i + 1;
	}
	
	while (d < k && !f){
		f = true;
		if (h[m-1] < n) {
			h[m-1]++;
			d++;
			f = false;
		}else{
			for (i = m - 2; i >= 0; i--) {
				if (h[i] < h[i+1]-1){
					h[i]++;
					for(j = i+1; j<m; j++) h[j] = h[j-1] + 1;
					d++;
					f = false;
					break;
				}
			}
		}
	}
	
	if (!f) 
		for (i = 0; i < m; i++) cout << h[i] << " ";
	else cout << "-1";
}