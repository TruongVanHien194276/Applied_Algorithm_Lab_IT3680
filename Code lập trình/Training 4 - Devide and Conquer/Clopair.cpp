#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

int p1, p2;
double result;

struct point{
	long long x, y;
	int id;
};

point a[MAX];

bool cmpX(point a, point b){
	return a.x < b.x;
}

bool cmpY(point a, point b){
	return a.y < b.y;
}

double dist(point a, point b){
	return sqrt((double)(a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void update(point a, point b){
	double x = dist(a, b);
	if (x < result) {
		result = x;
		p1 = a.id;
		p2 = b.id;
	}
}

void closest(int l, int r){
	if (l >= r) return;
	if (l + 1 == r) {
		update(a[l], a[r]);
		return;
	}

	int mid = (l + r) / 2;
	int mid_x = a[mid].x;

	closest(l, mid);
	closest(mid + 1, r);

	vector<point> vt;
	for (int i = l; i <= r; i++){
		if (abs(a[i].x - mid_x) <= result) {
			vt.push_back(a[i]);
		}
	}

	sort(vt.begin(), vt.end(), cmpY);

	double temp = result;
	for (int i = 0; i < vt.size(); i++){
		int j = i + 1;
		while(j < vt.size() && vt[j].y - vt[i].y <= temp){
			update(vt[i], vt[j]);
			j++;
		}
	}
}

int main(int argc, const char** argv) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i].x >> a[i].y;
		a[i].id = i;
	}

	sort(a, a + n, cmpX);
	result = 1e9;
	
	closest(0, n - 1);
	cout << fixed << setprecision(6) << min(p1, p2) << " " << max(p1, p2) << " " << result << endl;

	return 0;
}