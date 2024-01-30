#include <iostream>
#include <climits>

using namespace std;

int n, m; // 사무실의 크기
int arr[10][10]; // 사무실 배열
int k = 0; // cctv의 개수
int six = 0; // 벽 개수
pair<int, int> cctv[10]; // cctv 위치 저장 배열 {y좌표, x좌표}
int max_cnt = 0; //감시지대 최대크기
int cnt = 0; //감시지대 크기
int dx[] = {1, 0, -1, 0}; //우 상 좌 하
int dy[] = {0, -1, 0, 1};

//한 줄 감시
void monitor(int level, int dir, bool mon,int y, int x){
    dir %= 4;
    while(true){
        y = y + dy[dir];
        x = x + dx[dir];

        if(y < 0 || y >= n || x < 0 || x >= m) break; // 배열 범위를 벗어남
        if(arr[y][x] == 6) break; // 벽에 가로막힘

        if(mon && arr[y][x] == 0){
            arr[y][x] = level + 7; // 한 칸 감시 표시
            cnt++;
        }
        if(!mon && arr[y][x] == level + 7){
            arr[y][x] = 0; // 한 칸 감시 해제
            cnt--;
        }
    }
}

// level개의 cctv가 감시하고 있는 상태. 이제 (level+1)번째 cctv가 감시할 차례.
void backtracking(int level){

    // 마지막 cctv인 경우
    if(level == k){
        if(max_cnt < cnt) max_cnt = cnt; // 감시지대 최대크기 갱신
        return;
    }

    int y = cctv[level].first; // 현재 cctv의 y좌표
    int x = cctv[level].second; // 현재 cctv의 x좌표

    // 1번 cctv인 경우
    if(arr[y][x] == 1){
        // 1번 cctv를 90도씩 네 번 회전시키기
        for(int dir=0; dir<4; dir++){ // dir은 감시방향을 의미(0:우, 1:상, 2:좌, 3:하)
            monitor(level, dir, true, y, x); // 한 줄 감시
            backtracking(level + 1); // 다음 cctv 감시하러 가기
            monitor(level, dir, false, y, x); // 한 줄 감시 해제
        }
    }
    // 2번 cctv인 경우
    else if(arr[y][x] == 2){
        // 2번 cctv를 180도씩 두 번 회전시키기
        for(int dir=0; dir<2; dir++){
            monitor(level, dir, true, y, x); // 한 줄 감시
            monitor(level, dir+2, true, y, x); // 반대방향 감시
            backtracking(level + 1); // 다음 cctv 감시하러 가기
            monitor(level, dir, false, y, x); // 한 줄 감시 해제
            monitor(level, dir+2, false, y, x); // 반대방향 감시 해제
        }
    }
    // 3번 cctv인 경우
    else if(arr[y][x] == 3){
        // 3번 cctv를 90도씩 네 번 회전시키기
        monitor(level, 0, true, y, x); // 한 줄 감시
        for(int dir=0; dir<4; dir++){ // dir은 감시방향을 의미(0:우, 1:상, 2:좌, 3:하)
            monitor(level, dir+1, true, y, x); // 한 줄 감시
            backtracking(level + 1); // 다음 cctv 감시하러 가기
            monitor(level, dir, false, y, x); // 한 줄 감시 해제
        }
    }
    // 4번 cctv인 경우
    else if(arr[y][x] == 4){
        // 4번 cctv를 90도씩 네 번 회전시키기
        monitor(level, 0, true, y, x); // 한 줄 감시
        monitor(level, 1, true, y, x); // 한 줄 감시
        for(int dir=0; dir<4; dir++){ // dir은 감시방향을 의미(0:우, 1:상, 2:좌, 3:하)
            monitor(level, dir+2, true, y, x); // 한 줄 감시
            backtracking(level + 1); // 다음 cctv 감시하러 가기
            monitor(level, dir, false, y, x); // 한 줄 감시 해제
        }
    }
    // 5번 cctv인 경우
    else if(arr[y][x] == 5){
        // 5번 cctv는 회전할 필요 없음
        monitor(level, 0, true, y, x); // 한 줄 감시
        monitor(level, 1, true, y, x); // 한 줄 감시
        monitor(level, 2, true, y, x); // 한 줄 감시
        monitor(level, 3, true, y, x); // 한 줄 감시
        backtracking(level + 1); // 다음 cctv 감시하러 가기
        monitor(level, 0, false, y, x); // 한 줄 감시 해제
        monitor(level, 1, false, y, x); // 한 줄 감시 해제
        monitor(level, 2, false, y, x); // 한 줄 감시 해제
        monitor(level, 3, false, y, x); // 한 줄 감시 해제
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            // cctv 저장
            if(arr[i][j] >= 1 && arr[i][j] <= 5) cctv[k++] = {i, j};
            if(arr[i][j] == 6) six++;
        }
    }

    backtracking(0);
    cout << n*m - max_cnt - k - six;
}
