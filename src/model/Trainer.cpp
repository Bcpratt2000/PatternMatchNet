/*
 * Trainer.cpp
 *
 *  Created on: Nov 16, 2017
 *      Author: ben
 */

#include "Trainer.h"

Trainer::Trainer() {
	this->file = "";
}

Trainer::Trainer(string file) {
	this->file = file;

}

void Trainer::asyncTrain() {
	// puts the contents of in into trainingData
	cout << "Reading " << file << " into memory..." << endl;
	string trainingData = Util::readFile(file);
	Util::toLower(trainingData);

	if (trainingData == "") {
		cout << file + " is empty or does not exist" << endl;
		exit(1);
	}

	cout << "Training..." << endl;

	// counts the occurrences of every character string in the file within the character limits

	future<vector<NetworkNode>> threads[MAX_CHARACTERS-MIN_CHARACTERS];
	for (unsigned int charLength = MIN_CHARACTERS; charLength <= MAX_CHARACTERS; charLength++) {
//		threads[charLength - MIN_CHARACTERS] = async(&Trainer::trainCharSet, this, charLength, trainingData);
	}
	cout << "Network trained, finishing up weight calculations..." << endl;

	// multiplies the weights by the string length and divides them by the length of
	// the training data
	for (unsigned int i = 0; i < nodes.size(); i++) {
		nodes.at(i).setWeight(nodes.at(i).getWeight() * nodes.at(i).getPattern().length() * 26 / (double) trainingData.length());
	}

	//sorting is not implemented/required at the moment
	cout << "Weights calculated, sorting..." << endl;

	bool isSorted = false;
	string tempPattern;
	double tempWeight;
	long flips = 0;
	long iterations = 0;
	while (!isSorted) {
		isSorted = true;
		iterations++;
		for (unsigned int i = 0; i < nodes.size() - MIN_CHARACTERS; i++) {
			if (nodes.at(i).getWeight() > nodes.at(i + 1).getWeight()) {
				flips++;
				isSorted = false;
				tempPattern = nodes.at(i).getPattern();
				tempWeight = nodes.at(i).getWeight();

				nodes.at(i).setWeight(nodes.at(i + 1).getWeight());
				nodes.at(i).setPattern(nodes.at(i + 1).getPattern());

				nodes.at(i + 1).setPattern(tempPattern);
				nodes.at(i + 1).setWeight(tempWeight);
			}
		}

	}

	cout << "Sorted with " << iterations << " iterations and " << flips << " flips" << endl;

	for (unsigned int i = 0; i < nodes.size(); i++) {
		cout << nodes.at(i).getPattern() << ": " << nodes.at(i).getWeight() << endl;
	}

	cout << "Network trained from file: " << file << " with " << nodes.size() << " nodes" << endl;

}

void Trainer::train() {
	// puts the contents of in into trainingData
	cout << "Reading " << file << " into memory..." << endl;
	string trainingData = Util::readFile(file);
	Util::toLower(trainingData);

	if (trainingData == "") {
		cout << file + " is empty or does not exist" << endl;
		exit(1);
	}

	cout << "Training..." << endl;

	string trainingBuffer;
	int indexInVector;

	// counts the occurrences of every character string in the file withing the character limits
	for (unsigned int charLength = MIN_CHARACTERS; charLength <= MAX_CHARACTERS; charLength++) {
		for (unsigned int i = 0; i < trainingData.size() - charLength; i++) {
			trainingBuffer = trainingData.substr(i, charLength);
//			cout << trainingBuffer << endl;
			indexInVector = Util::findPatternInNodeVector(nodes, trainingBuffer);
			if (indexInVector == -1) {
				nodes.push_back(NetworkNode(trainingBuffer, 1));
			} else {
				nodes.at(indexInVector).setWeight(nodes.at(indexInVector).getWeight() + 1);
			}
		}
		cout << "Character set of " << charLength << " Complete" << endl;
	}
	cout << "Network trained, finishing up weight calculations..." << endl;

	// multiplies the weights by the string length and divides them by the length of
	// the training data
	for (unsigned int i = 0; i < nodes.size(); i++) {
		nodes.at(i).setWeight(nodes.at(i).getWeight() * nodes.at(i).getPattern().length() * 26 / (double) trainingData.length());
	}

	//sorting is not implemented/required at the moment
	cout << "Weights calculated, sorting..." << endl;

	bool isSorted = false;
	string tempPattern;
	double tempWeight;
	long flips = 0;
	long iterations = 0;
	while (!isSorted) {
		isSorted = true;
		iterations++;
		for (unsigned int i = 0; i < nodes.size() - MIN_CHARACTERS; i++) {
			if (nodes.at(i).getWeight() > nodes.at(i + 1).getWeight()) {
				flips++;
				isSorted = false;
				tempPattern = nodes.at(i).getPattern();
				tempWeight = nodes.at(i).getWeight();

				nodes.at(i).setWeight(nodes.at(i + 1).getWeight());
				nodes.at(i).setPattern(nodes.at(i + 1).getPattern());

				nodes.at(i + 1).setPattern(tempPattern);
				nodes.at(i + 1).setWeight(tempWeight);
			}
		}

	}

	cout << "Sorted with " << iterations << " iterations and " << flips << " flips" << endl;

	for (unsigned int i = 0; i < nodes.size(); i++) {
		cout << nodes.at(i).getPattern() << ": " << nodes.at(i).getWeight() << endl;
	}

	cout << "Network trained from file: " << file << " with " << nodes.size() << " nodes" << endl;

}

vector<NetworkNode> Trainer::trainCharSet(unsigned int charLength, string trainingData) {
	vector<NetworkNode> instanceNodes;
	string trainingBuffer;
	int indexInVector;

	for (unsigned int i = 0; i < trainingData.size() - charLength; i++) {
		trainingBuffer = trainingData.substr(i, charLength);
		indexInVector = Util::findPatternInNodeVector(instanceNodes, trainingBuffer);
		if (indexInVector == -1) {
			instanceNodes.push_back(NetworkNode(trainingBuffer, 1));
		} else {
			instanceNodes.at(indexInVector).setWeight(instanceNodes.at(indexInVector).getWeight() + 1);
		}
	}
	cout << "Character set of " << charLength << " Complete" << endl;

	return instanceNodes;
}

vector<NetworkNode> Trainer::getNodes() {
	return nodes;
}

int Trainer::add(int a, int b){
	return a+b;
}

Trainer::~Trainer() {
	// TODO Auto-generated destructor stub
}

