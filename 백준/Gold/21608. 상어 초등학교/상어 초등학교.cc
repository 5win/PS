#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e6;
const int MAX = 40001;

struct Student {
	int num;
	map<int, bool> like;
};

struct Point {
	int fNum, eNum, y, x;
};

int n;
vector<Student> s;
int board[21][21];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool inRange(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < n;
}

bool comp(Point& a, Point& b) {
	if(a.fNum == b.fNum) {
		if(a.eNum == b.eNum) {
			if(a.y == b.y) {
				return a.x < b.x;
			} else {
				return a.y < b.y;
			}
		} else {
			return a.eNum > b.eNum;
		}
	}
	return a.fNum > b.fNum;
}

vector<Point> findSeat(int cur) {
	vector<Point> v;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(board[i][j] != -1) continue;
			int fCnt = 0, eCnt = 0;
			for(int dir = 0; dir < 4; dir++) {
				int ny = i + dy[dir], nx = j + dx[dir];
				if(!inRange(ny, nx)) continue;
				if(board[ny][nx] == -1) {
					eCnt++;
				}
				map<int, bool> m = s[cur].like;
				if(m.find(board[ny][nx]) != m.end()) {
					fCnt++;
				}
			}

			v.push_back({fCnt, eCnt, i, j});
		}
	}
	return v;
}

int calcScore() {
	int sum = 0;

	for(int i = 0; i < s.size(); i++) {
		int cNum = s[i].num;
		map<int, bool> m = s[i].like;
		for(int r = 0; r < n; r++) {
			for(int c = 0; c < n; c++) {
				if(board[r][c] == cNum) {
					int cnt = 0;
					for(int dir = 0; dir < 4; dir++) {
						int ny = r + dy[dir], nx = c + dx[dir];
						if(!inRange(ny, nx)) continue;
						if(m.find(board[ny][nx]) != m.end()) {
							cnt++;
						}
					}
					if(cnt != 0)
						sum += pow(10, cnt - 1);
					break;
				}
			}
		}
	}

	return sum;
}

void print() {
	for(int i = 0 ; i< n; i++) {
		for(int j = 0; j <n ; j++)
			cout << board[i][j] << ' ';
		cout << endl;
	}
		cout << endl;
}

int solve() {
	
	for(int i = 0; i < s.size(); i++) {
		vector<Point> v = findSeat(i);
		sort(v.begin(), v.end(), comp);
		Point cur = v[0];
		board[cur.y][cur.x] = s[i].num;
	}

	return calcScore();
}

int main(void) {
    FASTIO;

	memset(board, -1, sizeof(board));
	cin >> n;
	for(int i = 0; i < n * n; i++) {
		int num, a, b, c, d;
		cin >> num >> a >> b >> c >> d;
		Student st;
		st.num = num - 1;
		st.like[a - 1] = true;
		st.like[b - 1] = true;
		st.like[c - 1] = true;
		st.like[d - 1] = true;
		s.push_back(st);
	}
	cout << solve() << '\n';

    return 0;
}