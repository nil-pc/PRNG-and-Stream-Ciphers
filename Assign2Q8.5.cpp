// Q5: Verify theorem presented by Ernesto Cesaro
// probability that gcd(x,y) = 1 is 6/(pi^2)
#include <iostream>
#include <bits/stdc++.h> 
#include <unordered_map> 
#include <time.h>
#include <cmath>
using namespace std;

//Function to calculate GCD of 2 numbers
int gcd(int  a, int b)
{
	if(b == 0)
		return a;
	return gcd( b, a % b);
}

int main()
{
	int a, b, c;
	float total_cnt, total_occ = 0;
	float prob, pi;
	cout<<"Enter no of value pairs to consider : ";
	cin>>total_cnt;
	cout<<"Generate randum numbers : \n";
	srand(time(0));
	a = rand();
	cout<<" no_1 : "<<a<<" ";
	for(int i = 0; i < total_cnt ; ++i)
	{
		b = rand();
		cout<<" no_"<<i+2<<" : "<<b<<" ";
		c = gcd(a, b);
		cout<<"gcd = "<<c<<"\n";
		if(c == 1)
			total_occ ++;
		a = b;
		if(i < (total_cnt - 1))
		 	cout<<" no_"<<i+2<<" : "<<a;
	}
	prob = total_occ/total_cnt;
	cout<<"\nProbability = "<< prob<<"\n";

	//Calculate value of pi
	pi = sqrt(6/prob);
	cout <<"pi = "<<pi<<"\n";
}

/*
NOte :-
If the result comes close to 3.14 we can observe that the probability of getting GCD of the pairs of numbers as 1 is around 0.6.
i.e if from the random number pairs chosen if the 60% of them have a GCD of 1 then the value of pi obtained is close to 3.14.

There are cases where most of the random number generated are coprimes i.e around 80-90% of the pairs have a GCD of 1.
In such cases the value of pi calculated is around 2.7
*/
