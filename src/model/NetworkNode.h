/*
 * Node.h
 *
 *  Created on: Nov 16, 2017
 *      Author: ben
 */

#include <string>

#ifndef MODEL_NODE_H_
#define MODEL_NODE_H_

namespace std {

class NetworkNode {
private:
	double weight;
	string pattern;
public:
	NetworkNode(string, double);
	virtual ~NetworkNode();

	string getPattern();
	void setPattern(string);

	double getWeight();
	void setWeight(double);
};

} /* namespace std */

#endif /* MODEL_NODE_H_ */
