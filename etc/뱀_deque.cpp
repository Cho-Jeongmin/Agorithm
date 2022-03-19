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
		board[apple[i][0] - 1][apple[i][1] - 1] = 2;//사과표시
	}

	int t = 0;//시간
	int rot = 0;//방향배열의 인덱스
	int dir = 0;//방향(우:0, 아래:1, 좌:2, 위:3)
	int x = 0, y = 0;//머리좌표
	board[y][x] = 1;//시작위치 표시

	while (true) {


		dq.push_back(make_pair(y, x));//덱에 머리 넣기

		//방향전환
		if (rot < rotation.size() && t == stoi(rotation[rot][0])) {
			if (rotation[rot][1] == "L") dir = (dir + 3) % 4;//좌회전
			else dir = (dir + 1) % 4;//우회전
			rot++;
		}

		//머리이동
		if (dir == 0) x++;
		else if (dir == 1) y++;
		else if (dir == 2) x--;
		else if (dir == 3) y--;

		//충돌 체크
		if (y < 0 || x < 0 || y >= n || x >= n) break;//벽과 부딪힘
		if (board[y][x] == 1) break;//몸통과 부딪힘

		//사과있으면 그대로

		//사과없으면
		if (board[y][x] != 2) {
			int ty = dq.front().first;//꼬리좌표
			int tx = dq.front().second;
			board[ty][tx] = 0;//꼬리지우기
			dq.pop_front();//덱에서 꼬리 없애기
		}

		board[y][x] = 1;//머리 표시
		t++;//시간 증가
	}

	answer = t + 1;

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