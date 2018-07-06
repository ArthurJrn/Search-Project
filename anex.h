#ifndef __ANEX_H__
#define __ANEX_H__
#include "dico.h"
#include "sound.h"
#include <map>
#include <iterator>
#include "soundex.h"
#include "bgroup.h"
#include "group.h"
#include <iostream>
#include <typeinfo>
#include <cctype>
#include <cstring>
#include <fstream>

using namespace std;

string calculate_soundex(Dico* digits,Dico* dico, char* word);
void update(Bgroup* bgp_p, string sound_s, string word, Group* groups, int i);
void dig_init(Dico *dig);
void dico_init(Dico *dico);
int dis(char* word_1, char* word_2);
string str_of_chr(char* word);
void update_bgroup(Bgroup* bgp_p, Soundex* s_p, Group* groups);
void soundex_init(Soundex *s, Dico *digits, Dico *dico);
string getNextToken(istream &in);
int file_len();
void proba(Dico *prob);


#endif
