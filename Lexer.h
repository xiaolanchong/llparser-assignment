// Lexer.h: interface for the Lexer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LEXER_H__FDB6B66B_7660_4F29_A664_59018C73F58C__INCLUDED_)
#define AFX_LEXER_H__FDB6B66B_7660_4F29_A664_59018C73F58C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <list>
#include <string> 

using namespace std;

enum TOKEN {	IDENT, LITER, PLMIN, FOR, ELSE, BRCON, 
				IF, OPEN_RND_BR, RETURN, CLOSE_RND_BR, TYPE, 
				OPEN_FIG_BR, CLOSE_FIG_BR, SEPAR , COMMA, NUL };

typedef list<string>::iterator iterator_s;
typedef list<TOKEN>::iterator iterator_t;

class Lexer  
{
public:

	Lexer();
	virtual ~Lexer();
	list<TOKEN> Process(list<string>& lst);
//	TOKEN	GetToken(string str);
	TOKEN	IsKeyword(string str);
	TOKEN	IsToken(char ch);
	bool	IsNumber(string str, int& pos);
	class AutoId
	{
		enum	STATE { START, LETTER };
		STATE	st;
	public:
		AutoId() : st(START) {};
		bool	GetLetter(char ch ) ;
		bool	CheckState() { return st == LETTER; } ;

	};
};

#endif // !defined(AFX_LEXER_H__FDB6B66B_7660_4F29_A664_59018C73F58C__INCLUDED_)
