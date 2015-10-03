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
vvi G;
#define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
map<pii, int> m;

int do_map(queue<int> &A, queue<int> &B){
	int flag = 0;
	while(!A.empty()){
		int x = A.front();
		A.pop();
		queue <int> temp = B;
		while(!B.empty()){
			int y = B.front();
			B.pop();
			if(m[MP(x, y)] == 0){
				flag = 1;
				m[MP(x, y)] = 1;
			}
		}
		B = temp;
	}
	queue <int> empty;
	A = empty;
	B = empty;
	if(flag) {
		// cout << "I marked some\n";
		return 1;}
	else {
		// cout << "I did some\n";
		return 0;}
}

int bfs(int n, int start_vertex, int run_vertex){
	queue<int> Q, P, A, B, last;
	Q.push(start_vertex);
	A.push(run_vertex);
	last = A;
	if(start_vertex == run_vertex) return 1;
	set<int> temp;
	int count  = 0;
	while(1){
		count++;
		while(!Q.empty()){
			// int z;cin >> z;
			int i = Q.front();
			// cout << "in 1st: " << i << endl;
			Q.pop();
			tr(G[i], it){
				// cout << "Inserting: " << *it << " ";
				temp.insert(*it);
			}
			temp.insert(i);
		}
		tr(temp, iit){
				P.push(*iit);
			}
			temp.clear();

		// cout << "Between\n";
		while(!A.empty()){
			int i = A.front();
			// cout << "in 2nd: " << i << endl;
			A.pop();
			tr(G[i], it){
				temp.insert(*it);
			}
			temp.insert(i);
		}

		tr(temp, iit){
			B.push(*iit);
		}
		temp.clear();
		// int xc; cin >> xc;
		Q = P;
		A = B;
		queue <int> print = P;
		// cout << endl;
		// while(!print.empty()) {cout << print.front() << " "; print.pop();}cout << endl;
		print = B;
		// while(!print.empty()) {cout << print.front() << " "; print.pop();}cout << endl;
		if(last == P) return count - 1;
		else last = B;
		if(B == P) return count;
		if (!do_map(B, P)) break;
		while(!P.empty()) P.pop();
		while(!B.empty()) B.pop();
	}
	return 0;
}

int main(){
	std::ios::sync_with_stdio(false);
	int t; cin >> t;
	int n, mm, a, b, c, v;
	while(t--){
		m.clear();
		vi x;
		cin >> n >> mm >> a >> b;
		RNG(i, n + 1) G.push_back(x);
		while(mm--){
			cin >> c >> v;
			G[c].PB(v);
			G[v].PB(c);
		}
		int zz =bfs(n, a, b);
		if(zz)  cout << zz << endl;
		else cout << "No\n";
		RNG(i, n + 1) G[i].clear();
		G.clear();
	}
return 0;
}
