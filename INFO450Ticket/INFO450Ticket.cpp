// INFO450Ticket.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class Ticket
{
	static int IDGenerator;
	int ID;
	char ticketStatus[50];
	char issueType[50];
	int usersImpacted;
	char name[50];
	char ticketDescription[500];
public:

	Ticket();
	int getID();
	void CaptureTicket();
	void ShowTicket();
	void CloseTicket();


};

//Ticket IDGenerator
int Ticket::IDGenerator = 1;

Ticket::Ticket()
{
	ID = IDGenerator++;
}

int Ticket::getID()
{
	return ID;
}

//Metod to CaptureTicket Info
void Ticket::CaptureTicket()
{

	cout << "enter ticket status: " << endl;
	gets_s(ticketStatus);
	cout << "What is the Name of the Caller? " << endl;
	gets_s(name);
	cout << "Issue Type? S=Server, A=Application, C=aCess" << endl;
	gets_s(issueType);
	cout << "Description of issue? " << endl;
	gets_s(ticketDescription);
	cout << "How many users impacted? " << endl;
	cin >> usersImpacted;

}

void Ticket::ShowTicket()
{
	
}


int main()
{

	
    return 0;
}

