#include "test.hpp"
#include <iostream>

void	TestEqualElem() {
	size_t rows = 2, columns = 9;

	Matrix M(rows, columns);
	for(size_t i = 0; i < rows; ++i)
		for (size_t j = 0; j < columns; ++j)
			M[i][j] = j;
	M[1][5] = 5;
	assert(M[1][5] == 5);
}

void	TestMultiply() {
	size_t rows = 2, columns = 9;

	Matrix M(rows, columns);
	for(size_t i = 0; i < rows; ++i)
		for (size_t j = 0; j < columns; ++j)
			M[i][j] = j;
	M[1][5] *= 5;
	M[1][8] *= 8;
	assert(M[1][5] == 25);
	assert(M[1][8] == 64);
}

void	TestNegativeRow() {
	size_t rows = -5, columns = 5;
	try {
		Matrix M(rows, columns);
	}
	catch (std::bad_alloc& ba) {
		std::cout << "TestNegativeRow is 	OK\n";
	}
}

void	TestNegativeColumn() {
	size_t rows = 5, columns = -5;
	try {
		Matrix M(rows, columns);
	}
	catch (std::bad_alloc& ba) {
		std::cout << "TestNegativeColumn is 	OK\n";
	}
}

void	TestEqualMatrixDiffSizes() {
	size_t rows = 3, columns = 6;
	Matrix A(rows, columns);
	Matrix B(6, 3);
	assert(A != B);
}

void	TestPrint() {
	size_t rows = 2, columns = 9;

	Matrix M(rows, columns);
	for(size_t i = 0; i < rows; ++i)
		for (size_t j = 0; j < columns; ++j) {
			M[i][j] = j;
		}
	std::cout << "------ M A T R I X : ------\n";
	std::cout << M;
}

int main() {
	TestEqualElem();
	std::cout << "TestEqual is			OK\n";
	TestMultiply();
	std::cout << "TestMultiply is			OK\n";
	TestNegativeRow();
	TestNegativeColumn();
	TestEqualMatrixDiffSizes();
	std::cout << "TestEqualMatrixDiffSizes is	OK\n";
	TestPrint();
	std::cout << "TestPrint is			OK\n";
}
