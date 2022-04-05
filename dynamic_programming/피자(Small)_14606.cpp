#include <iostream>
#include <vector>

using namespace std;

int dp(int n) {
	if (n == 1) return 0;
	return (n/2)*(n-n/2) + dp(n / 2) + dp(n - n / 2);
}

int main(void) {

	int n;

	cin >> n;

	int result = dp(n);

	cout << result << endl;

	return 0;
}