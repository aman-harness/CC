#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,k, count = 0, n_coming, first, second, temp ,disc, i, result ;
	cin >> n >> k;
	for(i = 0; i < k; i++){
		cin >> n_coming;
		cin >> first;
		temp = n_coming- 1;
		disc = 0;
        while(temp--){
        	cin >> second;
        	if (second -1 != first) disc++;
        	first = second;
        }
        count += disc;
	}
	result = 2* count + k -1;
	cout << result;
}