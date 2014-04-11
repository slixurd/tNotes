/*
 * File: Node.h
 * Author: flamme
 *
 * Create on: 2014.3.25
 */

#include <string>

#ifndef NODE_H
#define NODE_H



class Node{
	public:
		Node();
		Node(int n, int v, std::string ip);
		~Node();
		int getNodeId() const;
		int getVNodeId() const;
		std::string getServerIP() const;

	private:
		int nodeId;
		int vNodeId;
		std::string serverIP;
};

#endif
