// Caitlyn Hartmann
// OS Project 2: Banker's Algorithm
// Dr. Guan
// 1 December 2023

#include <iostream>
#include <stdlib.h> 
#include <stdio.h>

// total number of processes
#define n 5
// total number of resources
#define m 3

int main() {
	// p0-4 -> process names

	// set up the given allocation matrix
	int allocationMat[n][m] = { { 0, 1, 0 },			// p0 
								{ 2, 0, 0 },			// p1
								{ 3, 0, 2 },			// p2
								{ 2, 1, 1 },			// p3
								{ 0, 0, 2 } };			// p4

	// set up the given max matrix
	int maxMat[n][m] = { { 7, 5, 3 },		// P0 
								{ 3, 2, 2 },			// P1
								{ 9, 0, 2 },			// P2
								{ 2, 2, 2 },			// P3
								{ 4, 3, 3 } };			// P4

	// available resources
	int work[m] = { 3, 3, 2 };
	
	int z[n], final[n], loc = 0;

	// initialize vectors of size n

	// zero vector size of n
	for (int p = 0; p < n; p++) {
		z[p] = 0;
	}

	// create the need matrix, max - allocation
	int needMat[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			needMat[i][j] = maxMat[i][j] - allocationMat[i][j];
		}
	}

	// if need is less than or equal to work, work is equal to work + allocation
	int track = 0;
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < n; i++) {
			if (z[i] == 0) {
				int flag = 0;
				// if need is greater than work, break
				for (int j = 0; j < m; j++) {
					if (needMat[i][j] > work[j]) {
						flag = 1;
						break;
					}
				}
				// if need is less than or equal to work, w = w + alloc
				if (flag == 0) {
					final[loc++] = i;
					for (track = 0; track < m; track++) {
						work[track] += allocationMat[i][track];
					}
					z[i] = 1;
				}
			}
		}
	}


	int flag = 1;

	// check the sequence, to see if it is safe or not

	for (int i = 0; i < n; i++) {
		if (z[i] == 0) {
			flag = 0;
			std::cout << "The sequence is not safe... womp womp";
			break;
		}
	}

	if (flag == 1) {
		
		std::cout << "The safe sequence is:" << std::endl;
		for (int i = 0; i < n - 1; i++) {
			std::cout << " p" << final[i] << " ->";
		}
		std::cout << " p" << final[n - 1] << std::endl;
	}

	return (0);
}