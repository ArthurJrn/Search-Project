#ifndef __GROUP_H__
#define __GROUP_H__

#include "sound.h"
#include <cstring>
#include <cctype>
#include <iostream>
using namespace std;

class Group
{
	public:
		int m_value;
		int m_len;
		int m_cap;
		Sound* m_keys;
		char m_first;
		string m_sound;

		Group();
		Group(string sound, int value);
		~Group();
		int get_value();
		string get_sound();
		void add_key(string key);
		bool isKey(string key);
		void print_group();

};

#endif
