// Parser.h: interface for the Parser class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARSER_H__79A03DC6_6CA8_4B4A_9AAD_1E378A832F09__INCLUDED_)
#define AFX_PARSER_H__79A03DC6_6CA8_4B4A_9AAD_1E378A832F09__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include <list>
#include <iostream>
//#include <string>

using namespace std;
#include "Lexer.h"

class Parser  
{
	iterator_t		m_iter;
	list<TOKEN>		m_tok;
public:
	Parser();
	virtual ~Parser();
	TOKEN	Current();
	void	Next(TOKEN tok);
	void	Process(list<TOKEN>& tok);
//	void	Rule(string str) { exit; }

	void	ruleA();
	void	ruleB();
	void	ruleC();
	void	ruleD();
	void	ruleE();
	void	ruleF();
	void	ruleG();
	void	ruleH();
	void	ruleI();
	void	ruleJ();
	void	ruleK();
	void	ruleL();
	void	ruleM();
	void	ruleN();
	void	ruleO();
	void	ruleP();
	void	ruleQ();
	void	ruleR();
	void	ruleS();
	void	ruleT();
	void	ruleU();
	void	ruleV();
	void	ruleW();
	void	ruleO1();
	void	ruleQ1();
	void	ruleR1();
	void	ruleS1();
};

#endif // !defined(AFX_PARSER_H__79A03DC6_6CA8_4B4A_9AAD_1E378A832F09__INCLUDED_)
