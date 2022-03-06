#include <iostream>
#include <string>
#define MOD 1000000;

using namespace std;
int dp[5001];//dp[i] : i��° ���ڱ��� �о����� ���ü� �ִ� �ؼ�

int solution(string code, int n) {

    int n0 = stoi(code.substr(0, 1));//���ڸ� ����
    int n1 = stoi(code.substr(1, 1));//���ڸ� ����
    int n2 = stoi(code.substr(0, 2));//���ڸ� ����

    //dp[0]�� dp[1] �ʱ�ȭ
    if (n0 >= 1 && n0 <= 9) dp[0] += 1;
    if (n1 >= 1 && n0 <= 9) dp[1] += dp[0];
    if (n2 >= 10 && n2 <= 26) dp[1] += 1;

    for (int i = 2; i < n; i++) {

        int n1 = stoi(code.substr(i, 1));//���ڸ� ����
        int n2 = stoi(code.substr(i - 1, 2));//���ڸ� ����

        if (n1 >= 1 && n0 <= 9) dp[i] += dp[i - 1];
        if (n2 >= 10 && n2 <= 26) dp[i] += dp[i - 2];

        dp[i] %= MOD;
    }

    return dp[n - 1];
}

int main() {
    string str;
    cin >> str;
    int answer = solution(str, str.length());
    cout << answer;
    return 0;
}