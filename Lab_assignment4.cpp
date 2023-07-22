#include <iostream>
using namespace std;
int main()
{
	//Task 1. 
	float pow, num, product = 1;
	cout << "input a number, after that, input its raised power ";
	cin >> num >> pow;
	if (pow >= 1)
	{
		for ( ; pow >= 1; pow--)
		{
			product *= num;
		}cout << "num^pow= " << product << endl;
	}
	else 
	{   
		for ( ; pow<=-1 ; pow++)
		{
			product *= num;
		}cout <<"num^pow=" << 1 / product << endl;
	}
	//Task 2.
	int q,w=0;
	cout << "input the number to get reversed form ";
	cin >> q;
	while (q > 0)
	{ 
		w = w * 10+q%10;
		q = q / 10;

	}
	cout << w << endl;
	//Task 3.
	
	int a=0;
	for (int i = 5; i > a; i--)
	{
		for (int j = 5; i<j; j--)
		{
			cout << "*";
		}
		cout << '*' << endl;
	}
	//Task 4.
   
	for (int row = 1; row <= 5; row++)//row
	{
		for (	int y = 5; y >= row; y--)//space
		{
			cout << " ";
		}
		for (int z = 1; z <=row; z++)//stars in shown square of matrix
		{
			cout << "*";
		}
		
		cout << endl;
	}
	//Task 5.
	//rows
	for (int k = 1; k <= 3; k++)
	{
		
		for (int l = 1; l <= 3-k; l++)//spaces
		{
			cout << " ";
		}
		for (int c = 1; c <= 2 * k - 1; c++)//calumns
		{
			cout << "*";
		}
		cout <<endl;
		
	}
	//Task 6.
	for (int row = 1; row <= 5; row++)//rows
	{
		
		for (int col = 1; col <= row; col++)
		{   
			cout << "*";
		}//columns
		
		cout << endl;
		if (row == 5)//another line with 5 stars printed in 0ne line right after trieangle shape is done. 
		{
			for (int line = 1; line <= 5; line++)
			{
				cout << "*";
			}cout << endl;
		}continue;
	}
	for (int row1 = 4; row1 >= 1; row1--)
	{
		for (int col1 = 1; col1 <= row1; col1++ ) 
		{
			cout << "*";
		}
		cout << endl;
	}
	//Task 6.
	float den = 1, product1 =1;
	float sum=0;
	for (int num = 1; num <= 7; num++)//I put decrement statement after the while loop, in order that I get the proper answer.
	{   while (den <= num)//factorial
		{
			product1 *= den;
			den++;
		}
	    sum+= num / product1;//numerator/denomenator 
    }
	cout << "sum = " << sum << endl;//turns out that i added this secuential expression 7/!7+6/!6+5/!5+4/!4+3/!3+2/!2+1/!1=sum = 2.71806
	

	
	
	
	
	
	
	
}