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

class Node {
private:
	double weight;
	string label;
public:
	Node();
	virtual ~Node();

	string getLabel();
	void setLabel(string label);

	double getWeight();
	void setWeight(double weight);
};

} /* namespace std */

#endif /* MODEL_NODE_H_ */
