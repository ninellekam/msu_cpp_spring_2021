#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>

class Matrix {
	size_t rows;
	size_t columns;
	class Rows {
			size_t len;
			int *RowsArray;
			public:
				Rows(size_t len): len(len) {
						RowsArray = new int[len];
				}
				~Rows() { delete [] RowsArray; };
				int &operator[] (int index) {
					if (index >= len)
						throw std::out_of_range("Out of range");
					return RowsArray[index];
				}
				const int &operator[](int index) const {
					if (index >= len)
						throw std::out_of_range("Out of range");
					return RowsArray[index];
				};
	};
	public:
		Matrix();
		~Matrix();
		Matrix(size_t rows, size_t columns);
		Rows **MyMatrix;
		Rows & operator[](size_t i);
		void FillMatrix(int elem);
		const Rows& operator[](std::size_t i) const;
		void operator*=(int num);
		bool operator==(const Matrix &matrix) const;
		bool operator!=(const Matrix &matrix) const;
		size_t getRows() const { return rows; }
		size_t getColumns() const { return columns; }
};

#endif