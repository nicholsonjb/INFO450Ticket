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
	string ticketPriority;
	string ticketIssueType;
	string issueType;
	int usersImpacted;
	string name;
	string ticketDescription;
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
	getline(cin,name);
	cout << "Issue type: Issue Type? S=Server, A=Application, C=aCcess " << endl;
	getline(cin,ticketIssueType);
		if (ticketIssueType == "S" || ticketIssueType =="s")
		{
			issueType = "Server";
		}
		if (ticketIssueType == "A" || ticketIssueType == "a")
		{
			issueType = "Application";
		}
		if (ticketIssueType == "C" || ticketIssueType == "c")
		{
			issueType = "Access";
		}

	cout << "Description of Issue? " << endl;
	cout << issueType << endl;
	getline(cin,ticketDescription);
	
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
		if (usersImpacted >= 50)
		{
		ticketPriority = "HIGH";
		}
	cout << "Ticket status: " << ticketStatus << endl;
	cout << "Your issue ID is : " << ID << endl;
	cout << "--------------------------\n";
	cin.clear();
	cin.ignore();
}

//Method of TicketDisplay
void Ticket::ShowTicket()
{
	cout << "Ticket Listing: " << endl;
	cout << "Ticket ID: " << ID << endl;
	cout << "Type: " << issueType <<endl;
	cout << "Status: " << ticketStatus << endl;
	cout << "Description: " <<  ticketDescription << endl;
	cout << "User: " << name << endl;
	cout << "Users Impacted: " << usersImpacted << endl;
	cout << "Priroity: " << ticketPriority << endl;

	
}

void Ticket::CloseTicket()
{
	ticketStatus = "close";
}



int main()
{
	const int TICKETNUMBERS = 100;
	Ticket systemTickets[TICKETNUMBERS];
	
	systemTickets[TICKETNUMBERS].CaptureTicket();
	systemTickets[TICKETNUMBERS].ShowTicket();
	/*systemTickets[0].CloseTicket();*/
	return 0;
}

