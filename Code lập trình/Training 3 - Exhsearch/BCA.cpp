#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int MAX = 35;

int m, n; 
// m: số giáo viên
// n: số lượng khóa học
int course[MAX];
int TeacherChoice[MAX];
vector<vector<int> > listOfCourse; // Danh sách khóa học mà từng giáo viên có thể dạy
vector<vector<int> > listOfPairsOfConflicting; // Danh sách cặp khóa học xung đột
int LoadOfTeacher[MAX];
int LoadMaxOfTeacher = 0;
int minAll = 1e9;

void inputData(){
    cin >> m >> n;
    listOfCourse.resize(m+1);

    int k; 
    for (int i = 0; i < m; i++){
        cin >> k; // Số lượng khóa học mà từng giáo viên i có thể dạy
        for (int j = 0; j < k; j++){
            int temp; // Nhập lần lượt khóa học mà giáo viên i có thể dạy
            cin >> temp;
            listOfCourse[i].push_back(temp); // Giáo viên i có thể dạy khóa học có số là temp
        }
    }

    int K; // Số lượng cặp khóa học xung đột
    cin >> K;
    listOfPairsOfConflicting.resize(n+1);
    for (int i = 0; i < K; i++){
        int t1, t2;
        cin >> t1 >> t2;
        listOfPairsOfConflicting[t1].push_back(t2); // Khóa t1 xung đột với t2
        listOfPairsOfConflicting[t2].push_back(t1); // Vì t1 xung đột với t2 nên t2 cũng xung đột với t1
    }
}

bool check(int a, int i){
    // Kiểm tra xem khóa học a có gắn cho giáo viên i ?
    int tick = 0;
    for (int j = 0; j < listOfCourse[i].size(); j++){
        if (listOfCourse[i].at(j) == a)
            tick++;
    }
    if (tick == 0) return false;

    for (int j = 0; j < listOfPairsOfConflicting[a].size(); j++){
        if (course[listOfPairsOfConflicting[a].at(j)] == i && listOfPairsOfConflicting[a].at(j) < a)
            return false;
    }

    return true;
}

void solution(){
    minAll = min(minAll, LoadMaxOfTeacher);
}

void TryBCA(int a){
    for (int i = 0; i < m; i++){
        // Duyệt từng giáo viên i
        if (check(a, i)){
            course[a] = i;
            LoadOfTeacher[i]++;
            int pre = LoadMaxOfTeacher;
            LoadMaxOfTeacher = max(LoadMaxOfTeacher, LoadOfTeacher[i]);
            
            if (a == n) solution();
            else{
                if (LoadMaxOfTeacher < minAll) TryBCA(a+1);
            }

            LoadOfTeacher[i]--;
            LoadMaxOfTeacher = pre;
        }
    }
}

int main(int argc, const char** argv) {
    inputData();
    TryBCA(1);
    cout << minAll;
    return 0;
}
