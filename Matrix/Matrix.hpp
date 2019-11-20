#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>

class Matrix {

public:
	Matrix(int size_);

	Matrix(Matrix const &matrix);

	~Matrix();

	int getMatrix(int m, int n) const;

	void setMatrix(int m, int n, int value);

	int getSize() const;

	friend std::ostream& operator<<(std::ostream& out, const Matrix& m);

	friend std::istream& operator>>(std::istream& in, Matrix& m);

	friend Matrix operator+(const Matrix& left, const Matrix& right);

	friend Matrix operator-(const Matrix& left, const Matrix& right);

	friend Matrix operator*(const Matrix& left, const Matrix& right);
	 
private:
	int size_;
	int** matrix_;
};

#endif