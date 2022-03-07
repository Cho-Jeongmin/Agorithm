#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> blanks;//��ĭ ��ǥ ���� �迭
bool finish = false;//������ �ϼ� ����

//��ȿ�� �˻� �Լ�
bool check(int y, int x, vector<vector<int>> sudoku) {

    //������, ������ �˻�
    for (int i = 0; i < 9; i++) {
        if (sudoku[y][i] == sudoku[y][x] && i != x) {//��ġ�°� ������
            return false;
        }
        if (sudoku[i][x] == sudoku[y][x] && i != y) {//��ġ�°� ������
            return false;
        }
    }

    //3x3 �˻�
    int sy = (y / 3) * 3;//������ǥ
    int sx = (x / 3) * 3;
    for (int i = sy; i < sy + 3; i++) {
        for (int j = sx; j < sx + 3; j++) {
            
            if (sudoku[i][j] == sudoku[y][x] ) {//��ġ�°� ������
                if (i != y && j != x) 
                    return false;
            }
        }
    }

    return true;//��ȿ��
}

//��Ʈ��ŷ �Լ�
void backtracking(int n, vector<vector<int>>& sudoku) {//n�� ���° ��ĭ������ ǥ��

    if (n == blanks.size()) {//��� ��ĭ�� �� ä������
        finish = true;
        return;
    }

    //n��° ��ĭ�� ��ǥ
    int y = blanks[n].first;
    int x = blanks[n].second;

    for (int i = 1; i <= 9; i++) {//1���� 9���� �־��
        sudoku[y][x] = i;
        if (check(y, x, sudoku)) {//��ȿ�ϸ�
            backtracking(n + 1, sudoku);//���� ��ĭ�� ���� ���ȣ��
        }
        if (finish) return;//������ �ϼ��Ǹ� ��� ����
    }
    sudoku[y][x] = 0;//������ �ϼ� ���ϸ� �ٽ� �ǵ��� ����
    return;
}


vector<vector<int>> solution(vector<vector<int>>& sudoku) {

    //blanks�� ��ĭ ��ǥ ����
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudoku[i][j] == 0) {//��ĭ�̸�
                blanks.push_back(make_pair(i, j));//��ĭ ��ǥ ����
            }
        }
    }

    backtracking(0, sudoku);//��Ʈ��ŷ �Լ� ȣ��

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
