#include "utils.h"
using namespace std;

/*
UTILS
*/
std::string join(const vector<std::string>& vct, std::string c) {
	std::string str;
	str.clear();

	for (vector<std::string>::const_iterator p = vct.begin(); p != vct.end(); ++p) {
		str += *p;
		if (p != vct.end() - 1) {
			str += c;
		}
	}
	return str;
}

std::string toSsc(std::string stepLine) {
	std::string buff = "";
	for (int i = 0; i<stepLine.size(); i++) {
		switch (stepLine.at(i)) {
		case 'X':
			buff += "1";
			break;

		case 'M':
			buff += "2";
			break;

		case 'W':
			buff += "3";
			break;

		default:
			buff += "0";
		}
	}
	return buff;
}


int gcd(int a, int b) {
	if (a == 0) {
		return b;
	}
	return gcd(b%a, a);
}

int lcm(int a, int b) {
	if (a == 0 || b == 0)
		return 0;
	return (a*b) / gcd(a, b);
}



