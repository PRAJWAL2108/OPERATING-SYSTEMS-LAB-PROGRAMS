#include <stdio.h>
struct d
{
   char dname[10];
   char fname[10][10];
   int fcnt;
};
int main(void)
{
    int c, dcnt;
    struct d dir[10];
    printf("\n Enter the number of directories: ");
    scanf("%d",&dcnt);
    for(int i=0;i<dcnt;i++)
    {
           dir[i].fcnt=0;
            printf("\n Enter the name of directory: ");
            scanf("%s",dir[i].dname);
            do
            {
              printf("\n Enter the name of the file ");
            scanf("%s",dir[i].fname[dir[i].fcnt]);
            dir[i].fcnt++;
                  printf("\n Do you want to create another file: 1/0? ");
                  scanf("%d",&c);
            }while(c==1);
    }
    printf(" The directory and files are: \n");
    for(int i=0;i<dcnt;i++)
    {
      printf("\n%s",dir[i].dname);
      for(int j=0;j<dir[i].fcnt;j++)
      {
         printf(" \t %s ",dir[i].fname[j]);
      }
    }
    return 0;
}

