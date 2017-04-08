#pragma once


#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// struct representing each point
struct point {
	float x; // x cordinate
	float y; // y cordinate
};


// Function calculates the distance of the relative shortest cycle
// INPUT: int n - size of the array, P- arrary that holds the points, seq - the sequence the values are in
// OUTPUT: relative minimum distance

float calculate_dist(int n, point *P, int *seq)
{
	float dist = 0;
	for (int i = 0; i < n - 1; i++)
	{
		dist += abs(P[seq[i]].x - P[seq[i+1]].x) + abs(P[seq[i]].y - P[seq[i+1]].y); // calculate the distance between two points
	}
	dist += abs(P[seq[0]].x - P[seq[n - 1]].x) + abs(P[seq[0]].y - P[seq[n - 1]].y);
	return dist;
}


// Function that calculates the nearest unvisited neighboring point by distance
// INPUT: int n - size of array, P- array of points, int A- last point index we visited ,bool *Visited- allows us to check visited nodes
// OUTPUT: index of the closest point that has not been visisted
int closest(int n, point *P, int A, bool *Visited)
{
	int index = 0; // index of closest point
	float dist; // distance between points
	float min = HUGE_VALF; //min distance
	for (int i = 0; i < n; i++)
	{
		dist = abs(P[A].x - P[i].x) + abs(P[A].y - P[i].y); // calculate the distance between two points

		// if the distance is smaller than the min and the node has not been visited then set min index to current index
		if (dist < min && Visited[i] != true)
		{
			min = dist; // set value of min 
			index = i; // index of min
		}
	}
	return index;
}


// function calculates the furthest distance between any two 2D points
// INPUT: int n = the size of the array Point, *P - dynamic array of points
// OUTPUT: the index of the farthest distant point
int farthest(int n, point *P)
{
	float max = 0; // holds the max distance between two points
	float dist; // distance of 2 points
	int maxI; // the index of the max distance point

	// loop through all points
	for (int i = 0; i < n - 1; i++)
	{
		dist = abs(P[i].x - P[i+1].x) + abs(P[i].y - P[i+1].y); // calculate the distance between two points
		if (dist > max) // if the distance is greater than max then save the max index
		{
			maxI = i;
		}
	
	}
	// return the furthest
	return maxI;

}




// Function that prints the Hamiltoniman Cycle
// n- size of P,seq, P- dynamic array of points, seq- best sequence of minimum weight
void print_cycle(int n, point *P, int*seq)
{

	// prints entire cycle using the sequence stored in seq
	for (int i = 0; i < n; i++)
	{
		cout << "(" << P[seq[i]].x << "," << P[seq[i]].y << ") ";
	}
	cout << "(" << P[seq[0]].x << "," << P[seq[0]].y << ") "; // add on first point to end of print
	cout << '\n';
}



