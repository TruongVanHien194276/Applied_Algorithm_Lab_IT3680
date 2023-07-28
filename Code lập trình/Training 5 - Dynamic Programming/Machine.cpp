#include <bits/stdc++.h>

using namespace std;

const int MAX = 2000000;

int n;
vector<pair<int, int> > vt;
int result = 0;
int solution[MAX];

bool sortbyfirst(const pair<int, int> &a, const pair<int, int> &b){
    return a.first < b.first;
}

int main(int argc, const char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
    cout.tie(0);
    memset(solution, -1, sizeof(solution));
    cin >> n;
    int temp1, temp2;
    for (int i = 0; i < n; i++){
        cin >> temp1 >> temp2;
        vt.push_back(make_pair(temp1, temp2));
    }
    sort(vt.begin(), vt.end(), sortbyfirst);
    
    solution[vt[0].second] = vt[0].second - vt[0].first;
    solution[0] = 0;

    for (int i = 1; i < n; ++i){
        int second = vt[i].second;
        while (solution[second] == -1) second--;
        solution[vt[i].second] = max(solution[second], vt[i].second - vt[i].first);

        int first = vt[i].first;
        while(solution[first-1] == -1) first--;
        result = max(result, solution[first-1] + vt[i].second - vt[i].first);
    }
    cout << result;
	return 0;
}