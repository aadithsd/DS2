#include<stdio.h>
#include<conio.h>

void swap(int arr[],int i,int j)
{
    int temp;
    temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int partition(int arr[], int low, int high)
{
    int pivot,i,j;
    pivot=high;
    i=low;
    j=high-1;
    do
    {
        while(arr[i]<=arr[pivot] && i<=high){
                ++i;
                }
        while(arr[j]>arr[pivot] && j>low){
            --j;    
        }
        if(i<j){
            swap(arr,i,j);
        }
    }while(i<j);
    swap(arr,i,pivot);
    return i;
}

void quickSort(int arr[],int low, int high)
{
    if(low<high){
        int pivot=partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int n,i,j,arr[100];
    printf("enter number of elements: ");
    scanf("%d",&n);
    printf("enter array elements: ");
    for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
    }
    quickSort(arr,0,n-1);
    printf("sorted array: ");
    display(arr,n);
}
