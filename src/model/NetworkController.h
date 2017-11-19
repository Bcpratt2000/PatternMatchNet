/*
 * NetworkController.h
 *
 *  Created on: Nov 16, 2017
 *      Author: ben
 */

#include <string>
#include <vector>

#include "Trainer.h"
#include "NetworkLayer.h"


#ifndef MODEL_NETWORKCONTROLLER_H_
#define MODEL_NETWORKCONTROLLER_H_

using namespace std;

class NetworkController {
private:
	Trainer englishTrainer;
	Trainer mashTrainer;

	NetworkLayer english;
	NetworkLayer mash;
public:
	string check(string);
	NetworkController();
	virtual ~NetworkController();
};

#endif /* MODEL_NETWORKCONTROLLER_H_ */
