
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
#define ABS(a)   ((a)<0?-(a):(a))
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

int compare(double x, double y){
	if(ABS((x - y)) < pow(10, -9)) return 1;
	else return 0;
}
int main(){
	std::ios::sync_with_stdio(false);
	double x, y, x0, temp, res1, res2;
	// long long int k;
	cout.precision(12);
	cin >> x >> y;
	if(y == x){cout << x << endl; return 0;}
	if(y > x) {cout << -1; return 0;}
	else{
		temp = (x - y) / 2;
		cout.precision(10);
		int k = 1, flag = 0;
		while(temp > k * y){if(k > 1000000005) break; k++;}
		if(k < 1000000005) {
			if(!(temp <= y))k--;
			res1 = temp / k;
		}
		else res1 = -1;
		// cout << temp << " "<<res1 << endl;
		temp = (x + y) / 2;
		k = 1;
		while(temp > k * y){if(k > 1000000005) break; k++;}
		if(k < 1000000005) {
			if(!(temp <= y))k--;
			res2 = temp / k;
		}
		else res2 = -1;
		// cout << res2 << endl;
		if(res1 == -1 && res2 == -1){cout <<-1 << endl; return 0;}

		if(res1 > 0 && res2 > 0) cout << fixed <<min(res1, res2) << endl;  
		else if(res1 > 0)cout << fixed <<res1 << endl;  
		else cout << fixed <<res1 << endl;  
	} 
return 0;
}
