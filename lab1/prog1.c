#include<stdio.h>
void main() {
     int n;
     printf("enter size of array:");
     scanf("%d",&n);
     int arr[n];
     printf("enter element in array : ");
     for (int i=0;i<n;i++){
         scanf("%d",&arr[i]);
     }
         printf("\n");
         int mx=0,mx_num=-1;
         for(int i=0;i<n-1;i++){
             int c=0;
             for(int j=0;j<n;j++){
                 if(arr[i]==arr[j]){
                     c++;
                 }
                 if(c>mx){
                     mx=c;
                     mx_num=arr[i];
                 }
             }
         }
     printf("the num is %d with highest freq %d",mx_num,mx);
}