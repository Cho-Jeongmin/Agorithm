#include <iostream>
#include <vector>
using namespace std;

bool visited[101][101];

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

void dfs(int y, int x, int n, int m, vector<vector<int>>& b) {
    b[y][x] = 2;//�ܺΰ��� ǥ��
    visited[y][x] = true;//�湮ǥ��
    
    for (int i = 0; i < 4; i++) {
        //���� ��ǥ
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 0 && nx >= 0 && ny < n && nx < m && !visited[ny][nx] && (b[ny][nx] == 0 || b[ny][nx] == 2)) {
            dfs(ny, nx, n, m, b);//�湮
        }
    }
}

int solution(int n, int m, vector<vector<int>>& b) {
	int answer = 0; //�ð�

    int time = 0;

    while (true) {

        //visited �迭 �ʱ�ȭ
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i][j] = false;
            }
        }

        dfs(0, 0, n, m, b);//�ܺΰ��� 2�� ǥ��

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

        bool cheese = false;//ġ�� ���� ����

        //ġ�� ���ֱ�(0���� ǥ��)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (b[i][j] == 1) {//ġ���̸�
                    cheese = true;
                    int cnt = 0;//�´��� �ܺΰ��� ī��Ʈ
                    for (int k = 0; k < 4; k++) {
                        //������ǥ
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        //�迭 ���� �ȹ���� �ܺΰ����̸�
                        if (ny >= 0 && nx >= 0 && ny < n && nx < m && b[ny][nx] == 2) {
                            cnt++;//�ܺΰ��� ī��Ʈ
                        }
                    }
                    if (cnt >= 2) {//�´��� �ܺΰ��Ⱑ 2�� �̻��̸�
                        b[i][j] = 0;//ġ����ֱ�
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