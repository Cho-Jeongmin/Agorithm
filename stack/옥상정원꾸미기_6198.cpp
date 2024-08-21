#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  cin >> n;

  int h[80001] = {0};

  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  stack<pair<int, int>> s;
  s.push(make_pair(1000000001, n));

  int answer[80001] = {0};

  for (int i = n - 1; i >= 0; i--) {
    while (s.top().first < h[i]) {
      answer[i] += (1 + answer[s.top().second]);
      s.pop();
    }
    s.push(make_pair(h[i], i));
  }

  long long sum = 0;

  for (int i = 0; i < n; i++) {
    sum += answer[i];
  }

  cout << sum;
}
