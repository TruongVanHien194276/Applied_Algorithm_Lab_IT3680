#include<bits/stdc++.h>

using namespace std;

int N, Q;
vector<int> vt;
int dgg; // Độ gập ghềnh

void findDGG(){
    dgg = 1;
    for (int i = 1; i < N; i++){
        if (vt[i] != vt[i-1]) dgg++;
    }
}

// Đọc độ gập ghềnh của đường ban đầu
void inputData1(){
    cin >> N;
    for (int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        vt.push_back(temp);
    }
    findDGG();
    // Đưa vào độ gập ghềnh tại thời điểm hiện tại
}

// Hàm xử lý độ gập ghềnh của đường đi sau mỗi lần thay đổi
int Reroad(int p, int c){
    p--;
    int TFirst = 1; // Độ gập ghềnh tại đoạn [p-1, p+1] lúc chưa thay đổi
    if (vt[p] != vt[p-1] && p-1 >= 0) TFirst++;
    if (vt[p+1] != vt[p] && p+1 < N) TFirst++;

    int TSecond = 1; // Độ gập ghềnh tại đoạn [p-1, p+1] lúc đã sửa đổi
    vt[p] = c; // Sửa lại đường p bằng loại nhựa c
    if (vt[p] != vt[p-1] && p-1 >= 0) TSecond++;
    if (vt[p+1] != vt[p] && p+1 < N) TSecond++;

    int T = TSecond - TFirst;
    dgg += T;
    return dgg;
}

// Đọc những thay đổi và xử lý từng thay đổi
void inputData2(){
    cin >> Q;
    for (int i = 0; i < Q; i++){
        int p, c;
        cin >> p >> c;

        // Xử lý từng test và in ra kết quả
        cout << Reroad(p, c) << endl;
    }
}

int main(int argc, const char** argv) {
    inputData1();
    inputData2();
    return 0;
}