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

#define MIN_CHARACTERS 2
#define MAX_CHARACTERS 5

#include "Util.h"
#include "NetworkNode.h"

#ifndef MODEL_TRAINER_H_
#define MODEL_TRAINER_H_

using namespace std;

class Trainer {
public:
	vector<NetworkNode> getNodes();
	void train();
	Trainer() = default;
	Trainer(string);
	virtual ~Trainer();
private:
	vector<NetworkNode> nodes;
	string file;

};


#endif /* MODEL_TRAINER_H_ */
