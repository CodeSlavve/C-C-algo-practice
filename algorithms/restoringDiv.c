#include <stdio.h>

void RestoringAlgo(int M, int Q){
    int bits = sizeof(int) * 8;      //Unsigned integer 64 bits
    int A = 0, iteration = 0;
    int A_MSB;

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
            Q = Q | 1;                        //Q) = 1 when A is positive
        }
        iteration++;
    }

    A_MSB = (A >> (bits - 1)) & 1;        //A_MSB isolation again
    if(A_MSB == 1) A += M;

    printf("Remainder : %d\t", A);
    printf("Quotent : %d\n", Q);
}

int main(){
    int divisor, dividend;
    printf("Division for 'unsigned int'; Enter positive values only.\n");
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