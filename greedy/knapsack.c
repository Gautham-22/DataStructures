#include<stdio.h>

double knapsack(double *val, double *weight, double W, int n) {
    double temp1, temp2, temp;

    // for sorting
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-1-i; j++) {
            temp1 = val[j] / weight[j];
            temp2 = val[j+1] / weight[j+1];
            if(temp1 > temp2) {
                temp = val[j];
                val[j] = val[j+1];
                val[j+1] = temp;

                temp = weight[j];
                weight[j] = weight[j+1];
                weight[j+1] = temp;
            }
        }
    }

    double finalValue = 0.0, currentWeight = 0.0;
    int i;
    for(i=n-1; i>=0; i--) {
        if(currentWeight + weight[i] <= W) {
            currentWeight += weight[i];
            finalValue += val[i];
            printf("%lf-- %lf \n",currentWeight,finalValue);
        } else {
            break;
        }
    }

    finalValue += (val[i] / weight[i]) * (W - currentWeight);

    return finalValue;
}

void main() {
    int n;
    double W;
    printf("Enter the capacity of knapsack: ");
    scanf("%lf",&W);
    printf("Enter the number of items: ");
    scanf("%d",&n);
    double value[n], weight[n];
    printf("Enter the value or profit and weight of all items: ");
    for(int i=0; i<n; i++) {
        scanf("%lf %lf",&value[i],&weight[i]);
    }
    printf("Maximum value/profit that can be drawn: %lf.\n",knapsack(value,weight,W,n));
}