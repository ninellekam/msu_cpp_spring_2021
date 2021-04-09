#include "Matrix.hpp"

const Matrix::Rows& Matrix::operator[](size_t i) const {
	if (i >= rows)
		throw std::out_of_range("OUT RANGE\n");
	return *MyMatrix[i];
}

Matrix::Rows& Matrix::operator[](size_t i) {
	if (i >= rows)
		throw std::out_of_range("OUT RANGE\n");
	return *MyMatrix[i];
}

void Matrix::FillMatrix(int elem) {
	std::cout << this->rows << " " << this->columns;
	for (size_t i = 0; i < this->rows; ++i)
		for (size_t j = 0; j < this->columns; ++j)
			(*MyMatrix)[i][j] = elem;
}

Matrix::Matrix(size_t rows, size_t columns): rows(rows), columns(columns) {
	try {
		MyMatrix = new Rows*[rows];
	}
	catch(std::bad_alloc& error) {
		throw error;
	}
	for (size_t i = 0; i < rows; ++i) {
		try {
			MyMatrix[i] = new Rows(columns);
		}
		catch(std::bad_alloc& error) {
			for (size_t j = 0; j < i; ++j)
				delete MyMatrix[j];
			delete[] MyMatrix;
			throw error;
		}
	}
}

void Matrix::operator*=(int elem) {
	for (size_t i = 0; i < rows; ++i)
		for (size_t j = 0; j < columns; ++j)
			(*MyMatrix)[i][j] *= elem;
}

bool Matrix::operator==(const Matrix& obj) const {
	if (this == &obj)
		return true;
	if (obj.getColumns() != columns || obj.getRows() != rows)
		return false;
	for (size_t i = 0; i < rows; ++i)
		for (size_t j = 0; j < columns; ++j)
			if ((*MyMatrix)[i][j] != obj[i][j])
				return false;
	return true;
}

bool Matrix::operator!=(const Matrix& obj) const {
	if (*this == obj)
		return false;
	else
		return true;
}

Matrix::~Matrix() {
	for (size_t j = 0; j < rows; ++j)
		delete MyMatrix[j];
	delete[] MyMatrix;
}