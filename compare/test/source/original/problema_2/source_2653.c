#include<stdio.h>
int red=0;
int blue=0;
int oa,ob;
int main()
{
        scanf("%d %d",&red,&blue);
        if(red>blue)
        {
                oa=blue;
                ob=red-blue;
                if(ob%2==1)ob--;
        }
        else
        {
                oa=red;
                ob=blue-red;
                if(ob%2==1)ob--;
        }
        printf("%d %d\n",oa,ob/2);
        return 0;
}