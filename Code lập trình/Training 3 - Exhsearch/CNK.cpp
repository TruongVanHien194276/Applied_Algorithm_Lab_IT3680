#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll n, m, k, t;

ll mulmod(ll a, ll b, ll m){
	ll res = 1;
	if (a == 0) return 0;
	if (b == 0) return 0;
	if (a == 1) return b;
	if (b == 1) return a;

	ll a2 = mulmod(a, b/2, m);
	if ((b&1) == 0) return a2%m + a2 %m;
	else return a%m + a2%m + a2%m;
}

ll PowerMod(ll a, ll n, ll m){
	ll ret = 1;
	while (n){
		if (n & 1){
			ret = mulmod(ret, a, m);
			ret %= m;
		}
		a = mulmod(a, a, m);
		a %= m;
		n /= 2;
	}
	return ret;
}

void solution(ll n, ll k, ll m){
	ll ans = 1;
	for (int i=1; i <= k; i++){
		ans = mulmod(ans, n-k+i, m);
		ans %= m;
	}

	ll res1 = 1;
	for (int j = 1; j <= k; j++){
		res1 = mulmod(res1, j, m);
		res1%= m;
	}

	ll res2 = PowerMod(res1, m-2, m);
	ans = mulmod(ans, res2, m);
	ans %= m;
	cout << ans << endl;
}

int main(int argc, const char** argv) {
	cin >> t;
	while(t--)
	{
		cin >> n >> k >> m;
		solution(n, k, m);
	}
}
