#include <iostream>
#include <fstream>
#include <string.h> //strcpy()
#include <stdlib.h> //rand()
#include <time.h> //time()

static int parseArgs(int argc, char** argv, int& elC, int& lower, int& upper, char* filename);
static inline void writeRandIntsToFile(std::ofstream& myFile, int elC, int lower, int upper);

//Usage: writeRandInt {filename} -n {numberOfInts} -l {lowerBound} -u {upperBound}
int main(int argc, char** argv)
{
	int elC = 100; // Default number of elements to write
	int lower = 0, upper = INT_MAX;
#define MAXFILENAMESIZE 100
	char filename[MAXFILENAMESIZE];
	parseArgs(argc, argv, elC, lower, upper, filename);

#ifdef DEBUG
	std::cerr << "elc=" << elC << "  lo=" << lower << "  up=" << upper << "\nfilename=" << filename << "\n";//DEBUG
#endif /* DEBUG */

	std::ofstream myFile;
	myFile.open(filename);
	writeRandIntsToFile(myFile, elC, lower, upper);
	myFile.close();

	return 0;
}

inline int randInt(int lower, int upper) {
	int range = upper - lower;
	if (range == 0) {
		return lower;
	}
	return ((int)rand() % range) + 1 + lower;
}

static inline void writeRandIntsToFile(std::ofstream& myFile, int elC, int lower, int upper) {
	srand(time(NULL));
	while (--elC >= 0) {
		myFile << randInt(lower, upper) << "\n";
	}
}

bool isInt(char* str)
{
	if (*str == '-') {
		++str;
	}
	while (*str != '\0') {
		if (*str < '0' || *str > '9') {
			return false;
		}
		++str;
	}
	return true;
}

int strToInt(char* str) 
{
	int num = 0;
	int sign = (*str == '-') ? -1 + (*(++str) * 0) : 1; // <= horryfying but cool at the same time
	for ( ; *str >= '0' && *str <= '9'; ++str) {
		num = num*10 + (*str - '0');
	}
	return num * sign;
}

static inline int getNextArgToInt(char arg, int& myVar, int& iterator, int argc, char** argv, int& flag);

static int parseArgs(int argc, char** argv, int& elC, int& lower, int& upper, char* filename)
{
	for (int i = 1; i < argc; ++i) {
		if (argv[i][0] != '-') { //Filename
			strcpy(filename, argv[i]);
		} else { //Options
			if (argv[i][1] != '-') { //Short option
				for (int j = 1, newargseries = 0; argv[i][j] != '\0' && !newargseries; ++j) {
					switch (argv[i][j]) {
						case 'n':
							getNextArgToInt('n', elC, i, argc, argv, newargseries);
							break;
						case 'l':
							getNextArgToInt('l', lower, i, argc, argv, newargseries);
							break;
						case 'u':
							getNextArgToInt('u', upper, i, argc, argv, newargseries);
							break;
						default:
							std::cerr << "error: '" << argv[i][j] << "' unrecognized argument." << std::endl;
							break;
					}
				}
			} else { //Long option
				//TODO
			}
		}
	}
	return argc - 1;
}

static inline int getNextArgToInt(char arg, int& myVar, int& iterator, int argc, char** argv, int& flag) {
	if (++iterator >= argc) {
		std::cerr << "error: -" << arg << " option requires an integer argument." << std::endl;
		flag = true;
	} else {
		if (isInt(argv[iterator])) {
			myVar = strToInt(argv[iterator]);
		} else {
			std::cerr << "error: invalid argument to -" << arg << "n option \"" << argv[iterator]
				<< "\", must be an integer number." << std::endl;
		}
		flag = true;
	}
}
