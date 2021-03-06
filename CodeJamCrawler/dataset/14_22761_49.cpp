#include<algorithm>
#include<bitset>
#include<cassert>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define dprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", " << pair.Y << ")";}

void solve(int tc) {
    cout << "Case #" << tc << ": ";
    int n;
    cin >> n;
    LL p,q,r,s;
    cin >> p >> q >> r >> s;
    vector<LL> A(n);
    LL sum = 0;
    REP(i,n) {
        A[i] = (i*p+q)%r + s;
        sum += A[i];
    }
    LL bg = 0, nd = sum;
    while(bg < nd) {
        LL x = (bg+nd)/2;
        // can I do with best <= x
        LL me = 0;
        LL cnt = 0;
        REP(i,n) {
            if (me + A[i] > x) {
                ++cnt; me = 0;
            }
            me += A[i];
            if (me > x) cnt = 10;
        }
        if (cnt < 3) nd = x;
        else bg = x+1;
    }
    cout << (LD)(sum-bg)/sum << endl;

}


int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(16);
    int T;
    cin >> T;
    REP(i,T) solve(i+1);


    return 0;
}

