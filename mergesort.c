#include<stdio.h>
#include<conio.h>
void merge(int arr[],int low,int mid,int high)
{
    int temp[100];
    int i =low;
    int j = mid+1;
    int k = low;
    while(i<=mid && j<=high)
    {
        if(arr[i]<arr[j])
        {
          temp[k]=arr[i];
          i++;
        }
        else
        {
            temp[k]=arr[j];
            j++;
        }
        k++;
    }

    while(i<=mid)
    {
        temp[k]=arr[i];
        i++;
        k++;
    }

    while(j<=high)
    {
        temp[k]=arr[j];
        j++;
        k++;
    }
    for(i=low;i<=high;i++)
    {
        arr[i]=temp[i];
    }
}

void mergeSort(int arr[],int low,int high)
{
    if(low<high){
        int mid;
        mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
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
    int n,arr[100],i;
    printf("enter number of elements: ");
    scanf("%d",&n);
    printf("enter array elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    mergeSort(arr, 0, n - 1);

    printf("sorted array:\n");
    display(arr, n);

    return 0;
}



