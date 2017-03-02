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
	string ticketIssueType;
	string ticketPriority;
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
	getline(cin,ticketIssueType);
	cout << "Description of Issue? " << endl;
	gets_s(ticketDescription);
	cout << "How many users impacted? " << endl;
	cin >> usersImpacted;
		if (usersImpacted < 10)
		{
			ticketPriority = "Low";
		}
	if (usersImpacted >= 10 && usersImpacted < 50)
	{
		ticketPriority = "MED";
	}
	if (usersImpacted < 50)
	{
		ticketPriority = "HIGH";
	}
	cout << "Ticket status: " << ticketStatus << endl;
	cout << "Your ID number is: " << ID << endl;
}

//Method of TicketDisplay
void Ticket::ShowTicket()
{
	
}

void Ticket::CloseTicket()
{
	ticketStatus = "close";
}



int main()
{

	Ticket one;
	
	one.CaptureTicket();
	one.ShowTicket();
	one.CloseTicket();
	return 0;
}

