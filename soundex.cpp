#include "soundex.h"
#include "sound.h"
#include "dico.h"
#include <iostream>

using namespace std;

//Since the Dico constructor is called, no need to allocate nor free memory in the constructor or in the destructor
Soundex::Soundex() : Dico()
{
	m_cap = 400;
	m_len = 0;
	//m_entry = (Sound*)malloc(m_cap*sizeof(Sound));
}

Soundex::~Soundex()
{
	//free(m_entry);
}

string Soundex::search_sound(string key)
{
	int i;
	for(i=0; i<m_len; i++)
	{
		if(!key.compare(m_entry[i].m_key))
		{
			return m_entry[i].m_sound;
		}
	}
	return "";
}


//Same function as from Dico, only different parameters are taken into account
void Soundex::add_sound(string key, string sound)
{
	string id = search_sound(key);
	if(id != "")
	{
		m_entry[search_index(key)].m_sound = sound;
	}
	else
	{
		if(m_len==m_cap)
		{
			m_cap *=5;
			m_entry = (Sound*)realloc(m_entry, m_cap*sizeof(Soundex));
		}
		m_entry[m_len].m_key = key;
		m_entry[m_len].m_sound = sound;
		m_len ++;
	}
}


//Same printing function
void Soundex::soundex_print()
{
	for(int i = 0; i<m_len; i++)
	{
		cout << "Key :"<<m_entry[i].m_key << " Sound :" << m_entry[i].m_sound<<endl;
	}
}
