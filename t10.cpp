#include <iostream>
using namespace std;

namespace xx{
	class A{
	public:
		void show();
	};

}



int main()
{
	using namespace xx;
	A a;
	a.show();
}

namespace xx{
	void A::show()
	{
		cout<<"hi"<<endl;
	}
}