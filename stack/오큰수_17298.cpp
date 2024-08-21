#include <iostream>
#include <stack>
using namespace std;

int a[1000001] = {0};
int answer[1000001] = {0};

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  stack<int> s;

  for (int i = n - 1; i >= 0; i--) {
    while (!s.empty() && s.top() <= a[i]) {
      s.pop();
    }
    if (s.empty()) {
      answer[i] = -1;
    } else if (s.top() > a[i]) {
      answer[i] = s.top();
    }
    s.push(a[i]);
  }

  for (int i = 0; i < n; i++) {
    cout << answer[i] << " ";
  }
}
