/*
Author: Andrew Le
Email: andrewle19@csu.fullerton.edu
4/7/17

Rectilinear traveling salesperson problem: improved nearest neighbor algorithm
A special case of the classical traveling salesman problem (TSP) where the input is a Euclidean graph
INPUT: a positive integer n and a list P of n distinct points representing vertices of a Euclidean graph
OUTPUT: a list of n points from P representing a Hamiltonian cycle of relatively minimum total weight

*/

#include <iostream>
#include <cmath>
#include <chrono>
#include "neighbor.h"
using namespace std;


int main()
{
	int n; // number of verticies 
	point *P; // P- holds the value of every point
	int *M; //M - holds the indicies of the best relative set,
	bool *Visited; // holds if the index was visited
	int A, B; // A- current node, B- visiting nodes
	float dist; // hold the distance of min distance

	// display the header
	cout << "CPSC 335 Programming Assignment #3" << endl;
	cout << "Rectilinear traveling salesperson problem: exhaustive optimization algorithm" << endl;
	cout << "Enter the number of vertices (>2) " << endl;
	// read the number of elements
	cin >> n;

	// if less than 3 vertices then terminate the program
	if (n < 3)
	{
		return 0;
	}

	P = new point[n]; // dynamically allocate space for number of points

					  // read the sequence of distinct points
	cout << "Enter the points; make sure that they are distinct" << endl;
	for (int i = 0; i < n; i++) {
		cout << "x=";
		cin >> P[i].x;
		cout << "y=";
		cin >> P[i].y;
	}
	cout << "Input: n" << endl;
	cout << "n=" << n << endl;


	
	M = new int[n]; // allocate space
	// set the M set to be the list of indices, starting at 0 AND fill the arrary with values starting from 0 to n-1
	for (int i = 0; i < n; i++)
	{
		M[i] = i;
	}

	// starts the clock
	auto start = chrono::high_resolution_clock::now();
	
	Visited = new bool[n]; // allocate space for the Visited array of Boolean values
	// set it all to False
	for (int i = 0; i < n; i++)
	{
		Visited[i] = false;
	}
	
	
	

	// Calculate the starting Vertex A
	A = farthest(n, P); // get the farthest index
	// add it to the path
	M[0] = A;
	Visited[A] = true;

	for (int i = 1; i < n; i++)
	{
		// calculate the nearest unvisited neighbor from Node A
		B = closest(n, P, A, Visited);
		// Node B becomes the new node A
		A = B;
		// Add it to the path
		M[i] = A;
		Visited[A] = true;
	}
	
	dist = calculate_dist(n, P, M); // calculate the min relative distance

	// End the clock
	auto end = chrono::high_resolution_clock::now();

	// after shuffling them
	cout << "The Hamiltonian cycle of a relative minimum length " << endl;
	print_cycle(n, P, M);
	cout << "The relative minimum length is " << dist << endl;
	
	// print the time elapsed
	int microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count(); // microseconds
	double seconds = microseconds / 1E6; // convert to seconds
	cout << "elapsed time: " << seconds << " seconds" << endl;


	// de-allocate the dynamic memory space
	delete[] P;
	delete[] M;
	delete[] Visited;

	system("pause");
	return 0;
}