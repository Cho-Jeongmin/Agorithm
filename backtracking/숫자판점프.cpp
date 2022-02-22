#include <iostream>
#include <vector>
#include <set>
using namespace std;

int dy[4] = { 0, -1, 0 ,1 };
int dx[4] = { -1, 0, 1, 0 };
set<int> s;//집합 s (중복 제거용)

void backtracking(int y, int x, int level, int result, vector<vector<int>>& board) {

	if (level == 6) {//탈출조건
		s.insert(result);//집합 s에 6자리 숫자 삽입
		return;
	}


	for (int i = 0; i < 4; i++) {//상하좌우
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;//배열 범위 벗어남.

		backtracking(ny, nx, level + 1, result*10 + board[y][x], board);//재귀호출
	}

}


int solution(vector<vector<int>>& board) {
	int answer = 0; //다른 조합 개수

	//모든 점에 대해 백트래킹 실행
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

	//숫자판 초기화
	board.assign(5, vector<int>(5, 0));

	//숫자판 입력
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> num;
			board[i][j] = num;

		}
	}

	//만들 수 있는 서로 다른 여섯 자리의 수들의 개수 구하기
	result = solution(board);

	//출력
	cout << result;

}
