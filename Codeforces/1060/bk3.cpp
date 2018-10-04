
#include <bits/stdc++.h>

using namespace std;

#define ll long long

int F [13] [2]，a [13]，m;

int main (

		ll n;

		scanf ("%11 d"，&n);

		while (n)
		a [++m] =n % 10，n /= 10; for (int i =1; i  <= m; i++)

		for (int j = 0; j  <=9; j++)

		{

		if (j <= A [i])

		F [i] [0] = max (F [i] [0]，F [i - 1] [0] + a [i]);

		else

		F [i] [1] = max (F [i] [1]，F [i - 1] [0] +10+ a [i]);
		
		if (j  <a[i])

			F [i] [0] = max (F [i] [0]，F [i - 1] [1] + a [i] - 1);

		else

			F [i] [1] = max (F [i] [1]，F [i - 1] [1] +10 + a [i] - 1);

		printf ("%d\n", F [m] [0]);

		return 0;

		}
