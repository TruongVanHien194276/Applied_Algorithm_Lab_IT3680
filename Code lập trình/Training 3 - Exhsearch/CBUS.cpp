#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int MAX = 30;

int n, k;
// n: số hành khách
// k: số hành khách tối đa trên 1 xe bus
int distanceMin = INF;
int distanceCur = 0;
int passengers = 0; // Số hành khách trên xe hiện tại
int c[MAX][MAX]; // Ma trận khoảng cách
bool visited[MAX]; // đánh dấu
int x[MAX]; // Lưu trữ vị trí đường đi
int minDist;

void inputData(){
    cin >> n >> k;
    for (int i = 0; i <= 2*n; i++){
        for (int j = 0; j <= 2*n; j++){
            cin >> c[i][j]; // Khoảng cách từ điểm i đến điểm j
        }
    }
}

void findMin(){
    minDist = INF;
    for (int i = 0; i <= 2*n; i++){
        for (int j = 0; j <= 2*n; j++){
            if (i != j){
                minDist = min(minDist, c[i][j]);
            }
        }
    }
    return;
}

bool check(int a, int i){
    if (passengers == k){
        if (i <= n) return false;
    }

    if (c[x[a-1]][i] == 0) return false;
    // Nếu không có đường đi tới nó -> false

    if (i > n){
        if (!visited[i-n]) return false;
    }

    if (!visited[i]) return true;

    return false;
}

void solution(){
    distanceCur += c[x[2*n]][0];
    distanceMin = min(distanceMin, distanceCur);
    distanceCur -= c[x[2*n]][0];
}

void TryCBUS(int a){
    for (int i = 1; i <= 2*n; i++){
        if (check(a, i)){
            x[a] = i;
            visited[i] = true;
            distanceCur += c[x[a-1]][i];
            
            if (i <= n) passengers++;
            else passengers--;

            if (a == 2*n) solution();
            else{
                if (distanceCur + (2*n - a)*minDist < distanceMin){
                    TryCBUS(a+1);
                }
            }

            if (i <= n) passengers--;
            else passengers++;

            visited[i] = false;
            distanceCur -= c[x[a-1]][i];
        }
    }
}

int main(int argc, const char** argv) {
    inputData();
    findMin();
    x[0] = 0;
    TryCBUS(1);
    cout << distanceMin;
    return 0;
}