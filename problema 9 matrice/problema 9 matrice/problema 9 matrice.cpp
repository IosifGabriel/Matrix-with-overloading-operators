#include "pch.h"
#include <iostream>
#include "Matrix.h"
#include <fstream>

ifstream filein;

using namespace std;
int main()
{
	filein.open("matrix.in");
	Matrix m, n;
	filein >> m >> n;
	cout << "Matricele sunt:"<<endl;
	cout << m << endl << n;
	cout << "adunare:" << endl << m + n << endl;
	cout << "scadere:" << endl << m - n << endl;
	cout << "inmultire:" << endl << m * n << endl;
	cout << "-matrice:" << endl << -m << endl;

	cout << "matrice cu nr diferit de coloane si randuri"<<endl;
	Matrix p, q;
	filein >> p >> q;
	cout << "Matricele sunt:" << endl;
	cout << p << endl << q;
	cout << "adunare:" << endl << p + q << endl;
	cout << "scadere:" << endl << p - q << endl;
	cout << "inmultire:" << endl << p * q << endl;
	cout << "inmultire inversa i.e. din p*q in q*p" << endl << q * p << endl;
	cout << "-matrice:" << endl << -p << endl;


	cout << "rows si columns pentru o matrice" << endl;
	m.ReturnCols();
	m.ReturnRows();

	cout << "determinantul pentru " << endl << m << endl;
	m.Determinant();

	
	filein.close();
	return 0;
}