#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

bool visited[101][101];//�湮���ι迭
int area = 0;//����
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

void dfs(int m, int n, int y, int x, vector<vector<int>> picture) {
    visited[y][x] = true;//�湮ǥ��
    area++;//���� + 1

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;//�迭 ���� ���
        if (visited[ny][nx]) continue;//�̹� �湮��
        if (picture[y][x] != picture[ny][nx]) continue;//�ٸ� ������

        dfs(m, n, ny, nx, picture);//���ȣ��
    }

}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	vector<int> answer(2);

    int cnt = 0;//���� ����
    int max_area = 0;//�ִ� ����

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j]==0) {//0�� ���ִ� ������ ��ĥ ���ϹǷ�
                visited[i][j] = true;//�̸� visited ó��
            }
        }
    }

    //��� �湮���� ���� ���� ���� dfs ����.
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