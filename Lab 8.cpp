// C++ Program			Lab 08.cpp
// Course				CSE1311/W01
// Name:				Hakeem Wilson
// Assignment #:		Lab 8 
// Due Date:			3/24/2019

/*  The purpose od this prgram is to read data into an array from a file,
	then calculate the average and the variance for each data point,
	then find the highest and lowest values with in the array as well as their respective position.*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("input.txt");

	double average;
	double temp[24]; //declaring the array
	
	double total = 0;	 

	for (int i = 0; i < 24; ++i)    //notice the loop starts at 0 and goes to less than the last element
	{
		fin >> temp[i];
	}
	fin.close();

	for (int i = 0; i < 24; ++i)    //notice the loop starts at 0 and goes to less than the last element
	{
		total += temp[i];
	}
	average = (double)total / 24.0;
	
	int hour = 1;
	for (int i = 0; i < 24; ++i)    //notice the loop starts at 0 and goes to less than the last element
	{
		cout << "The average of the temperature over 24 hours is " << average << endl;
		cout << endl;
		cout << "Hour" << "\t\t" << "Temperature" << "\t\t" << "Difference from Average" << endl;
		cout << hour << "\t\t" << temp[i] << "\t\t\t" << temp[i] - average << endl;
		cout << endl;
		++hour;
	}
	
	double min = temp[0];	 	 //set min to the first position in the array
	double saveLow = 0;		//save the position of the lowest so far
	
	for (int i = 1; i < 24; ++i) 	//start at 1 since the first value is already in min    
	{
		if (temp[i] < min)	      	 //if a particular score is lower than the one in min
		{
			min = temp[i];     	//put that score in min and keep going
			saveLow = i;		//place the index of the lower score in saveLow
		}
	}
	cout << "The lowest of the temperatures is " << min << endl;
	cout << "The hour with the lowest number is " << saveLow + 1 << endl;
	cout << endl;
	
	double max = temp[0];	 	 //set max to the first position in the array
	double saveHigh = 0;		//save the position of the highest so far
	
	for (int i = 1; i < 24; ++i) 	//start at 1 since the first value is already in max    
	{
		if (temp[i] > max)	      	 //if a particular score is higher than the one in max
		{
			max = temp[i];     	//put that score in max and keep going
			saveHigh = i;		//place the index of the higher score in saveHigh
		}
	}

	cout << "The highest of the temperatures is " << max << endl;
	cout << "The hour with the highest number is " << saveHigh + 1 << endl;
	cout << endl;
	cout << "This was coded by Hakeem Wilson" << endl;
	system("PAUSE");
	return 0;
}