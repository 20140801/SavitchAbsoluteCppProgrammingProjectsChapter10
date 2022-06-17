#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
class TwoD
{
public:
	TwoD(); //default constructor
	TwoD(int row, int col);
	TwoD(const TwoD& matrix); //deep copy constructor
	~TwoD(); //destructor
	double& retValue(const int row, const int col) const
	{if (row <= MaxRows && col <= MaxCols && row >= 0 && col >= 0) { {return arr[row - 1][col - 1]; } }}
	void setValue(const int row, const int col, const double val) { arr[row][col] = val; }
	const TwoD& operator=(const TwoD& rightSide); // = overloading
	friend TwoD operator+(const TwoD& alpha, const TwoD& beta); //+ overloading
	void print() const; //print matrix
private:
	int MaxRows;
	int MaxCols;
	double** arr;
};
int main() 
{
	int maxRow, maxCol;
	double temp;
	cout << "Enter Matrix 1 row and column dimensions of the array:\n";
	cin >> maxRow >> maxCol;
	TwoD mat1(maxRow, maxCol);
	cout << "Enter Matrix 1 values:\n";
	for (int i = 0; i < maxRow; i++)
	{
		for (int j = 0; j < maxCol; j++)
		{
			cin >> temp;
			mat1.setValue(i, j, temp);
		}
	}
	cout << "Enter Matrix 2 row and column dimensions of the array:\n";
	cin >> maxRow >> maxCol;
	TwoD mat2(maxRow, maxCol);
	cout << "Enter Matrix 2 values:\n";
	for (int i = 0; i < maxRow; i++)
	{
		for (int j = 0; j < maxCol; j++)
		{
			cin >> temp;
			mat2.setValue(i, j, temp);
		}
	}
	cout << "Echoing Matrix 1:\n";
	mat1.print();
	cout << "Echoing Matrix 2:\n";
	mat2.print();
	cout << "Adding Matrix 1 and Matrix 2:\n";
	TwoD mat3 = mat1 + mat2;
	mat3.print();
	cout << "If you enter Matrix 3's row and column, than I will give you value\n";
	int r, c;
	cin >> r >> c;
	cout << '\n' << mat3.retValue(r, c);
	return 0;
}

TwoD::TwoD()
{
	MaxRows = 10;
	MaxCols = 10;
	arr = new double* [MaxRows];
	for (int i = 0; i < MaxRows; i++)
	{
		arr[i] = new double[MaxCols];
	}
	for (int i = 0; i < MaxRows; i++)
		for (int j = 0; MaxCols; j++)
			arr[i][j] = 0;
}
TwoD::TwoD(int row, int col)
{
	MaxRows = row;
	MaxCols = col;
	arr = new double* [MaxRows];
	for (int i = 0; i < MaxRows; i++)
	{
		arr[i] = new double[MaxCols];
	}
}
TwoD::TwoD(const TwoD& matrix)
{
	MaxRows = matrix.MaxRows;
	MaxCols = matrix.MaxCols;
	arr = new double* [MaxRows];
	for (int i = 0; i < MaxRows; i++)
	{
		arr[i] = new double[MaxCols];
	}
	for (int i = 0; i < MaxRows; i++)
	{
		for (int j = 0; j < MaxCols; j++)
		{
			arr[i][j] = matrix.arr[i][j];
		}
	}
}


void TwoD::print() const
{
	for (int i=0; i < MaxRows; i++)
	{
		for (int j = 0; j < MaxCols; j++)
		{
			cout << left << setw(7) << arr[i][j];
		}
		cout << '\n';
	}
}
const TwoD& TwoD::operator =(const TwoD& rightSide)
{
	if ((MaxRows != rightSide.MaxRows)||(MaxCols != rightSide.MaxCols))
	{
		for (int i = 0; i < MaxRows; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
		arr = new double* [rightSide.MaxRows];
		for (int i = 0; i < rightSide.MaxRows; i++)
		{
			arr[i] = new double[rightSide.MaxCols];
		}
	}
	MaxRows = rightSide.MaxRows;
	MaxCols = rightSide.MaxCols;
	for (int i = 0; i < MaxRows; i++)
	{
		for (int j = 0; j < MaxCols; j++)
		{
			arr[i][j] = rightSide.arr[i][j];
		}
	}
	return *this;
}
TwoD operator +(const TwoD& alpha, const TwoD& beta)
{
	if (alpha.MaxRows != beta.MaxRows)
	{
		cout << "Matrix 1 and Matrix 2 rows are not same\n";
		exit(1);
	}
	if (alpha.MaxCols != beta.MaxCols)
	{
		cout << "Matrix 1 and Matrix 2 columns are not same\n";
		exit(1);
	}
	TwoD* Added = new TwoD(alpha.MaxRows, alpha.MaxCols);
	for (int i = 0; i < Added->MaxRows; i++)
	{
		for (int j = 0; j < Added->MaxCols; j++)
		{
			Added->arr[i][j] = alpha.arr[i][j] + beta.arr[i][j];
		}
	}
	return *Added;
}
 TwoD::~TwoD()
{
	for (int i = 0; i < MaxRows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}