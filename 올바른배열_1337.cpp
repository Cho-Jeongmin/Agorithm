#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int arr[51] = {0,};
	int result[51] = { 0, };

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);//오름차순 정렬

	int cnt = 0;
	int min_cnt = INT_MAX;
	int tmp = 0;

	for (int i = 0; i < N; i++) {
		cnt = 0;
		int j;
		for (j = i + 1; j < N; j++) {
			cnt += arr[j] - arr[j-1] -1;
			if (arr[j] - arr[i] >= 4) {
				j++;
				break;
			}
		}
		if (arr[j - 1] - arr[i] < 4) cnt += 5 - (arr[j - 1] - arr[i] + 1);
		min_cnt = min(min_cnt, cnt);
	}

	cout << min_cnt << endl;

	return 0;
}