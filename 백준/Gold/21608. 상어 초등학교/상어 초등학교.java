import java.util.*;

class Seat implements Comparable<Seat> {
    int likeCnt = 0;
    int emptyCnt = 0;
    int y, x;

    public Seat(int liekCnt, int emptyCnt, int y, int x) {
        this.likeCnt = liekCnt;
        this.emptyCnt = emptyCnt;
        this.y = y;
        this.x = x;
    }

    public int compareTo(Seat other) {
        if(likeCnt != other.likeCnt)
            return other.likeCnt - likeCnt;
        if(emptyCnt != other.emptyCnt)
            return other.emptyCnt - emptyCnt;
        if(y != other.y)
            return y - other.y;
        return x - other.x;     
    }
}

class Pair {
    int y, x;
}

public class Main {

    int n;
    int score = 0;
    int[][] like = new int[401][4];
    int[] order = new int[401];
    int[][] board = new int[21][21];
    int[] dy = {0, 1, 0, -1};
    int[] dx = {1, 0, -1, 0};

    boolean inRange(int y, int x) {
        return 0 <= y && y < n && 0 <= x && x < n;
    }

    List<Seat> findSeat(int sNum) {
        List<Seat> seats = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] != 0) continue;
                int likeCnt = 0, emptyCnt = 0;
                for(int dir = 0; dir < 4; dir++) {
                    int ny = i + dy[dir], nx = j + dx[dir];
                    if(!inRange(ny, nx)) continue;
                    if(board[ny][nx] == 0) emptyCnt++;
                    for(int f = 0; f < 4; f++) {
                        if(like[sNum][f] == board[ny][nx])
                            likeCnt++;
                    }
                }
                seats.add(new Seat(likeCnt, emptyCnt, i, j));
            }
        }
        return seats;
    }

    void calcScore() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int likeCnt = 0;
                for(int dir = 0; dir < 4; dir++) {
                    int ny = i + dy[dir], nx = j + dx[dir];
                    if(!inRange(ny, nx)) continue;
                    for(int f = 0; f < 4; f++) {
                        if(like[board[i][j]][f] == board[ny][nx])
                            likeCnt++;
                    }
                }
                if(likeCnt > 0) {
                    score += (int)Math.pow(10, likeCnt - 1);
                }
            }
        }
    }

    void solve() {
        for(int i = 0; i < n * n; i++) {
            List<Seat> seats = findSeat(order[i]);
            Collections.sort(seats);
            Seat seat = seats.get(0);
            board[seat.y][seat.x] = order[i];
        }
        calcScore();
    }

    void start() {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        for(int i = 0; i < n * n; i++) {
            int s = sc.nextInt();
            for(int j = 0; j < 4; j++) {
                like[s][j] = sc.nextInt();
            }
            order[i] = s;
        }
        solve();
        System.out.println(score); 
    }

    public static void main(String[] args) {
        new Main().start();
    }
}