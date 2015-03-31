#include <iostream>
#include <string>

void printFramedString(std::string str, char framech = '*', std::ostream& outs = std::cout);

int main(int argc, char **argv)
{
	std::string myName;

	if (argc <= 1) {
		std::cout << "Enter your name:" << std::endl;
		std::getline(std::cin, myName);
	} else {
		for (int i = 1; i < argc; ++i) {
			myName.append(argv[i]);
			if (i < argc -1) {
				myName.append(" ");
			}
		}
	}

	printFramedString(myName);

	printFramedString(myName, '\'');

	return 0;
}

void printFramedString(std::string str, char framech, std::ostream& outs)
{
	int strsize = str.size();
	for (int i = 0; i < strsize + 4; ++i) {
		outs << framech;
	}
	outs << '\n';
	outs << framech << ' ' << str << ' ' << framech << '\n';
	for (int i = 0; i < strsize + 4; ++i) {
		outs << framech;
	}
	outs << std::endl;
}
