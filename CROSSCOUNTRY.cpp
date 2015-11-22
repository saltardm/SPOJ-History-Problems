//Crosscountry : Drew Saltarelli
//Longest Common Subsequence approach (DP)
//O(m*n)

#include <stdio.h>
#include <string.h>
const int MAXN=1002;
int f[MAXN][MAXN];
int a[MAXN];
int b[MAXN];
int n, m;
int main()
{
    int kcase, ans;
    scanf("%d",&kcase);
    while(kcase--){
        n = 0;
        ans = 0;
        while(scanf("%d",&a[++n]) && a[n] );
        n--;
        while( scanf("%d",&b[1] ) && b[1] ){
            m = 1;
            while(scanf("%d",&b[++m] ) && b[m] );
            m--;
            for(int i =0;i<=n;i++)f[i][0]=0;
            for(int j =0;j<=m;j++)f[0][j]=0;
            for(int i=1; i <= n; i++){
                for(int j=1; j<=m; j++ ){
                    f[i][j]=0;
                    if(a[i]==b[j] && f[i][j]<f[i-1][j-1]+1)f[i][j]=f[i-1][j-1]+1;
                    if(f[i][j]<f[i-1][j])f[i][j]=f[i-1][j];
                    if(f[i][j]<f[i][j-1])f[i][j]=f[i][j-1];
                    if(f[i][j]<f[i-1][j-1])f[i][j]=f[i-1][j-1];
                }
            }
            if(ans<f[n][m])ans=f[n][m];
        }
        printf("%d\n",ans);
    }
    return 0;
}
