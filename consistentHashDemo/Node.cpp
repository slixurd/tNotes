/*
 * File: Node.cpp
 * Author: flamme
 *
 * Created on: 2014.3.25
 */

#include "Node.h"


Node::Node(){
}

Node::Node(int n, int v, std::string ip): nodeId(n), vNodeId(v), serverIP(ip){
}

Node::~Node(){
}

int Node::getNodeId() const{
	return nodeId;
}

int Node::getVNodeId() const{
	return vNodeId;
}

std::string Node::getServerIP() const{
	return serverIP;
}
