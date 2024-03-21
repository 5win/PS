#include <string>
#include <vector>

using namespace std;

bool inRange(int n, int m, int y, int x) {
   	return 0 <= y && y < n && 0 <= x && x < m; 
}

bool existWall(vector<string>& park, int y, int x, int ny, int nx) {
    if(y > ny)
      	swap(y, ny);
    if(x > nx)
        swap(x, nx);
    for(int i = y; i <= ny; i++) {
        for(int j = x; j <= nx; j++) {
            if(park[i][j] == 'X') return true;
        }
    }
    return false;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    int n = park.size();
    int m = park[0].size();
    
    vector<int> answer;
    
    int y, x;
   	for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(park[i][j] == 'S') {
            	y = i;
                x = j;
                break;
            }
        }
    } 
    
   	for(int i = 0; i < routes.size(); i++) {
       	char dir = routes[i][0];
        int dist = routes[i][2] - '0';
        
        int ny = y, nx = x;
        switch(dir) {
            case 'N':
                ny = y - dist;
                break;
            case 'S':
      			ny = y + dist;
                break;
            case 'W':
    			nx = x - dist;            
                break;
            case 'E':
               	nx = x + dist; 
                break;
        }
		if(!inRange(n, m, ny, nx) || existWall(park, y, x, ny, nx)) continue;
        y = ny;
      	x = nx;
    } 
    answer.push_back(y);
    answer.push_back(x);
    
    return answer;
}