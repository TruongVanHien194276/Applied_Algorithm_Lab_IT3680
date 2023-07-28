#include<bits/stdc++.h>

using namespace std;

const int MAX = 10001;

int N,K,i;
int x[MAX];
int dem, cnt, t;

bool check(int v, int k){
    if (v == 0 && dem + 1 == i) return false;
    return true;
}

void solution(){
    cnt++;
    if (cnt == K) {
        for (int j = 1; j <= N; j++)
            cout << x[j] << " ";
        exit(0);
    }
}

void TRY(int k) {
    for (int v = 0; v <= 1; v++){
        if(check(v,k)){
            x[k] = v;
            if (v == 0) dem++;
            else{
                t = dem;
                dem = 0;
            }
            if (k == N) solution();
            else TRY(k + 1);
            if (v == 0) dem--;
            else dem = t;
        }
    }
}

int main(int argc, const char** argv) {
    cin >> N >> K >> i;
    cnt = 0;
    dem = 0;
    if (i == 1) {
		cout << -1 << endl; 
		return 0;
	}
    TRY(1);
    if (cnt < K) cout << -1 << endl;
}

