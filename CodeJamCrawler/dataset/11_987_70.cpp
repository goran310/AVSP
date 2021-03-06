#include <cstdio>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define REP(i,a) FOR(i,0,a-1)
#define FORD(i,a,b) for(int i=a,_b=b;i>=_b;i--)
#define REPD(i,a) FORD(i,a-1,0)
#define _m(a,b) memset(a,b,sizeof(a))

#define MAX 1010

int main (void) {
	int T; scanf("%d", &T);
	int N;
	int V[MAX];
	int R;
	int A, SA, B, SB;
	
	FOR(iT, 1, T) {
		scanf("%d", &N);
		REP(i, N) scanf("%d", &V[i]);
		
		R = -1;
		
		REP(n, (1<<N)) {
			A = SA = B = SB = 0;
			
			REP(i, N) {
				if(((1<<i) & n)) {
					A += V[i];
					SA ^= V[i];
				} else {
					B += V[i];
					SB ^= V[i];
				}
			}
			
			if(SA == SB && A && B) {
				R = max(R, A);
			}
		}
		
		printf("Case #%d: ", iT);
		if(R == -1) puts("NO");
		else printf("%d\n", R);
		
	}
	
	return 0;
}
