/*
 * NetworkLayer.h
 *
 *  Created on: Nov 16, 2017
 *      Author: ben
 */

#include "Util.h"
#include <vector>
#include "NetworkNode.h"

#ifndef MODEL_NETWORKLAYER_H_
#define MODEL_NETWORKLAYER_H_

using namespace std;

class NetworkLayer{

private:
	vector<NetworkNode> nodes;
public:
	NetworkLayer() = default;
	NetworkLayer(vector<NetworkNode>);
	virtual ~NetworkLayer();
	double calculate(string);
};

#endif /* MODEL_NETWORKLAYER_H_ */
