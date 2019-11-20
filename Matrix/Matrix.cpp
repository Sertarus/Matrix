#include "Matrix.hpp"
#include <iostream>

using namespace std;

Matrix::Matrix(int size_) {
	this->matrix_ = new int* [size_];
	for (int i = 0; i < size_; i++) {
		this->matrix_[i] = new int[size_];
		for (int j = 0; j < size_; j++)
			this->matrix_[i][j] = 0;
	}
	this->size_ = size_;
}

Matrix::Matrix(Matrix const &matrix) {
	this->matrix_ = new int* [matrix.size_];
	for (int i = 0; i < matrix.size_; i++) {
		this->matrix_[i] = new int[matrix.size_];
		for (int j = 0; j < matrix.size_; j++)
			this->matrix_[i][j] = matrix.matrix_[i][j];
	}
	this->size_ = matrix.size_;
}

Matrix::~Matrix() {
	for (int i = 0; i < this->size_; i++)
		delete[] matrix_[i];
	delete[] matrix_;
}

int Matrix::getSize() const {
	return this->size_;
}

int Matrix::getMatrix(int m, int n) const {
	try {
		if (m >= this->size_ || n >= this->size_ || m < 0 || n < 0)
			throw "Index Out Of Bounds";
		return this->matrix_[m][n];
	}
	catch (const char* err) {
		cerr << err;
	}
	return 0;
}

void Matrix::setMatrix(int m, int n, int value) {
	try {
		if (m >= this->size_ || n >= this->size_ || m < 1 || n < 1)
			throw "Exception: Index Out Of Bounds";
		matrix_[m - 1][n - 1] = value;
	}	
	catch (const char* err) {
		cerr << err;
	}
}

Matrix operator+(const Matrix& left, const Matrix& right) {
	try {
		if (left.size_ != right.size_) {
			throw "Exception: Different Matrix Sizes";
		}
		Matrix new_matrix(left.size_);
		for (int i = 0; i < new_matrix.getSize(); i++) {
			for (int j = 0; j < new_matrix.getSize(); j++) {
				new_matrix.matrix_[i][j] = left.matrix_[i][j] + right.matrix_[i][j];
			}
		}
		return new_matrix;
	}
	catch (const char* err) {
		cerr << err;
	}
}

Matrix operator-(const Matrix& left, const Matrix& right) {
	try {
		if (left.size_ != right.size_) {
			throw "Exception: Different Matrix Sizes";
		}
		Matrix new_matrix(left.size_);
		for (int i = 0; i < new_matrix.size_; i++) {
			for (int j = 0; j < new_matrix.size_; j++) {
				new_matrix.matrix_[i][j] = left.matrix_[i][j] - right.matrix_[i][j];
			}
		}
		return new_matrix;
	}
	catch (const char* err) {
		cerr << err;
	}
}

Matrix operator*(const Matrix& left, const Matrix& right) {
	try {
		if (left.size_ != right.size_) {
			throw "Exception: Different Matrix Sizes";
		}
		Matrix new_matrix(left.size_);
		for (int i = 0; i < new_matrix.size_; i++) {
			for (int j = 0; j < new_matrix.size_; j++) {
				for (int k = 0; k < new_matrix.size_; k++) {
					new_matrix.matrix_[i][j] += left.matrix_[i][k] * right.matrix_[k][j];
				}
			}
		}
		return new_matrix;
	}
	catch (const char* err) {
		cerr << err;
	}
}

ostream& operator<<(ostream& out, const Matrix& m) {
	for (int i = 0; i < m.getSize(); i++) {
		for (int j = 0; j < m.getSize(); j++) {
			cout << m.getMatrix(i, j) << " ";
		}
		cout << endl;
	}
	return out;
}

istream& operator>>(istream& in, Matrix& m) {
	for (int i = 0; i < m.size_; i++)
		for (int j = 0; j < m.size_; j++) {
			cout << "a[" << i + 1 << "," << j + 1 << "]: ";
			in >> m.matrix_[i][j];
		}
	return in;
}
