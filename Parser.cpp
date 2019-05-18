// Parser.cpp: implementation of the Parser class.
//
//////////////////////////////////////////////////////////////////////

#include "Parser.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#define RUL(x)	cout << x << endl;
#define ERR		{cout << "Unexpected symbol" << endl;exit(1);} 

Parser::Parser()
{

}

Parser::~Parser()
{

}

void	Parser::Process(list<TOKEN>& tok)
{
	m_tok = tok;
	m_iter = m_tok.begin();
	ruleA();
	
}

TOKEN	Parser::Current()
{
	if(m_iter == m_tok.end())
		return NUL;
	else
		return *m_iter;
}

void	Parser::Next(TOKEN tok)
{
	if(*m_iter != tok)
		ERR
	else
		m_iter++;
}

/////////////////////////////////////////////////////////////

void	Parser::ruleA()
{
	if(	Current() == TYPE	||
		Current() == LITER	||
		Current() == FOR	||
		Current() == IF		||
		Current() == RETURN		)
	{
		RUL("A -> BA")
		ruleB();
		ruleA();
	}
	else
	{
		RUL("A -> Null")
	}
}

void	Parser::ruleB()
{
	if(Current() == TYPE)
	{
		RUL("B -> C")
		ruleC();
	}
	else if(Current() == LITER)
	{
		RUL("B -> G");
		ruleG();
	}
	else if(Current() == FOR)
	{
		RUL("B -> K");
		ruleK();
	}
	else if(Current() == IF)
	{
		RUL("B -> O");
		ruleO();
	}
	else if(Current() == RETURN)
	{
		RUL("B -> T");
		ruleT();
	}
	else 
		ERR
}

void	Parser::ruleC()
{
	RUL("C->Type Ident D")
	Next(TYPE);
	Next(IDENT);
	ruleD();
}

void	Parser::ruleD()
{
	if(Current() == COMMA)
	{
		RUL("D ->, Ident D");
		Next(COMMA);
		Next(IDENT);
		ruleD();
	}
	else if(Current() == SEPAR)
	{
		RUL("D -> ;");
		Next(SEPAR);
	}
	else 
		ERR
}

void	Parser::ruleE()
{
	RUL("E ->Type Ident F")
	Next(TYPE);
	Next(IDENT);
	ruleF();
}

void	Parser::ruleF()
{
	if(Current() == COMMA)
	{
		RUL("F-> , Ident F");
		Next(COMMA);
		Next(IDENT);
		ruleF();
	}
	else 
	{
		RUL("F -> Null")
	}
}

void	Parser::ruleG()
{
	RUL("G -> Liter H")
	Next(LITER);
	ruleH();
}

void	Parser::ruleH()
{
	if(Current() == PLMIN)
	{
		RUL("H -> +- G");
		Next(PLMIN);
		ruleG();
	}
	else if(Current() == SEPAR)
	{
		RUL("H -> ;");
		Next(SEPAR);
	}
	else 
		ERR	
}

void	Parser::ruleI()
{
	RUL("I -> Liter J")
	Next(LITER);
	ruleJ();
}

void	Parser::ruleJ()
{
	if(Current() == PLMIN)
	{
		RUL("J -> +- I");
		Next(PLMIN);
		ruleI();
	}
	else
	{
		RUL("J -> Null");
	}
}

void	Parser::ruleK()
{
	if(Current() == FOR)
	{
		RUL("K-> for(L;L;L) M");
		Next(FOR);
		Next(OPEN_RND_BR);
		ruleL();
		Next(SEPAR);
		ruleL();
		Next(SEPAR);
		ruleL();
		Next(CLOSE_RND_BR);
		ruleM();
	}
	else
	{
		ERR
	}
}

void	Parser::ruleL()
{
	if(Current() == TYPE)
	{
		RUL("L-> E")
		ruleE();
	}
	else if( Current() == LITER )
	{
		RUL("L -> I")
		ruleI();
	}
	else
	{
		RUL("L -> Null")
	}
}

void	Parser::ruleM()
{
	if(	Current() == TYPE	||
		Current() == LITER	||
		Current() == FOR	||
		Current() == IF		||
		Current() == RETURN	||
		Current() == BRCON		)
	{
		RUL("M -> V")
		ruleV();
	}
	else if(Current() == SEPAR)
	{
		RUL("M -> ;");
		Next(SEPAR);
	}
	else if(Current() == OPEN_FIG_BR)
	{
		RUL("M -> {W}");
		Next(OPEN_FIG_BR);
		ruleW();
		Next(CLOSE_FIG_BR);
	}
	else 
		ERR
}

void	Parser::ruleN()
{
	
}

void	Parser::ruleO()
{
//	iCurrent() == IF)
	RUL("O -> if(P)Q")
	Next(IF);
	Next(OPEN_RND_BR);
	ruleP();
	Next(CLOSE_RND_BR);
	ruleQ();
}

void	Parser::ruleP()
{
	if(Current() == TYPE)
	{
		RUL("P -> E");
		ruleE();
	}
	else if (Current() == LITER)
	{
		RUL("P -> I")
		ruleI();
	}
	else 
		ERR
}

void	Parser::ruleQ()
{
	if(	Current() == TYPE	||
		Current() == LITER	||
		Current() == FOR	||
		Current() == IF		||
		Current() == RETURN		)
	{
		RUL("Q -> BR")
		ruleB();
		ruleR();
	}
	else if(Current() == OPEN_FIG_BR)
	{
		RUL("Q -> {A}R")
		Next(OPEN_FIG_BR);
		ruleA();
		Next(CLOSE_FIG_BR);
		ruleR();
	}	
}

void	Parser::ruleR()
{
	if(Current() == ELSE)
	{
		RUL("R -> else S")
		Next(ELSE);
		ruleS();
	}
	else
	{
		RUL("R -> Null")
	}
}

void	Parser::ruleS()
{
	if(	Current() == TYPE	||
		Current() == LITER	||
		Current() == FOR	||
		Current() == IF		||
		Current() == RETURN		)
	{
		RUL("S -> B")
		ruleB();
	}
	else if(Current() == OPEN_FIG_BR)
	{
		RUL("S -> {A}")
		Next(OPEN_FIG_BR);
		ruleA();
		Next(CLOSE_FIG_BR);
	}			
}

void	Parser::ruleT()
{
	RUL("return U")
	Next(RETURN);
	ruleU();	
}

void	Parser::ruleU()
{
	if(Current() == SEPAR)
	{
		RUL("U -> ;")
		Next(SEPAR);
	}
	else if(Current() == LITER)
	{
		RUL("U -> G")
		ruleG();
	}
}

void	Parser::ruleV()
{
	if(Current() == TYPE)
	{
		RUL("V -> C")
		ruleC();
	}
	else if(Current() == LITER)
	{
		RUL("V -> G");
		ruleG();
	}
	else if(Current() == FOR)
	{
		RUL("V -> K");
		ruleK();
	}
	else if(Current() == IF)
	{
		RUL("V -> O1");
		ruleO1();
	}
	else if(Current() == RETURN)
	{
		RUL("V -> T");
		ruleT();
	}
	else if(Current() == BRCON)
	{
		RUL("V -> break/continue;")
		Next(BRCON);
		Next(SEPAR);
	}
	else
		ERR
}

void	Parser::ruleW()
{
	if(	Current() == TYPE	||
		Current() == LITER	||
		Current() == FOR	||
		Current() == IF		||
		Current() == RETURN	||
		Current() == BRCON	)
	{
		RUL("W -> VW")
		ruleV();
		ruleW();
	}
	else
	{
		RUL("W -> Null")
	}
}

void	Parser::ruleO1()
{
	RUL("O -> if(P) Q1")
	Next(IF);
	Next(OPEN_RND_BR);
	ruleP();
	Next(CLOSE_RND_BR);
	ruleQ1();	
}

void	Parser::ruleQ1()
{
	if(	Current() == TYPE	||
		Current() == LITER	||
		Current() == FOR	||
		Current() == IF		||
		Current() == RETURN	||
		Current() == BRCON		)
	{
		RUL("Q1 -> VR1")
		ruleV();
		ruleR1();
	}
	else if(Current() == OPEN_FIG_BR)
	{
		RUL("Q1 -> {W}R1")
		Next(OPEN_FIG_BR);
		ruleW();
		Next(CLOSE_FIG_BR);
		ruleR1();
	}	
}

void	Parser::ruleR1()
{
	if(Current() == ELSE)
	{
		RUL("R1 -> else S1")
		Next(ELSE);
		ruleS1();
	}
	else
	{
		RUL("R1 -> Null")
	}
}

void	Parser::ruleS1()
{
	if(	Current() == TYPE	||
		Current() == LITER	||
		Current() == FOR	||
		Current() == IF		||
		Current() == RETURN	||
		Current() == BRCON		)
	{
		RUL("S1 -> V")
		ruleV();
	}
	else if(Current() == OPEN_FIG_BR)
	{
		RUL("S1 -> {W}")
		Next(OPEN_FIG_BR);
		ruleW();
		Next(CLOSE_FIG_BR);
	}	
}