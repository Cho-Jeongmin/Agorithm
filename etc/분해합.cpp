#include <iostream>
using namespace std;

//���� ���� ������ ����
int solution(int n) {
	int answer = 0;
    bool found = false;

    for (int i = 1; i < n; i++) {

        int c = i;//������

        int sum = i;//������

        while (c != 0) {
            sum += c % 10;
            c = c / 10;
        }

        if (sum == n) {
            found = true;
            answer = i;
            break;
        }
    }

    if (!found) answer = 0;

	return answer;
}

int main(void) {
    int n;
    //�Է�
    cin >> n;
    //����
    int answer = solution(n);
    //���
    cout << answer;
    return 0;
}