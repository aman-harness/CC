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
#define nl      printf("\n")
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
// int graph[5005][5005];
list <int> mylist[5002];
map < pii , int> m;
pii tempp;
void check( int v){
	vi ret;
	int x, temp;
	FOR(i, 1, v + 1){
		int flag =1;
		while(mylist[i].begin() != mylist[i].end()){
			cout << "Top , i : " << mylist[i].front() << " " << i  << " flag " << flag<< endl;
			temp = mylist[i].front();
			mylist[i].pop_front();
			if(!m[make_pair(temp, i)]){
			// if(!graph[temp][i]){
				flag = 0;
				break;
			}
			cout << "FORront , i : " << temp << " " << i  << " flag " << flag<< endl;
		}
		if(flag) ret.PB(i);
	}
	sort(ret.begin(), ret.end());
	// cout << "size -- " << ret.size() << endl;
	FOR(i, 0, ret.size()) cout << ret[i] << " ";
	cout << endl;
	m.clear();
}

int main(){
	std::ios::sync_with_stdio(false);
	int i, j, n, k, e, v, from , to;
	while(1){
		// cout << " give  v n  \n";
		cin >> v; if(!v) break;
		cin >> n;
		FOR(i, 1, v ) {m[make_pair(i, i)] = 1;mylist[i].push_back(i);}
		// graph[v][v] = 1;
		RNG(i,n){

			// cout << " give edges: ";
			cin >> from >> to;
			// graph[from][to] = 1;
			// m[from, to] = 1;
			m[make_pair(from, to)] = 1;
			mylist[from].push_back(to);
		}
	check(v);
	FOR(i, 1, v + 1) mylist[i].clear();
	// FOR(i, 1, v + 1) FOR(j, i, v + 1) graph[i][j] = 0;
	}
return 0;
}