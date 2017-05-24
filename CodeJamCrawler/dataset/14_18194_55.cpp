/*
 * D.cpp
 *
 *  Created on: 2014-4-12
 *      Author: bjfudq
 */
#include <functional>
#include <algorithm>
#include <iostream>
//#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;
//#pragma comment(linker,"/STACK:102400000,102400000")

#define MEM(a) (memset((a),0,sizeof(a)))
#define LEN(a) (int)strlen((a))
#define fr(a) for(int i=0;i<(a);i++)
#define sf(a) scanf("%d",&(a))
#define sf64(a) scanf("%I64d",&(a))
#define sff(a) scanf("%lf",&(a))
#define sfs(a) scanf("%s",(a))
#define sf2(a,b) scanf("%d%d",&(a),&(b))
#define sf2s(a,b) scanf("%s%s",(a),(b));
#define sf2f(a,b) scanf("%lf%lf",&(a),&(b))
#define sf264(a,b) scanf("%I64d%I64d",&(a),&(b))
#define pf(a) printf("%d\n",(a))
#define pfc(a) printf("%c",(a));
#define pf64(a) printf("%I64d\n",(a))
#define pff(a) printf("%lf\n",(a))
#define pfs(a) printf("%s\n",(a))
#define pf2(a,b) printf("%d %d\n",(a),(b))
#define pf2s(a,b) printf("%s%s\n",(a),(b));
#define pf2f(a,b) printf("%lf %lf\n",(a),(b))
#define pf264(a,b) printf("%I64d %I64d\n",(a),(b))
#define pfn printf("\n")
#define LL unsigned long long

const int N=1010;
const int M=1000010;
const int MOD=1000000007;
const int INF=0x7fffffff;
const int dir4[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
const int dir8[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,1},{1,-1},{-1,-1},{1,1}};
const double eps=1e-16;
const double PI=acos(-1.0);

inline int sign(double x){return (x>eps)-(x<-eps);}
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
/*************************/

double a[N],b[N];
int n;

bool cmp(double a,double b)
{
	return a > b;
}

void deal1()
{
	int a_h=0,b_h=0,a_e=n-1,b_e=n-1;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(a[a_h] > b[b_h] )
		{
			ans++;
			a_h++;
			b_h++;
		}
		else if(a[a_h] < b[b_h])
		{
			a_e--;
			b_h++;
		}
		else
		{
			if(a[a_e] > b[b_e])
			{
				ans++;
				a_e--;
				b_e--;
			}
			else if(a[a_e] < b[b_e])
			{
				a_e--;
				b_h++;
			}
			else
			{
				if(a[a_h] == a[a_e])
				{
					a_h++;
					b_h++;
				}
				else
				{
					a_e--;
					b_h++;
				}
			}
		}
	}
	printf("%d ",ans);
}

void deal2()
{
	int a_h=0,b_h=0,b_e=n-1;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(b[b_h] > a[a_h])
		{
			b_h++;
			a_h++;
		}
		else if(b[b_h] < a[a_h])
		{
			b_e--;
			a_h++;
			ans++;
		}
		else
		{
			a_h++;
			b_e--;
		}
	}
	pf(ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("testin.txt", "r", stdin);
    freopen("testout.txt", "w", stdout);
#endif
    int T,cas=1;
    sf(T);
    while(T--)
    {
    	printf("Case #%d: ",cas++);
    	sf(n);
    	fr(n) sff(a[i]);
    	fr(n) sff(b[i]);
    	sort(a,a+n,cmp);
    	sort(b,b+n,cmp);
    	deal1();
    	deal2();
    }
    return 0;
}
