using namespace std;
#include<iostream>
int dp[500];
int main()
{
    char c,nxt;
    char abc[]="welcome to code jam";
    string s;
    int cases,t=0,f=0,no=0,noc;
    cin>>cases;
    getline(cin,s);
    //for(int l=0;l<cases;l++)
    //{
    while(1)
    {
           t=0;
           getline(cin,s);
           //cout<<s;
           no++;
           int j=0,sum=1;
           for(int i=0;i<500;i++) dp[i]=0;
           for(int i=0;i<s.length();i++)
           {
                   if(s[i]=='w')
                   {dp[i]=sum;sum++;}
           }
           for(int i=1;i<strlen(abc);i++)
           {
               sum=0;noc=0;
               for(int j=0;j<s.length();j++)
               {
                       if(s[j]==abc[i-1])
                       sum=dp[j];
                       else if(s[j]==abc[i])
                       {dp[j]=sum+noc;noc=dp[j];}
               }
           }
           int m=0;
           for(int i=0;i<s.length();i++)
           {
                  // cout<<dp[i]<<" ";
                   if(s[i]=='m')
                   m=max(m,dp[i]);
           }
           cout<<"Case #"<<no<<": ";
           if(m<10) printf("000");
           else if(m<100) printf("00");
           else if(m<1000) printf("0");
           printf("%d\n",m);
           if(no==cases) break;
    }
//}       
 return 0;
}          
             
                 