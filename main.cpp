/*
note that n! = (2 * 3 * ... * n)
so log(n!) = log(2 * 3 * ... * n) = log(2) + log(3) + ... + log(n)
This is important because if k is a positive integer then the ceiling of log(k) is the number of digits in the base-10 representation of k. 
Thus, these lines of code are counting the number of digits in n!
*/
p = 0.0;
for(j = 2; j <= n; j++)
    p += log10(j);
d = (int)p + 1;
/* 
Then, these lines of code allocate space to hold the digits of n!
*/

a = new unsigned char[d];
for (i = 1; i < d; i++)
    a[i] = 0; //initialize

/* Then we just do the grade-school multiplication algorithm */
p = 0.0;
for (j = 2; j <= n; j++) 
{
    q = 0;
    p += log10(j);
    z = (int)p + 1;
    for (i = 0; i < z; i++) 
    {
        t = (a[i] * j) + q;
        q = (t / 10);
        a[i] = (char)(t % 10);
    }
}
/*
The outer loop is running from j from 2 to n because at each step we will multiply the current result represented by the digits in a by j. 
The inner loop is the grade-school multiplication algorithm wherein we multiply each digit by j and carry the result into q if necessary.
The p = 0.0 before the nested loop and the p += log10(j) inside the loop just keep track of the number of digits in the answer so far.
*/
for( i = d -1; i >= 0; i--)
    cout << (int)a[i];
cout<<"\n";
delete []a;
