/*
 * NetworkController.cpp
 *
 *  Created on: Nov 16, 2017
 *      Author: ben
 */

#include "NetworkController.h"

NetworkController::NetworkController(){
	string filePath = "/home/ben/eclipse-workspace/NeuralNet/src/model/TrainingData/English.txt";
	englishTrainer = Trainer(filePath);
	mashTrainer = Trainer(filePath);
	englishTrainer.train();
	cout << "trained" << endl;
}

NetworkController::~NetworkController() {
	// TODO Auto-generated destructor stub
}

string check(string text){

	return "";
}
