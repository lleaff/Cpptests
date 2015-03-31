#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	std::string myName;

	if (argc <= 1) {
		std::cout << "Enter your name:" << std::endl;
		std::cin >> myName;
	} else {
		for (int i = 1; i < argc; ++i) {
			myName.append(argv[i]);
			if (i < argc -1) {
				myName.append(" ");
			}
		}
	}

	std::cout << "Name: " << myName << std::endl;

	return 0;
}
