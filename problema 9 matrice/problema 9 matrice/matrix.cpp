#include "pch.h"
#include <iostream>
#include "Matrix.h"
using namespace std;

Matrix::Matrix()//constructor of class Matrix 
{
/* 
initial voiam sa citesc ca Matrix M(3,3) si sa dau valori dar m-am razgandit
am lasat functia ca inainte si doar am modificat la 0 rows and cols ca la unii operatori 
cand trebuie sa returnez un obiect sa nu returneze "practic" nimic.
i.e. la "+" 
*/ 
	rows = 0;
	cols = 0;
	Mat = new int*[rows];
	if (Mat == nullptr)
	{
		cout << "memory could not be allocated for matrix";
	}
	else
	{
		for (int i = 0; i < rows; i++)
		{
			Mat[i] = new int[cols];
			if(Mat[i]==nullptr)
			{
				cout << "memory could not be allocated in matrix";
				break;
			}
		}

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				Mat[i][j] = 0;
	}
}


Matrix::Matrix(int row, int col)//constructor of class Matrix 
{
	/*
	pana la urma a trebuit sa fac si unul care primeste coloanele si randurile
	*/
	rows = row;
	cols = col;
	Mat = new int*[rows];
	if (Mat == nullptr)
	{
		cout << "memory could not be allocated for matrix";
	}
	else
	{
		for (int i = 0; i < rows; i++)
		{
			Mat[i] = new int[cols];
			if (Mat[i] == nullptr)
			{
				cout << "memory could not be allocated in matrix";
				break;
			}
		}

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				Mat[i][j] = 0;
	}
}

Matrix::Matrix(const Matrix &other)  //copy constructor
{
	this->cols = other.cols;
	this->rows = other.rows;
	this->Mat = new int*[other.rows];
	if (this->Mat == nullptr)
		cout << "memory could not be allocated for matrix";
	else
	{
		for (int i = 0; i < other.rows; i++)
		{
			this->Mat[i] = new int[other.cols];
			if (this->Mat[i] == nullptr)
			{
				cout << "memory coult not be allocated in matrix";
				break;
			}
		}
		for (int i = 0; i < other.rows; i++)
			for (int j = 0; j < other.cols; j++)
				this->Mat[i][j] = other[i][j];
	}
}


int* &Matrix::operator [](int const  &index)const
{
	return  Mat[index];
}


void Matrix::operator=(const Matrix &other)   // practic e copy constructorul
{	
	if (other.cols != 0 && other.rows != 0)  // daca sunt 0 inseamna ca atribui nimic si nu are sens
	{
		this->cols = other.cols;
		this->rows = other.rows;
		this->Mat = new int*[other.rows];
		if (this->Mat == nullptr)
			cout << "memory could not be allocated for matrix";
		else
		{
			for (int i = 0; i < other.rows; i++)
			{
				this->Mat[i] = new int[other.cols];
				if (this->Mat[i] == nullptr)
				{
					cout << "memory coult not be allocated in matrix";
					break;
				}
			}
			for (int i = 0; i < other.rows; i++)
				for (int j = 0; j < other.cols; j++)
					this->Mat[i][j] = other[i][j];
		}
	}



}


Matrix  Matrix::operator-()const
{
	Matrix temp(this->rows, this->cols);

	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++)
			temp.Mat[i][j] = this->Mat[i][j] * -1;
	return temp;
}


Matrix  Matrix::operator +(const Matrix &t)const  //add 2 matrix
{
	Matrix temp;
		if (this->rows == t.rows && this->cols == t.cols)
		{
			temp = t;
			for (int i = 0; i < this->rows; i++)
				for (int j = 0; j < this->cols; j++)
					temp.Mat[i][j] = t.Mat[i][j] + this->Mat[i][j];
			return temp;
		}
    
		cout << "matrix could not be added, different sizes!!!! try again!!";
		return temp; // nu contine nimic aici
}


Matrix  Matrix::operator *(const Matrix &t)const//multiplay matrix on the right
{
	if (this->rows != t.cols)
	{
		Matrix temp;
			cout << "matrix could not be multiplied because of different columns- rows size!!";
		return temp;
	}
	else
	{
		Matrix temp(this->rows, t.cols);

		for (int i = 0; i < this->rows; i++)
			for (int j = 0; j < t.cols; j++)
				for (int k = 0; k < this->cols; k++)
					temp[i][j] += this->Mat[i][k] * t.Mat[k][j];
		return temp;
	}

}

Matrix  Matrix::operator *(const int &num)const //multiply with number
{
	Matrix temp(this->rows, this->cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			temp.Mat[i][j] = this->Mat[i][j] * num;
	return temp;
}

Matrix  Matrix::operator -(const Matrix &t)const //matrix subtraction 
{
	Matrix temp;
	if (this->rows != t.rows || this->cols != t.cols)
	{
		cout << "could not substract matrix!! they're different size!!! try again!!";
		return temp;
	}
	else
	{
		temp = t;
		for (int i = 0; i < this->rows; i++)
			for (int j = 0; j < this->cols; j++)
				temp.Mat[i][j] = this->Mat[i][j] - t.Mat[i][j];
		return temp;
	}
	
}


Matrix::~Matrix()//destrucor 
{
	
	for (int i = 0; i < this->rows; i++)
		delete[] this->Mat[i];
	delete[] this->Mat;

}