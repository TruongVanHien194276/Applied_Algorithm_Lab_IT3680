#include<bits/stdc++.h>

using namespace std;

int n, k;
vector<pair<int, int> > pos;
vector<pair<int, int> > neg;

void input(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        int x, m;
        cin >> x >> m;
        if (x > 0){
            pos.push_back(make_pair(x, m));
        }else{
            neg.push_back(make_pair(-x, m));
        }
    }
}

long long POSTMAN(vector<pair<int, int> > vt){
    // Sắp xếp theo thứ tự tăng dần
    // Sắp xếp pair: ưu tiên so sánh first, nếu first bằng nhau thì so sánh second
    sort(vt.begin(), vt.end());

    long long res = 0;
    int lef = 0;
    for (int i = vt.size() - 1; i >= 0; i--){
        int x = vt[i].first;
        int m = vt[i].second;

        if (lef != 0){ // Nếu có phần dư ở trước chuyển cho điểm hiện tại
            if (lef >= m){ // Nếu phần dư >= số hàng cần chuyển cho điểm hiện tại
                lef -= m;
                continue;
            }else{ // Nếu không đủ
                m -= lef;
            }
        }

        int c = m / k + (m % k != 0); // Số lần chuyển
        res += 1LL * 2 * c * x; // Đoạn đường cần phải đi
        // ép kiểu phép nhân thành long long
        lef = c * k - m; // Số dư kiện hàng
    }
    return res;
}

int main(int argc, const char** argv) {
    input();
    cout << POSTMAN(pos) + POSTMAN(neg);
    return 0;
}