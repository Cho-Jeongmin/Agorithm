#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> blanks;//빈칸 좌표 저장 배열
bool finish = false;//스도쿠 완성 여부

//유효성 검사 함수
bool check(int y, int x, vector<vector<int>> sudoku) {

    //가로줄, 세로줄 검사
    for (int i = 0; i < 9; i++) {
        if (sudoku[y][i] == sudoku[y][x] && i != x) {//겹치는게 있으면
            return false;
        }
        if (sudoku[i][x] == sudoku[y][x] && i != y) {//겹치는게 있으면
            return false;
        }
    }

    //3x3 검사
    int sy = (y / 3) * 3;//시작좌표
    int sx = (x / 3) * 3;
    for (int i = sy; i < sy + 3; i++) {
        for (int j = sx; j < sx + 3; j++) {
            
            if (sudoku[i][j] == sudoku[y][x] ) {//겹치는게 있으면
                if (i != y && j != x) 
                    return false;
            }
        }
    }

    return true;//유효함
}

//백트래킹 함수
void backtracking(int n, vector<vector<int>>& sudoku) {//n은 몇번째 빈칸인지를 표시

    if (n == blanks.size()) {//모든 빈칸을 다 채웠으면
        finish = true;
        return;
    }

    //n번째 빈칸의 좌표
    int y = blanks[n].first;
    int x = blanks[n].second;

    for (int i = 1; i <= 9; i++) {//1부터 9까지 넣어보기
        sudoku[y][x] = i;
        if (check(y, x, sudoku)) {//유효하면
            backtracking(n + 1, sudoku);//다음 빈칸에 대해 재귀호출
        }
        if (finish) return;//스도쿠가 완성되면 계속 리턴
    }
    sudoku[y][x] = 0;//스도쿠 완성 못하면 다시 되돌려 놓기
    return;
}


vector<vector<int>> solution(vector<vector<int>>& sudoku) {

    //blanks에 빈칸 좌표 저장
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudoku[i][j] == 0) {//빈칸이면
                blanks.push_back(make_pair(i, j));//빈칸 좌표 저장
            }
        }
    }

    backtracking(0, sudoku);//백트래킹 함수 호출

	return sudoku;
}

int main() {
    vector<vector<int>> sudoku(9, vector<int>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) cin >> sudoku[i][j];
    }
    
    auto output = solution(sudoku);
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) cout << output[i][j] << ' ';
        cout << '\n';
    }
    
    return 0;
}
