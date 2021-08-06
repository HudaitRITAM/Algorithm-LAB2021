#include <stdio.h>
void main(){
    int n;
    printf("enter size of array :");
    scanf("%d",&n);
     int arr[n];
     printf("enter element in array : ");
     for (int i=0;i<n;i++){
         scanf("%d",&arr[i]);
}
int i;
for(i=0;i<n-1;i++){
    if(arr[i+1]<arr[i])
    break;
}
 printf("the value of k is %d",i);
}