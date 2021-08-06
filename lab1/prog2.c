#include <stdio.h>
void main(){
    int n,i,j,key;
    printf("enter size of array : ");
    scanf("%d",&n);
     int arr[n];
     printf("enter element in array : ");
     for (int i=0;i<n;i++){
         scanf("%d",&arr[i]);
}
printf("enter key :");
scanf("%d",&key);
printf("\n");
int f=0;
for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
        if(((arr[i]*arr[i])+(arr[j]*arr[j]))==key)
        {
            f=1;
            break;
        }
    }
    if(f==1)
    break;
}
printf("i: %d j : %d",i,j);
}