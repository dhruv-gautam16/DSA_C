#include <stdio.h>
void merge(int arr[], int a, int b, int r) 
{
  int n1 = b - a + 1;
  int n2 = r - b;
  int L[n1], M[n2];
  for (int i = 0; i < n1; i++)
  { 
     L[i] = arr[a + i];
  }
  for (int j = 0; j < n2; j++)
  {
    M[j] = arr[b + 1 + j];
  }
  int i, j, k;
  i = 0;
  j = 0;
  k = a;
  while (i < n1 && j < n2) 
  {
    if (L[i] <= M[j]) 
    {
      arr[k] = L[i];
      i++;
    } 
    else 
    {
      arr[k] = M[j];
      j++;
    }
    k++;
  }
  while (i < n1) 
  {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) 
  {
    arr[k] = M[j];
    j++;
    k++;
  }
}
void merge_sort(int arr[], int l, int r) 
{
  if (l < r) 
  {
    int m = l + (r - l) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}
void display_array(int arr[], int size) 
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void swap(int *a, int *b) 
{
  int t = *a;
  *a = *b;
  *b = t;
}
int partition(int array[], int low, int high) 
{
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) 
  {
    if (array[j] <= pivot) 
    {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}
void quick_sort(int array[], int low, int high) 
{
  if (low < high) 
  {
    int pi = partition(array, low, high);
    quick_sort(array, low, pi - 1);
    quick_sort(array, pi + 1, high);
  }
}
void display_array_quick(int array[], int size) 
{
  for (int i = 0; i < size; ++i) 
  {
    printf("%d  ", array[i]);
  }
}

void main(){
    int r =1;
    int opt,i,n;
    printf("Enter the size of your arrray\n");
    scanf("%d",&n);
    int arr[n];
    for ( i = 0; i < n; i++)
    {
        printf("Enter your element\n");
        scanf("%d",&arr[i]);
    }
    
    do
    {
        printf("MENU\n");
        printf("1. FOR IMPLEMENTING QUICK SORT\n");
        printf("2. FOR IMPLEMENTING MERGE SORT\n");
        printf("3. FOR EXITING THIS MENU\n");
        scanf("%d",&opt);
        if (opt==1)
        {
            quick_sort(arr,0,n-1);
            printf("The sorted array looks like\n");
            display_array(arr,n);
        }
        else if (opt==2)
        {
            merge_sort(arr,0,n-1);
            printf("The sorted array is\n");
            display_array_quick(arr,n);
        }
        else{
            r=0;
        }
        
        
    } while (r>0);
    
}