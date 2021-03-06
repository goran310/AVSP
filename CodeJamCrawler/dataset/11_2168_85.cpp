#include <algorithm>
#include <iostream>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)      (a).begin(),(a).end()
#define sz(a)       int((a).size())
#define FOR(i,a,b)  for(int i=a;i<b;++i)
#define REP(i,n)    FOR(i,0,n)
#define UN(v)       sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)     memset(a,b,sizeof a)
#define pb          push_back
#define X           first
#define Y           second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> point;

void Solve(){
	int n;
	cin >> n;
	vi a(n);
	for (int &x : a) cin >> x;
	vi b = a;
	sort(all(b));
	for (int &x : a) x = lower_bound(all(b), x) - b.begin();
	fill(all(b), 0);
	int res = 0;
	REP (i, n) 
		if (!b[i]) {
			int k = 0;
			for (int x = i; !b[x]; x = a[x]) {
				b[x] = 1;
				++k;
			}
			if (k > 1) res += k;
		}
	cout << res << endl;
}

int main(){
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	int a = 0, b;
	for(cin >> b; a++ < b ; Solve()) printf("Case #%d: ", a);
	return 0;
}
