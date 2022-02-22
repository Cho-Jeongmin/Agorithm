#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int dp[301];

int solution(int n, vector<int>& score) {

	//초기화
	dp[0] = 0;
	dp[1] = score[1];
	dp[2] = score[1] + score[2];

	//dp 채우기
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + score[i], dp[i - 3] + score[i - 1] + score[i]);
	}

	return dp[n];
}

int main() {
	int n;
	cin >> n;
	int answer;
	vector<int> score(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> score[i];
	}

	answer = solution(n, score);

	cout <<  answer;
}