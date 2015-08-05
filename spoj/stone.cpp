#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<utility>
#define f(i,a,n) for(i=a;i<n;i++)
#define spc " "
#include<cstdio>
using namespace std;

pair <float, float> input[100000];
float ansfirst,anssecond;
float xy[1000000],yx[1000000];
float area;
int main(){
//ios_base:sync_with_stdio (false);
int a,b,c,d,e,f,i,j,m,n,k,t;
cin >> t;

while(t--){
    cin >> n;
    f(i,0,n){
    cin >> input[i].first >> input[i].second;
        }
    input[i].first = input[0].first;
    input[i].second = input[0].second;
    f(i,0,n){
        xy[i] = input[i].first * input[i+1].second;
        yx[i] = input[i].second * input[i+1].first;
        }
    area =0;
    f(i,0,n){
        area += float(xy[i] - yx[i]);
        }
    area *= 0.5;
    //if(area<0) area = -area;
    ansfirst = 0;
    anssecond = 0;
    f(i,0,n){
            ansfirst += float((input[i].first + input[i+1].first) * (xy[i] - yx[i]));
            anssecond += float((input[i].second + input[i+1].second) * (xy[i] - yx[i]));
        }
    //cout << area;
    ansfirst /= (6.0 * area);
    anssecond /= (6.0 * area);
    if(ansfirst<=0 && ansfirst > -0.005) ansfirst = 0.00;
    if(anssecond <= 0 && anssecond > -0.005) anssecond = 0.00;
    //cout << ansfirst << spc* << anssecond <<endl;
    printf("%.2f %.2f\n", ansfirst, anssecond);
}
return 0;
}

