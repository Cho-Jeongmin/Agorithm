#include <iostream>

using namespace std;

int laptop[41][41];

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    // 모든 스티커에 대해
    for(int tmp=0; tmp<k; tmp++){
        int r, c;
        cin >> r >> c;

        int sti[11][11];

        // k번째 스티커 입력받기
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin >> sti[i][j];
            }
        }

        // 네 방향으로 돌리기
        for(int dir=0; dir<4; dir++){

            bool sticked = false;

            int a, b; // 스티커의 가로 세로 길이
            if(dir % 2 == 0){
                a = r;
                b = c;
            }
            else{
                a = c;
                b = r;
            }

            // 노트북의 왼쪽 위부터 맞춰보기
            for(int i=0; i<=n-a; i++){
                for(int j=0; j<=m-b; j++){

                    // (i, j)에 붙일 수 있는지 확인
                    bool fit = true;
                    for(int p=0; p<a; p++){
                        for(int q=0; q<b; q++){

                            int d, e; // 스티커 내의 좌표
                            if(dir == 0){
                                d = p;
                                e = q;
                            }
                            else if(dir == 1){
                                d = r-q-1;
                                e = p;
                            }
                            else if(dir == 2){
                                d = r-p-1;
                                e = c-q-1;
                            }
                            else if(dir == 3){
                                d = q;
                                e = c-p-1;
                            }

                            if(laptop[i+p][j+q] == 1 && sti[d][e] == 1){
                                fit = false;
                            }
                        }
                    }

                    // 붙일 수 있다면 붙이기
                    if(fit){
                        for(int p=0; p<a; p++){
                            for(int q=0; q<b; q++){

                                int d, e; // 스티커 내의 좌표
                                if(dir == 0){
                                    d = p;
                                    e = q;
                                }
                                else if(dir == 1){
                                    d = r-q-1;
                                    e = p;
                                }
                                else if(dir == 2){
                                    d = r-p-1;
                                    e = c-q-1;
                                }
                                else if(dir == 3){
                                    d = q;
                                    e = c-p-1;
                                }

                                if(sti[d][e] == 1) laptop[i+p][j+q] = 1;
                            }
                        }
                        sticked = true;
                    }
                    if(sticked) break;
                }
                if(sticked) break;
            }
            if(sticked) break;
        }
    }

    // 스티커가 붙은 칸의 수 세기
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(laptop[i][j] == 1) cnt++;
        }
    }

    cout << cnt;

    return 0;
}
