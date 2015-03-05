#include <iostream>
#include <string>

int main()
{
	bool iTRUE = true;
	bool iFALSE = false;
	std::cout << iTRUE << " ... " << iFALSE << std::endl;

	char x = 'x';
	char y = 'y';
	std::cout << x << " ... " << y << '\n';

	int one = 1;
	double twoPointFive = 2.5;
	std::cout << one << " ... " << twoPointFive << "\n";

	std::string yolo = "yolo";
	char yoloCStyle[] = "yolo";
	std::cout << yolo << " ... " << yoloCStyle << std::endl;

	std::cout << "END\n";
}
