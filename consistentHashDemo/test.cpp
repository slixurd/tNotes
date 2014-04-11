/*
 * File: test.cpp
 * Author: flamme
 *
 * Created on: 2014.3.25
 */

#include <iostream>
#include <cstring>
#include <time.h>
#include <stdint.h>

#include "Node.h"
#include "ConsistenHash.hpp"

using namespace std;
uint32_t getRandomIPHash(){
	return rand() % 5000;
}

int main(){
	ConsistenHash chashtest;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 1000; j = j + 100){
			Node tmp(i, j, "127.0.0.1");
			chashtest.insert(tmp);		
		}
	}
	
	srand(time(0));
	for (int i = 0; i < 10; i++){
		uint32_t tmp = getRandomIPHash();
		cout << tmp << endl;
		map<uint32_t, Node, less<uint32_t> >::iterator it;
		it = chashtest.find(tmp);
		cout << it->second.getNodeId() << " " << it->second.getVNodeId() << " " << it->second.getServerIP() << endl;
	}
	return 0;
}
