#include "dico.h"
#include "sound.h"
#include <iostream>
#include <cstring>

using namespace std;


//Constructor -> important to allocate the memory with a great initial capacity to prevent stack overflow
Dico::Dico()
{
	Sound test;
	m_cap = 400;
	m_entry = (Sound*)malloc(m_cap*sizeof(Dico));
	m_len = 0; //The initial length is null, the dictionary is empty
}

//Destructor : important to free the memory
Dico::~Dico()
{
	free(m_entry);
}


//!!Does not return the value of the key (the index is not quite relevant but could be usefull
int Dico::search_index(string key)
{
	int i;
	for(i=0; i<m_len; i++)
	{
		if(!key.compare(m_entry[i].m_key))
		{
			return i;
		}
	}
	return -1;
}


//Returns the value associated with the key in entry
int Dico::search_value(string key)
{
	int i;
	for(i=0; i< m_len; i++)
	{
		if(!key.compare(m_entry[i].m_key))//if we find a key that already exists
		{
			return m_entry[i].m_value; //then we return its value
		}

	}
	return -1;//otherwise we simply return 0
}


//Returns the key associated with a particular value (important value!=sound)
//Only usefull for the dictionary with 1-> "1" etc...
string Dico::search_key(int value)
{
	int i;
	for(i=0; i< m_len; i++)
	{
		if(m_entry[i].m_value == value) //if we find a match in the value
		{
			return m_entry[i].m_key;//then we return it
		}
	}
	return "";//Else an empty string is returned
}



//Most important function -> adds a couple (key/sound) in the dictionary
//We must not overflow the Dictionary structure, so we must check everytime if the capacity is reached, and reallocate memory
void Dico::add_value(string key, int value)
{
	int idx = search_value(key);//we search the value for this key if it already exists
	if(idx != -1)
	{
		m_entry[idx].m_value = value;//the key already exists, we simply change the value
	}
	//Indeed no need for reallocation here, the memory already exists
	else
	{
		if(m_len == m_cap)//Need for reallocation
		{
			m_cap *=5;
			m_entry = (Sound*)realloc(m_entry, m_cap*sizeof(Dico));
		}
		m_entry[m_len].m_key = key;
		m_entry[m_len].m_value = value;
		m_len +=1;
		

	}
}

//Printing the whole dictionary
void Dico::dict_print()
{
	int n = m_len;
	for(int i=0; i< n; i++)
	{
		cout << "Key :" << m_entry[i].m_key << " value :" << m_entry[i].m_value <<endl;
	}
}




