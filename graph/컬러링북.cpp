#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

bool visited[101][101];//방문여부배열
int area = 0;//넓이
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

void dfs(int m, int n, int y, int x, vector<vector<int>> picture) {
    visited[y][x] = true;//방문표시
    area++;//넓이 + 1

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;//배열 범위 벗어남
        if (visited[ny][nx]) continue;//이미 방문함
        if (picture[y][x] != picture[ny][nx]) continue;//다른 영역임

        dfs(m, n, ny, nx, picture);//재귀호출
    }

}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	vector<int> answer(2);

    int cnt = 0;//영역 개수
    int max_area = 0;//최대 넓이

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j]==0) {//0이 써있는 영역은 색칠 안하므로
                visited[i][j] = true;//미리 visited 처리
            }
        }
    }

    //모든 방문하지 않은 점에 대해 dfs 수행.
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                area = 0;
                dfs(m, n, i, j, picture);
                max_area = max(max_area, area);
                cnt++;
            }
        }
    }

    answer[0] = cnt;
    answer[1] = max_area;

	return answer;
}

int main() {

    int m, n;
    cin >> m >> n;

    vector<vector<int>> picture(m, vector<int>(n));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) cin >> picture[i][j];

    auto answer = solution(m, n, picture);

    cout << answer[0] << ' ' << answer[1];

    return 0;
}