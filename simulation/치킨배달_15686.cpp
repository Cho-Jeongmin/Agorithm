#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, m;
int arr[52][52];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
int mn = INT_MAX;

// 도시의 치킨 거리
int city_chicken_dist(){
    int sum = 0;
    for(auto h : house){
        int c1 = h.second;
        int r1 = h.first;

        // 집의 치킨 거리
        int chicken_dist = INT_MAX;
        for(auto c : chicken){
            int r2 = c.first;
            int c2 = c.second;
            if(arr[r2][c2] == 2) continue; // 폐업된 치킨집은 패스
            int dist = abs(r1-r2) + abs(c1-c2);
            if(chicken_dist > dist) chicken_dist = dist;
        }

        sum += chicken_dist;
    }
    return sum;
}

 // k개의 치킨집을 고른 상태에서 num-k개의 치킨집을 더 고르는 함수.
void backtracking(int k, int num, int r, int c){ //r과 c는 직전에 고른 치킨집의 좌표

    if(k == num){
        int val = city_chicken_dist(); // 도시의 치킨 거리 구하기
        if(mn > val) mn = val; // 최소 거리 갱신
        return;
    }

    // ⚠️ 2차원 배열 순회
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i < r) continue;
            if(i == r && j <= c) continue;
            if(arr[i][j] != 2) continue;
            
            arr[i][j] = 3; // 방문표시
            backtracking(k+1, num, i, j);
            arr[i][j] = 2;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // 입력
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1) house.push_back({i, j});
            if(arr[i][j] == 2) chicken.push_back({i, j});
        }
    }
    
    // 1~m개 고르기
    for(int num=1; num<=m; num++){
        backtracking(0, num, 0, 0);
    }
    
    cout << mn;

    return 0;
}
