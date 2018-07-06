#ifndef __SOUND_H__
#define __SOUND_H__

#include <iostream>
using namespace std;

//This class associates a key to a "sound"
//Very usefull in order to create the soundex and the dictionnaries : we need a structure that associates two elements 
//For example a letter and a digit, or a word and its soundex value
class Sound
{
	public:
		int m_value;
		string m_key;
		string m_sound;
		Sound();
		Sound(int value, string key);
		Sound(string key, string sound);
		Sound(string key);
		~Sound();
		int get_value();
		string get_key();
		string get_sound;
};

#endif
