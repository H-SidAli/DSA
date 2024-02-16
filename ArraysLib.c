#include <math.h>
//--------------------------------------------------------------------------------------
void Read1D(int *size, int T[]){
   //Reading the Array
    printf("Enter the size of the array:\n");
    scanf(" %d",size);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < *size; i++)
        {
            printf("Arr[%d] =",i);
            scanf("%d",&T[i]);
        }
}
//--------------------------------------------------------------------------------------
void Write1D(int size, int T[]){
    for (int i = 0; i < size; i++)
    {
        printf(" %d |",T[i]);
    }
    printf("\n");
    return;
}
//--------------------------------------------------------------------------------------
int MinArr1D(int size, int T[]){
    int min = T[0];
    for (int i = 1; i < size; i++)
    {
        if(min > T[i]){
            min = T[i];
        }
    };
    return min;
}
//--------------------------------------------------------------------------------------
int MaxArr1D(int size, int T[]){
    int max = T[0];
    for (int i = 1; i < size ; i++){
        if(max < T[i]){
            max = T[i];
        }
    };
    return max;
}
//--------------------------------------------------------------------------------------
int SearchV(int size, int T[],int V){
    for (int i = 0; i < size; i++)
    {
        if (T[i] == V)
        {
            return i;
        }
        }
        return -1;
    }
//--------------------------------------------------------------------------------------
void InsertV(int *size, int T[], int V, int VE){
    int ind = SearchV(*size, T, V);
    if (ind == -1){
        printf("The value doesn't exist");
    }
    else{
        *size = *size + 1;
        for (int i = *size -1 ; i >= ind +2 ; i--)
        {
            T[i] = T[i-1];
        }
        T[ind + 1] = VE;  
    }
}
//--------------------------------------------------------------------------------------
int BinSearch(int size, int T[], int V){
    int low = 0;
    int high = size-1;
    while (low <= high){
        int mid = (high + low) / 2;
        if (T[mid] == V){
            return 1;
        }
        if(T[mid] > V){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return 0;  
}
//--------------------------------------------------------------------------------------
void SqrElements(int n, int T1[],int m, int T2[], int *c, int Arr[]){
    int cpt=0;
    for(int i=0; i<n; i++){
        float a = sqrt(T1[i]);
        int b = (int) a;
        if( a == b ){
            Arr[cpt] = T1[i];
            cpt++;
        }
    }
    for (int i = 0; i < m; i++)
    {
        float a = sqrt(T2[i]);
        int b = (int) a;
        if (a == b){
            Arr[cpt] = T2[i];
            cpt++;
        }
    }
    *c = cpt;
}
//---------------------------------------------------------------------------------------
