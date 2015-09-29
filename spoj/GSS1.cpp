
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
#include <limits.h>

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
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

void constructMinSegmentTree(int input[], int segTree[], int low, int high, int pos){

  if(low == high) {segTree[pos] = input[low]; return;}
  int mid = low + (high - low) / 2;
  constructMinSegmentTree(input, segTree, low, mid, 2*pos + 1);
  constructMinSegmentTree(input, segTree, mid + 1, high, 2*pos + 2);
  segTree[pos] = (segTree[2 * pos + 1] + segTree [2 * pos + 2]);
  return ;
}

void consructTree(int input[], int segTree[], int len_input){
    constructMinSegmentTree(input, segTree, 0, len_input - 1, 0);
}

int rangeMinimumQuery(int segTree[], int qlow, int qhigh, int low, int high, int pos){
    if(qlow <=low && qhigh >= high) return segTree [pos];
    else if( qlow  > high || qhigh < low ) return INT_MIN;
    else{
      int mid = low + (high - low) / 2;
      return MAX(rangeMinimumQuery(segTree, qlow, qhigh, low, mid, 2 * pos + 1) ,
                 rangeMinimumQuery(segTree, qlow, qhigh, mid + 1, high, 2 * pos + 2));
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
int input[50002], segTree[250000];
int main(){
	std::ios::sync_with_stdio(false);
	int n, x, y;
	si(n);
	RNG(i, n) si (input[i]);
	consructTree(input, segTree, n);
	int m; si(m);
	while(m--){
		si(x); si(y);
		printf("%d\n", rangeMinimumQuery(segTree, x - 1, y -1, 0, n-1, 0));
		// rangeMinimumQuery(segTree, x - 1, y -1, 0, n-1, 0);
	}
return 0;
}
