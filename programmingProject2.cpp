#include <iostream>
using namespace std;
class Polynomial
{
public:
	Polynomial() :size(1) //default constructor
	{coefficient = new double[1]; *coefficient = 0;};
	
	Polynomial(const Polynomial& a); //deep copy
	Polynomial(double* coef, int siz); //parameter is coefficients and size
	
	
	const double& operator[](int exp) const { return coefficient[exp]; } //[] overload, return specific coefficient
	const Polynomial& operator=(const Polynomial& rightSide);//assign to 
	int whatSize() { return size; }

	friend Polynomial operator+(const Polynomial& left, const Polynomial& right); //func+func
	friend Polynomial operator+(const Polynomial& left, const double d); //func+const
	friend Polynomial operator+(const double d, const Polynomial& right); //const+const

	friend Polynomial operator-(const Polynomial& left, const Polynomial& right); //func-func
	friend Polynomial operator-(const Polynomial& left, double d); //const-func
	friend Polynomial operator-(double d, const Polynomial& right); //const+func

	
	friend Polynomial operator*(const Polynomial& left, const Polynomial& right); //func*func
	friend Polynomial operator*(const Polynomial& left, double d); //func*const
	friend Polynomial operator*(double d, const Polynomial& right); //const*func
	double eval(double d); //return f(value)
	void print(); //print polynomial func

	~Polynomial() { delete[] coefficient; } //destructor
private:
	double* coefficient; 
	int size; // == degree+1
};

int main() 
{
	Polynomial Zero;
	cout << "Zero function\n";
	Zero.print();
	cout << '\n';
	double constant[] = { 3 };
	Polynomial Cons(constant, 1);
	cout << "Cons function\n";
	Cons.print();
	cout << '\n';
	double quad[] = { 2,5,1 };
	cout << "Quad function\n";
	Polynomial Quad(quad, 3);
	Quad.print();
	cout <<"Quad(3) = " << Quad.eval(3.0) << '\n' << '\n';
	double cubic[] = { 1,3,7,1 };
	Polynomial Cubic(cubic, 4);
	cout << "Cubic function\n";
	Cubic.print();
	cout << "Cubic(3) = " << Cubic.eval(3.0) << "\n\n";
	Polynomial A = Cubic; //copy
	cout << "A that copies Cubic function\n";
	A.print();
	cout << '\n';
	A = Quad + Cubic;
	cout << "new A that Cubic + Quad = ";
	A.print();
	cout <<"A(3) = " << A.eval(3.0) << endl<<endl;
	cout << "new A that 3 + Cubic = ";
	A = 3 + Cubic;
	A.print();
	cout << "new A that Cubic + 3 = ";
	A = Cubic + 3;
	A.print();
	cout << '\n';
	A = Cubic-Quad;
	cout << "new A that Cubic - Quad = ";
	A.print();
	cout << "A(3) = " << A.eval(3.0) << endl<<endl;
	cout << "new A that 3 - Cubic = ";
	A = 3 - Cubic;
	A.print();
	cout << "new A that Cubic - 3 = ";
	A = Cubic - 3;
	A.print();
	cout << '\n';
	cout << "new A that Cubic * Quad = ";
	A = Cubic * Quad;
	A.print();
	cout << "A(3) = " << A.eval(3.0) << endl<<endl;
	cout << "new A that 3 * Cubic = ";
	A = 3 * Cubic;
	A.print();
	cout << "new A that Cubic * 3 = ";
	A = Cubic * 3;
	A.print();


	return 0;
}

Polynomial::Polynomial(const Polynomial& a)
{
	size = a.size;
	coefficient = new double[size];
	for (int i = 0; i < size; i++)
	{
		coefficient[i] = a.coefficient[i];
	}
}
Polynomial::Polynomial(double* coef, int siz)
{
	size = siz;
	coefficient = new double[size];
	for (int i = 0; i < size; i++)
	{
		coefficient[i] = coef[i];
	}
}
const Polynomial& Polynomial::operator=(const Polynomial& rightSide)
{
	if (size != rightSide.size)
	{
		delete[] coefficient;
		size = rightSide.size;
		coefficient = new double[size];
	}
	for (int i = 0; i < size; i++)
	{
		coefficient[i] = rightSide[i];
	}
	return *this;
}
Polynomial operator+(const Polynomial& left, const Polynomial& right)
{
	int bigSize, smallSize;
	double* sumCoef;
	if (left.size >= right.size)
	{
		bigSize = left.size;
		smallSize = right.size;
		sumCoef = new double[bigSize];
		for (int i = 0; i < bigSize; i++)
		{
			sumCoef[i] = left[i];
		}
	}
	else
	{
		smallSize = left.size;
		bigSize = right.size;
		sumCoef = new double[bigSize];
		for (int i = 0; i < bigSize; i++)
		{
			sumCoef[i] = right[i];
		}
	}
	for (int i = 0; i < smallSize; i++)
	{
		sumCoef[i] = left[i] + right[i];
	}
	return Polynomial(sumCoef, bigSize);
}
Polynomial operator+(const Polynomial& left, double d)
{
	double* sumCoef = new double[left.size];
	sumCoef[0] = d + left[0];
	for (int i = 1; i < left.size; i++)
	{
		sumCoef[i] = left[i];
	}
	return Polynomial(sumCoef, left.size);
}
Polynomial operator+(double d, const Polynomial& right)
{
	double* sumCoef = new double[right.size];
	sumCoef[0] = d + right[0];
	for (int i = 1; i < right.size; i++)
	{
		sumCoef[i] = right[i];
	}
	return Polynomial(sumCoef, right.size);
}
Polynomial operator-(const Polynomial& left, const Polynomial& right)
{
	int bigSize, smallSize;
	double* difCoef;
	if (left.size >= right.size)
	{
		bigSize = left.size;
		smallSize = right.size;
		difCoef = new double[bigSize];
		for (int i = 0; i < bigSize; i++)
		{
			difCoef[i] = left[i];
		}
		for (int i = 0; i < smallSize; i++)
		{
			difCoef[i] -= right[i];
		}
		
	}
	else
	{
		smallSize = left.size;
		bigSize = right.size;
		difCoef = new double[bigSize];
		for (int i = 0; i < bigSize; i++)
		{
			difCoef[i] = -right[i];
		}
		for (int i = 0; i < smallSize; i++)
		{
			difCoef[i] += left[i];
		}
	}
	
	return Polynomial(difCoef, bigSize);
}
Polynomial operator-(const Polynomial& left, double d)
{
	double* difCoef = new double[left.size];
	difCoef[0] = left[0]-d;
	for (int i = 1; i < left.size; i++)
	{
		difCoef[i] = left[i];
	}
	return Polynomial(difCoef, left.size);
}
Polynomial operator-(double d, const Polynomial& right)
{
	double* difCoef = new double[right.size];
	difCoef[0] = d-right[0];
	for (int i = 1; i < right.size; i++)
	{
		difCoef[i] = -(right[i]);
	}
	return Polynomial(difCoef, right.size);
}
Polynomial operator*(const Polynomial& left, const Polynomial& right)
{
	int mulSize = left.size + right.size - 1;
	double* mulCoef = new double[mulSize];
	for (int i = 0; i < mulSize; i++)
	{
		mulCoef[i] = 0;
	}
	for (int i = 0; i < left.size; i++)
	{
		for (int j = 0; j < right.size; j++)
		{
			mulCoef[i + j] += left[i] * right[j];
		}
	}
	return Polynomial(mulCoef, mulSize);
}
Polynomial operator*(double d, const Polynomial& right)
{
	if (d == 0) // multifly 0
	{
		return Polynomial();
	}
	double* mulCoef = new double[right.size];
	for (int i = 0; i < right.size; i++)
	{
		mulCoef[i] = d * right[i];
	}
	return Polynomial(mulCoef, right.size);
}
Polynomial operator*(const Polynomial& left, double d)
{
	if (d == 0) // multifly 0
	{
		return Polynomial();
	}
	double* mulCoef = new double[left.size];
	for (int i = 0; i < left.size; i++)
	{
		mulCoef[i] = d * left[i];
	}
	return Polynomial(mulCoef, left.size);
}
void Polynomial::print() 
{
	for (int i = size - 1; i > 1; i--)
	{
		if (coefficient[i] == 1)
		{
			cout << "x^" << i << " + ";
			continue;
		}
		else if (coefficient[i] == 0)
		{
			continue;
		}
		cout << coefficient[i] << "x^" << i << " + ";
	}
	if (size >= 2) 
	{
		cout << coefficient[1] << "x + ";
	}
	cout << coefficient[0] << '\n';
}
double Polynomial::eval(double d)
{
	double result = coefficient[0];
	for (int i = 1; i < size; i++)
	{
		double k = 1;
		for (int j = 1; j <= i; j++)
		{
			k *= d;
		}
		result += k * coefficient[i];
	}
	return result;
}