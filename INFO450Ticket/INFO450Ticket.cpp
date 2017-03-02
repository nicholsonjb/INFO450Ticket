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
	string ticketStatus;
	char ticketIssueType[50];
	int ticketPriority;
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
	ticketStatus = "open";
}

int Ticket::getID()
{
	return ID;
}

//Metod to CaptureTicket Info
void Ticket::CaptureTicket()
{
	cout << "Enter Customer Name: " << endl;
		gets_s(name);
	cout << "Issue type: Issue Type? S=Server, A=Application, C=aCcess " << endl;
		gets_s(ticketIssueType);
	cout << "Description of Issue? " << endl;
		gets_s(ticketDescription);
	cout << "How many users impacted? " << endl;
		cin >> usersImpacted;
	cout << "Ticket status: " << ticketStatus << endl;
	
}


int main()
{

	
    return 0;
}

