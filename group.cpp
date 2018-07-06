#include "sound.h"
#include "group.h"
#include <cstring>
#include <iostream>
using namespace std;

Group::Group()
{
	m_len = 0;
	m_value = 0;
	m_cap = 500;
	m_keys = (Sound*)malloc(m_cap*sizeof(Sound));
}

Group::Group(string sound, int value)
{
	m_len = 0;
	m_value = value;
	m_cap = 500;
	m_sound = sound;
	m_first = m_sound[0];
	m_keys = (Sound*)malloc(m_cap*sizeof(Sound));
}

Group::~Group()
{
	free(m_keys);
}

int Group::get_value(){return m_value;}

string Group::get_sound(){return m_sound;}

bool Group::isKey(string key)
{
	for(int i = 0; i<m_len; i++)
	{
		if(!key.compare(m_keys[i].m_key)){return 1;}
	}
	return 0;
}

void Group::add_key(string key)
{
	if(!isKey(key))//The key doesn't already belong to the group
	{
		if(m_len == m_cap)
		{
//			cout << "realloc de key"<<endl;
			m_cap *=10;
			m_keys = (Sound*)realloc(m_keys, m_cap*sizeof(Sound));

		}
		//m_keys[m_len] is a Sound so it has a key and  value
		m_keys[m_len].m_key = key;
		m_first = toupper(key[0]);
		m_len ++;
	}
}

void Group::print_group()
{
	cout << "Sound : "<<m_sound<<endl;
	for(int i = 0; i<m_len; i++)
	{
		cout << "\tKey n"<<i<< " : "<<m_keys[i].m_key<<endl;
	}
}
