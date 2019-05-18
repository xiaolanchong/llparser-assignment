// Lexer.cpp: implementation of the Lexer class.
//
//////////////////////////////////////////////////////////////////////

#include "Lexer.h"
#include <ctype.h>
#include <iostream>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Lexer::Lexer()
{
}

Lexer::~Lexer()
{

}

list<TOKEN>	Lexer::Process(list<string>& lst)
{
	list<TOKEN> tok;
	iterator_t	itok = tok.begin();
	iterator_s	istr = lst.begin();
	while( istr != lst.end())
	{
		string s = *istr;
		int gpos = 0;
		do 
		{
			AutoId autom;
			int lpos = gpos;
			string nowlexstr;
			while(autom.GetLetter(s[lpos++]))
			{
				nowlexstr += s[lpos-1];
	//			break;
			}
			if(nowlexstr != "")
			{
				tok.push_back(IsKeyword(nowlexstr));
				gpos = lpos-1;
			}
			else
			{
				if(IsNumber(s, gpos))
					tok.push_back(LITER);
				if(s[gpos])
					tok.push_back(IsToken(s[gpos]));
				gpos++;
			}
		
		}
		while(gpos < static_cast<int>(s.length())) ;
		istr++;
	}
	return tok;
}

bool	Lexer::AutoId::GetLetter(char ch )
{
	switch(st)
	{
	case START:	if(isalpha(ch))
				{
					st = LETTER;
					return true;
				}
				return false;
	case LETTER:if(isalpha(ch) || (ch >= '0' && ch <= '9'))
					 return true;
				else
					return false;

	}
	return false;
}

TOKEN Lexer::IsKeyword(string str)
{
	if(str == "if")
		return IF;
	else if (str == "else")
		return ELSE;
	else if (str == "break" || str == "continue")
		return BRCON;
	else if(str == "return")
		return RETURN;
	else if(str == "for")
		return FOR;
	else if(str == "int" || str == "float" || str == "double")
		return TYPE;
	return IDENT;
}

TOKEN	Lexer::IsToken(char ch)
{
	switch(ch)
	{
	case '(' : return OPEN_RND_BR;
	case ')' : return CLOSE_RND_BR;
	case '+' : 
	case '-' : return PLMIN;
	case '{' : return OPEN_FIG_BR;
	case '}' : return CLOSE_FIG_BR;
	case ';' : return SEPAR;
	case ',' : return COMMA;
	}
	cerr << "Unknown symbol : " << ch << endl;
	exit(1);
}

bool	Lexer::IsNumber(string str, int& pos)
{
	int lpos = pos;
	while(str[pos] >= '0' && str[pos] <= '9') pos++;
	if(lpos == pos)
		return false;
	if(str[pos] != '.')
		return true;
	lpos = ++pos;
	while(str[pos] >= '0' && str[pos] <= '9') pos++;
	if(lpos == pos)
	{
		pos--;
		return false;
	}
	return true;
}