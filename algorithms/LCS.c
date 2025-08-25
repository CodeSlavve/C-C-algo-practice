#include <stdio.h>
#include <string.h>

void LCS(char SeqX[], char SeqY[], int m, int n) {
    int LCS[m+1][n+1];

    //Fill LCS table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                LCS[i][j] = 0;
            }
            else if (SeqX[i-1] == SeqY[j-1]) {
                LCS[i][j] = 1 + LCS[i-1][j-1];
            }
            else {
                LCS[i][j] = (LCS[i-1][j] > LCS[i][j-1]) ? LCS[i-1][j] : LCS[i][j-1];
            }
        }
    }

    printf("The size of LCS: %d\n", LCS[m][n]);

    //Reconstruct LCS sequence
    int index = LCS[m][n];
    char SeqR[index + 1];
    SeqR[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (SeqX[i-1] == SeqY[j-1]) {
            SeqR[index - 1] = SeqX[i-1];
            i--; j--; index--;
        }
        else if (LCS[i-1][j] > LCS[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }

    printf("LCS : ");
    for(int k = 0; k < LCS[m][n]; k++){
        printf("%c ", SeqR[k]);
    }
}

int main() {
    int sizeX, sizeY;
    printf("Enter size of first sequence: ");
    scanf("%d", &sizeX);
    printf("Enter size of second sequence: ");
    scanf("%d", &sizeY);

    char SeqX[sizeX+1], SeqY[sizeY+1];
    printf("Enter first sequence (string): ");
    scanf("%s", SeqX);
    printf("Enter second sequence (string): ");
    scanf("%s", SeqY);

    LCS(SeqX, SeqY, strlen(SeqX), strlen(SeqY));

    return 0;
}