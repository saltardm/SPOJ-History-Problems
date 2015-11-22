//Mice and Maze : Drew Saltarelli
//Floyd-Warshall Implementation
//O(n^3)
//  Note: Shortest Path, "not all mice can reach the exit" 
#include <stdio.h> 
#define N 160 

int map[N][N]; 

int main() 
{ 
int i, n, e, t, m, a, b, tmp; 
scanf("%d%d%d%d", &n, &e, &t, &m);
for(i = 1; i <= m; i++) 
{ 
    scanf("%d%d%d", &a, &b, &tmp);
    map[a][b] = tmp; 
} 
    
for(i = 1; i <= n; i++) 
    for(a = 1; a <= n; a++)
        for(b = 1; b <= n; b++) 
            if(map[a][i] && map[i][b]) 
                if(map[a][b] == 0 || map[a][b] > map[a][i] + map[i][b]) 
                    map[a][b] = map[a][i] + map[i][b]; 
                    tmp = 0;
                    for(i = 1; i <= n; i++)
                        if((map[i][e] && map[i][e] <= t) || (i == e)) 
                            tmp++; 
printf("%d\n", tmp); 
return 0;
} 
