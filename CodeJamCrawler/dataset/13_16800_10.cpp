#include <cstdio>
using namespace std;
int x,y,a,b,T,i,j,ok;
char move1,move2,move1_reverse,move2_reverse;
int main()
{
    freopen("problemB.in","r",stdin);
    freopen("problemB.out","w",stdout);
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d %d",&x,&y);
        a=x;b=y;
        move1='E';
        move1_reverse='W';
        move2='N';
        move2_reverse='S';
        if(x<0)
        {
            a=0-a;
            move1='W';
            move1_reverse='E';
        }
        if(y<0)
        {
            b=0-b;
            move2='S';
            move2_reverse='N';
        }
        ok=1;
        printf("Case #%d: ",i);
        for(j=1;ok && a!=0 && b!=0;j++)
        {
            if(a>=b)
            {
                if(a-j>=0)
                {
                    a-=j;
                    printf("%c",move1);
                }
                else
                ok=0;
            }
            else
            {
                if(b-j>=0)
                {
                    b-=j;
                    printf("%c",move2);
                }
                else
                ok=0;
            }
        }
        if(a!=0)
        {
            while(a>=4)
            {
                a+=j;j++;
                a+=j;j++;
                printf("%c%c",move1_reverse,move1_reverse);
                a-=j;j++;
                a-=j;j++;
                printf("%c%c",move1,move1);
            }
            while(a>0)
            {
                a+=j;j++;
                printf("%c",move1_reverse);
                a-=j;j++;
                printf("%c",move1);
            }
        }
        if(b!=0)
        {
            while(b>=4)
            {
                b+=j;j++;
                b+=j;j++;
                printf("%c%c",move2_reverse,move2_reverse);
                b-=j;j++;
                b-=j;j++;
                printf("%c%c",move2,move2);
            }
            while(b>0)
            {
                b+=j;j++;
                printf("%c",move2_reverse);
                b-=j;j++;
                printf("%c",move2);
            }
        }
        printf("\n");
    }
}