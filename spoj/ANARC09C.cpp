
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
#define lli long long 
#define pow2(n) (1<<(n))
#define pow2l(n) ((ll)1<<(n))
// #define MAX(a,b) ((a)>(b)?(a):(b))
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
#define MAX 1000

#include <stdio.h>
#include <string.h>
 
// marks all mutiples of 'a' ( greater than 'a' but less than equal to 'n') as 1.
bool arr[1000000];
void markMultiples( int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num-1 ] = 1; // minus 1 because index starts from 0.
        ++i;
    }
}
 
// A function to print all prime numbers smaller than n
void SieveOfEratosthenes(int orig, int n, vector<pii> &x)
{
    // There are no prime numbers smaller than 2
    if (n >= 2)
    {
        // Create an array of size n and initialize all elements as 0
        memset(arr, 0, sizeof(int) * 8);
 
        /* Following property is maintained in the below for loop
           arr[i] == 0 means i + 1 is prime
           arr[i] == 1 means i + 1 is not prime */
        for (int i=1; i<n; ++i)
        {
            if ( arr[i] == 0 )
            {
                //(i+1) is prime, print it and mark its multiples
                if(orig % (i + 1) != 0) continue;
                int s;
                for(s = 2; s < 30; s++) if(orig % (int) pow(i+1, s) !=0) break; x.PB(MP(i+ 1, s-1));
                markMultiples(i+1, n);
            }
        }
    }
}
int main(){
	std::ios::sync_with_stdio(false);
	vector<pii > x;
	int n, m, j = 1;
	cin >> m >> n;
	while(m != 0 && n !=0)	{
		x.clear();
		if(m >2) SieveOfEratosthenes(m, m / 2, x); else if( m== 2) x.PB(MP(2, 1)); else 
		if(n >2) SieveOfEratosthenes(n, n / 2, x); else x.PB(MP(2, 1));
		sort(x.begin(), x.end());
		int sum = 0;
		FOR(i, 0, x.size()) {if(x[i].first == x[i + 1].first)  sum += x[i + 1].second - x[i++].second; else sum += x[i].second;}
		vector<pii > :: iterator it = x.begin();
		FOR(i, 0, x.size()) cout << x[i].first << " " << x[i].second << " , "; cout << endl;
		for(; it < x.end() - 1; it++){
			if((*it).first == ((*(it + 1)).first)) x.erase(it, it + 1);}
		FOR(i, 0, x.size()) cout << x[i].first << " " << x[i].second << " , "; cout << endl;
		cout << j++ << ". " <<x.size() << ":" << sum << endl;	
		cin >> m >>n;
	}
return 0;
}
