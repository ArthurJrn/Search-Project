#ifndef __WORD_H__
#define __WORD_H__

#include "anex.h"
#include "dico.h"
#include "soundex.h"
#include "bgroup.h"
#include <iostream>
#include <string>

using namespace std;

class Word
{
	public:
		int m_len;
		string m_word;
		Dico *m_dico;
		Dico *m_dig;
		Dico *m_prob;
		Soundex *m_s;
		Bgroup *m_bgp;
		Word();
		int len();
		Word(string word);
		~Word();
		void set_word(string word);
		string solve(char* entry);
		int EditingDistance(Word word);

};

#endif
