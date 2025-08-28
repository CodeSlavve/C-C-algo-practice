#include <stdio.h>
#define N 5

void num2bin(int num, int arr[N]){
    if (num < 0) num = -num;              //changing negative to positive
    for(int i = N-1; i >= 0; i--){        //converting to binary array
        arr[i] = num % 2;
        num /= 2;
    }
}

void twosComplement(int num, int arr[N]){
    int bits[N];
    num2bin(num, bits);
    for(int i = 0; i < N; i++){          //inverting bits
        arr[i] = !bits[i];
    }
    int carry = 1;
    for(int i = N-1; i >= 0; i--){
        int sum = arr[i] + carry;
        arr[i] = sum & 1;
        carry = (sum >> 1) & 1;
    }
}

void binAdd(int A[], int arr[]){
    int carry = 0;
    for(int i = N-1; i >= 0; i--){
        int sum = A[i] + arr[i] + carry;
        A[i] = sum & 1;
        carry = (sum >> 1) & 1;
    }
}

void printarrays(int A[], int Q[], int Q_1){
    for(int i = 0; i < N; i++){
       printf("%d", A[i]);
    }
    putchar('\t');
    for(int i = 0; i < N; i++){
        printf("%d", Q[i]);
    }
    putchar('\t');
    printf("%d\n", Q_1);
}

void boothsMultiply(int M[], int Q[], int Mn[]){
    int Q_1 = 0, count = N;
    int A[N] = {0};
    int iteration = 1;
    do{
        printf("\nIteration : %d\n", iteration);
        printf("A:\t Q: \t Q(-1):\n");
        printarrays(A, Q, Q_1);

        if((Q[N-1] == 1) && (Q_1 == 0)){
            binAdd(A, Mn);
            printarrays(A, Q, Q_1);
        }else if((Q[N-1] == 0) && (Q_1 == 1)){
            binAdd(A, M);
            printarrays(A, Q, Q_1);
        }

        Q_1 = Q[N-1];
        for(int i = N-1; i >= 0; i--){
            Q[i] = Q[i-1];
        } 
        Q[0] = A[N-1];
        int temp = A[0];
        for(int i = N-1; i >= 0; i--){
            A[i] = A[i-1];
        }
        A[0] = temp;

        printarrays(A, Q, Q_1);
        count--; iteration++;
    } while (count != 0);
    printf("\nFinal result: ");
    for(int i = 0; i < N; i++) printf("%d", A[i]);
    for(int i = 0; i < N; i++) printf("%d", Q[i]);
    putchar('\n');
}

int main(){
    int num1, num2;
    printf("Enter first number : ");
    scanf("%d", &num1);
    printf("Enter second number : ");
    scanf("%d", &num2);

    int M[N], Q[N], Mn[N];
    if(num1 < 0 && num2 < 0){
        twosComplement(num1, M);
        num2bin(num1, Mn);
        twosComplement(num2, Q);
    }else if(num1 < 0) {
        twosComplement(num1, M);
        num2bin(num1, Mn);
        num2bin(num2, Q);
    }else if(num2 < 0) {
        num2bin(num1, M);
        twosComplement(num1, Mn);
        twosComplement(num2, Q);
    }else {
        num2bin(num1, M);
        twosComplement(num1, Mn);
        num2bin(num2, Q);
    }

    printf("Binary of Multiplicand [M] : ");
    for(int i = 0; i < N; i++){
        printf("%d", M[i]);
    }
    putchar('\n');
    printf("Binary of [-M] : ");
    for(int i = 0; i < N; i++){
        printf("%d", Mn[i]);
    }
    putchar('\n');
    printf("Binary of Multiplier [Q] : ");
    for(int i = 0; i < N; i++){
        printf("%d", Q[i]);
    }
    putchar('\n');
    printf("Binary Multiplication using booths algorithm for M (%d) and Q (%d):\n", num1, num2);
    boothsMultiply(M, Q, Mn);
    printf("i.e. %d", num1 * num2);

    return 0;
}