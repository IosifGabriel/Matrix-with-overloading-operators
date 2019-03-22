#pragma once
#ifndef Matrix_h
#define Matrix_h
#include <iostream>
using namespace std;


class Matrix
{
private:
	int rows;
	int cols;
	int **Mat;


public:
	Matrix();
	Matrix(int row, int col);
	Matrix(const Matrix &other);
	~Matrix();
	int* &operator[](int const &index)const;
	void operator=(const Matrix &otherM);
	Matrix  operator -()const;
	Matrix  operator-(const Matrix &t) const;
	Matrix  operator+(const Matrix &t)const;
	Matrix  operator*(const Matrix &t)const;
	Matrix  operator*(const int &num)const;
	
	void ReturnCols()
	{
		cout << cols << endl;
	}
	void ReturnRows()
	{
		cout << rows << endl;
	}

	void Determinant()
	{
		if (rows != cols)
			cout << "it hasnt got any determinant because rows != cols";
		else
		{
			if (cols == rows && rows == 1)
				cout << Mat[0][0];
			else if (cols == rows && rows == 2) 
				cout << (Mat[0][0] * Mat[1][1]) - (Mat[1][0] * Mat[0][1]) << endl;
			else if (cols == rows && rows == 3)
				cout << Mat[0][0] * Mat[1][1] * Mat[2][2] + Mat[0][1] * Mat[1][2] * Mat[2][0] + Mat[0][2] * Mat[1][0] * Mat[2][1] - Mat[2][0] * Mat[1][1] * Mat[0][2] - Mat[2][1] * Mat[1][2] * Mat[0][0] - Mat[2][2] * Mat[1][0] * Mat[0][1]<<endl;
		}
	}


	friend std::ostream &operator<<(std::ostream &os, const Matrix &m) 
	{
		for (int i = 0; i < m.rows; i++) 
		{
			for (int j = 0; j < m.cols; j++) 
			{
				os << m.Mat[i][j] << "  ";
			}
			os << '\n';
		}
		return os;
	}

	friend std::istream &operator>>(std::istream &is, Matrix &m)
	{
		is >> m.rows >> m.cols;
		m.Mat = new int *[m.rows];
		if (m.Mat == nullptr)
		{
			cout << "Memory could not be allocated for matrix";
		}
		else
		{
			for (int i = 0; i < m.rows; i++)
			{
				m.Mat[i] = new int[m.cols];
				if (m.Mat[i] == nullptr)
				{
					cout << "Memory could not be allocated in matrix";
					break;
				}
			}

			for (int i = 0; i < m.rows; i++)
				for (int j = 0; j < m.cols; j++)
					is >> m.Mat[i][j];
		}

		return is;
	}
};
#endif // !Matrix.h


