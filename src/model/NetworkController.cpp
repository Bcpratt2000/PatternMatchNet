/*
 * NetworkController.cpp
 *
 *  Created on: Nov 16, 2017
 *      Author: ben
 */

#include "NetworkController.h"

NetworkController::NetworkController(){
	englishTrainer = Trainer("src/model/TrainingData/English.txt");
	mashTrainer = Trainer("src/model/TrainingData/German.txt");

	englishTrainer.train();
	mashTrainer.train();

	english = NetworkLayer(englishTrainer.getNodes());
	mash = NetworkLayer(mashTrainer.getNodes());
}

NetworkController::~NetworkController() {
	// TODO Auto-generated destructor stub
}

string NetworkController::check(string text){
	if(mash.calculate(text)<=english.calculate(text)){
		return "English";
	}
	return "German";
}
