#include<iostream>

using namespace std;


main()
{

long long int a,b,t,t1,d,i,c;

	cin>>t1;

	while(t1-->0){
		cin>>a>>b;

		if(a>b){
			t=a;
			a=b;
			b=t;
		}

		c=b%a;

		if(c==0){
			d=(b-2*a)/a;
		}
		else{
			d=(b-2);
		}

		if(d<0){
			d=0;
		}
		if(a==b){
		d=1;
		}

		cout<<d<<endl;
	}



}
