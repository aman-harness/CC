
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
#include <iterator>
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
	int k; si(k); int cal[k + 1], candy[k + 1];
	RNG(i, k) cin >> candy[i] >> cal[i];
	ll sum = 0;
	FOR(i, 0, k) sum += candy[i] * cal[i];
	ll t = sum;
	sum /= 2; sum++;
	int dp[k + 1][sum + 2];
	int update[sum + 2], temp[sum + 2];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	FOR(i, 1, candy[0] + 1) dp[0][cal[0] * i] = 1; 
	FOR(i, 1, k){
		memset(update, 0, sizeof(update));
		memset(temp, 0, sizeof(temp));
		FOR(j, 0, sum){
			if(dp[i - 1][j]){
				update[j] += 1; //cout <<"Updated " << j << " as 1";
				if(candy[i] * cal[i] + j < sum) {update[(candy[i] + 1) * cal[i] + j] -= 1;}
			}
		}
		FOR(j, 0, sum) if(update[j])cout << i << " " << j << ","; cout << endl;
		for(int j = 0; j < sum;) {if(j + cal[i]  > sum) break; if(update[j]) {temp[j] = update[j]; temp[j + cal[i]] += update[j];} j++;}
		cout << endl << endl;
		if(i == 3) RNG(j, sum) cout << update[j] << " ";
		FOR(j, 0, sum) dp[i][j] += temp[j];
		FOR(j, 0, sum) if(update[j])cout << i << " " << j << ","; cout << endl;
		FOR(j, 0, sum) if(dp[i][j])cout << i << " " << j << ","; cout << endl;
	}
	int ret = 0;
	FOR(i, 0, sum) if(dp[k - 1][i]) ret = i;
	// FOR(i, 0, k){
	// 	FOR(j, 0, sum) if(dp[i][j]) cout << i << "  - " << j << endl; cout <<endl;
	// }
	cout << t << " " <<ret;
return 0;
}
