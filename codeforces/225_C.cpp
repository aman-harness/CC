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
#include <limits.h>
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

int main(){
	std::ios::sync_with_stdio(false);
	int m, n, x, y;
	cin >> n >> m >> x >> y;
	char input[n][m];
	int w[m], b[m];
	RNG(i, n) RNG(j, m) cin >> input[i][j];
	RNG(i, m) {
		int sum = 0;
		RNG(j, n){
			if(input[j][i] == '#') sum += 1;
		} 
		b[i] = sum; w[i] = n - sum;
	}
	FOR(i, 1, m) {w[i] += w[i - 1]; b[i] += b[i-1];}
	int dp[m][2];
	// 0 Stands for ending row as black;
	// 1 stands for ending row as white.
	// -1 value reprewsnts that calculation for that value is not possible.

	FOR(i, 0, m) dp[i][0] = dp[i][1] = -1;
	FOR(i, x - 1, m){
		// For black as ending
		// Search from all the whites.
		int minn = INT_MAX, cost;
		// if(i == 0){}
		if(i == x - 1){
			dp[i][0] = b[i];
			dp[i][1] = w[i];
			continue;
		}

		int start = max(0,  i - y + 1);
		// start and end are both the possible first charecters.

		// Loop for black ending
		FOR(j, start, i - x + 2){
			if(!j){
				minn = min(minn, b[i]);
			}
			else{
				if(dp[j - 1][1] != -1){
					minn = min(minn, dp[j - 1][1] + b[i] - b[j - 1]);
				}
			}
		}
		if(minn < INT_MAX) dp[i][0] = minn;

		minn = INT_MAX;

		// loop for white ending
		FOR(j, start, i - x + 2){
			if(!j){
				minn = min(minn, w[i]);
			}
			else{
				if(dp[j - 1][0] != -1){
					minn = min(minn, dp[j - 1][0] + w[i] - w[j - 1]);
				}
			}
		}
		if(minn < INT_MAX) dp[i][1] = minn;
	}
	cout << min(dp[m - 1][0], dp[m - 1][1]) << endl;
return 0;
}
