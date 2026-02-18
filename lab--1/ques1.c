//time complexity
#include<stdio.h>
#include<time.h>
int main()
{ int n;
    printf("enter n:");
    scanf("%d",&n);
    clock_t start = clock();
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=i;j++)
    {
        for(int k=1;k<=100;k++)
        {
            printf("UPES");
        }
    }
}
clock_t end = clock();
 double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nExecution time = %f seconds\n", time_taken);

    return 0;
}