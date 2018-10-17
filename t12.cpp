#include <iostream>  

int main()
{
    try{
	int a=3;
	int b = 0;
	int c;
	c=a/b;
	std::cout<<c<<std::endl;
    }
    catch(...)
    {
	std::cout<<"Exception"<<std::endl;
    }
    std::cout<<"End"<<std::endl;
}
