#ifndef HEADER
#define HEADER
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <map>
#include <numeric>
#include <string>
#include <sstream>
#include <set>
#include <vector>
using namespace std;

#ifdef _MSC_VER
#include <hash_map>
#include <hash_set>
using namespace stdext;
#else
#include <ext/hash_map>
#include <ext/hash_set>
using namespace __gnu_cxx;
#endif

#define FIN(file) freopen(file, "r", stdin)

#define CLR(x) memset(x,0,sizeof(x))
#define SET(x,v) memset(x,v,sizeof(x))

#define PREC(n) cout.setf(ios::fixed);cout.precision(n);

#define VAR(a,b) __typeof(b) a=(b)
#define EH(i,m) for (VAR(i,(m).begin());i!=(m).end();++(i))
#define EHD(i,m) for (VAR(i,(m).rbegin());i!=(m).rend();++(i))
#define IN(x,s) ((s).find(x)!=(s).end())
#define ALL(x) (x).begin(),(x).end()
#define REP(i,s,n) for(int i=(s),_i=(n);i<_i;++i)
#define REPD(i,s,n) for(int i=(s),__i=(n);i>=__i;--i)

#define INF 0x7FFFFFFF
#define EPS 1e-3
#define GT(a,b) ((a)>(b)+EPS)
#define GTE(a,b) ((a)>(b)-EPS)
#define EQ(a,b) ((a)>(b)-EPS && (a)<(b)+EPS)
#define LS(a,b) ((a)<(b)-EPS)
#define LSE(a,b) ((a)<(b)+EPS)
#define SQR(x) ((x)*(x))
#define NORM(x,y) (sqrt(SQR(x)+SQR(y)))

#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define FMAX(x,y) (GT(x,y)?(x):(y))
#define FMIN(x,y) (LS(x,y)?(x):(y))
#define ABS(x) ((x)<0?(-(x)):(x))
#define FABS(x) (LS(x,0.0)?(-(x)):(x))

inline bool _alpha(char c){return isalpha(c)!=0;}
inline bool _digit(char c){return isdigit(c)!=0;}
inline bool _space(char c){return c<=' ';}
inline bool _notsp(char c){return c>' ';}
inline bool _upper(char c){return isupper(c)!=0;}
inline bool _lower(char c){return islower(c)!=0;}
inline bool _alnum(char c){return isalnum(c)!=0;}
inline bool _notan(char c){return isalnum(c)==0;}

template<class X, class Y>
X to(Y value){
    stringstream ss(value);
    X res;
    ss>>res;
    return res;
}

istream& in=cin;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
#define V(x) vector<x >
#define VI V(int)
#define VL V(ll)

const double PI=acos(-1.0);
const double E=exp(1.0);
#endif

#ifndef READER
#define READER
#define I_SIZE 819200

char I_buff[I_SIZE];
size_t I_pos,I_len,I_in;
bool I_all;
void I_read(){
    if(I_len>I_pos)memcpy(I_buff,I_buff+I_pos,I_len-I_pos);
    I_len-=I_pos;I_pos=0;
    I_in = fread(I_buff+I_len,1,I_SIZE-I_len,stdin);
    if (I_in != I_SIZE-I_len){I_all=true;}
    I_len+=I_in;I_buff[I_len]=0;
}
inline char I_next(){return I_buff[I_pos++];}
char I_chk_next(){if (!I_all && I_pos+20>I_len)I_read();return I_next();}

void I_init(){I_all=false;I_len=0;I_pos=0;I_read();}
int I_sign(){
    int sign=1;char ch;
    while(((ch=I_chk_next())<'0'||ch>'9')&&ch!='-');
    if (ch=='-')sign=-1;else --I_pos;
    return sign;
}
template <class T> 
size_t I_t(char* p,T f){
    size_t i=1;while(!f(p[0]=I_chk_next()));while(f(p[i]=I_chk_next())){++i;}p[i]=0;--I_pos;return i;
}
char I_c(){char ch;while(_space(ch=I_chk_next()));return ch;}
size_t I_s(char *p){return I_t(p,_notsp);}
size_t I_l(char *p){size_t i=0;while((p[i]=I_chk_next())!='\n')++i;if (p[i-1]=='\r')--i;p[i]=0;return i;}
template <class T>
T I(){
    T res=0;char ch;
    while((ch=I_chk_next())<'0' || ch>'9');res=ch-'0';
    while((ch=I_next())>='0' && ch<='9'){res*=10;res+=ch-'0';}
    --I_pos;return res;
}
template <> double I<double>(){
    double res=0.0,p=1;char ch;
    while((ch=I_chk_next())<'0' || ch>'9');res=ch-'0';
    while((ch=I_next())>='0' && ch<='9'){res*=10;res+=ch-'0';}
    if(ch=='.')while((ch=I_next())>='0' && ch<='9'){p*=10;res+=(ch-'0')/p;};
    --I_pos;return res;
}
template <class T> inline T Is(){int s=I_sign();T v=I<T>();return s*v;}
inline bool I_e(){return I_all && I_pos>=I_len;}
#define II (I<int>())
#define IL (I<ll>())
#define IS(x) (I_s(x))
#define IC (I_c())
#define ID (I<double>())
#define IIS (Is<int>())
#define ILs (Is<ll>())
#define IDS (Is<double>())
#endif

void Run();

int main(){
#ifndef ONLINE_JUDGE
    FIN("in.txt");
#endif
    I_init();
    Run();
    return 0;
}

bool g[2][210][210];

void Run(){
    int cn = II;
    REP(cni, 1, cn+1){
        int r = II;
        CLR(g);
        deque<pair<int, int> > v;
        int row = 0;
        int col = 0;
        int p = 0;
        int q = 1;
        REP(i,0,r){
            int x1 = II;
            int y1 = II;
            int x2 = II;
            int y2 = II;
            if (x2 > row)row=x2;
            if (y2 > col)col=y2;
            REP(j,x1,x2+1){
                REP(k,y1,y2+1){
                    g[p][j][k]=true;
                }
            }
        }
        REP(i,1,row+1){
            REP(j,1,col+1){
                if (g[p][i][j]){
                    v.push_back(make_pair(i, j));
                }
            }
        }
        
        ++row;
        ++col;
        
        int res = 0;
        while(true){
            if (v.empty()){
                break;
            }
            REP(i,0,row+1){
                REP(j,0,col+1){
                    g[q][i][j]=false;
                }
            }
            int len = v.size();
            REP(i,0,len){
                pair<int, int> x = v.front();
                v.pop_front();
                if (g[p][x.first - 1][x.second] || g[p][x.first][x.second-1]){
                    g[q][x.first][x.second]=true;
                }
                
                if (g[p][x.first+1][x.second-1]){
                    g[q][x.first+1][x.second] = true;
                    //if (x.first + 1 > row){
                    //    row = x.first + 1;
                    //}
                }
                
                if (g[p][x.first-1][x.second+1]){
                    g[q][x.first][x.second+1] = true;
                    //if (x.second + 1 > col){
                    //    col = x.second + 1;
                    //}
                }
            }
            
            REP(i,1, row+1){
                REP(j,1,col+1){
                    if (g[q][i][j]){
                        v.push_back(make_pair(i,j));
                    }
                }
            }
            ++res;
            p = 1-p;
            q = 1-q;
        }
        
        printf("Case #%d: %d\n", cni, res);
    }
}