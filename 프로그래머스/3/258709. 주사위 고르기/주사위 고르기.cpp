#include <bits/stdc++.h>

using namespace std;

int n;
bool visited[11];
bool res[11];
vector<vector<int>> dices;
int maxWin = 0;
vector<int> A, B;

void calcDfs(int idx, int sum, bool flag) {
    
    if(idx == n) {
        if(flag) {
            A.push_back(sum);
        } else {
            B.push_back(sum);
        }
        return;
    }
    
    if(visited[idx] != flag) {
        calcDfs(idx + 1, sum, flag);
        return;
    }
    
    for(int i = 0; i < 6; i++) {
       	calcDfs(idx + 1, sum + dices[idx][i], flag);
    }
}

void calcWin() {
    sort(B.begin(), B.end());
    
    int win = 0;
    for(int i = 0; i < A.size(); i++) {
        win += lower_bound(B.begin(), B.end(), A[i]) - B.begin();
    }
    
    if(maxWin < win) {
        maxWin = win;
       	for(int i = 0; i < n; i++)
            res[i] = visited[i];
    }
    A.clear();
    B.clear();
}

void dfs(int here, int cnt) {
    
    if(cnt == n / 2) {
        calcDfs(0, 0, true);
        calcDfs(0, 0, false);
        calcWin();
        return;
    }
    
   	for(int next = here + 1; next < n; next++) {
        visited[next] = true;
       	dfs(next, cnt + 1);
        visited[next] = false;
    } 
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    
    n = dice.size();
    dices = dice;
    
    dfs(-1, 0);
    
    for(int i = 0; i < n; i++) {
        if(res[i])
        	answer.push_back(i + 1);
    }
    
    return answer;
}