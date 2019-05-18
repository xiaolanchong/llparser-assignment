// LL.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <list>

#include "Lexer.h"
#include "Parser.h"
 
using namespace std;

int main(int /*argc*/, char* /*argv*/[])
{
	Lexer			lex;
	ifstream		file("sample.txt");
	list<string>	lststr;
	string			s;
//	file.
	while(!(file >> s).fail())
	{
		lststr.push_back(s);
//		cout << s << endl;
	}
	list<TOKEN> lsttok = lex.Process(lststr);
	iterator_t titer = lsttok.begin();
	cout << "********************************************" << endl;
	cout << "File's tokens : " << endl;
	while(titer != lsttok.end())
	{
		switch(*titer)
		{
		case  TYPE: cout << "TYPE" << endl;
					break;
		case  IF: cout << "IF" << endl;
					break;
		case  ELSE: cout << "ELSE" << endl;
					break;
		case  FOR: cout << "FOR" << endl;
					break;
		case  IDENT: cout << "ident" << endl;
					break;
		case  LITER: cout << "Liter" << endl;
					break;
		case  PLMIN: cout << "PlusMin" << endl;
					break;
		case  BRCON: cout << "br-con" << endl;
					break;
		case  OPEN_RND_BR: cout << "(" << endl;
					break;
		case  CLOSE_RND_BR: cout << ")" << endl; 
					break;
		case  OPEN_FIG_BR: cout << "{" << endl; 
					break;
		case  CLOSE_FIG_BR: cout << "}" << endl; 
					break;
		case  RETURN: cout << "return" << endl; 
					break;
		case  SEPAR :cout << ";" << endl; 
					break;
		default:	cout << "Unkn" << endl;
		}
		titer++;
	}
	cout <<endl;
	Parser par;
	cout << "*****************Parser's rules************************" << endl;
	par.Process(lsttok);
	return 0;
}
/*
IDENT, LITER, PLMIN, FOR, ELSE, BRCON, 
				IF, OPEN_RND_BR, RETURN, CLOSE_RND_BR, TYPE, 
				OPEN_FIG_BR, CLOSE_FIG_BR, SEPAR };
				*/