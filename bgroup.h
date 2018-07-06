#ifndef __BGROUP_H__
#define __BGROUP_H__

#include "sound.h"
#include "group.h"
#include <iostream>
#include <cstring>
using namespace std;

class Bgroup
{
	public:
		int m_len;
		int m_cap;
		Group** m_groups;
		
		Bgroup();
		~Bgroup();
		void print_bgroup();
		void add_group(Group* g);
		bool isInBgroup(string sound);
		Group* corres_group(string sound);
};

#endif

