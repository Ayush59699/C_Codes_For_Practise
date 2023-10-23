#include <stdio.h>
#include <stdlib.h>
#define I __INT_MAX__
int cost[][8]={{I , I , I , I , I , I , I , I } ,
               {I , I , 25 , I , I , I ,15 ,I},
               {I , 25 ,I , 15 , I , I ,I , 10},
               {I , I , 15 , I , 8 , I , I , I },
               {I , I , I , 8 , I , 16 , I , 14},
               {I , I , I , I , 16 , I , 20 ,18},
               {I , 15 , I , I , I , 20 , I , I},
               {I , I , 10 , I , 14 , 18, I , I}};
        
int near[8]={I};
int t[2][7];

int main(){
    int i,j,k,u,v,n=7,min=I;
    for(i=1;i<=n;i++){     //FINDING SMALLEST EDGE
        for(j=1;j<=n;j++){
            if(cost[i][j]<min){
                min=cost[i][j];
                u=i;
                v=j;
            }
        }
    }

    t[0][0]=u;
    t[1][0]=v;
    near[u]=near[v]=0;
    for(i=1; i<=n; i++){    // finding vertices near to u or v
        if(near[i]!=0){
            if(cost[i][u] < cost[i][v])
                near[i]=u;
            else
                near[i]=v;
        }
    }

    for(i=1;i<n-1;i++){
        min=I;
        for(j=1;j<=n;j++){
            if(near[j]!=0 && cost[j][near[j]]  < min){
                k=j;
                min= cost[j][near[j]];
            }
        }

        t[0][i]=k;
        t[1][i]=near[k];
        near[k]=0;
        for(j=1;j<=n;j++){
            if(near[j]!=0 && cost[j][k] < cost[j][near[j]])
                near[j]=k;
        }
    }
    for(i=0;i<n-1;i++){
        printf("( %d , %d )\n", t[0][i] , t[1][i] );
    }

}