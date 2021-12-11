#include<stdio.h>

void add(int* A, int* B, int* C, int n, int x){
    int i,j;
    int m=n;
    if(x==0) {
        m=n; 
    }                                                                                                                              
    else {
        m=n/2;
    }
    for (i=0;i<m;i++) {
        for (j=0;j<m;j++) {
            *(C+i*m+j) = *(A+i*n+j) + *(B+i*n+j);
        }
    }
}
   
void sub(int* A, int* B, int* C, int n, int x){
    int i,j;
    int m=n;
    if(x==0) {
        m=n; 
    }                                                                                                                              
    else {
        m=n/2;
    }
    for (i=0;i<m;i++) {
        for (j=0;j<m;j++) {
            *(C+i*m+j) = *(A+i*n+j) - *(B+i*n+j);
        }
    }
} 

void strassen(int* A, int* B, int* C, int n){
    int i,j;
    if(n==2) {                               //Base case is 2x2 matrix
        int P=(*A+*(A+n+1))*(*B+*(B+n+1));  //P=(A[0][0]+A[1][1])*(B[0][0]+B[1][1])
        int Q=(*(A+n)+*(A+n+1))*(*B);   //Q=(A[1][0]+A[1][1])*B[0][0]
        int R=(*A)*(*(B+1)-*(B+n+1));   //R=A[0][0]*(B[0][1]-B[1][1])
        int S=(*(A+n+1))*(*(B+n)-*B);   //S=A[1][1]*(B[1][0]-B[0][0])
        int T=(*A+*(A+1))*(*(B+n+1));   //T=(A[0][0]+A[0][1])*B[1][1]
        int U=(*(A+n)-*A)*(*B+*(B+1));  //U=(A[1][0]-A[0][0])*(B[0][0]+B[0][1])
        int V=(*(A+1)-*(A+n+1))*(*(B+n)+*(B+n+1));  //V=(A[0][1]-A[1][1])*(B[1][0]+B[1][1])

        *C=P+S-T+V;
        *(C+1)=R+T;
        *(C+n)=Q+S;                                                                                                                            
        *(C+n+1)=P+R-Q+U;
    }
    else {
        int m=n/2, x[m][m], y[m][m], o[n][n];
        for(i=0;i<n;i++) {
            for(j=0;j<n;j++) {
                o[i][j]=0;          //We are setting up a zero matrix to perform addition with when required
            }
        }

        /*P=(A[0][0]+A[1][1])*(B[0][0]+B[1][1])*/
        int P[m][m];
        add(A, A+m*(n+1), x, n,1);
        add(B, B+m*(n+1), y, n,1);
        strassen(x, y, P, m);                                                                                                                  
                                                                                                                                               
        /*Q=(A[1][0]+A[1][1])*B[0][0]*/
        int Q[m][m];
        add(A+m*n, A+m*(n+1), x, n,1);
        add(B, o, y, n,1);
        strassen(x, y, Q, m);                                                                                                                  
                                                                                                                                               
        /*R=A[0][0]*(B[0][1]-B[1][1])*/
        int R[m][m];
        add(A, o, x, n,1);               //adding A to 0 matrix
        sub(B+m, B+m*(n+1), y, n,1);
        strassen(x, y, R, m);                                                                                                                  
                                                                                                                                               
        /*S=A[1][1]*(B[1][0]-B[0][0])*/
        int S[m][m];
        add(A+m*(n+1), o, x, n,1);
        sub(B+m*n, B, y, n,1);
        strassen(x, y, S, m);                                                                                                                  
                                                                                                                                               
        /*T=(A[0][0]+A[0][1])*B[1][1]*/
        int T[m][m];
        add(A, A+m, x, n,1);
        add(B+m*(n+1), o, y, n,1);
        strassen(x, y, T, m);                                                                                                                  
                                                                                                                                               
        /*U=(A[1][0]-A[0][0])*(B[0][0]+B[0][1])*/
        int U[m][m];
        sub(A+m*n, A, x, n,1);
        add(B, B+m, y, n,1);
        strassen(x, y, U, m);                                                                                                                  
                                                                                                                                               
        /*V=(A[0][1]-A[1][1])*(B[1][0]+B[1][1])*/
        int V[m][m];
        sub(A+m, A+m*(n+1), x, n,1);
        add(B+m*n, B+m*(n+1), y, n,1);
        strassen(x, y, V, m);                                                                                                                  
                                                                                                                                               
        int W[m][m], X[m][m], Y[m][m], Z[m][m];
        sub(V,T,x,m,0);
        add(S,x,y,m,0);
        add(P,y,W,m,0); // W=P+S-T+V
        add(R,T,X,m,0); // X=R+T
        add(Q,S,Y,m,0); // Y=Q+S
        sub(U,Q,x,m,0);
        add(R,x,y,m,0);
        add(P,y,Z,m,0); // Z=P+R-Q+U
        for (i=0;i<m;i++)
            for (j=0;j<m;j++){
                *(C+i*n+j) = W[i][j]; //C[0][0]=W
                *(C+i*n+j+m) = X[i][j]; //C[0][1]=X
                *(C+(i+m)*n+j) = Y[i][j]; //C[1][0]=Y
                *(C+(i+m)*n+j+m) = Z[i][j]; //C[1][1]=Z
            }                                                                                                                                  
    }                                                                                                                                          
}                                                                                                                                          
void main() {
    int i,j,k,m,n,n1,n2,n3,n4,o=1;

    printf("Enter the order of the 1st Matrix (rows and columns): ");
    scanf("%d%d",&n1,&n2);
    int A[n1][n2];
    printf("Enter the elements of first matrix (row-wise):\n");
    for(i=0; i<n1; i++){
        for(j=0; j<n2; j++) {
            scanf("%d",&A[i][j]);
        }
    }

    printf("Enter the no. of columns of the 2nd Matrix: ");
    scanf("%d",&n3);
    int B[n2][n3];
    printf("Enter the elements of second matrix (row-wise):\n");
    for(i=0;i<n2;i++) {
        for(j=0;j<n3;j++) {
            scanf("%d",&B[i][j]);
        }
    }

    // choosing the largest dimension and filling rest with 0s                                                                                                                                  
    if(n1>n2)
        n4=n1;                               
    else
        n4=n2;  

    if(n3>n4)
        n=n3;                                                                                                                              
    else
        n=n4;

    // finding the minimum power of 2 that is greater than largest dimension
    m = 1;
    while(n > m) {
        m *= 2;
    }

    int a[m][m],b[m][m],C[m][m];
    for(i=0;i<m;i++) {
        for(j=0;j<m;j++){
            a[i][j]=0;
            b[i][j]=0;
        }
    }
    for(i=0;i<n1;i++) {
        for(j=0;j<n2;j++) {
            a[i][j]=A[i][j];
        }  
    }                                                                                                                 
    for(i=0;i<n2;i++) {
        for(j=0;j<n3;j++) {
            b[i][j]=B[i][j];   
        }
    }                                                                                                                       
                                                                                                                                               
    printf("This is the first matrix: \n");
    for(i=0;i<n1;i++){
        printf("| ");
        for(j=0;j<n2;j++) {
            printf("%d ",a[i][j]);
        }
        printf("|\n");
    }

    printf("This is the second matrix: \n");
    for(i=0;i<n2;i++){
        printf("| ");
        for(j=0;j<n3;j++) {
            printf("%d ",b[i][j]);
        }
        printf("|\n");
    }
                                                                                                                                               
    strassen(a,b,C,m);

    printf("This is the final matrix: \n");
    for(i=0;i<n1;i++){
        printf("| ");
        for(j=0;j<n3;j++) {
            printf("%d ",C[i][j]);
        }
        printf("|\n");
    }
}                 