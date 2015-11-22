//Wireless : Drew Saltarelli
//Difference Array approach described by Brian Bi and Amlesh Jayakumar
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int diff[30001][1001];

int main()
{
    int cols, rows, radius, bitrate, left, right, col, row;
    scanf("%d", &rows);
    scanf("%d", &cols);
    diff[rows+1][cols+1];
    for (int i = 0 ; i <= rows ; i++)
	    for (int j = 0 ; j <= cols ; j++)
		diff [i] [j] = 0;
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &col);
        scanf("%d", &row);
        scanf("%d", &radius);
        scanf("%d", &bitrate);
        row--;
        col--;
        for (int j = max(0, col - radius); j <= min (cols - 1, col + radius); j++)
        {
            left = max(0,row - (int) sqrt (radius * radius - (col - j) * (col - j)));
            right = min(rows - 1, row + (int)sqrt (radius * radius - (col - j) * (col - j)));
            diff [left] [j] += bitrate;
	    	diff [right + 1] [j] -= bitrate;
        }
    }
    int best = 0;
	int count = 0;
	for (int i = 0 ; i < rows ; i++)
	    for (int j = 0 ; j < cols ; j++)
	    {
		    if (i > 0)
		        diff [i] [j] += diff [i - 1] [j]; 
		    if (diff [i] [j] == best)
		        count++;
	    	if (diff [i] [j] > best)
	    	{
		        best = diff [i] [j];
		        count = 1;
		    }
	    }
	    printf("%d\n", best);
	    printf("%d\n", count);
        system("PAUSE");
        return 0;
}





        

    
