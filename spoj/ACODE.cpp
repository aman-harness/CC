#include<iostream>
#include<cstdio>
#include<string.h>
#include<stdlib.h>

using namespace std;
unsigned long long int dp[5001];
int main(){
	unsigned long long int len, i;
	char String[5001];
	char key[] = "0";
	cin >> String;
	while(strcmp (String, key) != 0){
        len = strlen(String);
        memset(dp,0,5000);
        dp[0] = 1;
        if (len > 1) {
        	if (String[0] == '0' || String[0] == '1') dp[1] = 2; 
        	else if(String[0] == '2' && String[1] < 55) dp[1] = 2; 
        	else dp[1] = 1; 
        	}
        for(i = 2; i < len ; i++){
            if ((String[i-1] == '0' || String[i-1] == '1') || (String[i-1] == '2' && String[i] < 55))
            	{dp[i] = dp[i-1] + dp[i - 2];}
            else dp[i] = dp[i-1];
            // cout << dp[i] << " " << i << endl;
        }
        cout << dp[len -1] << endl;
        cin >> String;
	}
return 0;
}