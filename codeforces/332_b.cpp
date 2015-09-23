
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
#define p(n)    prlong long intf("%d ",n)
#define pl(n)   prlong long intf("%lld",n)
#define sf(n)   scanf("%f",&n)
#define sd(n)   scanf("%lf",&n)
#define ss(n)   scanf("%s",n)
#define pf(n)   prlong long intf("%f ",n)
#define pd(n)   prlong long intf("%lf ",n)
#define ps(n)   prlong long intf("%s ",n)
#define nl      putchar('\n')
#define e1      first
#define e2      second

#define INF     (long long int)1e9
#define MOD     (long long int)(1e9+7)
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

#define FOR(i,a,b)  for(long long int i=a;i<b;i++)
#define RNG(i,n)    FOR(i,0,n)
#define REV(i,a,b)  for(long long int i=a;i>=b;--i)
#define FORECH(v,c) for(typeof((c).begin()) v=(c).begin(); v!=(c).end(); ++v)
#define ALL(a)      (a).begin(),(a).end()
#define LEN(a)      ((long long int)(a.size()))
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

long long int calc(long long int n, long long int k, long long int *A){
	long long int start[n + 2], end[n + 2], sum[n + 2], pos_s[n + 2], pos_e[n + 2];
	memset(start, 0, (n + 1) * sizeof(long long int));memset(end, 0, (n + 1)* sizeof(long long int));
	sum[0] = A[0];
	FOR(i, 1, n) sum[i] = sum[i -1] + A[i];
	RNG(i, n){
		if(!i) start[i] = sum[k - 1];
		else if(i + 2 * k  <= n || i + k <= n){
			start[i] = sum[i + k - 1] - sum[i - 1];
		}
		if(i == k-1) end[i] = sum[k - 1];
		if(i + 1 - 2 * k >= 0 || i >= k) end[i] = sum[i] - sum[i - k];
	}

	// RNG(i, n) cout << start[i] << " "; cout << endl;
	// RNG(i, n) cout << end[i] << " "; cout << endl;
	RNG(i, n + 1)
	long long int max = 0;
	RNG(i, n) {pos_s[i] = pos_e[i] = i;}
	for(long long int i = n - k; i >= 1; i-- ) if(start[i - 1] < start[i]) {start[i - 1] = start[i ]; pos_s[i - 1] = pos_s[i];}
	for(long long int i = k; i < n; i++) if(end[i] <= end[i-1]) {end[i]= end[i-1]; pos_e[i] = pos_e[i-1];}
	long long int max = 0, s = k, e = k-1;
	// RNG(i, n) cout << start[i] << " "; cout << endl;
	// RNG(i, n) cout << "Pos: "<< pos_s[i] << " "; cout << endl;
	// RNG(i, n) cout << end[i] << " "; cout << endl;
	// RNG(i, n) cout << pos_e[i] << " "; cout << endl;
	FOR(i, k-1,n){
		if(i + k - 1 >= n) break;
		if(end[i] + start[i + 1] > max) {max = end[i] + start[i + 1];s = pos_s[i + 1], e = pos_e[i];}
	}
	cout  << e - k + 2 << " " << s + 1 ;
	// FOR(i, k , n - k + 1) if(end[i - 1] + start[i] > max) {max = end[i - 1] + start[i]; s = i; end = i - 1;}
}

int main(){
	std::ios::sync_with_stdio(false);
	long long int n, k, temp; cin >> n >> k; temp = n;
	long long int A[n + 2]; RNG(i, n) cin >> A[i];
	calc(n, k, A);
return 0;
}
