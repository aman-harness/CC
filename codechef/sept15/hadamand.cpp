#include <stdio.h>

void main(void) {

int i, N;

scanf("Input N value:   %d", &N);

char **h = (char**) calloc(N, sizeof(char*));

for ( i = 0; i < N; i++ ) {
    h[i] = (char*) calloc(N, sizeof(char));
}

int ii, xx, yy;

h[0][0]='1';


for(ii=2; ii<=N; ii*=2) {
    //Top right quadrant.
    for(xx=0; xx<(ii/2); ++xx) {
        for(yy=(ii/2); yy<ii; ++yy){
            h[xx][yy]=h[xx]yy-(ii/2)];                          
        }
    }
    //Bottom left quadrant.
    for(yy=0; yy<(ii/2); ++yy) {
        for(xx=(ii/2); xx<ii; ++xx) {
            h[xx][yy]=h[xx-(ii/2)][yy];
        }
    }
    //Bottom right quadrant, inverse of other quadrants.
    for(xx=(ii/2); xx<ii; ++xx) {
        for(yy=(ii/2); yy<ii; ++yy) {
            h[xx][yy]=h[xx-(ii/2)][yy-(ii/2)];
            if(h[xx][yy]=='1') {
                h[xx][yy]='0';
            }
            else {
                h[xx][yy]='1';
            }
        }
    }
}


//Printing matrix.
for(xx=0; xx<N; ++xx) {
    for(yy=0; yy<N; ++yy) {
        printf("%c",h[xx][yy]); 
    }
    printf("\n");
}
}