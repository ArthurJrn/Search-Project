#ifndef __SOUNDEX_H__
#define __SOUNDEX_H__
#include "sound.h"
#include "dico.h"
#include <iostream>

using namespace std;

//Inherits from Dico indeed it is essentially a dictionary, we must simply add some functions to adapt it to the structure of the Soundex
//The soundex associates a word with a code relative to the way we hear it
//Vowels are not taken into account ; the first letter remains in upper case in the beginning ; 
//Example : the code for "Hello" is H4400
class Soundex : public Dico
{
	public:
		
		Soundex();
		~Soundex();
		string search_sound(string key);
		void add_sound(string key, string sound);
		void soundex_print();

};

#endif
