#include <iostream>

int main()
{
	std::cout<< (false && true || true )<<std::endl;
	std::cout<< (true || true && false )<< std::endl;
	return 0;
}