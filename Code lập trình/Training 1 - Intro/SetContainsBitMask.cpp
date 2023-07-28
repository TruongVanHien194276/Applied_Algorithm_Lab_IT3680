#include<bits/stdc++.h>

using namespace std;

int n, m, a[32], b[32];

// Thuật toán tìm kiếm nhị phân
bool CheckBinarySearch(int arr[], int left, int right, int x) {
  if (right >= left) {
    int mid = (left + right) / 2;
 
    if (arr[mid] == x) return true; // Nếu arr[mid] = x, trả về true
    else if (arr[mid] > x) return CheckBinarySearch(arr, left, mid - 1, x); 
        // Nếu arr[mid] > x, thực hiện tìm kiếm nửa trái của mảng
    else return CheckBinarySearch(arr, mid + 1, right, x);
        // Nếu arr[mid] < x, thực hiện tìm kiếm nửa phải của mảng

  }else return false; // Nếu không tìm thấy
}
int checkAppear(){
    for (int i = 0; i < m; i++){
        if (!CheckBinarySearch(a, 0, n-1, b[i])){
            return 0;
            break;
        }
    }
    return 1;
}
int main(int argc, const char** argv) {
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }

    cout << checkAppear();
    return 0;
}