#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

template <typename T>
class MATRIX {
public:
	MATRIX(const int& row, const int& col):row(row),col(col)
	{
		p = new T[row*col];
	}
	//MATRIX(){}
	~MATRIX()
	{
		delete p;
		p=NULL;
	}
	T& operator()(const int& i, const int& j)
	{
		return p[i*col+j];
	}
	void show()
	{
		for(int i=0;i<row;i++)
		{
			for(int j =0; j<col;j++)
				cout<<p[i*col+j]<<" ";
			cout<<endl;
		}
	}
	int Rows(){ return row;}
	int Cols(){ return col;}

private:
	T * p=NULL;
	int row,col;
};




int main()
{
	MATRIX<double> mat(4,4);

	for(int i = 0; i<mat.Rows(); i++)
		for(int j =0; j<mat.Cols(); j++)
			mat(i,j) = i>j?j:i;

	mat.show();

	return 0;
}

