#include<stdio.h>

void swap(int *x,int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
   }
  
  int main() {
      
	printf("enter three variables \n");
        int a,b,c;
    
        scanf("%d%d%d",&a,&b,&c);	
    
    
    swap(&a,&b);
    swap(&a,&c);
    printf("the three numbers after swapping are : %d %d %d\n",a,b,c);
    return 0;
}