/*
 * NetworkController.h
 *
 *  Created on: Nov 16, 2017
 *      Author: ben
 */

#include <string>
#include <vector>
#include <stdio.h>
#include <chrono>

#include "Trainer.h"
#include "NetworkLayer.h"


#ifndef MODEL_NETWORKCONTROLLER_H_
#define MODEL_NETWORKCONTROLLER_H_

using namespace std;

class NetworkController {
private:
	vector<NetworkLayer> networks;
	vector<string> labels;

	NetworkLayer computer;
	NetworkLayer human;
public:
	string check(string);
	NetworkController(vector<string>, vector<string>);
	virtual ~NetworkController();
};

#endif /* MODEL_NETWORKCONTROLLER_H_ */
