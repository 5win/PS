#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1000001];
vector<int> radj[1000001];
int s = 1987654321;
int e = 0;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    
    for(int i = 0; i < edges.size(); i++) {
        int src = edges[i][0], dst = edges[i][1];
        s = min(s, src); s = min(s, dst);
        e = max(e, src); e = max(e, dst);
        adj[src].push_back(dst);
        radj[dst].push_back(src);
    }
    
    int v;
    for(int i = s; i <= e; i++) {
       	if(adj[i].size() >= 2 && radj[i].size() == 0) {
            v = i;
            break;
        }
    }
    
    int res[3] = {0, };
    for(int i = s; i <= e; i++) {
        if(adj[i].size() == 0 && radj[i].size() == 0) continue;
        if(i == v) continue;
        if(adj[i].size() == 0) 
            res[1]++;
        if(adj[i].size() == 2) 
            res[2]++;
    }
    res[0] = adj[v].size() - res[1] - res[2];
    
    answer.push_back(v);
    for(int i = 0; i < 3; i++)
        answer.push_back(res[i]);
    
    return answer;
}