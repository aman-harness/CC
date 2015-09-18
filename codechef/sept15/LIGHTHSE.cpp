#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <queue>
#include <deque>
#include <set>
#include <list>
#include <map>
#include <functional>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <numeric>
#include <stack>
#include <utility>
using namespace std;

#define s(n)    scanf("%d",&n)
#define sl(n)   scanf("%lld",&n)
#define p(n)    printf("%d ",n)
#define pl(n)   printf("%lld",n)
#define sf(n)   scanf("%f",&n)
#define sd(n)   scanf("%lf",&n)
#define ss(n)   scanf("%s",n)
#define pf(n)   printf("%f ",n)
#define pd(n)   printf("%lf ",n)
#define ps(n)   printf("%s ",n)
#define nl      putchar('\n')
#define e1      first
#define e2      second

#define INF     (int)1e9
#define MOD     (int)(1e9+7)
#define LINF    (ll)1e18
#define EPS     1e-11
const double PI = acos(-1.0)

#define pow2(n) (1<<(n))
#define pow2l(n) ((ll)1<<(n))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(n)   ((a)<0?-(a):(a))
#define MAXE(...)   max_element(__VA_ARGS__)
#define MINE(...)   min_element(__VA_ARGS__)

#define FOR(i,a,b)  for(int i=a;i<b;i++)
#define RNG(i,n)    FOR(i,0,n)
#define REV(i,a,b)  for(int i=a;i>=b;--i)
#define FORECH(v,c) for(typeof((c).begin()) v=(c).begin(); v!=(c).end(); ++v)
#define ALL(a)      (a).begin(),(a).end()
#define LEN(a)      ((int)(a.size()))
#define PB(x)       push_back(x)
#define TIMES(x)    while((x)--)
#define UPB         upper_bound
#define LWB         lower_bound
#define MP          make_pair

#ifndef ONLINE_JUDGE
#define DEBUG__
#endif
#ifdef DEBUG__
    #define derr(x)     cerr<<"<"<<#x<<": "<<x<<">"<<endl
    #define _DEBUG(...) __VA_ARGS__
    ;template<typename T> void debug(T a, T b){ for(;a!=b;++a) cerr<<*a<<" "; cerr<<endl; }
#else
    #define derr(...)
    #define _DEBUG(...)
    ;template<typename T> void debug(T a, T b){}
#endif

typedef long long       ll;
typedef pair<int, int>  pii;
typedef pair<ll, ll>    pll; 
typedef vector<int> vi;
typedef vector<ll>  vl;
typedef vector<vi>  vvi;
typedef vector<vl>  vvl;
typedef list<int>   li;
typedef map<int,int> mii;

template<typename T> T modPow(T b, T e, T m=(ll)MOD){T res=1;while(e){if(!(e&0x1))res=(res*b)%m;e>>=1;b=(b*b)%m;}return res; }
template<typename T> T gcd (T u, T v){ return (u==0||v==0||u==v)?(u|v):((~u&1)?((v&1)?gcd(u>>1,v):gcd(u>>1,v>>1)<<1):((~v&1)?gcd(u,v>>1):((u>v)?gcd((u-v)>>1,v):gcd((v-u)>>1,u)))); }
template<typename T> T lcm (T a, T b){ return a*b/gcd(a,b); }
//#undef DEBUG__
///////////////////////////////          FAST  IO          ///////////////////////////////////////
#define gc getchar_unlocked
void si(int &n){
    register int ch=gc();
    int neg = 0;
    n=0;
    while((ch<48||ch>57) && ch!='-')ch=gc();
    if(ch=='-'){ neg=1; ch=gc(); }
    for(;ch>47 && ch<58; ch=gc()) n = (n<<1)+(n<<3)+ch-48;
    if(neg)n=-n;
}

int main(){
	std::ios::sync_with_stdio(false);
	int t;cin >> t;
	int x[500000], y[500000];
	int x_l, x_r, y_t, y_b;
	int flag = 0;
	while(t--){
		flag = 0;
		int n; cin >> n;
		cin >> x[0] >> y[0];
		x_l = 0; x_r = 0;
		y_t = 0; y_b = 0;
		FOR(i, 1, n){
			cin >> x[i] >> y[i];
			if(x[i] < x[x_l]) x_l = i;
			else if(x[i] > x[x_r]) x_r = i;
			if(y[i] < y[y_b]) y_b = i;
			else if(y[i] > y[y_t]) y_t = i;
		}
		FOR(i, 0, n){
			 if(x[x_l] == x[i] && y[y_t] == y[i]) {cout << 1 << endl << i + 1 << " "<< "SE"<< endl;flag = 1;break;}
			 else if(x[x_l] == x[i] && y[y_b] == y[i]) {cout << 1 << endl << i + 1 << " "<< "NE"<< endl;flag = 1;break;}
			 else if(x[x_r] == x[i] && y[y_b] == y[i]) {cout << 1 << endl << i + 1 << " "<< "NW"<< endl;flag = 1;break;}
			 else if(x[x_r] == x[i] && y[y_t] == y[i]) {cout << 1 << endl << i + 1 << " "<< "SW"<< endl;flag = 1;break;}
		}
		//      if(x_l == y_t){cout << 1 << endl << x_l + 1 << " "<< "SE"<< endl;}
		// else if(x_l == y_b){cout << 1 << endl << x_l + 1 << " "<< "NE"<< endl;}
		// else if(x_r == y_b){cout << 1 << endl << x_r + 1 << " "<< "NW"<< endl;}
		// else if(x_r == y_t){cout << 1 << endl << x_r + 1 << " "<< "SW"<< endl;}
		if(!flag){
			cout << 2 << endl;
			if(0);
			else if(y[x_l] <= y[x_r]){
				cout << x_l + 1 << " " << "NE" <<endl;
				cout << x_r + 1 << " " << "SW" <<endl;
			}
			else{
				cout << x_l + 1 << " " << "SE" <<endl;
				cout << x_r + 1 << " " << "NW" <<endl;
			}
		}
	}
return 0;
}
// (NWNorth-Western, NENorth-Eastern, SWSouth-Western, SESouth-Eastern) 