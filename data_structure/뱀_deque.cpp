#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;
deque<pair<int, int>> dq;

int solution(int n, int k, int l, vector<vector<int>>& apple, vector<vector<string>>& rotation) {

	int answer = 0;

	int board[101][101] = { {0,} };

	for (int i = 0; i < k; i++) {
		board[apple[i][0] - 1][apple[i][1] - 1] = 2;//���ǥ��
	}

	int t = 0;//�ð�
	int rot = 0;//����迭�� �ε���
	int dir = 0;//����(��:0, �Ʒ�:1, ��:2, ��:3)
	int x = 0, y = 0;//�Ӹ���ǥ
	board[y][x] = 1;//������ġ ǥ��

	while (true) {


		dq.push_back(make_pair(y, x));//���� �Ӹ� �ֱ�

		//������ȯ
		if (rot < rotation.size() && t == stoi(rotation[rot][0])) {
			if (rotation[rot][1] == "L") dir = (dir + 3) % 4;//��ȸ��
			else dir = (dir + 1) % 4;//��ȸ��
			rot++;
		}

		//�Ӹ��̵�
		if (dir == 0) x++;
		else if (dir == 1) y++;
		else if (dir == 2) x--;
		else if (dir == 3) y--;

		//�浹 üũ
		if (y < 0 || x < 0 || y >= n || x >= n) break;//���� �ε���
		if (board[y][x] == 1) break;//����� �ε���

		//��������� �״��

		//���������
		if (board[y][x] != 2) {
			int ty = dq.front().first;//������ǥ
			int tx = dq.front().second;
			board[ty][tx] = 0;//���������
			dq.pop_front();//������ ���� ���ֱ�
		}

		board[y][x] = 1;//�Ӹ� ǥ��
		t++;//�ð� ����
	}

	answer = t + 1;

	return answer;
}

int main() {
	int n, k, l;

	cin >> n >> k;
	vector<vector<int>> apple(k, vector<int>(2));
	for (int i = 0; i < k; i++) //��� ��ġ
		cin >> apple[i][0] >> apple[i][1];
	cin >> l;
	vector<vector<string>> rotation(l, vector<string>(2));
	for (int i = 0; i < l; i++) //ȸ�� ����
		cin >> rotation[i][0] >> rotation[i][1];
	//����
	int answer = solution(n, k, l, apple, rotation);
	//���
	cout << answer;
	return 0;
}