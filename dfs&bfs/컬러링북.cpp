#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool visited[101][101];
int area = 0;

void dfs(int y, int x, int m, int n, vector<vector<int>> picture) {
	visited[y][x] = true;
	area++;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];//인접 좌표
		int nx = x + dx[i];

		//배열 범위 벗어나거나 이미 방문한 점
		if (ny < 0 || nx < 0 || ny >= m || nx >= n || visited[ny][nx]) continue;
		//다른 영역인 점
		if (picture[ny][nx] != picture[y][x]) continue;

		dfs(ny, nx, m, n, picture);//재귀방문
	}
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	vector<int> answer(2);

	int cnt = 0;//영역 개수
	int max_area = 0;//최대 넓이

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (picture[i][j] == 0) continue;//색칠하지 않는 영역

			if (!visited[i][j]) {//방문하지 않은 점이면
				area = 0;//영역 넓이 초기화
				dfs(i, j, m, n, picture);//해당 점이 포함된 영역 전체 방문
				cnt++;//영역 개수 카운트
				max_area = max(max_area, area);//최대 넓이 갱신
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