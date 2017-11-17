/*
 * Trainer.cpp
 *
 *  Created on: Nov 16, 2017
 *      Author: ben
 */

#include "Trainer.h"

namespace std {

Trainer::Trainer(string file) {
	Trainer::file = file;

}

void Trainer::train() {
	string trainingData;
	// puts the contents of in into trainingData
	cout << "Reading " << file << " into memory..." << endl;
	trainingData = Util::readFile(file); //TODO change to lowercase

	cout << "Training..." << endl;

	string trainingBuffer;
	int indexInVector;

	// counts the occurrences of every character string in the file withing the character limits
	for (unsigned int charLength = MIN_CHARACTERS; charLength <= MAX_CHARACTERS; charLength++) {
		for (unsigned int i = 0; i < trainingData.size() - charLength; i++) {
			trainingBuffer = trainingData.substr(i, i + charLength);
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
		nodes.at(i).setWeight((nodes.at(i).getWeight() * ((double) nodes.size() * 26)) / (double) trainingData.length());
	}

	//sorting is not implemented/required at the moment
//	cout << "Weights calculated, sorting..." << endl;

	cout << "Network trained from file: " << file << endl;

}
vector<NetworkNode> Trainer::getNodes(){
	return nodes;
}

Trainer::~Trainer() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
