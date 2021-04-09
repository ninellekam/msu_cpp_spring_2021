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
				throw std::out_of_range("OUT RANGE\n");
			return RowsArray[index];
		}
		const int &operator[](int index) const {
			if (index >= len)
				throw std::out_of_range("OUT RANGE\n");
			return RowsArray[index];
		};
		Rows operator+(const Rows &row) const {
			Rows row_return(len);
			for(size_t i = 0; i < len; i++)
				row_return.RowsArray[i] = RowsArray[i] + row.RowsArray[i];
			return row_return;
		}
		friend std::ostream& operator<<(std::ostream &out, const Rows &row) {
			for(size_t i = 0; i < row.len; ++i)
				out << row.RowsArray[i] << std::endl;
			return out;
		}
};
	public:
		Matrix();
		~Matrix();
		Matrix(size_t rows, size_t columns);
		std::ostream& operator<<(std::ostream& out) {
			for(size_t i = 0; i < rows; i++)
				out << *(MyMatrix[i]) << std::endl;
			return out;
		}
		Rows **MyMatrix;
		Rows & operator[](size_t i);
		void FillMatrix(int elem);
		const Rows& operator[](std::size_t i) const;
		void operator*=(int num);
		bool operator==(const Matrix &matrix) const;
		bool operator!=(const Matrix &matrix) const;
		Matrix operator +(Matrix &obj) const;
		size_t getRows() const { return rows; }
		size_t getColumns() const { return columns; }
		friend std::ostream& operator<<(std::ostream &out, const Matrix &m) {
			for(size_t i = 0; i < m.rows; ++i)
				out << m.MyMatrix[i] << std::endl;
			return out;
		}
};

#endif