#include <stdio.h>
void main(){
    int n;
    printf("enter the size of array :");
    scanf("%d",&n);
     int arr[n];
     printf("enter element in array : ");
     for (int i=0;i<n;i++){
         scanf("%d",&arr[i]);
}
int i,j;
for(i=0;i<n;i++){
    int mul=1;
    for(j=0;j<n;j++){
        if(i!=j)
        mul*=arr[j];
    }
    printf(",%d",mul);
}
}