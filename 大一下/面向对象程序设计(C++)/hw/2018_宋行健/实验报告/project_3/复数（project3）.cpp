#include <iostream>
using namespace std;

class Complex
{
	// 默认为私有变量private
	double real;
	double imaginary;
public:
	//默认构造函数将复数初始化为0+0i
	Complex()
	{
		real = 0;
		imaginary = 0;
	}

	//将对象的成员变量设置为任何值
	void set(double re,double imag)
	{
		imaginary = imag;
		real = re;
	}

	//将对象初始化为实变量+0*i
	void set(double re)
	{
		imaginary = 0;
		real = re;
	}

	// 调用实部
	double get_Real(void)
	{
		return real;
	}

	// 调用虚部
	double get_Imaginary(void)
	{
		return imaginary;
	}

	// 重载 + 运算符，用于把两个 Complex 对象相加
	Complex operator+(const Complex& data)
	{
		Complex complex_num;
		complex_num.real = this->real + data.real;
		complex_num.imaginary = this->imaginary + data.imaginary;
		return complex_num;
	}

	// 重载 - 运算符，用于把两个 Complex 对象相减
	Complex operator-(const Complex& data)
	{
		Complex complex_num;
		complex_num.real = this->real - data.real;
		complex_num.imaginary = this->imaginary - data.imaginary;
		return complex_num;
	}

	// 重载 * 运算符，用于把两个 Complex 对象相乘
	Complex operator*(const Complex& data)
	{
		Complex complex_num;
		complex_num.real = this->real * data.real - this->imaginary * data.imaginary;
		complex_num.imaginary = this->imaginary * data.real + this->real * data.imaginary;
		return complex_num;
	}

	// 重载 == 运算符，用于比较两个 Complex 对象
	bool operator ==(const Complex& data)
	{
		//Complex complex_num;  【注意：关系运算符的重载，这里不需要定义结果变量】
		if (this->real == data.real && this->imaginary == data.imaginary)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// 重载 >> 运算符，用于比较两个 Complex 对象
	bool operator >>(const Complex& data)
	{
		if (this->real > data.real)
		{
			return true;
		}
		else if (this->real == data.real)
		{
			if (this->imaginary > data.imaginary)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	// 重载 << 运算符，用于比较两个 Complex 对象
	bool operator <<(const Complex& data)
	{
		if (this->real < data.real)
		{
			return true;
		}
		else if (this->real == data.real)
		{
			if (this->imaginary < data.imaginary)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	// 展示所输入的复数
	void show()	
	{
		cout << "You Input:\t" << get_Real() << " + " << get_Imaginary() << " * i" << endl;
	}

};


int main()
{
	Complex i;
	i.set(0, 1);			//初始化i为0+1i		

	Complex complex_1;                // 声明 Complex_1，类型为 Complex
	Complex complex_2;                // 声明 Complex_2，类型为 Complex
	Complex complex_result;           // 声明 Complex_result，类型为 Complex
	double real, imaginary;           // 声明double类型的复数的两个组成部分
	
	// Complex_1 赋值为纯实数类型（只有一个参数，为实部）
	cout << "Please intput the second complex number (One Parameter):" << endl;
	cin >> real;
	complex_1.set(real);		// 形成调用Complex类型私有变量的端口
	complex_1.show();		// 展示所输入的虚数
	
	// Complex_2 赋值为复数数类型（有两个参数，一个为实部，另一个为虚部）
	cout << "\nPlease intput the first complex number (Two Parameters):" << endl;
	cin >> real >> imaginary;
	complex_2.set(real, imaginary);		// 形成调用Complex类型私有变量的端口
	complex_2.show();		// 展示所输入的虚数

	// 把两个对象相加
	complex_result = complex_1 + complex_2;
	cout << "\n加法：" << endl;
	cout << "("<<complex_1.get_Real() << " + " << complex_1.get_Imaginary() << " * i ) + (" << complex_2.get_Real() << " + " << complex_2.get_Imaginary() << " * i ) == (" << complex_result.get_Real() << " + " << complex_result.get_Imaginary() << " * i )" << endl;

	// 把两个对象相减
	complex_result = complex_1 - complex_2;
	cout << "\n减法：" << endl;
	cout << "(" << complex_1.get_Real() << " + " << complex_1.get_Imaginary() << " * i ) - (" << complex_2.get_Real() << " + " << complex_2.get_Imaginary() << " * i ) == (" << complex_result.get_Real() << " + " << complex_result.get_Imaginary() << " * i )" << endl;

	// 把两个对象相乘
	cout << "\n乘法：" << endl;
	complex_result = complex_1 * complex_2;
	cout << "(" << complex_1.get_Real() << " + " << complex_1.get_Imaginary() << " * i ) * (" << complex_2.get_Real() << " + " << complex_2.get_Imaginary() << " * i ) == (" << complex_result.get_Real() << " + " << complex_result.get_Imaginary() << " * i )" << endl;

	// 把两个对象相比较
	cout << "\n比大小：" << endl;
	if (complex_1 << complex_2)
	{
		cout << "(" << complex_1.get_Real() << " + " << complex_1.get_Imaginary() << " * i ) < (" << complex_2.get_Real() << " + " << complex_2.get_Imaginary() << " * i )" << endl;
	}
	else if (complex_1 >> complex_2)
	{
		cout << "(" << complex_1.get_Real() << " + " << complex_1.get_Imaginary() << " * i ) > (" << complex_2.get_Real() << " + " << complex_2.get_Imaginary() << " * i )" << endl;
	}
	else
	{
		cout << "(" << complex_1.get_Real() << " + " << complex_1.get_Imaginary() << " * i ) == (" << complex_2.get_Real() << " + " << complex_2.get_Imaginary() << " * i )" << endl;
	}

	return 0;
}