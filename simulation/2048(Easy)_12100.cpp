#include <iostream>

using namespace std;

int n;
int arr[21][21];
int arr2[21][21];
int dir = 0; // (0: 좌, 1: 하, 2: 우, 3: 상)
int prev_dir = 0;

void rotate(int dir){
    int diff = (dir - prev_dir + 4) % 4;
    while(diff--){
        //복사
        int tmp[21][21];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                tmp[i][j] = arr2[i][j];
            }
        }
        //diff번 시계방향으로 90도 회전
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                arr2[i][j] = tmp[n-j-1][i];
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    int mx = 0;
    for(int tmp=0; tmp<(1<<10); tmp++){

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                arr2[i][j] = arr[i][j];
            }
        }

        int num = tmp;
        dir = 0;
        for(int k=0; k<5; k++){ //5번 이동

            //방향 정하기
            prev_dir = dir;
            dir = num % 4;
            num /= 4;

            rotate(dir);

            // dir 방향으로 이동시키기
            for(int i=0; i<n; i++){
                int index = 0;
                int low = 0;
                int high = 1;

                while(true){
                    //빈칸 건너뛰기
                    while(low < n && arr2[i][low] == 0){
                        low++;
                        high++;
                    }
                    while(high < n && arr2[i][high] == 0){
                        high++;
                    }
                    if(high >= n){ // 맨끝에 도달
                        int tmp = arr2[i][low];
                        arr2[i][low] = 0;
                        arr2[i][index++] = tmp;
                        break;
                    }

                    // 수가 같으면 합치기
                    if(arr2[i][low] == arr2[i][high]){
                        int tmp = arr2[i][low] * 2;
                        arr2[i][low] = 0;
                        arr2[i][high] = 0;
                        arr2[i][index++] = tmp;
                        low = high + 1;
                        high = low + 1;
                    }
                    else{
                        int tmp = arr2[i][low];
                        arr2[i][low] = 0;
                        arr2[i][index++] = tmp;
                        low = high;
                        high = low + 1;
                    }
                }
            }
        }

        //가장 큰 블록 찾기
        int block = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(block < arr2[i][j]) block = arr2[i][j];
            }
        }
        if(mx < block) mx = block;
    }

    cout << mx;
  
    return 0;
}
