
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

	vector <string > arr;

	int inline isPalindrome(unsigned long long number, unsigned char base)
	{
	 unsigned long long forward = number;
	 unsigned long long reversed = 0;
	 unsigned char digit;

	 while (number > 0)
	 {
	  digit = number % base;
	  reversed = reversed * base + digit;
	  number = number / base;
	 }
	 return (forward == reversed);
	}

	void makePalindromes(
	       unsigned long long number,
	       unsigned char base,
	       unsigned long long* palindromes)
	{
	 
	 unsigned long long upper = number;
	 unsigned long long lower = 0;
	 unsigned char digit;
	 unsigned int i;
	 unsigned long long power = 1;

	 /* Form upper and lower portions of the new palindromes */
	 while (number > 0)
	 {
	  upper = upper * base;  /* Shift left for each digit */
	  digit = number % base;
	  lower = lower * base + digit;
	  number = number / base;
	  power*=base;
	 }
	 palindromes[0] = upper + lower;
	 palindromes[1] = upper * base + lower; /* Middle digit: 0 */
	 for (i=1; i<base; i++)
	 { 
	  palindromes[i+1] = palindromes[1] + i*power;/* Middle digit: i */
	 }
	 
	}

	void find_multi_base_palindromes(
	       unsigned char base1,
	       unsigned char base2,
	       unsigned long long max_number,
	       unsigned long long* multi_base_palindromes,
	       unsigned long long int* multi_base_count)
	{
	 unsigned int i;
	 unsigned long long counter = 0;
	 unsigned long long* base1_palindromes;
	 unsigned int max_palindromes = *multi_base_count;

	 base1_palindromes = (unsigned long long*)
	    malloc((base1+1)*sizeof(unsigned long long));
	int flag = 1;
	 *multi_base_count = 0;
	 while (1)
	 {

	  makePalindromes(counter,base1,base1_palindromes);

	  if (base1_palindromes[0] > max_number)
	    break; 

	  for (i=0; i <= base1; i++)
	  {
	   if (base1_palindromes[i] > max_number)
	     break; /* Exit "for" loop if (odd) palindrome exceeds max */

	   if (isPalindrome(base1_palindromes[i],base2))
	   {
	    if (*multi_base_count == max_palindromes + 2)
	      {
	      	flag = 0;
	      	break;
	      }
	    else
	    {
	     multi_base_palindromes[*multi_base_count] = 
	       base1_palindromes[i];
	     (*multi_base_count)++;
	    }
	   }
	  }
	  if(!flag) break;
	  counter++;
	 }
	}

	int main(){
		std::ios::sync_with_stdio(false);
		int t;
		cin >> t;
		int b1, b2;
		while(t--){
		{
			cin >> b1 >> b2;
			if(b1 > b2) swap(b1, b2);
			unsigned long long int decimal_binary_count = 1000; /* (Room to spare) */
			unsigned long long decimal_binary_palindromes[1005]; 
			unsigned long long  int i;
			unsigned long long sum = 0;
	        find_multi_base_palindromes (b1,b2,429496722222222,decimal_binary_palindromes,&decimal_binary_count); 

	 	for (i=2; i < decimal_binary_count; i++) /* i=1 skips dupe 0 */
	   		printf("%lld ", decimal_binary_palindromes[i] );
	   	printf("\n");

			// find_multi_base_palindromes
			//   (2, 10, 230584303ULL,decimal_binary_palindromes,&decimal_binary_count); 

			// for (i=2; i < decimal_binary_count; i++)  i=1 skips dupe 

		}
		}
	return 0;
	}
