/*
Author : Shubham Kumaram
Date Created : 24 January, 2016

This program lets you use very large integers in your program as easily as you would use an int data.
Currently, it supports assignment, addition, multiplication and printing with a single cout statement.

TODO : Add support for subtraction and division
TODO : Adding support for int + big_integer and similar multiplication operation

The program works fine as is as on 24 January 2016
*/
#ifndef BIG_INTEGERS_H
#define BIG_INTEGERS_H

#include <iostream>
#include <vector>
using namespace std;

class big_integer
{
	vector <int> number;

	public:
	
	big_integer();
	big_integer(vector <int> num);

	vector <int> get_number() const 
	{
		return number;
	}

	void set_number(vector <int> num)
	{
		number = num;
	}

	void push_back(int n);
	int size() const;
	
	int& operator[](int i);
	
	/*Note : Though the overloaded = works fine, it cannot be used for initialisation.
		 It must be initialised first using a constructor (default works fine) and then a value should be assigned to it
		
		For example : big_integer a =  10; //this code does not work
		Use instead : big_integer a;
			      a = 10;
	*/
	big_integer operator=(const big_integer &rhs);
	big_integer operator=(const int rhs);

	big_integer operator+(int num2) const;
	big_integer operator+(big_integer &num2) const;   

	big_integer operator*(int num2) const;
	big_integer operator*(big_integer &num2) const;   

	friend ostream& operator<<(ostream &out, big_integer &num);
};
#endif
