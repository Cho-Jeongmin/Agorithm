#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <string>

using namespace std;

int board[101][101] = { 0 };

int solution(int n, int k, int l, vector<vector<int>>& apple, vector<vector<string>>& rotation) {

	int answer;
	int hy=0, hx=0;//�Ӹ� ��ġ
	int ty=0, tx=0;//���� ��ġ
	int h_dir=0, t_dir = 0;//�Ӹ�/���� ���� (�� �Ʒ� �� �� 0 1 2 3)
	int h_time = 0, t_time = 0;//�Ӹ�/���� �ð�
	int h_rot = 0, t_rot = 0;//rotation �ε���

	//��� ǥ��
	for (int i = 0; i < k; i++) {
		int ay = apple[i][0]-1;
		int ax = apple[i][1]-1;
		board[ay][ax] = 2;//����� 2
	}

	//�� ���� ǥ��
	board[0][0] = 1;

	while (true) {
		
		//�Ӹ����� ��ȯ
		if (h_time == stoi(rotation[h_rot][0])) {
			if (rotation[h_rot][1] == "D") h_dir = (h_dir + 1) % 4;//��ȸ��
			else h_dir = (h_dir - 1 + 4) % 4;//��ȸ��
			if(h_rot<l-1) h_rot++;
		}

		//�Ӹ���ǥ �̵�
		if (h_dir == 0) hx++;//��
		else if (h_dir == 1) hy++;//�Ʒ�
		else if (h_dir == 2) hx--;//��
		else if (h_dir == 3) hy--;//��

		h_time++;//�Ӹ��ð� ����

		if (hy < 0 || hx < 0 || hy >= n || hx >= n) {//���� �ε�����
			break;
		}
		else if (board[hy][hx] == 1) {//����� �ε�����
			break;
		}
		
		if (board[hy][hx] != 2) {//��� ������

			//���� �����
			board[ty][tx] = 0;

			//�������� ��ȯ
			if (t_time == stoi(rotation[t_rot][0])) {
				if (rotation[t_rot][1] == "D") t_dir = (t_dir + 1) % 4;//��ȸ��
				else t_dir = (t_dir - 1 + 4) % 4;//��ȸ��
				if (t_rot < l - 1)t_rot++;
			}
			//������ǥ �̵�
			if (t_dir == 0) tx++;//��
			else if (t_dir == 1) ty++;//�Ʒ�
			else if (t_dir == 2) tx--;//��
			else if (t_dir == 3) ty--;//��

			t_time++;//�����ð� ����
		}

		board[hy][hx] = 1;//�Ӹ� �׸��� (or ��� �����)

		/* 
		//board ���
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		*/
	}

	answer = h_time;

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