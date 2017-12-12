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

unsigned long hash(string& input){
		unsigned long long sumOfChars = 0;
		auto inputArr = input.data();
		unsigned long size = sizeof(inputArr);
		unsigned long retBuffer = 0;

		for(unsigned int i = 0; i<size*100; i++){
			sumOfChars += inputArr[i%size]*inputArr[i<<(12203*i&size)%size];
		}
		retBuffer ^= (sumOfChars << 16);
		sumOfChars=0;
		for(unsigned int  i = 0; i<size*100; i++){
			sumOfChars += inputArr[(sumOfChars+i*13)%size] ^ inputArr[(i*103841)%size];
		}
		retBuffer+=sumOfChars;
		return retBuffer;
	}

	static int isInVector(vector<unsigned long long>& vect, unsigned long long& value){
		for(unsigned long i = 0; i < vect.size(); i++){
			if(vect.at(i) == value){
				return 1;
			}
		}
		return 0;
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

string Util::readFile(string& file) {
	string strBuffer = "";

	std::ifstream fileStream;
	fileStream.open(file.c_str());
	ostringstream ss = ostringstream { };
	ss << fileStream.rdbuf();
	fileStream.close();

	return ss.str();
}

int Util::findPatternInNodeVector(vector<NetworkNode>& nodes, string& text) {
	for (unsigned int i = 0; i < nodes.size(); i++) {
		if (nodes.at(i).getPattern() == text)
			return i;
	}
	return -1;
}

void Util::toLower(string& text){
	for(unsigned int i = 0; i < text.length(); ++i) {
		text[i] = tolower(text[i]);
	}
}

Util::~Util() {
	// TODO Auto-generated destructor stub
}
