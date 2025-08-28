#include <stdio.h>

void boothsmultiply(int M, int Q){
    int Q_1 = 0, A = 0, iteration = 0;
    int Q0;
    int bits = sizeof(void*) * 4;       //signed bits

    while (iteration < bits){
        Q0 = Q & 1;
        if((Q0 == 1) && (Q_1 == 0)){
            A -= M;
        } else if ((Q0 == 0) && (Q_1 == 1)){
            A += M;
        }
        Q_1 = Q0;
        Q = (A & 1) << (bits - 1) | ((unsigned)Q >> 1);
        A >>= 1;
        iteration++;
    }
    long long result = ((long long)A << bits) | (unsigned int)Q;
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