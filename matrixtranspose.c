#include<stdio.h>
#include<stdlib.h>
void transpose(int a[10][10],int b[10][10],int r,int c);
int main()
{
    int a[10][10]; int b[10][10];
    int r,c;
    printf("Enter row and column\n");
    scanf("%d%d",&r,&c);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("MATRIX\n");
     for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    transpose(a,b,r,c);
    
}
void transpose(int a[10][10],int b[10][10],int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
           b[j][i] = a[i][j];   
        }
    }   
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
            printf("%d ",b[i][j]);
        }
           printf("\n");
    }
}