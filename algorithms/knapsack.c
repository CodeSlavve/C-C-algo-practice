#include<stdio.h>


void merge(int num, int Wt[], int profit[], float fraction[], int low, int mid, int high){
    float tempFract[num], tempProfit[num], tempWeight[num];
    int k = low, i = low,  j = mid + 1;

    while(i <= mid && j <= high){
	    if(fraction[i] >= fraction[j]){
	        tempFract[k] = fraction[i];
            tempProfit[k] = profit[i];
            tempWeight[k] = Wt[i];
	        i++; k++;
	    } else {
	        tempFract[k] = fraction[j];
            tempProfit[k] = profit[j];
            tempWeight[k] = Wt[j];
	        j++;k++;
	    }
    }

    while(i <= mid){
	    tempFract[k] = fraction[i];
        tempProfit[k] = profit[i];
        tempWeight[k] = Wt[i];
	    i++ ; k++;
    }
    while(j <= high){
	    tempFract[k] = fraction[j];
        tempProfit[k] = profit[j];
        tempWeight[k] = Wt[j];
	    j++ ; k++;
    }
    
    for(i = low; i <= high; i++){
        fraction[i] = tempFract[i];
        profit[i] = tempProfit[i];
        Wt[i] = tempWeight[i];
    }
}


void mergeSort(int num, int Wt[], int profit[], float fraction[], int low, int high){
    if(low < high){
        int mid = (low + high)/2;

        mergeSort(num, Wt, profit, fraction, low, mid);
        mergeSort(num, Wt, profit, fraction, mid+1, high);

        merge(num, Wt, profit, fraction, low, mid, high);
    }
}


void knapsackAlgo(int num, int maxC, int Wt[], int profit[], float fraction[]){
    float frac = 0, prof = 0, currWt = 0;

    for(int i = 0; i < num; i++){
	    if(currWt + Wt[i] <= maxC){
	        currWt += Wt[i];
	        prof += profit[i];
        } else {
	        frac = ((maxC - currWt) / Wt[i]);
	    	currWt = currWt + Wt[i] * frac;
	        prof = prof + profit[i] * frac;
	        break;
        }
    }
    printf("\nOptimal Profit : %.2f\n", prof);
}


void displayInfo(int num, int maxC, int Wt[], int profit[], float fraction[]){
    int i;

    printf("\nWeight array: ");
    for(i = 0; i < num; i++) printf("%d ", Wt[i]);

    printf("\nProfit array: ");
    for(i = 0; i < num; i++) printf("%d ", profit[i]);

    printf("\nFraction array (Profit/Weight): ");
    for(i = 0; i < num; i++) printf("%.2f ", fraction[i]);

    printf("\nNumber of items: %d", num);
    printf("\nMaximum capacity: %d\n", maxC);
}


void main(){
    int maxC, num;

    printf("\nEnter Maximum Capacity of Weight: ");
    scanf("%d", &maxC);
    printf("\nEnter Number of Items: ");
    scanf("%d", &num);

    int Wt[num], profit[num];
    float fraction[num];

    printf("\nEnter Weight of each item: ");
    for(int i = 0; i < num; i++){
        scanf("%d", &Wt[i]);
    }
    printf("\nEnter Profit of each item: ");
    for(int i = 0; i < num; i++){
        scanf("%d", &profit[i]);
    }

    for(int i = 0; i < num; i++){
	    fraction[i] = (float)profit[i]/Wt[i];
    }

    displayInfo(num, maxC, Wt, profit, fraction);

    mergeSort(num, Wt, profit, fraction, 0, num-1);

    printf("\nSorted Fraction array(Profit/Weight):");
    for(int i = 0; i < num; i++){
        printf("%.2f ", fraction[i]);
    }

    printf("\nSorted Profit array:");
    for(int i = 0; i < num; i++){
        printf("%d ", profit[i]);
    }

    printf("\nSorted Weight array:");
    for(int i = 0; i < num; i++){
        printf("%d ", Wt[i]);
    }
    printf("\n");

    knapsackAlgo(num, maxC, Wt, profit, fraction);
}