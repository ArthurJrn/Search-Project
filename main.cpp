#include "dico.h"
#include "sound.h"
#include "soundex.h"
#include "sentence.h"
#include "anex.h"
#include "group.h"
#include "word.h"
#include "bgroup.h"
#include <iostream>
#include <cctype>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	Dico dico;
	Dico dig;
	Dico prob;
	Dico *prob_p;
	prob_p = &prob;
	Dico *dico_p;
	dico_p = &dico;
	Dico *dig_p;
	dig_p = &dig;
	dico_init(dico_p);
	dig_init(dig_p);
	Soundex s;
	Soundex* s_p;
	s_p = &s;
	Bgroup bgp;
	Bgroup* bgp_p;
	bgp_p = &bgp;

	soundex_init(s_p, dig_p, dico_p);
	Group groups[40000];
	proba(prob_p);
	update_bgroup(bgp_p, s_p, groups);
	char entry[50];
	cout << "Enter a word"<<endl;
	cin >>entry;
	Word w;
	w.m_s = s_p;
	w.m_dico = dico_p;
	w.m_dig = dig_p;
	w.m_prob = prob_p;
	w.m_bgp = bgp_p;
	string solved = w.solve(entry);
	cout << "Did you mean :";
	cout << solved<< " ?"<<endl;
//	Sentence new_sentence;
//	new_sentence.solve_s();
	return 0;

}
