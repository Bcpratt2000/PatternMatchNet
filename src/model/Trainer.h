/*
 * Trainer.h
 *
 *  Created on: Nov 16, 2017
 *      Author: ben
 */

#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <fstream>
#include <algorithm>
#include <stdio.h>

#define MIN_CHARACTERS 1
#define MAX_CHARACTERS 3

#include "Util.h"
#include "NetworkNode.h"

#ifndef MODEL_TRAINER_H_
#define MODEL_TRAINER_H_

using namespace std;

class Trainer {
public:
	vector<NetworkNode> getNodes();
	void train();
	Trainer();
	Trainer(string);
	virtual ~Trainer();
private:
	vector<NetworkNode> nodes;
	string file;

};


#endif /* MODEL_TRAINER_H_ */
