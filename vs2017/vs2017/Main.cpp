#include <iostream>

int Multiply(int a, int b)
{
	return a * b;
}

int main()
{
	std::cout << Multiply(5,6) << std::endl;
	std::cin.get();
}