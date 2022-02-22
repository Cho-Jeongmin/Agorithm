#include <iostream>
#include <vector>
#include <set>
using namespace std;

int dy[4] = { 0, -1, 0 ,1 };
int dx[4] = { -1, 0, 1, 0 };
set<int> s;//���� s (�ߺ� ���ſ�)

void backtracking(int y, int x, int level, int result, vector<vector<int>>& board) {

	if (level == 6) {//Ż������
		s.insert(result);//���� s�� 6�ڸ� ���� ����
		return;
	}


	for (int i = 0; i < 4; i++) {//�����¿�
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;//�迭 ���� ���.

		backtracking(ny, nx, level + 1, result*10 + board[y][x], board);//���ȣ��
	}

}


int solution(vector<vector<int>>& board) {
	int answer = 0; //�ٸ� ���� ����

	//��� ���� ���� ��Ʈ��ŷ ����
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			backtracking(i, j, 0, 0, board);
		}
	}

	answer = s.size();

	return answer;

}

int main() {
	vector<vector<int>> board;
	int num, result;

	//������ �ʱ�ȭ
	board.assign(5, vector<int>(5, 0));

	//������ �Է�
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> num;
			board[i][j] = num;

		}
	}

	//���� �� �ִ� ���� �ٸ� ���� �ڸ��� ������ ���� ���ϱ�
	result = solution(board);

	//���
	cout << result;

}