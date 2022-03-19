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
		int ny = y + dy[i];//���� ��ǥ
		int nx = x + dx[i];

		//�迭 ���� ����ų� �̹� �湮�� ��
		if (ny < 0 || nx < 0 || ny >= m || nx >= n || visited[ny][nx]) continue;
		//�ٸ� ������ ��
		if (picture[ny][nx] != picture[y][x]) continue;

		dfs(ny, nx, m, n, picture);//��͹湮
	}
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	vector<int> answer(2);

	int cnt = 0;//���� ����
	int max_area = 0;//�ִ� ����

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (picture[i][j] == 0) continue;//��ĥ���� �ʴ� ����

			if (!visited[i][j]) {//�湮���� ���� ���̸�
				area = 0;//���� ���� �ʱ�ȭ
				dfs(i, j, m, n, picture);//�ش� ���� ���Ե� ���� ��ü �湮
				cnt++;//���� ���� ī��Ʈ
				max_area = max(max_area, area);//�ִ� ���� ����
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