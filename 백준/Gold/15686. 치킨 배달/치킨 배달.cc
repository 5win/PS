#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<sstream>
#include<limits>
#include<algorithm>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<numeric>

#define endl '\n'

using namespace std;
const int INF = 1987654321;
const int MAX = 1000 * 1000 * 10;
const int _MOD = 1000000007;

int n;
int m;
vector< pair<int, int> > home;
vector< pair<int, int> > chick;

int solve() {
    vector<int> perm(chick.size(), 1);
    fill(perm.begin(), perm.begin() + chick.size() - m, 0);
    int ret = INF;
    do {
        int distSum = 0;
        for(int i = 0; i < home.size(); i++) {
            int cDist = INF;
            for(int j = 0; j < chick.size(); j++) {
                if(perm[j] == 1) 
                    cDist = min(cDist, abs(chick[j].first - home[i].first) + abs(chick[j].second - home[i].second));
            }
            distSum += cDist;
        }
        ret = min(ret, distSum);
    } while(next_permutation(perm.begin(), perm.end()));
    return ret;
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);   
   
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            if(temp == 1) 
                home.push_back({i, j});
            else if(temp == 2) 
                chick.push_back({i, j});
        }
    }
    cout << solve() << endl;
    
    return 0;
}