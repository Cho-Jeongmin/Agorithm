#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <string>

using namespace std;

int board[101][101] = { 0 };

int solution(int n, int k, int l, vector<vector<int>>& apple, vector<vector<string>>& rotation) {

	int answer;
	int hy=0, hx=0;//머리 위치
	int ty=0, tx=0;//꼬리 위치
	int h_dir=0, t_dir = 0;//머리/꼬리 방향 (오 아래 왼 위 0 1 2 3)
	int h_time = 0, t_time = 0;//머리/꼬리 시간
	int h_rot = 0, t_rot = 0;//rotation 인덱스

	//사과 표시
	for (int i = 0; i < k; i++) {
		int ay = apple[i][0]-1;
		int ax = apple[i][1]-1;
		board[ay][ax] = 2;//사과는 2
	}

	//뱀 몸통 표시
	board[0][0] = 1;

	while (true) {
		
		//머리방향 전환
		if (h_time == stoi(rotation[h_rot][0])) {
			if (rotation[h_rot][1] == "D") h_dir = (h_dir + 1) % 4;//우회전
			else h_dir = (h_dir - 1 + 4) % 4;//좌회전
			if(h_rot<l-1) h_rot++;
		}

		//머리좌표 이동
		if (h_dir == 0) hx++;//오
		else if (h_dir == 1) hy++;//아래
		else if (h_dir == 2) hx--;//왼
		else if (h_dir == 3) hy--;//위

		h_time++;//머리시간 증가

		if (hy < 0 || hx < 0 || hy >= n || hx >= n) {//벽과 부딪히면
			break;
		}
		else if (board[hy][hx] == 1) {//몸통과 부딪히면
			break;
		}
		
		if (board[hy][hx] != 2) {//사과 없으면

			//꼬리 지우기
			board[ty][tx] = 0;

			//꼬리방향 전환
			if (t_time == stoi(rotation[t_rot][0])) {
				if (rotation[t_rot][1] == "D") t_dir = (t_dir + 1) % 4;//우회전
				else t_dir = (t_dir - 1 + 4) % 4;//좌회전
				if (t_rot < l - 1)t_rot++;
			}
			//꼬리좌표 이동
			if (t_dir == 0) tx++;//오
			else if (t_dir == 1) ty++;//아래
			else if (t_dir == 2) tx--;//왼
			else if (t_dir == 3) ty--;//위

			t_time++;//꼬리시간 증가
		}

		board[hy][hx] = 1;//머리 그리기 (or 사과 지우기)

		/* 
		//board 출력
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
	for (int i = 0; i < k; i++) //사과 위치
		cin >> apple[i][0] >> apple[i][1];
	cin >> l;
	vector<vector<string>> rotation(l, vector<string>(2));
	for (int i = 0; i < l; i++) //회전 정보
		cin >> rotation[i][0] >> rotation[i][1];
	//연산
	int answer = solution(n, k, l, apple, rotation);
	//출력
	cout << answer;
	return 0;
}
