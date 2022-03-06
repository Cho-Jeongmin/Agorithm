#include <iostream>
#include <map>
#include <string>

using namespace std;

int N, M;
map<string, bool> m;
string str;
int cnt = 0;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {

		cin >> str;
		m[str] = true;//key: tmp, value: true
		//s.insert(pair<string, bool>(str, true));µµ °¡´É
	}

	for (int i = 0; i < M; i++) {
		cin >> str;
		if (m[str]) cnt++;
	}

	cout << cnt;

	return 0;
}