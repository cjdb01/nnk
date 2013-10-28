#include "som.h"

#include <fstream>

int main()
{
	std::ifstream in("data24.txt", std::ios::in);
    pipe::kohonen<> k(in);
}