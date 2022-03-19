#include <iostream>
#include <vector>
using namespace std;

bool visited[101][101];

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

void dfs(int y, int x, int n, int m, vector<vector<int>>& b) {
    b[y][x] = 2;//외부공기 표시
    visited[y][x] = true;//방문표시
    
    for (int i = 0; i < 4; i++) {
        //인접 좌표
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 0 && nx >= 0 && ny < n && nx < m && !visited[ny][nx] && (b[ny][nx] == 0 || b[ny][nx] == 2)) {
            dfs(ny, nx, n, m, b);//방문
        }
    }
}

int solution(int n, int m, vector<vector<int>>& b) {
	int answer = 0; //시간

    int time = 0;

    while (true) {

        //visited 배열 초기화
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i][j] = false;
            }
        }

        dfs(0, 0, n, m, b);//외부공기 2로 표시

        /*
        cout << time << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << b[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        */

        bool cheese = false;//치즈 존재 여부

        //치즈 없애기(0으로 표시)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (b[i][j] == 1) {//치즈이면
                    cheese = true;
                    int cnt = 0;//맞닿은 외부공기 카운트
                    for (int k = 0; k < 4; k++) {
                        //인접좌표
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        //배열 범위 안벗어나고 외부공기이면
                        if (ny >= 0 && nx >= 0 && ny < n && nx < m && b[ny][nx] == 2) {
                            cnt++;//외부공기 카운트
                        }
                    }
                    if (cnt >= 2) {//맞닿은 외부공기가 2개 이상이면
                        b[i][j] = 0;//치즈없애기
                    }
                }
            }
        }
        if (!cheese) break;
        time++;
    }

    answer = time;

	return answer;
}

int main() {
    int n, m, answer;

    vector<vector<int>> board_main;
    cin >> n >> m;
    board_main.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> board_main[i][j];
    }
    answer = solution(n, m, board_main);
    cout << answer;
    return 0;
}
