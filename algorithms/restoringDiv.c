#include <stdio.h>
#include <stdlib.h>

//Works for Signed integer too
void RestoringAlgo(int M, int Q){
    int bits = sizeof(int) * 8;      //Signed integer 32 bits  (4 * 8 = 32)
    int A = 0, iteration = 0;
    int A_MSB;

    int signM = (M < 0);
    int signQ = (Q < 0);

    M = abs(M);
    Q = abs(Q);

    while(iteration < bits){
        A_MSB = (A >> (bits - 1)) & 1;        //A_MSB isolation

        A = (A << 1) | ((Q >> (bits - 1)) & 1);     //Left-Shift A,Q (A value changes)
        Q <<= 1;                                    //Q value changes
        if(A_MSB == 1){                    //A is negative
            A += M;
        } else if(A_MSB == 0){             //A is positive
            A -= M;
        }

        A_MSB = (A >> (bits - 1)) & 1;        //A_MSB isolation again
        if(A_MSB == 1){
            Q = Q | 0;                        //Q0 = 0 when A is negative
        } else if (A_MSB == 0){
            Q = Q | 1;                        //Q0 = 1 when A is positive
        }
        iteration++;
    }

    A_MSB = (A >> (bits - 1)) & 1;        //A_MSB isolation again
    if(A_MSB == 1) A += M;

    if(signM ^ signQ) Q = - Q;
    if(signQ) A = -A;

    printf("Remainder : %d\t", A);
    printf("Quotent : %d\n", Q);
}

int main(){
    int divisor, dividend;
    printf("Enter the Divisor (M) : ");
    scanf("%d", &divisor);
    if(divisor == 0) {
        printf("Division with 0 not possible.\n");
        return 0;
    }

    printf("Enter the Dividend (Q) : ");
    scanf("%d", &dividend);

    RestoringAlgo(divisor, dividend);
    return 0;
}