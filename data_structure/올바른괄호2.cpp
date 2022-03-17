#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<string> solution(int T, vector<string> inputs) {
    vector<string> answer(T);

    for (int i = 0; i < T; i++) {

        bool fail = false;

        int top = 0;
        for (int j = 0; j < inputs[i].length(); j++) {

            if (inputs[i][j] == '(') top++;//������ȣ�� ���ÿ� �ֱ�
            if (inputs[i][j] == ')') top--;//������ȣ�� ���ÿ��� ����

            if (top < 0) {//������ȣ�� ���� ���� ���
                fail = true;
                break;
            }
        }

        if (fail) answer[i] = "NO";
        else if (top != 0) answer[i] = "NO";//������ȣ ������ �� ���� ���
        else answer[i] = "YES";
    }

    return answer;
}

void show(int n, vector<string>answer) {
    int i;
    //test ���
    for (i = 0; i < n; i++)
        cout << answer[i] << '\n';
}
//test ����
int main() {
    int T;
    cin >> T;
    vector<string> inputs(T);
    for (int i = 0; i < T; i++) cin >> inputs[i];
    vector<string> answer = solution(T, inputs);
    show(T, answer);
    return 0;
}