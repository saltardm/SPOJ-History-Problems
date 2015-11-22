    #include <cstdio>

    int main()
    {
       int tc;   
       scanf ("%d", &tc);
       while (tc--)
          {
             int x;
             int y;
             scanf ("%d %d", &x, &y);
             if (x == 0 && y == 0)
             {
                printf ("0\n");
                continue;
             }
             if (x < y)
             {
                printf ("No Number\n");
                                    continue;
             }
                            if (y == 0 && x > 2)
                            {
                               printf ("No Number\n");
                                    continue;
             }
             if ((x - y) > 3)
             {
                printf ("No Number\n");
                continue;
                            }
             
             if (x >= y)
             {
                //borderline cases         
                if ((x % 2 == 0 && y % 2 != 0) || (x % 2 != 0 && y % 2 == 0))
                {
                   printf ("No Number\n");
                }
                //even cases            
                if (x % 2 == 0 && y % 2 == 0)
                {
                   int sum = x + y;
                   printf ("%d\n", sum);
                }
                //odd cases
                if (x % 2 != 0 && y % 2 != 0)
                {
                   int sum2 = x+y-1;
                   printf ("%d\n", sum2);
                }
             }
          }
          return 0;
    }
