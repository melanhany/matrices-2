#include <iostream>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("result.txt");

void in(int **matrix, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			fin >> matrix[i][j];
}

void out(int **matrix, int n)
{
	for (int i = 0; i < n; i++, fout << endl)
		for (int j = 0; j < n; j++)
			fout << matrix[i][j] << " ";
	fout << endl;
}

bool isPrime(int a)
{
	// 0 and 1 are not prime numbers
	if (a == 0 || a == 1 || a < 0) {
		return false;
	}
	else {
		for (int i = 2; i <= a / 2; ++i) {
			if (a % i == 0) {
				return false;
				break;
			}
		}
	}
	return true;
}

int op1(int **matrix, int n)
{
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			if (isPrime(matrix[i][j]))
				matrix[i][j] = matrix[i][j] * matrix[i][j];
		}
	}
	
	return **matrix;
}


int op2(int **matrix, int n)
{
	int max = matrix[0][0];
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] > max) {
				max = matrix[i][j];
				k = i;
			}
		}
	}
	int min = matrix[0][0];
	int a = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] < min) {
				min = matrix[i][j];
				a = i;
			}
		}
	}
	int temp;
	for (int j = 0; j < n; j++)
	{
		 temp = matrix[k][j];
		 matrix[k][j] = matrix[a][j];
		 matrix[a][j] = temp;
	}
	return **matrix;
}


bool AE(int **matrix, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((matrix[i][j] > 0) && (matrix[i][j] % 4 == 0)) {
				count += 1;
				j = n;
			}
		}
	}
	if (count == n)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int statement_true(int **A, int **B, int **C, int n)
{
	int i, j;
	op1(B, n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			A[i][j] = A[i][j] * 2;
			C[i][j] = B[i][j] + A[i][j];
		}
	}
	return **C;
}

int statement_false(int **A, int **B, int **C, int n)
{
	int i, j, k;
	op2(A, n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			B[i][j] = B[i][j] * -3;
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				C[i][j] += (B[i][k] * A[k][j]);
			}
		}
	}
	return **C;
}


int main()
{
	int n, m, i = 0, j = 0;

	cout << "Type in n: " << endl;
	cin >> n;

	int **A;
	A = new int*[n];
	// filling up array a with memory
	for (i = 0; i < n; i++) {
		A[i] = new int[n];
	}
	// input of elements of matrix a
	in(A, n);

	int **B;
	B = new int*[n];
	// filling up array a with memory
	for (i = 0; i < n; i++) {
		B[i] = new int[n];
	}
	// input of elements of matrix a
	in(B, n);

	int **C;
	C = new int*[n];
	// filling up array a with memory
	for (i = 0; i < n; i++) {
		C[i] = new int[n];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			C[i][j] = 0;
		}
	}

	if (AE(B, n))
	{
		statement_true(A, B, C, n);
		out(C, n);
	}
	else
	{
		statement_false(A, B, C, n);
		out(C, n);
	}
}