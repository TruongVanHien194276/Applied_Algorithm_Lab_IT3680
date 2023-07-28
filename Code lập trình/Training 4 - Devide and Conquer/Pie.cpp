#include<bits/stdc++.h>

using namespace std;

const int MAX = 10000;
const double PI = 4*atan(1);

int N, F;
int cnt = 1e9;
int r[MAX];
double S[MAX];
double MAXS;

void inputData(){
    MAXS = 0;
    cin >> N >> F;
    for(int i = 0; i < N; i++){
        cin >> r[i];
        S[i] = PI * r[i] * r[i];
        MAXS = max(S[i], MAXS);
    }
}

bool check(double s){
    int sum = 0;
    for (int i = 0; i < N; i++){
        sum += floor(S[i]/s); 
        // floor(double x): trả về giá trị nguyên lớn nhất nhỏ hơn hoặc bằng x 
    }
    return sum > F;
}

double PIE(double left, double right){
    double mid = (left + right)/2;
    cnt--;

    if (right - left < 1e-7 || cnt < 0) return mid;
    else{
        if (check(mid)) return PIE(mid, right);
        else return PIE(left, mid);
    }
}

int main(int argc, const char** argv) {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++){
        inputData();
        cout << setprecision(6) << fixed << PIE(0, MAXS) << endl;
    }
    return 0;
}