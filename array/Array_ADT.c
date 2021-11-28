#include<stdio.h>
#include<stdlib.h>
struct Array {
    int *A;
    int size;
    int length;
};

void Display(struct Array arr){
    printf("The elements are : [ ");
    for(int i=0;i<arr.length;i++){
        printf("%d, ",arr.A[i]);
    }
    printf("]\n");
}

int Append(struct Array *arr,int x){
    if(arr->length == arr->size){
        return 0;
    }else {
        arr->A[arr->length] = x;
        arr->length++;
        return 1;
    }
}

int Insert(struct Array *arr,int index,int x){
    if(arr->length == arr->size){
        return 0;
    }else {
        for(int i=arr->length-1;i >= index;i--){
            arr->A[i+1] = arr->A[i];
        }
        arr->A[index] = x;
        arr->length++;
        return 1;
    }
}

int Delete(struct Array *arr,int index){
    int i;
    if(index <= (arr->length-1)){
        arr->A[index] = 0;
        for(i=index;i < arr->length-1;i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->A[i] = 0;
        arr->length--;
        return 1;
    }else {
        return 0;
    }
}

int Linear_Search(struct Array *arr,int key){
    for(int i=0;i<arr->length;i++){
        if(key == arr->A[i]){
            return i;
        }
    }
    return -1;
}

int Binary_Search(struct Array *arr,int key){
    int mid, midIndex, low = 0, high = arr->length-1;
    while(low <= high){
        midIndex = ( low + high )/2;
        mid = arr->A[midIndex];
        if(key == mid){
            return midIndex;
        }else if(key < mid){
            high = midIndex - 1;
        }else {
            low = midIndex + 1;
        }
    }
    return -1;
}

int Get(struct Array arr,int index){
    if(index >=0 && index<(arr.length)){
        return arr.A[index];
    }
}

void Set(struct Array *arr,int index,int x){
    if(index >=0 && index<(arr->length)){
        arr->A[index] = x;
    }
}

int Min(struct Array arr){
    int min = arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(arr.A[i] < min){
            min = arr.A[i];
        }
    }
    return min;
}

int Max(struct Array arr){
    int max = arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(arr.A[i] > max){
            max = arr.A[i];
        }
    }
    return max;
}

int Sum(struct Array arr){
    int sum = 0;
    for(int i=0;i<arr.length;i++){
        sum += arr.A[i];
    }
    return sum;
}

float Average(struct Array arr){
    float sum = 0;
    for(int i=0;i<arr.length;i++){
        sum += arr.A[i];
    }
    return sum/arr.length;
}

void Reverse(struct Array *arr){
    int temp, n = arr->length;
    for(int i=0;i<n/2;i++){
        temp = arr->A[i];
        arr->A[i] = arr->A[n-i-1];
        arr->A[n-i-1] = temp;
    }
}

void Left_Shift(struct Array *arr){
    int i;
    for(i=0;i < arr->length-1;i++){
        arr->A[i] = arr->A[i+1];
    }
    arr->A[i] = 0;
}

void Right_Shift(struct Array *arr){
    int i;
    for(i=arr->length-1;i > 0;i--){
        arr->A[i] = arr->A[i-1];
    }
    arr->A[i] = 0;
}

void Left_Rotate(struct Array *arr){
    int temp = arr->A[0], i;
    for(i=0;i < arr->length-1;i++){
        arr->A[i] = arr->A[i+1];
    }
    arr->A[i] = temp;
}

void Right_Rotate(struct Array *arr){
    int temp = arr->A[arr->length-1], i;
    for(i=arr->length-1;i > 0;i--){
        arr->A[i] = arr->A[i-1];
    }
    arr->A[i] = temp;
}

int IsSorted(struct Array arr){
    for(int i=0;i<arr.length-1;i++){
        if(arr.A[i] > arr.A[i+1]){
            return 0;
        }
    }
    return 1;
}

int InsertInSortedArray(struct Array *arr,int x){
    if(arr->size == arr->length){
        return 0;
    }
    int i = arr->length - 1;
    while(arr->A[i] > x){
        arr->A[i+1] = arr->A[i];
        i--;
    } 
    arr->A[i+1] = x;
    arr->length++;
    return 1;
}

void Rearrange(struct Array *arr){
    int i = 0, j = arr->length-1, temp;
    while(i < j){
        while(arr->A[i] < 0){
            i++;
        }
        while(arr->A[j] > 0){
            j--;
        }
        if(i<j){
            temp = arr->A[i];
            arr->A[i] = arr->A[j];
            arr->A[j] = temp;
        }
    }
}

struct Array *Merge(struct Array arr1,struct Array arr2){
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->length = arr1.length + arr2.length;
    arr3->size = arr1.size + arr2.size;
    while(k < arr3->length && i < arr1.length && j < arr2.length){
        if(arr1.A[i] < arr2.A[j]){
            arr3->A[k++] = arr1.A[i++];
        }else {
            arr3->A[k++] = arr2.A[j++];
        }
    }

    for(;j<arr2.length;j++){
        arr3->A[k++] = arr2.A[j];
    }
    for(;i<arr2.length;i++){
        arr3->A[k++] = arr1.A[i];
    }
    return arr3;
}

// Set operations
struct Array *Union1(struct Array arr1,struct Array arr2){  // unsorted arrays
    int i = 0, j = 0, k = 0, exists = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->size = arr1.size + arr2.size;
    for(i=0;i < arr1.length;i++){
        arr3->A[k++] = arr1.A[i];
    }
    for(j=0;j < arr2.length;j++){
        for(int ind = 0;ind < k;ind++){
            if(arr2.A[j] == arr3->A[ind]){
                exists = 1;
                break;
            }
        }
        if(!exists){
            arr3->A[k++] = arr2.A[j];
        }
        exists = 0;
    }
    arr3->length = k;
    return arr3;
}

struct Array *Union2(struct Array arr1,struct Array arr2){ //sorted arrays
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->size = arr1.size + arr2.size;
    while(i < arr1.length && j < arr2.length){
        if(arr1.A[i] < arr2.A[j]){
            arr3->A[k++] = arr1.A[i++];
        }
        if(arr2.A[j] < arr1.A[i]){
            arr3->A[k++] = arr2.A[j++];
        }
        if(arr1.A[i] == arr2.A[j]){
            arr3->A[k++] = arr1.A[i++];
            j++;
        }
    }  
    for(;i < arr1.length;i++){
        arr3->A[k++] = arr1.A[i];
    }
    for(;j < arr2.length;j++){
        arr3->A[k++] = arr2.A[j];
    }
    arr3->length = k;
    return arr3;
}

struct Array *Intersection1(struct Array arr1,struct Array arr2){ //unsorted arrays
    int i = 0, j = 0, k = 0, exists = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->size = arr1.size + arr2.size;
    for( i = 0;i<arr1.length;i++){
        for(j = 0;j<arr2.length;j++){
            if(arr1.A[i] == arr2.A[j]){
                exists = 1;
                break;
            }
        }
        if(exists){
            arr3->A[k++] = arr1.A[i];
        }
        exists = 0;
    } 
    arr3->length = k;
    return arr3;
}

struct Array *Intersection2(struct Array arr1,struct Array arr2){ //sorted arrays
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->size = arr1.size + arr2.size;
    while(i < arr1.length && j < arr2.length){
        if(arr1.A[i] < arr2.A[j]){
            i++;
        }
        if(arr2.A[j] < arr1.A[i]){
           j++;
        }
        if(arr1.A[i] == arr2.A[j]){
            arr3->A[k++] = arr1.A[i++];
            j++;
        }
    }  
    arr3->length = k;
    return arr3;
}

struct Array *Difference1(struct Array arr1,struct Array arr2){ //unsorted arrays
    int k = 0, exists = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->size = arr1.size;
    for(int i=0;i<arr1.length;i++){
        for(int j=0;j<arr2.length;j++){
            if(arr1.A[i] == arr2.A[j]){
                exists = 1;
                break;
            }
        }
        if(!exists){
            arr3->A[k++] = arr1.A[i];
        }
        exists = 0;
    }    
    arr3->length = k;
    return arr3;
}

struct Array *Difference2(struct Array arr1,struct Array arr2){ //sorted arrays
    int i=0, j=0, k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->size = arr1.size;
    while(i < arr1.length && j < arr2.length){
        if(arr1.A[i] == arr2.A[j]){
            i++;
            j++;
        }
        if(arr1.A[i] < arr2.A[j]){
            arr3->A[k++] = arr1.A[i++];
        }
        if(arr2.A[j] < arr1.A[i]){
            j++;
        }
    }
    for(;i<arr1.length;i++){
        arr3->A[k++] = arr1.A[i];
    }
    arr3->length = k;
    return arr3;
}

int MAX(struct Array arr){
    int max = arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(arr.A[i] >= max){
            max = arr.A[i];
        }
    }
    return max;
}

void duplicates(struct Array arr){
    struct Array temp;
    temp.length = MAX(arr) + 1;
    int a[temp.length];
    temp.A = a;
    for(int ind=0;ind<temp.length;ind++){
        temp.A[ind] = 0; 
    }
    for(int ind=0;ind<arr.length;ind++){
        temp.A[arr.A[ind]] += 1; 
    }
    for(int i=0;i<temp.length;i++){
        if(temp.A[i] > 1){
            printf("%d is repeated %d times\n",i,temp.A[i]-1);
        }
    }
    Display(temp);
}

void main()
{
    struct Array arr1;
    int a[10] = {2,5,2,5,2};
    arr1.A = a;
    arr1.size = 10;
    arr1.length = 5;
    duplicates(arr1);
}