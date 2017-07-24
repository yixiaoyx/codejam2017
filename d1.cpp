#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define O 2
#define X 1
#define P -1 // +
#define XN 3
#define PN 4

bool inRange(int x, int min, int max) {
    return x>=min && x <= max;
}

bool canPutO(int **m, int n, int r, int c) {
    for (int i = 1; i <= n; i++) {
        if (i!=c && m[r][i] != 0 && m[r][i] != P && m[r][i] != PN) return false;
        if (i!=r && m[i][c] != 0 && m[i][c] != P && m[r][i] != PN) return false;
        if (i!=r && inRange(r+c-i, 1, n) && m[i][r+c-i] != 0 
                && m[i][r+c-i] != X && m[i][r+c-i] != XN) return false;
        if (i!=r && inRange(i-r+c, 1, n) && m[i][i-r+c] != 0 
                && m[i][i-r+c] != X && m[i][i-r+c] != XN) return false;
    }
    return true;
}

bool canPutP(int **m, int n, int r, int c) {
    for (int i = 1; i <= n; i++) {
        if (i!=r && inRange(r+c-i, 1, n) && m[i][r+c-i] != 0 
                && m[i][r+c-i] != X && m[i][r+c-i] != XN) return false;
        if (i!=r && inRange(i-r+c, 1, n) && m[i][i-r+c] != 0 
                && m[i][i-r+c] != X && m[i][i-r+c] != XN) return false;
    }
    return true;
}

bool canPutX(int **m, int n, int r, int c) {
    for (int i = 1; i <= n; i++) {
        if (i!=c && m[r][i] != 0 && m[r][i] != P && m[r][i] != PN) return false;
        if (i!=r && m[i][c] != 0 && m[i][c] != P && m[r][i] != PN) return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    int t, n, m, r, c, moves, score;
    char model;
    int **matrix;
    vector<string>change;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        cin >> m;
        moves = 0, score = m;
        matrix = (int **)calloc(n+1, sizeof(int *));
        for (int j = 0; j <= n; j++)
            matrix[j] = (int *)calloc(n+1, sizeof(int));
        for (int j = 0; j < m; j++) {
            cin >> model;
            cin >> r;
            cin >> c;
            switch(model) {
                case '+': { matrix[r][c] = P;
                            break;
                          }
                case 'x': { matrix[r][c] = X;
                            break;
                          }
                case 'o': { matrix[r][c] = O;
                            score++;
                            break;
                          }
            }
        }
        for (int k = 1; k <= n; k++) {
            for (int l = 1; l <= n; l++) {
                if (matrix[k][l] == 0) {
                    if (canPutX(matrix, n, k, l)) {
                        matrix[k][l] = XN;
                        score++;
                        moves++;
                    } else if (canPutP(matrix, n, k, l)) {
                        matrix[k][l] = PN;
                        score++;
                        moves++;
                    }
                }
            }
        } 
        for (int k = 1; k <= n; k++) {
            for (int l = 1; l <= n; l++) {
                if (matrix[k][l]==X || matrix[k][l]==P || matrix[k][l]==0) {
                    if (canPutO(matrix, n, k, l)) {
                        matrix[k][l] = O;
                        score += (matrix[k][l]==0)? 2:1;
                        moves++;
                        change.push_back("o " + to_string(k) + " " + to_string(l));
                    }
                } else if (matrix[k][l]==XN || matrix[k][l]==PN) {
                    if (canPutO(matrix, n, k, l)) {
                        matrix[k][l] = O;
                        score++;
                        change.push_back("o " + to_string(k) + " " + to_string(l));
                    } else {
                        if (matrix[k][l]==XN)   
                            change.push_back("x " + to_string(k) + " " + to_string(l));
                        else if (matrix[k][l]==PN)
                            change.push_back("+ " + to_string(k) + " " + to_string(l));
                    }
                }
            }
        } 
        cout << "Case #" << i+1 << ": " << score << " " << moves << endl;
        for (int j = 0; j < moves; j++) {
            cout << change.at(j) << endl;
        }
        change.clear();
        free(matrix);
    }

    return 0;
}
