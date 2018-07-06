#include <iostream>
#include "sound.h"
using namespace std;

Sound::Sound()
{
	
}

Sound::~Sound()
{
}

Sound::Sound(int value, string key)
{
	m_value = value;
	m_key = key;
}

Sound::Sound(string key, string sound)
{
	m_key = key;
	m_sound = sound;
}

Sound::Sound(string key)
{
	m_key = key;
}

int Sound::get_value(){ return m_value;}
string Sound::get_key(){ return m_key;}
