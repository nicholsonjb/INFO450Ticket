// INFO450Ticket.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <stdio.h>
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
	cout << "Your issue ID is : " << ID << endl;
	cout << "--------------------------\n\n";
	
	
}

//Method of TicketDisplay
void Ticket::ShowTicket()
{
	cout << "--------------------------\n";
	cout << "Ticket Listing: " << endl;
	cout << "--------------------------\n\n";
	cout << "Ticket ID: " << ID << endl;
	cout << "Type: " << issueType <<endl;
	cout << "Status: " << ticketStatus << endl;
	cout << "Description: " <<  ticketDescription << endl;
	cout << "User: " << name << endl;
	cout << "Users Impacted: " << usersImpacted << endl;
	cout << "Priroity: " << ticketPriority << endl;
	cout << "--------------------------\n\n";

	
}

void Ticket::CloseTicket()
{
	ticketStatus = "closed";
	cout << "Ticket number " << ID <<" is " << ticketStatus << endl;
}




int main()
{
	const int MAXTICKETS = 100;
	char ans;
	Ticket myTickets[MAXTICKETS];
	int totalTickets = 0;
	totalTickets++;
	
	do {
		cout << "Open new ticket ? enter Y to continue " << endl;
		cin >> ans;
		cin.clear();
		cin.ignore(2, '\n');

		
	for ( int i = 0; i < totalTickets; i++ )
		 { 	
		 myTickets[i].CaptureTicket();
		
		 }
		
		 for (int i = 0; i < totalTickets; i++)
		 {
			 myTickets[i].ShowTicket();
			 
		 }
		
		 
		 
} while (ans != 'Y' && ans != 'y');

	myTickets[0].CloseTicket();
	 
	return 0;
}
