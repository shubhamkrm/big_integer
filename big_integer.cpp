#include "big_integer.h"
#include <cmath>

big_integer::big_integer()
{
}

big_integer::big_integer(vector <int> num)
{
	number = num;
}
/*
********************************************************************************

	THE FOLLOWING THREE FUNCTIONS ARE DEFINED TO MAKE MY LIFE EASIER

********************************************************************************
*/
void big_integer::push_back(int n)
{
	number.push_back(n);
}

int big_integer::size() const
{
	return number.size();
}

int& big_integer::operator[](int i)
{
	return number[i];
}

/*
********************************************************************************

		IMPLEMENTATIONS FOR OVERLOADED OPERATORS


Note: One important thing to note here is that the numbers are stored in a reve-
-rse order. That is, the units place is stored at index 0, and so on.

For Example : The number 126 is stored as | 6 | 2 | 1 |,
where `|   |` represents a cell in the vector.
********************************************************************************
*/

/*Assigning a big_integer to another big_integer
Very useful to store the result of various arithmatic operations on big_integer in a way that feels natural
*/
big_integer big_integer::operator=(const big_integer& rhs)
{
	set_number(rhs.get_number());
	return *this;
}

/*Assigning a big_integer with an integer data
Useful for initial assignments and for converting integers to big_integer
*/
big_integer big_integer::operator=(const int rhs)
{
	int tmp = rhs;
	while (tmp>0)
	{
		number.push_back(tmp%10);
		tmp/=10;
	}
	return *this;
}

/*
Addition of big_integer and an integer:
The code is mostly self explanatory, I hope.
*/
big_integer big_integer::operator+(int num2) const
{
	big_integer sum;
	int carry = num2;

	for (int i=0;i<number.size() && carry>0;++i)
	{
		int temp = number[i]+carry;
		sum.push_back(temp%10);
		carry = temp/10;
	}
	while (carry>0)
	{
		sum.push_back(carry%10);
		carry/=10;
	}
	return sum;
}

big_integer big_integer::operator+(big_integer &num2) const
{
	big_integer sum;
	const big_integer *larger;
	int i=0, carry = 0;
	if  (number.size()>=num2.size())
		larger = this;
	else
		larger = &num2;

//TODO : Modify this method to use the overloaded + operator
	for (i=0;i<number.size() && i<num2.size();++i)
	{
		int temp = number[i] + num2[i] + carry;
		sum.push_back(temp%10);
		carry = temp / 10;
	}

	while (i<larger->size())
	{
		int temp = larger->number[i] + carry;
		sum.push_back(temp%10);
		carry=temp / 10;
		++i;
	}

	while (carry > 0)
	{
		sum.push_back(carry%10);
		carry/=10;
	}
	return sum;
}	

//TODO: implement the following functions later using Karatsuba method
big_integer big_integer::operator*(int num2) const
{
	big_integer product;
	int carry = 0;
	for (int i=0;i<number.size();++i)
	{
		int temp = number[i] * num2 + carry;
		product.push_back(temp%10);
		carry = temp / 10;
	}
	while (carry>0)
	{
		product.push_back(carry%10);
		carry/=10;
	}
	return product;
}

big_integer big_integer::operator*(big_integer &num2) const
{
	big_integer  product;
	for (int i=0;i<number.size();++i)
	{
		big_integer step_product;
		step_product = num2 * number[i];		
		product = step_product*pow(10,i) + product;
	}
	return product;
}

ostream& operator<<(ostream &out,big_integer &num)
{
	for (int i=num.size()-1;i>=0;--i)
		out<<num[i];
	return out;
}
