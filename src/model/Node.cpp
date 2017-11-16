/*
 * Node.cpp
 *
 *  Created on: Nov 16, 2017
 *      Author: ben
 */

#include "Node.h"

namespace std {

Node::Node() {

}

void Node::setWeight(double weight) {
	Node::weight = weight;
}

double Node::getWeight(){
	return weight;
}

void Node::setLabel(string label){
	Node::label = label;
}

string Node::getLabel(){
	return label;
}

Node::~Node() {
	delete weight;
	delete label;
}

} /* namespace std */
