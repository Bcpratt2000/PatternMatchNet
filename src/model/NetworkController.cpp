/*
 * NetworkController.cpp
 *
 *  Created on: Nov 16, 2017
 *      Author: ben
 */

#include "NetworkController.h"

NetworkController::NetworkController(vector<string> trainingDataPaths, vector<string> labels) {
	if (trainingDataPaths.size() != labels.size()) {
		cout << "labels is not of equal size to training data paths" << endl;
		exit(1);
	}

	this->labels = labels;

	Trainer trainer;
	for (unsigned int i = 0; i < trainingDataPaths.size(); i++) {
		trainer = Trainer(trainingDataPaths[i]);
		trainer.train();
		networks.push_back(NetworkLayer(trainer.getNodes()));
	}
}

NetworkController::~NetworkController() {
	// TODO Auto-generated destructor stub
}

string NetworkController::check(string text) {
	vector<double> values;
	vector<string> sortingLabels = labels;
	double startTime = (double) clock();
	int largestIndex = 0;
	double largestValue = 0;
	double smallestValue = std::numeric_limits<double>::max();

	// calculate values
	for (unsigned int i = 0; i < networks.size(); i++) {
		values.push_back(networks.at(i).calculate(text));
//		cout << labels[i] << ": " << values[i] << endl;
		if (values[i] > largestValue) {
			largestIndex = i;
			largestValue = values[i];
		}

		if (values[i] < smallestValue) {
			smallestValue = values[i];
		}

	}
	cout << "Milliseconds Taken " << (((double) clock() - startTime) / CLOCKS_PER_SEC) * 1000 << endl;

	//sort language values;
	bool isSorted = false;
	double tempValue;
	string tempLabel;
	while (!isSorted) {
		isSorted = true;
		for (unsigned int i = 0; i < values.size() - 1; i++) {
			if (values.at(i) > values.at(i + 1)) {
				isSorted = false;
				tempValue = values.at(i);
				values.at(i) = values.at(i + 1);
				values.at(i + 1) = tempValue;

				tempLabel = sortingLabels.at(i);
				sortingLabels.at(i) = sortingLabels.at(i + 1);
				sortingLabels.at(i + 1) = tempLabel;
			}
		}
	}

	//normalize values to percentages
	double totalValues;
	for (unsigned int i = 0; i < values.size(); i++) {
		totalValues += values[i];
	}

	for (unsigned int i = 0; i < values.size(); i++) {
		cout << sortingLabels[i] << ": " << (values[i]/largestValue)*100 << "%" << endl;
	}

	return labels[largestIndex];
}
