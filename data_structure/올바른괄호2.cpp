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

            if (inputs[i][j] == '(') top++;//열린괄호면 스택에 넣기
            if (inputs[i][j] == ')') top--;//닫힌괄호면 스택에서 빼기

            if (top < 0) {//닫힌괄호가 먼저 나온 경우
                fail = true;
                break;
            }
        }

        if (fail) answer[i] = "NO";
        else if (top != 0) answer[i] = "NO";//열린괄호 개수가 더 많은 경우
        else answer[i] = "YES";
    }

    return answer;
}

void show(int n, vector<string>answer) {
    int i;
    //test 출력
    for (i = 0; i < n; i++)
        cout << answer[i] << '\n';
}
//test 메인
int main() {
    int T;
    cin >> T;
    vector<string> inputs(T);
    for (int i = 0; i < T; i++) cin >> inputs[i];
    vector<string> answer = solution(T, inputs);
    show(T, answer);
    return 0;
}