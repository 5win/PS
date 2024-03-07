#include <string>
#include <vector>

using namespace std;

bool inRange(int idx, int len) {
  	return idx < len;
}

int solution(vector<string> babbling) {
    int answer = 0;
    
    for(int i = 0; i < babbling.size(); i++) {
        string cur = babbling[i];
        bool notCnt = false;
        int prev_word = 0;
        for(int j = 0; j < cur.size();) {
            bool isWrong = false;
          	switch(cur[j]) {
                case 'a':
                    if(prev_word == 1) {
                        isWrong = true;
                        break;
                    }
                    if(inRange(j + 2, cur.size()) && cur[j + 1] == 'y' && cur[j + 2] == 'a') {
                      	j += 3; 
                        prev_word = 1;
                        break;
                    }
                   	isWrong = true; 
                    break;
                case 'y':
                    if(prev_word == 2) {
                        isWrong = true;
                        break;
                    }
                    if(inRange(j + 1, cur.size()) && cur[j + 1] == 'e') {
                        j += 2;
                        prev_word = 2;
                        break;
                    }
                    isWrong = true;
                    break;
                case 'w':
                    if(prev_word == 3) {
                        isWrong = true;
                        break;
                    }
                    if(inRange(j + 2, cur.size()) && cur[j + 1] == 'o' && cur[j + 2] == 'o') {
                        j += 3;
                        prev_word = 3;
                        break;
                    }
                    isWrong = true;
                    break;
                case 'm':
                    if(prev_word == 4) {
                        isWrong = true;
                        break;
                    }
                    if(inRange(j + 1, cur.size()) && cur[j + 1] == 'a') {
                        j += 2;
                        prev_word = 4;
                        break;
                    }
                    isWrong = true;
                    break;
                default:
                    isWrong = true;
                    break;
            }
           	if(isWrong) {
                notCnt = true;
                break;
            } 
        }
        
        if(!notCnt) answer++;
    }
    
    
    return answer;
}