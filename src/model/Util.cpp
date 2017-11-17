/*
 * Util.cpp
 *
 *  Created on: Nov 16, 2017
 *      Author: ben
 */

#include "Util.h"

Util::Util() {
	// TODO Auto-generated constructor stub

}

int Util::countOccurences(string sample, string pattern) {
	int index = sample.find(pattern);
	int count = 0;
	while (index != -1) {
		count++;
		sample = sample.substr(index + 1);
		index = sample.find(pattern);
	}
	return count;
}

string Util::readFile(string file) {
	string strBuffer = "";

	std::ifstream fileStream;
	fileStream.open(file);
	while (fileStream.is_open()) {
		fileStream >> strBuffer;
	}
	fileStream.close();

	return strBuffer;
}

int Util::findPatternInNodeVector(vector<NetworkNode> nodes, string text){
	for (unsigned int i = 0; i < nodes.size(); i++) {
			if (nodes.at(i).getPattern()==text)
					return i;
	}
	return -1;
}

Util::~Util() {
	// TODO Auto-generated destructor stub
}
