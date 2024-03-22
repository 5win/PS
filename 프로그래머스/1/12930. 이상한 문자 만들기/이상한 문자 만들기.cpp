#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    
    int up = 'a' - 'A';
    int idx = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') {
            idx = 0;
            continue;
        }
        if(idx % 2 == 0 && s[i] >= 'a')
            s[i] -= up;
        if(idx % 2 == 1 && s[i] < 'a')
            s[i] += up;
        idx++;
    }
    
    return s;
}