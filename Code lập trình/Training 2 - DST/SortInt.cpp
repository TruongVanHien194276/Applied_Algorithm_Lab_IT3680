#include<bits/stdc++.h>
 
using namespace std;
 
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
 
int partition (int arr[], int low, int high){
    int pivot = arr[high];    
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}
 
void quickSort(int arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
int main(int argc, const char** argv) {
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    quickSort(A, 0, n-1);
    for (int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    return 0;
}