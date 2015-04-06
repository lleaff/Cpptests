#include <iostream>
#include <cstdlib>

const char programName[] = "./fullNameReverser";
#define MAXNAMELENGTH 50
const char testStr[][MAXNAMELENGTH] = {
	  "Iz Mael Chiki Tak"
	, "MERLIN Paul"
	, "JACKELINE SHAZBOT"
	, "Bertrand LEBLANC DeSonNom"
};

bool isInt(char *cstr)
{
	while (*cstr == ' ' || *cstr == '\t' || *cstr == '-') {
		++cstr;
	}
	while (*cstr >= '0' && *cstr <= '9') {
		if (*++cstr == '\0') {
			return true;
		}
	}
	return false;
}

int toInt(char *cstr)
{
	int sign = 1;
	while (*cstr == '-' || *cstr == '+' || *cstr == ' ' || *cstr == '\t') {
		if (*cstr == '-') {
			sign *= -1;
		}
	}
	int num = 0;
	while (*cstr != '\0') {
		num = num*10 + (*cstr++ - '0');
	}
	return num;
}

int main(int argc, char** argv)
{
#define DEFAULTTESTCOUNT 5
	int testC = argc > 1 && isInt(argv[1])? toInt(argv[1]) : DEFAULTTESTCOUNT;

	std::string testCall = programName;

	for (int i = 0; i < testC; ++i) {
		testCall.append(testStr[i]);
		system(testCall.data());
	}
}
