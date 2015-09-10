#include<bits/stdc++.h>
#define f(i, a, n) for(i = a; i < n; i++)
using namespace std;
int  leffft[1000000], rightt[1000000];
pair<int, int> input[1000000];
long long int countt[1000000];

int answer(int number, char turn){
	cout << "Answer :" << number << endl;
	if(number & 1) if (turn == 'D') cout << "D"; else cout << "C";
	else  if (turn == 'C') cout << "D"; else cout << "C";
}

int LessThanEqualBinSearch( long long int key, const int len )
{
    int min = 0;
    int max = len-1;

    while( min <= max)
    {
        int mid = min + ((max - min) / 2);

         if (input[mid].first < key)  min  = mid + 1;
        else if (input[mid].first > key)  max  = mid - 1;
        else   /*input[i].first[mid] = key)*/return mid    ;
    }
    if( max < 0 )
        return 0;  // key < input[i].first
    else
    if( min > (len-1))
        return -1; // key >= input[len-1].first	 // KEY_NOT_FOUND
    else
        return (min < max)
            ? min  
            : max + 1;
}


inline long long int calc(int vertices){
	long long int sum = 0, i;
	f(i, 0, vertices){
		 sum = 0;
		 sum += (leffft[i] + rightt[i] + 1) * (leffft[i] + rightt[i] + 2);
		 sum /= 2;
		 sum -= ((leffft[i]) * (leffft[i] + 1) / 2);
		 sum -= ((rightt[i]) * (rightt[i] + 1) / 2);
		 input[i].second = sum;
	}
}

int calc_r(int i, int val, int vertices){
	if(i >= vertices -1) return 0;
	int sum = 0;
	if(input[i + 1].first > val) return 0;
	else sum += 1 + rightt[i + 1] + calc_r(i + rightt[i + 1] + 1, val, vertices);
	return sum;
}



int calc_l(int i, int val){
	if(i == 0) return 0;
	int sum = 0;
	if(input[i - 1].first >  val) return 0;
	else sum += 1 + leffft[i - 1] + calc_l(i - leffft[i - 1] - 1, val);
	return sum;
}

int find(int vertices){
	int back, i;
	leffft[0] = 0;
	rightt[vertices - 1] = 0;
    f(i, 1, vertices){
        leffft[i] = calc_l(i, input[i].first);
    }
    for(i = vertices -2; i >= 0; i--) rightt[i] = calc_r(i, input[i].first, vertices);
}

int main(){
	int i, j, m, n, t, k, l, cond, loc;
	char sign, turn;
	cin >> n >> m;
	memset(leffft, 0, (m + 1) * sizeof(int));
    f(i,0,n) cin >> input[i].first;
    find(n);
    calc(n);
    // sort(input, input + n);
    countt[0] = 1;
    f(i, 1, n) { countt[i] = countt[i-1] + input[i].second; cout << countt[i] << endl;}
    while(m--){
    	cin >> sign >> cond >> turn;
    	loc = 0;
    	cout << "Location --  " << loc << endl;
    	if(loc == -1 && sign == '>') if (turn == 'C') cout << "D"; else cout << "C";
    	else if(loc == -1 && sign == '<') answer(countt[n-1], turn);
    	else if(sign == '='){
    	    answer(input[loc].second, turn);}
    	else if (sign == '<'){
    		answer(countt[loc -1], turn);
    	}
    	else{
            if(input[loc].first == cond) answer(countt[n-1] - countt[loc], turn);
            else answer(countt[n-1]- countt[loc -1], turn);  
    	}

    }
    cout << endl;
}   