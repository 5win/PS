#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = "";
    
    for(int i = 0; i < my_string.size(); i++) {
        if(s <= i && i < s + overwrite_string.size()) {
            answer += overwrite_string[i - s];
        }
        else {
            answer += my_string[i];
        }
    }
    
    return answer;
}