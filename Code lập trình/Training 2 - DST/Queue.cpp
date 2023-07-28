#include<bits/stdc++.h>

using namespace std;

const int N=1e5+100;

struct node{  
	int l;
	int r;
	int sum;
}p[N<<2];

int a[N], ans[N];

void pushup(int cur){
	p[cur].sum = min(p[cur<<1].sum, p[cur<<1|1].sum);
}

void build(int l, int r, int cur){
	p[cur].l = l;
	p[cur].r = r;
	p[cur].sum = 0;
	if (l==r) return ;
	int mid = (l + r)/2 ;
	build(l, mid, cur<<1);
	build(mid + 1, r, cur<<1|1);
}

void update(int v,int pos,int cur){
	int L = p[cur].l;
	int R = p[cur].r;
	if (L == R) {
		p[cur].sum = v;
		return ;
	}

	int mid = (L + R)/2;
	if (pos <= mid) update(v, pos, cur<<1);
	else update(v, pos, cur<<1|1);
	pushup(cur);
}

int query(int v, int cur){
	int L = p[cur].l;
	int R = p[cur].r;
	if (v <= p[cur].sum) return 0;
	if (L == R) return L;
	int res = 0;
	res = query(v, cur<<1|1);
	if (res == 0) res = query(v, cur<<1);
	return res;
}

int main(int argc, const char** argv) {
	int x, n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	build(1, n, 1);
	for (int i = n; i >= 1; i--){
		x = query(a[i], 1);

		if (x == 0) ans[i] = -1;
		else ans[i] = x - i -1;

		update(a[i], i, 1);
	}
	for (int i = 1; i <= n;i++){
		cout << ans[i] << " ";
	}
	return 0;
}