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
#include "anex.h"

using namespace std;

string getNextToken(istream &in)
{
    char c;
    std::string ans="";
    c=in.get();
    while(!isalpha(c) && !in.eof())//cleaning non letter charachters
    {
        c=in.get();
    }
    while(isalpha(c))
    {
        ans.push_back(tolower(c));
        c=in.get();
    }
    return ans;
}

void proba(Dico *prob)
{
    map<string,int> words;
    ifstream fin("out.txt");

    string s;
    string empty ="";
    while((s=getNextToken(fin))!=empty )
            ++words[s];

    for(map<string,int>::iterator iter = words.begin(); iter!=words.end(); ++iter)
    {
//        cout<<iter->first<<' '<<iter->second<<endl;
	  prob->add_value(iter->first, iter->second); 
    }
    fin.close();
}




void soundex_init(Soundex *s, Dico *digits, Dico *dico)
{
	string word;
	ifstream infile;
	string word2 = "hello";
	ofstream outfile;
	infile.open("out.txt");
	//outfile.open("new.h");
	char w[70];
	int n = file_len();
	//outfile << "#ifndef __NEW_H__\n" << "#define __NEW_H__\n";
	//outfile << "#include <stdio.h>\n";
	//outfile << "#include <stdlib.h>\n";
	//outfile << "void init_soundex(Soundex *s);\n\n";
	//outfile << "void init_soundex(Soundex *s)\n";
	//outfile << "{\n";
	for(int i = 0; i< n -1; i++)
	{
		getline(infile, word);
		word.copy(w, word.length());
		w[word.length()] = '\0';
		string sound_s = calculate_soundex(digits, dico, w);
		s->add_sound(w, sound_s);
//		update_bgroup(bgp_p, sound_s, word);
//		outfile << "\ts->add_sound("<<"%"<<word<<"%"<<", "<<"%"<<sound_s<<"%"<<");\n";
		//cout << "Sound : "<<sound_s << "for word : "<<word<<endl;
//		dgp.add_sound(sound_s, w);
	}
	//outfile << "}\n"<<"#endif\n";
	infile.close();
	//outfile.close();
}

void update_bgroup(Bgroup* bgp_p, Soundex* s_p, Group* groups)
{
	for(int i = 0; i< s_p->m_len; i++)
	{
		string sound_s = (s_p->m_entry[i]).m_sound;
		string word = (s_p->m_entry[i]).m_key;
		update(bgp_p, sound_s, word, groups, i);
	}
}

void update(Bgroup* bgp_p, string sound_s, string word, Group* groups, int i)
{
	if(!bgp_p->isInBgroup(sound_s))//if the sound isn't already registered
	{
		Group* g_p = new Group();
		g_p = &groups[i];
		g_p->m_sound = sound_s;
		bgp_p->add_group(g_p);
	}
	(bgp_p->corres_group(sound_s))->add_key(word);


}


//Returns the length of the file that we are loading to create our data base of words
//Indeed we need to read the file once in order to get its length
int file_len()
{
	fstream infile;
	infile.open("out.txt");
	int i = 0;
	while(!infile.eof())
	{
		i++;
		string word;
		getline(infile, word);
	}
	infile.close();
	return i;
}

//Transforms a char* into a string
string str_of_chr(char* word)
{
	string res = "";
	for(int i =0; i< strlen(word); i++)
	{
		char k = tolower(word[i]);
		res = res + k;
	}
	return res;
}


//This function calculates the soundex value of a word
string calculate_soundex(Dico* digits,Dico* dico, char* word)
{
	int n = strlen(word);
	char d = toupper(word[0]);
	int count = 1;//There is already one letter which is the first one (reminder, in upper case)
	string res = "";//res is the string in which the soundex value will be stored
	res = res + d;
	for(int i=1; i< n; i++)
	{
		if(count == 5) break;
		char k = tolower(word[i]);
		string key = "";
		key = key + k; //key is a lower letter in the word *word
		if(dico->search_value(key) == -1)
		{
			dico->add_value(key, 0);//This is not a word
		}
		if(dico->search_value(key) != 0)//We have to take this letter in account
		{

			int val = dico->search_value(key);
			string s = digits->search_key(val);
			res = res + s;
			count ++;
		}
	}
	//if count != 5 then we have to fill in with zeros
	while(count !=5)
	{
		res = res + '0';
		count++;
	}
	return res;
}

//Initiating a dictionary to associate digits with string values
void dig_init(Dico *dig)
{
	dig->add_value("1", 1);
	dig->add_value("2", 2);
	dig->add_value("3", 3);
	dig->add_value("4", 4);
	dig->add_value("5", 5);
	dig->add_value("6", 6);
}


//Initiating the dictionary to associate the letters with their corresponding values in the soundex
//Initiating other characters with value 0 so that queries with typos don't raise errors
void dico_init(Dico *dico)
{
	dico->add_value("b", 1);
	dico->add_value("f", 1);
	dico->add_value("p", 1);
	dico->add_value("v", 1);
	dico->add_value("c", 2);
	dico->add_value("g", 2);
	dico->add_value("j", 2);
	dico->add_value("k", 2);
	dico->add_value("q", 2);
	dico->add_value("s", 2);
	dico->add_value("x", 2);
	dico->add_value("z", 2);
	dico->add_value("d", 3);
	dico->add_value("t", 3);
	dico->add_value("l", 4);
	dico->add_value("m", 5);
	dico->add_value("n", 5);
	dico->add_value("r", 6);
	dico->add_value("a", 0);
	dico->add_value("e", 0);
	dico->add_value("h", 0);
	dico->add_value("i", 0);
	dico->add_value("o", 0);
	dico->add_value("u", 0);
	dico->add_value("y", 0);
	dico->add_value("w", 0);
	dico->add_value(".", 0);
	dico->add_value(";", 0);
	dico->add_value("_", 0);
	dico->add_value("/", 0);
	dico->add_value("&", 0);
	dico->add_value("1", 0);
	dico->add_value("2", 0);
	dico->add_value("3", 0);
	dico->add_value("4", 0);
	dico->add_value("5", 0);
	dico->add_value("6", 0);
	dico->add_value("7", 0);
	dico->add_value("8", 0);
	dico->add_value("9", 0);
	dico->add_value("!", 0);
	dico->add_value("é", 0);
	dico->add_value("?", 0);
	dico->add_value("%", 0);
	dico->add_value(":", 0);
	dico->add_value("^", 0);
	dico->add_value("#", 0);
	dico->add_value("~", 0);
	dico->add_value("{", 0);
	dico->add_value("(", 0);
	dico->add_value(")", 0);
	dico->add_value("|", 0);
	dico->add_value("]", 0);
	dico->add_value("}", 0);

}
