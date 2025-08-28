#include <stdio.h>

void boothsmultiply(int M, int Q){
    int Q_1 = 0, A = 0, iteration = 1;
    int A_0, A_MSB, Q_0, Q_MSB;
    while (iteration <= 32){
        Q_0 = Q & 1;
        if((Q_0 == 1) && (Q_1 == 0)){
            A -= M;
        } else if ((Q_0 == 0) && (Q_1 == 1)){
            A += M;
        }
        Q_1 = Q_0;
        Q = (A & 1) << 31 | ((unsigned)Q >> 1);
        A >>= 1;
        iteration++;
    }
    long long result = ((long long)A << 32) | (unsigned int)Q;
    printf("Product = %lld\n", result);
}

int main(){
    int num1, num2;
    printf("Enter first number : ");
    scanf("%d", &num1);
    printf("Enter second number : ");
    scanf("%d", &num2);

    boothsmultiply(num1, num2);

    return 0;
}