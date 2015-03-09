#include <iostream>
#include <fstream>

#include <string.h> //strcpy()

static inline int parseArgs(int argc, char** argv, char* filename, int& maxentries);

//Usage: readRandInt {filename} -n {maxentries (optional)}
int main(int argc, char** argv)
{
#define MAXFILENAMESIZE 100
	char filename[MAXFILENAMESIZE];
	int maxentries = INT_MAX;

	parseArgs(argc, argv, filename, maxentries);

	std::string line;
	std::ifstream rfile;

	rfile.open(filename);
	if (rfile.is_open()) {
		for (int i = 0; i < maxentries && !rfile.eof(); ++i) {
			getline(rfile, line);
			std::cout << line << '\n';
		}
		rfile.close();
	} else {
		std::cerr << "error: no input file\n";
	}
}


static inline bool isInt(char *str)
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

static inline int strToInt(char *str)
{
	int num = 0, sign = 1;
	if (*str == '-') {
		sign = -1;
		++str;
	}
	while (*str != '\0') {
		num = num*10 + *str - '0';
		++str;
	}
	return num * sign;
}

static inline int processNextIntArg(char *nextString, int& myVar) {
	if (!isInt(nextString)) {
		return 0;
	} else {
		myVar = strToInt(nextString);
		return 1;
	}
}

static inline int parseArgs(int argc, char** argv, char* filename, int& maxentries)
{
	for (int i = 1; i < argc; ++i) {
		if (argv[i][0] != '-') {
			strcpy(filename, argv[i]);
		} else {
			if (argv[i][1] != '-') { //Short option
				for (int j = 1, argfound = false; argv[i][j] != '\0' && !argfound; ++j) {
					switch(argv[i][j]) {
						case 'n':
							processNextIntArg(argv[++i], maxentries); 
							argfound = true;
							break;
						default:
							std::cerr << "error: invalid argument '" << argv[i][j] << "'\n";
							break;
					}
				}
			} else {
				//TODO
			}
		}
	}
	return argc - 1;
}
