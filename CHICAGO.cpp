//Chicago : Drew Saltarelli
//Floyd Warshall approach
//O(n^3)
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<string>

using namespace std;


double d[105][105];

int main()
{
    int n,m;
    while(cin>>n && n){
        cin>>m;
        int x,y; double w;
        for(int i=0;i<=n;++i)
            for(int j=0;j<=n;++j)
                d[i][j]=0;
        
        for(int i=0;i<m;++i){
            cin>>x>>y>>w;
            w/=100;
            d[x-1][y-1]=d[y-1][x-1]=w;
            d[x-1][x-1]=d[y-1][y-1]=1;
        }
        
        for (int k=0; k<n; k++)
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                    d[i][j] = max(d[i][j], d[i][k] * d[k][j]);
        
        printf("%0.6f percent\n",d[0][n-1]*100);
    }
    return 0;
}
