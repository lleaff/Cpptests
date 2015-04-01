#include <iostream>
#include <string>

void printFramedString(std::string str, char framech = '*', int padding = 1, std::ostream& outs = std::cout);

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

	printFramedString(myName, '$', 5);

	return 0;
}

void printFramedString(std::string str, char framech, int padding, std::ostream& outs)
{
	int strsize = str.size();
	outs << std::string(strsize + padding*2 + 2, framech) << '\n';
	outs << framech << std::string(strsize + padding*2, ' ') << framech << '\n';
	outs << framech << std::string(padding, ' ') << str << std::string(padding, ' ') << framech << '\n';
	outs << framech << std::string(strsize + padding*2, ' ') << framech << '\n';
	outs << std::string(strsize + padding*2 + 2, framech) << '\n';
	outs << std::endl;
}
