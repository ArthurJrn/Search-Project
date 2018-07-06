#ifndef __DICO_H__
#define __DICO_H__
#include <iostream>
#include "sound.h"
#include <list>
using namespace std;


//Inherits from class Sound
//This class is simply a group of "Sound"s. Only works with keys that are letters and sounds that are digits
//This class enables us to describe fully the associations between letters and digits in the soundex
//Function add_value that inserts a new association
class Dico: public Sound
{
	public:
		Sound* m_entry;
		int m_cap;
		int m_len;

		Dico();
		~Dico();
		int search_value(string key);
		string search_key(int value);
		int search_index(string key);
		void add_value(string key, int value);
		void dict_print();

};

#endif
