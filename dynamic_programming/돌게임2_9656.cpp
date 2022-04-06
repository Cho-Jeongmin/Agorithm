#include <iostream>

using namespace std;

int main(void) {

	int n;
	cin >> n;

	bool dp[1001] = {false, };

	dp[1] = false;
	dp[2] = true;
	dp[3] = false;

	for (int i = 4; i <= n; i++) {
		if (!dp[i - 1] || !dp[i - 3]) dp[i] = true;
	}

	if (dp[n]) cout << "SK";
	else cout << "CY";

	return 0;
}