#include "word.h"
#include "anex.h"
#include "dico.h"
#include "soundex.h"
#include "bgroup.h"

#include <iostream>
#include <string>
using namespace std;

Word::Word()
{
	Dico *m_dico;
	Dico *m_prob;
	Dico *m_dig;
	Soundex *m_s;
	Bgroup *m_bgp;
}

int Word::len()
{
	return m_word.length();
}

Word::Word(string word)
{
	m_word = word;
	Dico *m_dico;
	Dico *m_prob;
	Dico *m_dig;
	Soundex *m_s;
	Bgroup *m_bgp;
	m_word = word;
}

Word::~Word()
{

}

void Word::set_word(string word)
{
	m_word = word;
}

int Word::EditingDistance(Word word)
{
    int NbRow = len(), NbCol = word.len();
    unsigned int tab[NbRow][NbCol];
    int CoutSub, i, j;

        // Initialisation du tableau
    for (i=0; i < NbRow+1 ; i++)
        for(j=0; j < NbCol+1; j++)
            tab[i][j] = 0;

    for (i=0; i< NbRow; i++) tab[i][0] = i;
    for (j=0; j< NbCol; j++) tab[0][j]= j;

    for (i = 1; i<NbRow; i++){
        for (j = 1; j<NbCol; j++){
                if (m_word[i] == word.m_word[j]) CoutSub = 0;

                else CoutSub = 1;

                tab[i][j] = std::min(tab[i-1][j] +1, std::min(tab[i][j-1] + 1, tab[i-1][j-1]+CoutSub));
                }
    }

        return(tab[NbRow-1][NbCol-1]);
}

string Word::solve(char* entry)
{
	string word = str_of_chr(entry);
	set_word(word);
	Word new_word;
	Word word_min;
	int d_min = 100;
	int occur_max = 0;
	int d, occur;
	string out = calculate_soundex(m_dig, m_dico, entry);
	char first = toupper(entry[0]);
	if(!m_bgp->isInBgroup(out))
	{
		for(int i = 0; i< m_bgp->m_len; i++)
		{
			if(first == ((m_bgp->m_groups[i])->m_first))
			{
				for(int k = 0; k< m_bgp->m_groups[i]->m_len; k++)
				{
					new_word.set_word(((m_bgp->m_groups[i])->m_keys[k]).m_key);
					d = EditingDistance(new_word);
					occur = m_prob->search_value(((m_bgp->m_groups[i])->m_keys[k]).m_key);
					if(d < d_min)
					{
						word_min.set_word(((m_bgp->m_groups[i])->m_keys[k]).m_key);
						d_min = d;
						occur_max = occur;
					}
					else if(d == d_min)
					{
						if(occur_max < occur)
						{
							word_min.set_word(((m_bgp->m_groups[i])->m_keys[k]).m_key);
							occur_max = occur;
						}
					}
				}
			}
		}
	}
	else
	{
		
		if(first == ((m_bgp->corres_group(out))->m_first))
		{
			for(int k = 0; k< m_bgp->corres_group(out)->m_len; k++)
			{
				new_word.set_word(((m_bgp->corres_group(out))->m_keys[k]).m_key);
				d = EditingDistance(new_word);
				occur = m_prob->search_value(((m_bgp->corres_group(out))->m_keys[k]).m_key);
				if(d < d_min)
				{
					word_min.set_word(((m_bgp->corres_group(out))->m_keys[k]).m_key);
					d_min = d;
					occur_max = occur;
				}
				else if(d == d_min)
				{
					if(occur_max < occur)
					{
						word_min.set_word(((m_bgp->corres_group(out))->m_keys[k]).m_key);
						occur_max = occur;
					}
				}
			}
		}
	}
	return word_min.m_word;

}

