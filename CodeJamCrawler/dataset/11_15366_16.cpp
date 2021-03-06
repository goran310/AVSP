//Karol Farbiś - xneby
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <utility>
#include <functional>
#include <complex>

using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef complex<LL> PL;
typedef complex<double> P;
template<class T> T operator&(const complex<T>& a, const complex<T>& b){return real(a)*real(b)+imag(a)*imag(b);}
template<class T> T operator|(const complex<T>& a, const complex<T>& b){return real(a)*imag(b)-imag(a)*real(b);}
template<class T> bool operator||(const complex<T>& a, const complex<T>& b){return a|b==0;}
template<class T> bool operator&&(const complex<T>& a, const complex<T>& b){return a&b==0;}

const LD EPS = 1e-6;
const LL INF = 1000000000000000000LL;
const int SINF = 1000000000;

#define REP(I, N) for(int I=0; I<(N); ++I)
#define FOR(I, M, N) for(int I=(M); I<=(N); ++I)
#define FORD(I, M, N) for(int I=(M); I>=(N); --I)
#define EACH(it, x) for(typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(), (x).end()

#ifdef DEBUG

#define D(x) printf("%s: %d\n", #x, (x))
#define Ds(x) printf("%s: %s\n", #x, (x))
#define Dt(x,n) do { printf("%s:\n", #x); REP(_i, (n)) printf("%d ", (x)[_i]); printf("\n"); } while(0)
#define Dtz(x,s,k) do { printf("%s <%d, %d):\n", #x, (s), (k)); FOR(_i, (s), (k)) printf("%d ", (x)[_i]); printf("\n"); } while(0)
#define DUPA printf("dupa from line %d\n", __LINE__)
#define Dbg printf
#include <iostream>

#else

#define D(x)
#define Ds(x)
#define Dt(x,n)
#define Dtz(x,s,k)
#define DUPA
#define Dbg(...)

#endif

const int MAX_N = 10007;

int tab[MAX_N];

int skresl(int n){
	int i=0;
	while(tab[n+i]){
			tab[n+i]--;
			i++;
	}
	return i;
}

void solve(){
	int n;
	scanf("%d", &n);
	FOR(i,1,10000)tab[i]=0;
	FOR(i,1,n){
		int t;
		scanf("%d", &t);
		tab[t] ++;
	}

	if(n==0){
		puts("0");
		return;
	}
	if(n==1){
		puts("1");
		return;
	}

	int wy = 1001;

	FORD(i,10000,1){
		while(tab[i]>tab[i-1])wy=min(skresl(i),wy);
	}
	printf("%d\n", wy);
}

int main(int argc, char** argv, char** envp){
	int t;
	scanf("%d", &t);

	FOR(i,1,t){
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
