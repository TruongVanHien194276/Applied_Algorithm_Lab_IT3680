#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > Vt1, Vt2;
int T, L, C, mt[2001][2001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> T;
	while (T--){
		int rs = 0;
		Vt1.clear();
		Vt2.clear();

		cin >> L >> C;
		for(int i = 0; i <= 2000; i++){
			for(int j = 0; j <= 2000; j++){
				mt[i][j] = 0;
			}
		}

		for (int i = 0; i < L; i++){
			for (int j = 0; j < C; j++){
				int a;
				cin >> a;
				if(a == 1){
					Vt1.push_back({i, j});
				}
			}
		}

		for (int i = 0; i < L; i++){
			for (int j = 0; j < C; j++){
				int b;
				cin >> b;
				if(b == 1){
					Vt2.push_back({i, j});
				}
			}
		}
		for (int i = 0; i < Vt1.size(); i++){
			for (int j = 0; j < Vt2.size(); j++){
				mt[Vt1[i].first - Vt2[j].first + 1000][Vt1[i].second - Vt2[j].second + 1000]++;
				rs = max(rs, mt[Vt1[i].first - Vt2[j].first + 1000][Vt1[i].second - Vt2[j].second + 1000]);
			}
		}
		cout << rs << endl;
	}
    return 0;
}