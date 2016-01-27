/*
Author : Shubham Kumaram
Date Created : 24 January, 2016

This program lets you use very large integers in your program as easily as you would use an int data.
Currently, it supports assignment, addition, multiplication and printing with a single cout statement.

TODO : Add support for subtraction and division

The program works fine as is as on 26 January 2016
*/
#ifndef BIG_INTEGERS_H
#define BIG_INTEGERS_H

#include <iostream>
#include <vector>
using namespace std;

class big_integer
{
	//This vector stores the number in a reverse order, i.e, the unit's place is stored at index 0
	vector <int> number;
	bool isNegative;

	public:

	//The default constructor. Initializes the vector with null
	big_integer();
	//I don't really expect users to use this constructor, but just in case
	big_integer(vector <int> num);

	//getter function for the private field `number`
	vector <int> get_number() const 
	{
		return number;
	}

	//setter function for the private field `number`, though the use of '=' is recommended to avoid any reversal problems
	void set_number(vector <int> num)
	{
		number = num;
	}

	/*
	The next three functions are there to make my life easier, but I have made them public to allow the user to manipulate the original vector
	*/
	
	//adds a character to the end of the vector (The beginning of the number)
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
	friend big_integer operator+(int num1, big_integer &num2);

	big_integer operator*(int num2) const;
	big_integer operator*(big_integer &num2) const;   
	friend big_integer operator*(int num1, big_integer &num2);

	friend ostream& operator<<(ostream &out, big_integer &num);
};
#endif
