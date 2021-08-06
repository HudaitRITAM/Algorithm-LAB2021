#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int z = 0;
    int s = 0;
    int p = 1;
    int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
               if (matrix[i][j]) {
                  z++;
                }
            if (i == j){
                p *=matrix[i][j];
              }
            if (j > i){
              s += matrix[i][j];
            }
        }
    }

    printf("the number of non zero elements : %d\n",z);
    printf("the sum of elements above diagonal: %d\n", s);
     printf("the product of  diagonal elements: %d\n", p);
    printf("the minor diagonal elements: \n");
     for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < n; j++)
          {
           
            if (i + j >= n){
              printf("%d, ",matrix[i][j]);
                  
           }
        }
   }
return 0;
}