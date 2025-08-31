#include <iostream>
#include <cmath>
#define N 9
using namespace std;

int SudokuCheck(int x[N][N]){

    //Checking Row
    for(int i = 0; i < N; i++){
        bool seen[N+1] = {false};
        for(int j = 0; j < N; j++){
            int num = x[i][j];
            if(num < 1 || num > 9){
                cout << "Number out of bound.\n" << flush;
                return 0;
            }
            if(seen[num]) {
                cout << "Repetition in Row " << i + 1 << endl;
                return 0;
            }
            seen[num] = true;
        }
    }

    //Checking Column =
    for(int j = 0; j < N; j++){
        bool seen[N + 1] = {false};
        for(int i = 0; i < N; i++){
            int num = x[i][j];
            if(num < 1 || num > 9){
                cout << "Number out of bound.\n" << flush;
                return 0;
            }
            if(seen[num]){
                cout << "Repition in Column " << j + 1 << endl;
                return 0;
            }
            seen[num] = true;
        }
    }

    // Checking each 3x3 grid for duplicates
    for (int row = 0; row < N; row += 3) {
        for (int col = 0; col < N; col += 3) {
            bool seen[N + 1] = {false};
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int num = x[row + i][col + j];
                    if(num < 1 || num > 9){
                        cout << "Number out of bound.\n" << flush;
                        return 0;
                    }
                    if (seen[num]) {
                        cout << "Repetition in a 3 x 3 grid.\n" << flush;
                        return 0;
                    }
                    seen[num] = true;
                }
            }
        }
    }
    return 1;
}

int main(){
    cout << "Enter your 9 x 9 Sudoku (1 - 9):\n";
    int x[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> x[i][j];
        }
    }

    int result = SudokuCheck(x);
    if(result) cout << "Entered Numbers are a Sudoku.\n" << flush;
    return 0;
}