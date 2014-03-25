/*
 * File: ConsistenHash.hpp
 * Author: flamme
 *
 * Created on: 2014.3.25
 */

#include <stdint.h>
#include <map>
#include <string>
#include <algorithm>
#include "Node.h"

#ifndef CONSISTENHASH_H
#define CONSISTENHASH_H

class ConsistenHash{
	public:
		typedef typename std::map<uint32_t, Node, std::less<uint32_t> >::iterator iterator;

		ConsistenHash(){
		}

		~ConsistenHash(){
		}

		int size() const{
			return nodes.size();
		}
		
		bool empty() const{
			return nodes.empty();
		}

		void insert(const Node& node){
			uint32_t hash = getHash(node);
			nodes.insert(std::pair<uint32_t, Node>(hash, node));
		}

		void erase(iterator it){
			nodes.erase(it);
		}

		iterator find(uint32_t hash){
			if (nodes.empty()){
				return nodes.end();
			}

			iterator it = nodes.lower_bound(hash);

			if (it == nodes.end()){
				it = nodes.begin();
			}

			return it;
		}

		iterator begin(){
			return nodes.begin();
		}

		iterator end(){
			return nodes.end();
		}

	private:
		uint32_t getHash(const Node& node){
			uint32_t hash = node.getNodeId() * 1000 + node.getVNodeId();
			return hash;
		}
		std::map<uint32_t, Node, std::less<uint32_t> >nodes;
};


#endif
