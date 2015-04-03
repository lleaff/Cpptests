#include <iostream>
#include <cstdlib>

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
		num = num*10 + (*cstr - '0');
	}
	return num;
}

int main(int argc, char** argv)
{
#define DEFAULTTESTCOUNT 5
	int testC = argc > 1 && isInt(argv[1])? DEFAULTTESTCOUNT : toInt(argv[1]);

	for (int i = 0; i < testC; ++i) {

	}
}
