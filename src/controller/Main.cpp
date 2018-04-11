/*
 * Main.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: Ben Pratt
 */
#include <iostream>
#include <stdio.h>
#include <string>
#include "../model/NetworkController.h"

using namespace std;

int main() {
	vector<string> trainingData;
	vector<string> labels;

	trainingData.push_back("src/model/TrainingData/English.txt");
	labels.push_back("English");

	trainingData.push_back("src/model/TrainingData/German.txt");
	labels.push_back("German");

	trainingData.push_back("src/model/TrainingData/Spanish.txt");
	labels.push_back("Spanish");

	trainingData.push_back("src/model/TrainingData/French.txt");
	labels.push_back("French");

	trainingData.push_back("src/model/TrainingData/keyMash.txt");
	labels.push_back("Key Mash");

	trainingData.push_back("src/model/TrainingData/ComputerGeneratedNumbers.txt");
	labels.push_back("Number");

	NetworkController network = NetworkController(trainingData, labels);
	string tempStr;
	while (tempStr != "exit" || tempStr != "quit") {
		cout << "Enter text: ";
		getline(cin, tempStr);
		cout << network.check(tempStr) << "\n" << endl;

	}
	return 0;
}

