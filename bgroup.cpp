#include "bgroup.h"
#include "group.h"
#include "sound.h"
#include <cstring>
#include <iostream>
using namespace std;

Bgroup::Bgroup()
{
	m_len = 0;
	m_cap = 500;
	m_groups = (Group**)malloc(m_cap*sizeof(Group*));
}

Bgroup::~Bgroup()
{
	free(m_groups);
}

bool Bgroup::isInBgroup(string sound)
{
	for(int i = 0; i< m_len; i++)
	{
		if(!sound.compare(m_groups[i]->m_sound)){return 1;}
	}
	return 0;
}

void Bgroup::add_group(Group* g)
{
	if(!isInBgroup(g->m_sound))
	{
		if(m_len == m_cap)
		{
			m_cap *=5;
			m_groups = (Group**)realloc(m_groups, m_cap*sizeof(Group*));
		}
		m_groups[m_len] = g;
		m_len++;
	}
}

void Bgroup::print_bgroup()
{
	for(int i = 0; i< m_len; i++)
	{
		m_groups[i]->print_group();
	}
}

Group* Bgroup::corres_group(string sound)
{
	for(int i = 0; i< m_len; i++)
	{
		if(!sound.compare(m_groups[i]->m_sound)){return m_groups[i];}
	}
}
