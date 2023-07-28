 
#include<iostream>
#define MAX 20
using namespace std;
 
int n;
int Bool[MAX] = {false};//Đánh dấu chưa có phần tử nào sử dụng hết
int A[MAX];//Lưu hoán vị vào mảng A
 
void solution(){
    for (int i = 1; i <= n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}
 
void TRY(int k) {
    for (int i = 1; i <= n; i++) {
        //Kiểm tra nếu phần tử chưa được chọn thì sẽ đánh dấu
        if (!Bool[i]) {
            A[k] = i; // Lưu một phần tử vào hoán vị
            Bool[i] = true;//Đánh dấu đã dùng

            if (k == n) solution();
            else TRY(k+1);

            Bool[i] = false;
        }
    }
}
 
int main(int argc, const char** argv) {
    cin >> n;
    TRY(1);
    return 0;
}