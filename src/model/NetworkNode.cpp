/*
 * Node.cpp
 *
 *  Created on: Nov 16, 2017
 *      Author: ben
 */

#include "NetworkNode.h"

namespace std {

NetworkNode::NetworkNode(string pattern, double weight) {
	NetworkNode::pattern = pattern;
	NetworkNode::weight = weight;

}

void NetworkNode::setWeight(double weight) {
	NetworkNode::weight = weight;
}

double NetworkNode::getWeight(){
	return weight;
}

void NetworkNode::setPattern(string label){
	NetworkNode::pattern = label;
}

string NetworkNode::getPattern(){
	return pattern;
}

NetworkNode::~NetworkNode() {
//	delete Node::weight;
//	delete Node::pattern;
}

} /* namespace std */
