#include <bits/stdc++.h>

using namespace std;

int indegree[1000001], outdegree[1000001];
int s = 1987654321;
int e = 0;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    
    for(int i = 0; i < edges.size(); i++) {
        int src = edges[i][0], dst = edges[i][1];
        s = min(s, src); s = min(s, dst);
        e = max(e, src); e = max(e, dst);
        indegree[dst]++;
        outdegree[src]++;
    }
    
    int v;
    for(int i = s; i <= e; i++) {
       	if(indegree[i] == 0 && outdegree[i] >= 2) {
            v = i;
            break;
        }
    }
    
    int res[3] = {0, };
    for(int i = s; i <= e; i++) {
        if(indegree[i] == 0 && outdegree[i] == 0) continue;
        if(i == v) continue;
        if(outdegree[i] == 0) 
            res[1]++;
        if(outdegree[i] == 2) 
            res[2]++;
    }
    res[0] = outdegree[v] - res[1] - res[2];
    
    answer.push_back(v);
    for(int i = 0; i < 3; i++)
        answer.push_back(res[i]);
    
    return answer;
}