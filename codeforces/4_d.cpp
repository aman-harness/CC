
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

int lcs(vector<pair <pii, int > > &v, int x, int y){
	if(!v.size()) {cout << 0 << endl; return 0;}
	int dp[v.size() + 15];
	memset(dp, 0, sizeof(int) * v.size() + 5);
	int past[v.size() + 15];
	memset(past, -1, sizeof(int) * v.size() + 5);
	if(x < v[0].first.first && y < v[0].first.second) dp[0] = 1; else dp[0] = 0;
	FOR(i, 1, v.size()){
		if(x < v[i].first.first && y < v[i].first.second){
			dp[i] = 1;
			RNG(j, i) if(v[i].first.second > v[j].first.second && v[i].first.first > v[j].first.first && dp[j] + 1 > dp[i]) {dp[i] = dp[j] + 1;past[i]= j;}
		} 
		else dp[i] = 0;
	}
	int max = 0;
	RNG(i, v.size()) if(dp[i] > dp[max]) max = i;
	stack <int> stk;
	cout << dp[max] << endl;
	while(max != -1){
		stk.push(max);
		max= past[max];
	}
	while(!stk.empty()) {cout << v[stk.top()].second  + 1<< " "; stk.pop();}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::vector<pair <pii, int> > v;
	int n, w, h, x, y; cin >> n >> w >> h;
	RNG(i, n){
		cin >> x >> y;
		if(x <= w || y <= h) continue;
		v.PB(MP(MP(x, y), i));
	}
	sort(v.begin(), v.end(), less<pair<pii, int> >());
	// cout << v[0].first << endl;
	lcs(v, w, h);
return 0;
}
