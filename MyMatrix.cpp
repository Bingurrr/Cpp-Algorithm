#include <iostream>
#include "MyMatrix.h"

// Constructor
myMatrix::myMatrix(int nRows, int nCols) : rows(nRows), cols(nCols), pData(NULL)
{
	allocateMemory();
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			pData[i][j];
}
myMatrix::myMatrix(int nRows, int nCols, int initValue) : rows(nRows), cols(nCols), pData(NULL)
{
	allocateMemory();
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			pData[i][j] = initValue;
}
myMatrix::myMatrix(int nRows, int nCols, int* data) : rows(nRows), cols(nCols), pData(NULL)
{
	allocateMemory();
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			pData[i][j] = data[i * cols + j];
}
myMatrix::myMatrix(int nRows, int nCols, int** data) : rows(nRows), cols(nCols), pData(NULL)
{
	allocateMemory();
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			pData[i][j] = data[i][j];
}
myMatrix::~myMatrix()
{
	if (pData != NULL)
		deleteMemory();
}
// Copy constructor
myMatrix::myMatrix(const myMatrix& mat) :
	rows(mat.rows), cols(mat.cols), pData(NULL)
{
	allocateMemory();
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			pData[i][j] = mat.pData[i][j];
}
// Accessor functions
int myMatrix::getRows() const
{
	return rows;
}
int myMatrix::getCols() const
{
	return cols;
}
int* myMatrix::operator [](int i) const
{
	if ((i < 0) || (i >= rows))
		errorMessage("Accessing out-of-bound value of a matrix");
	return pData[i];
}
int& myMatrix::operator ()(int i, int j) const
{
	if ((i < 0) || (i >= rows) || (j < 0) || (j >= cols))
		errorMessage("Accessing out-of-bound value of a matrix");
	return pData[i][j];
}
// Overloaded binary operators
myMatrix myMatrix::operator +(const myMatrix& mat) const
{
	if ((rows != mat.rows) || (cols != mat.cols))
		errorMessage("operator +(const myMatrix& mat) const");
	myMatrix ret(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			ret.pData[i][j] = mat.pData[i][j] + pData[i][j];
		}
	}
	return ret;
}
myMatrix myMatrix::operator -(const myMatrix& mat) const
{
	if ((rows != mat.rows) || (cols != mat.cols))
		errorMessage(":operator -(const myMatrix& mat) const");
	myMatrix ret(rows, cols);
	for (int i = 0; i <rows; i++) {
		for (int j = 0; j < cols; j++) {
			ret.pData[i][j] = pData[i][j] - mat.pData[i][j];
		}
	}
	return ret;
}
myMatrix myMatrix::operator *(const myMatrix& mat) const
{
	if (cols != mat.rows)
		errorMessage("operator *(const myMatrix& mat) const");
	myMatrix ret(cols, mat.rows);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < mat.cols; j++)
			for (int k = 0; k < cols; k++)
				ret[i][j] += pData[i][k] * mat.pData[i][j];
	return ret;
}

myMatrix myMatrix::operator *(int value) const
{
	myMatrix ret(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			ret[i][j] = pData[i][j]*value;
		}
	}
	return ret;
}
// Assignment operators
myMatrix& myMatrix::operator =(const myMatrix& mat)
{
	if (&mat == this)
		return *this;
	return *this;
}
myMatrix& myMatrix::operator +=(const myMatrix& mat)
{
	if ((rows != mat.rows) || (cols != mat.cols))
		errorMessage("operator +=(const myMatrix& mat)");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			pData[i][j] = mat.pData[i][j] + pData[i][j];
		}
	}
	return *this;
}
myMatrix& myMatrix::operator -=(const myMatrix& mat)
{
	if ((rows != mat.rows) || (cols != mat.cols))
		errorMessage("operator -=(const myMatrix& mat)");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			pData[i][j] = pData[i][j] - mat.pData[i][j];
		}
	}
	return *this;
}
myMatrix& myMatrix::operator *=(const myMatrix& mat)
{
	if (cols != mat.rows)
		errorMessage("operator *=(const myMatrix& mat)");
	int s = 0;
	int t = 0;
	for (int r = 0; r < rows * mat.cols; r++) {
		if (t == mat.cols) {
			s++;
			t = 0;
		}
		for (int i = 0; i < cols; i++) {
			pData[s][t] += pData[s][i] * mat.pData[i][t];
		}
		t++;
	}
	return *this;
}
myMatrix& myMatrix::operator *=(int value)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			pData[i][j] = pData[i][j]*value;
		}
	}
	return *this;
}
bool myMatrix::operator ==(const myMatrix& mat) const
{
	if ((rows != mat.rows) || (cols != mat.cols))
		return false;
}
bool myMatrix::operator !=(const myMatrix& mat) const
{
	return !((*this) == mat);
}
// Overloaded unary operators
myMatrix myMatrix::operator -() const // unary minus
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			pData[i][j] = pData[i][j] * (-1);
		}
	}
	return *this;
}
// transpose the matrix
myMatrix& myMatrix::transpose()
{
	myMatrix ret(cols, rows);
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			ret.pData[i][j] = pData[j][i];
		}
	}
	return ret;
}
// private functions
void myMatrix::allocateMemory()
{
	if (pData != NULL)
		deleteMemory();
	pData = new int* [rows];
	if (pData == NULL)
		errorMessage("Memory allocation error");
	pData[0] = new int[rows * cols];
	if (pData[0] == NULL)
	{
		delete[] pData;
		errorMessage("Memory allocation error");
	}
	for (int i = 1; i < rows; i++)
		pData[i] = pData[0] + i * cols;
}
void myMatrix::deleteMemory()
{
	delete[] pData[0];
	delete[] pData;
	pData = NULL;
}
void myMatrix::errorMessage(string str) const
{
	cout << "Error: " << str << endl;
	exit(1);
}
// friend functions
myMatrix operator *(int value, const myMatrix& mat)
{
	myMatrix ret(mat.rows, mat.cols);
	for (int i = 0; i < mat.rows; i++) {
		for (int j = 0; j < mat.cols; j++) {
			ret.pData[i][j] = mat.pData[j][i]*value;
		}
	}
	return ret;
}
ostream& operator <<(ostream& outStream, const myMatrix& mat)
{
	outStream << mat.rows << "*" << mat.cols << endl;
	for (int i = 0; i < mat.rows; i++)
	{
		for (int j = 0; j < mat.cols; j++)
			outStream << mat[i][j] << " ";
		outStream << endl;
	}
	return outStream;
}
istream& operator >>(istream& inStream, myMatrix& mat)
{
	mat.deleteMemory();
	inStream >> mat.rows >> mat.cols;
	mat.allocateMemory();
	for (int i = 0; i < mat.rows; i++)
	{
		for (int j = 0; j < mat.cols; j++)
			inStream >> mat[i][j];
	}
	return inStream;
}