#include<bits/stdc++.h>

using namespace std;
int img[500][600];

int check(int a, int b)
{
	if(a >= 6 || a <= 0 || b <= 0 || b >= 10) return 0;
	else return 1;
}

int count(int a, int b){
	cout << a << " " << b << " "<< img[a][b]  << endl;
	int z;
	img[a][b] = 1;
	// if (img[a][b]) cin >> z;
	// cin >> z; 
	int sum = 1;
    if(!check(a, b)) return 0;
	if (0){
	    cout << "Called \n" << img[a][b] << a << b;
		return 0;
	}
	else{
        if(check (a + 1, b)) if(!img[a + 1][b]) { img[a + 1][b] = 1 ;sum += count(a + 1, b);}
        if(check (a, b + 1)) if(!img[a][b + 1]) { img[a][b + 1] = 1 ;sum += count(a, b + 1);}
        if(check(a, b - 1)) if(!img[a][b - 1]) { img[a][b - 1] = 1 ;sum += count(a, b - 1);}
        if(check(a - 1, b)) if(!img[a - 1][b]) { img[a - 1][b] = 1 ;sum += count(a - 1, b);}
        return sum;
	}
}

int mark(int a, int b, int c, int d){
	int i, j;
	for(i = a; i < c; i++)
		for(j = b; j < d; j++){
			// cout << "Coloring " << i << j << endl;
        	img[i][j] = 2;
        	if(i == 2 && b == 5) cout << "Hi\n";
		}
}

int main(){
	int a, b, c ,d, e, f;
	// memset(img, 0, 50 * 60 * sizeof(int));
	// cin >> a >> b >> c >> d;
	mark(0, 3, 5, 9);
	// cin >> a >> b >> c >> d;
	// mark(30, 8, 31, 59);
	// cin >> a >> b >> c >> d;
	// mark(0, 20, 49, 25);
	// cin >> a >> b >> c >> d;
	// mark(0, 35, 49, 45);
	cout << endl << count(1,1);
}

// 10 15 11 59
// 30 8 31 59
// 0 20 49 25
// 0 35 49 45
