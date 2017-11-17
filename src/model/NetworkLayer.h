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

namespace std {

class NetworkLayer {
private:
	vector<NetworkNode> nodes;
public:
	NetworkLayer(vector<NetworkNode>);
	virtual ~NetworkLayer();
	double calculate(string);
};

} /* namespace std */

#endif /* MODEL_NETWORKLAYER_H_ */
