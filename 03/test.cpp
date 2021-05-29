#include "Matrix.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
#include <cstring>


void GetRowColTest() {
	const size_t rows = 2;
	const size_t cols = 3;
	Matrix MTRX(rows,cols);
	assert(MTRX.getRows() == 2);
	assert(MTRX.getColumns() == 3);
	MTRX[1][1] = 10;
	int32_t x = MTRX[1][1];
	assert(x == 10);
}

void GetElTest() {
	const size_t rows = 4;
	const size_t cols = 2;
	Matrix MTRX(rows, cols);
	Matrix MTRX_LOCAL(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			MTRX[i][j] = 5;
		}
	}
	MTRX_LOCAL = MTRX;
	assert(MTRX_LOCAL==MTRX);
	MTRX *= 10;
	assert(MTRX[3][1] == 50);
	assert(MTRX_LOCAL != MTRX);
}

void MulTest()
{
	const size_t rows = 5;
	const size_t cols = 5;
	Matrix MTRX(rows, cols);
	Matrix m1(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			MTRX[i][j] = 3;
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			m1[i][j] = 6;
		}
	}
	MTRX *= 2;
	assert(MTRX == m1);
}

void CheckTest() {
	const size_t rows = 9;
	const size_t cols = 7;
	Matrix MTRX(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			MTRX[i][j] = 8;
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			 assert(MTRX[8][6] == 8);
		}
	}
}

void PlusTest() {
	const size_t rows = 5;
	const size_t cols = 5;
	Matrix MTRX(rows, cols);
	Matrix m1(rows, cols);
	Matrix m2(rows, cols);
	Matrix m3(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			MTRX[i][j] = 2;
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			m1[i][j] = 3;
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			m2[i][j] = 5;
		}
	}
	m3 = m1 + MTRX;
	assert(m2 == m3);
}
void EqualTest()
{
	const size_t rows = 5;
	const size_t cols = 5;
	Matrix MTRX(rows, cols);
	Matrix m1(rows, cols);
	Matrix m2(rows, cols);
	Matrix m3(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			MTRX[i][j] = 2;
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			m1[i][j] = 3;
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			m2[i][j] = 5;
		}
	}
	m3 = m1 + MTRX;
	assert(m2 == m3);
	assert(MTRX != m2);
	m3 = m2 = MTRX;
	assert(m3 == MTRX);
}

void OnexOneTest()
{
	const size_t rows = 1;
	const size_t cols = 1;
	Matrix MTRX(rows, cols);

	MTRX[0][0] = 5;
	assert( MTRX[0][0] == 5);
}

void ExceptionTest() {
	const size_t rows = 4;
	const size_t cols = 7;
	bool catching = false;

	Matrix MTRX(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			MTRX[i][j] = (i+1)*10 + j+1;
		}
	}
	try {
		MTRX[10][1] = 11;
	}
	catch (const std::out_of_range& e) {
		catching = true;
	}
	assert(catching);
}

void 	OutTest() {
	const size_t rows = 5;
	const size_t cols = 9;
	Matrix MTRX(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			MTRX[i][j] = 1;
		}
	}
	std::cout << MTRX;
}

int main() {
	OutTest();
	std::cout<<"OK!\n"<<std::endl;
	GetRowColTest();
	std::cout<<"OK!\n"<<std::endl;
	GetElTest();
	std::cout<<"OK!\n"<<std::endl;
	MulTest();
	std::cout<<"OK!\n"<<std::endl;
	CheckTest();
	std::cout<<"OK!\n"<<std::endl;
	PlusTest();
	std::cout<<"OK!\n"<<std::endl;
	EqualTest();
	std::cout<<"OK!\n"<<std::endl;
	OnexOneTest();
	std::cout<<"OK!\n"<<std::endl;
	ExceptionTest();
	std::cout<<"OK!\n"<<std::endl;
	return 0;
}