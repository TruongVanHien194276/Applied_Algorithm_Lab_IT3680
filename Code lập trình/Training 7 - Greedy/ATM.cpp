#include<bits/stdc++.h>
 
using namespace std;
 
unsigned long long fewestNumber = 0;
 
unsigned long long countOfSols(unsigned long long w, unsigned long long c){
	//v1 luu so cach chon cac to tien sao cho it to tien nhat
	//v2 luu so to tien it nhat sau moi luy thua
	vector<unsigned long long> v1;
	vector<unsigned long long> v2;
	int flag = 0;
	// tmp: so luong dong 5000 * 10^c lon nhat can dung
	unsigned long long tmp = 0;
	if (w % 1000 != 0 || w <= 0) return 0;
	else{
		w = w / 1000;
		unsigned long long x = pow(10,c+1);
		unsigned long long p = pow(10,c);

		if (w >= x){
			tmp = w / x;
			w = w % x;
			// xet so dau tien sau khi w % x
			unsigned long long i = w / p;
			if (i < 5 && i > 0){
				tmp --;
				flag = 1;
				w = w + 5 * p;
			}
		}

		while (c != -1) {
			p = pow(10,c);
			unsigned long long a = w / p;
			// neu a = cac so sau thi co 1 cach chon a va can 1 to
			if (a == 1 || a == 2 || a == 3 || a == 5){
				v1.push_back(1);
				v2.push_back(1);
			}
			// neu a = cac so sau thi co 1 cach chon a va can 2 to
			else if (a == 7 || a == 8){
				v1.push_back(1);
				v2.push_back(2);
			}	
			// neu a == 4 hoac a == 6 thi co 2 cach chon a va can 2 to
			else if (a == 4 || a == 6){
				v1. push_back(2);
				v2.push_back(2);
			}
			// neu a == 9 thi co  3 cach chon a va can it nhat 3 to
			else if (a == 9){
				v1.push_back(3);
				v2.push_back(3);
			}

			w = w % p;
			c--;
		}
	}

	unsigned long long result = 1;
	for (int i = 0; i < v1.size(); i++){
		result *= v1[i];	
	}

	if (flag == 0) fewestNumber += tmp*2;
	else fewestNumber += tmp *2 + 1;

	for (int i = 0; i < v2.size(); i++){
		fewestNumber += v2[i];
	}
	
	return result;	
}
 
int main(int argc, const char** argv) {
	int n;
	cin >> n;
	unsigned long long M[n][2];
	for (int i = 0; i < n; i++){
		cin >> M[i][0];
		cin >> M[i][1];
	}

	for (int i = 0; i < n; i++){
		unsigned long long result = countOfSols(M[i][0], M[i][1]);

		if (result != 0) cout << fewestNumber << " " << result << endl;
		else cout << 0 << endl;

		fewestNumber = 0;
	}

	return 0;
}