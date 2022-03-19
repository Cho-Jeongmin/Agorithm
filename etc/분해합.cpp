#include <iostream>
using namespace std;

//가장 작은 생성자 리턴
int solution(int n) {
	int answer = 0;
    bool found = false;

    for (int i = 1; i < n; i++) {

        int c = i;//생성자

        int sum = i;//분해합

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
    //입력
    cin >> n;
    //연산
    int answer = solution(n);
    //출력
    cout << answer;
    return 0;
}