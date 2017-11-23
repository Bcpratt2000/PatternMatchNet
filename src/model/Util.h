/*
 * Util.h
 *
 *  Created on: Nov 16, 2017
 *      Author: ben
 */

#include <string>
#include <fstream>
#include <streambuf>
#include <stdio.h>
#include <vector>
#include <sstream>

#include "NetworkNode.h"

#ifndef MODEL_UTIL_H_
#define MODEL_UTIL_H_

using namespace std;

class Util {
public:
	Util();
	virtual ~Util();
	static int countOccurences(string&, string&);
	static string readFile(string);
	static int findPatternInNodeVector(vector<NetworkNode>&, string&);
	static void toLower(string&);
};


#endif /* MODEL_UTIL_H_ */
