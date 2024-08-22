#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define ll long long

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  cin >> n;

  stack<pair<int, int>> s;
  ll sum = 0;

  while (n--) {
    int height;
    cin >> height;

    while (!s.empty() && s.top().first < height) {
      sum += s.top().second;
      s.pop();
    }

    int cnt = 0;

    while (!s.empty() && s.top().first == height) {
      sum += s.top().second;
      cnt = s.top().second;
      s.pop();
    }

    if (!s.empty() && s.top().first > height) {
      sum++;
    }

    s.push({height, cnt + 1});
  }

  cout << sum;
}
