/*
 * NetworkLayer.cpp
 *
 *  Created on: Nov 16, 2017
 *      Author: ben
 */

#include "NetworkLayer.h"


NetworkLayer::NetworkLayer(vector<NetworkNode> nodes) {
	NetworkLayer::nodes = nodes;
	// TODO Auto-generated constructor stub

}

double NetworkLayer::calculate(string text){
	double accum = 0;
	for(unsigned int i=0; i<NetworkLayer::nodes.size(); i++){
//		accum+=nodes.at(i).getWeight() * Util::countOccurences(text, nodes.at(i).getPattern());
	}
	return accum;
}

NetworkLayer::~NetworkLayer() {

}
