#include <bits/stdc++.h>

using namespace std;


int cnt[51][51];

vector<string> split(string str) {
    vector<string> ret;
    stringstream ss(str);
    string s;
    while(getline(ss, s, ' ')) {
        ret.push_back(s);
    }
    return ret;
}

int findIdx(vector<string> friends, string name) {
    for(int i = 0; i < friends.size(); i++) {
        if(friends[i] == name) {
            return i;
        }
    }
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    for(int i = 0; i < gifts.size(); i++) {
   		vector<string> name = split(gifts[i]); 
       	int idx1 = findIdx(friends, name[0]); 
        int idx2 = findIdx(friends, name[1]);
        cnt[idx1][idx2]++;
    }
    
    int sum[51][2] = {0, };
    for(int i = 0; i < friends.size(); i++) {
        for(int j = 0; j < friends.size(); j++) {
            sum[i][0] += cnt[i][j];
            sum[i][1] += cnt[j][i];
        }
    }
    
   	int res[51] = {0, };
    for(int i = 0; i < friends.size(); i++) {
        for(int j = 0; j < friends.size(); j++) {
            if(i == j) continue;
            if(cnt[i][j] > cnt[j][i]) res[i]++;
            else if((!cnt[i][j] && !cnt[j][i]) || cnt[i][j] == cnt[j][i]) {
                int score1 = sum[i][0] - sum[i][1];
                int score2 = sum[j][0] - sum[j][1];
                if(score1 > score2)
                  	res[i]++;
            }
        }
    }
    
    answer = *max_element(res, res + friends.size());
    
    return answer;
}