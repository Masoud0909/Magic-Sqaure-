/*magic square of order n is an n x n matrix that is filled with the distinct integers 1, 2, 3, …, n2
,
such that the elements in each row, each column, and each diagonal sum up to the same constant
(called the magic constant M = [n(n
	2 + 1)] / 2).The following is a magic square of order 4. It
	contains the numbers 1..16, such that all directions have equal sums(in this case 34)
	Write a program that reads n2
	values from the keyboard and test whether they form a magic square.
	You will need functions such as :
void readSquare(int square[][5], int n)
int leftRightDiagonalSum(int square[][5], int n)
int rightLeftDiagonalSum(int square[][5], int n)
int columnSum(int square[][5], int n, int columnNumber)
int rowSum(int square[][5], int n, int rowNumber)
bool validMagicSquare(int square[][5], int n)*/

#include <iostream>
#include <vector>	

using namespace std;

//Function to read the values into the matrix 

void readSquare(int square[][5], int n) {
	cout << "Enter the values for the magic square: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> square[i][j];
		}
	}
}

//Fucntion to calculate the sum of the left-to-right diagonal

int leftRightDiagonalSum(int square[][5], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += square[i][i];
	}
	return sum;
}
// Function to calculate the sum of the righ-to-left diagonal
int rightleftDiagonalSum(int square[][5], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += square[i][n - i - 1];
	}
	return sum;
}
//Function to calculate the sum of a specific row
int rowSum(int sqaure[][5], int n, int rowNum) {
	int sum = 0;
	for (int j = 0; j < n; j++) {
		sum += sqaure[rowNum][j];
	}
	return sum;
}
//Function to sum up a specific column

int columnSum(int square[][5], int n, int columnNum) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += square[i][columnNum];
	}
	return sum;
}
//Fucntion to verify if the matrix is a MAGIC SQAURE
bool validMagicSqaure(int square[][5], int n) {
	int magicSum = n * (n * n + 1) / 2;
	//check diagonals
	if (leftRightDiagonalSum(square, n) != magicSum)return false;
	if (rightleftDiagonalSum(square, n) != magicSum)return false;
	//check rows and columns
	for (int i = 0; i < n; i++) {
		if (rowSum(square, n, i) != magicSum)return false;
		if (columnSum(square, n, i) != magicSum)return false;
	}
	return true;
}
int main() {
	int n;
	cout << "Enter the size the magic square (n); ";
	cin >> n;
	int square[5][5];

	readSquare(square, n);
	if (validMagicSqaure(square, n))
		cout << "The Matrix is a MAGIC SQUARE!!! " << endl;
	else
		cout << "The Matrix is not a Magic Sqaure :/ .";

	return 0;
}