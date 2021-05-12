#include <iostream>
using namespace std;
class soPhuc{
private:
	int phanthuc;
	int phanao;
public:
	void nhap()
	{
		cout << "Nhap phan thuc: "; cin >> this->phanthuc;
		cout << "Nhap phan ao: "; cin >> this->phanao;
	}
	void in()
	{
		cout << "Phan thuc: " << this->phanthuc << "   Phan ao: " << this->phanao << endl; 
	}
	soPhuc operator+(const soPhuc &x)
	{
		soPhuc c;
		c.phanthuc = x.phanthuc + this->phanthuc;
		c.phanao = x.phanao + this->phanao;
		return c;
	}
	soPhuc operator-(const soPhuc&x)
	{
		soPhuc c;
		c.phanthuc = this->phanthuc - x.phanthuc;
		c.phanao = this->phanao - x.phanao;
		return c;
	}
	soPhuc operator*(const soPhuc&x)
	{
		soPhuc c;
		c.phanthuc = this->phanthuc*x.phanthuc - this->phanao*x.phanao;
		c.phanao = this->phanthuc*x.phanao + this->phanao*x.phanthuc;
		return c;
	}
	soPhuc operator/(const soPhuc&x)
	{
		soPhuc c;
		c.phanthuc = (this->phanthuc*x.phanthuc + this->phanao*x.phanao) / (x.phanthuc*x.phanthuc + x.phanao*x.phanao);
		c.phanao = (x.phanthuc*this->phanao - this->phanthuc*x.phanao) / (x.phanthuc*x.phanthuc + x.phanao*x.phanao);
		return c;
	}

};
int main()
{
	soPhuc a, b;
	cout << "Nhap thong tin so phuc a:"; 
	a.nhap();
	cout << "Nhap thong tin so phuc b:"; 
	b.nhap();
	soPhuc c=a+b;
	soPhuc d = a - b;
	soPhuc e = a*b;
	soPhuc f = a / b;
	cout << "Cong: " << endl; c.in();
	cout << "Tru: " << endl; d.in();

	cout << "Nhan: " << endl; e.in();
	cout << "Chia: " << endl; f.in();
}
