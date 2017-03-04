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
	/*bool continueTicket();*/


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
	char ans;
	

	do 
	{	
		cout << "Open new ticket?  enter Y to continue Press. " << endl;
		cin.get(ans);
		cin.ignore();
		
		cout << "Enter Customer Name:" << endl;
		getline(cin, name);

		cout << "Issue type: Issue Type? S=Server, A=Application, C=aCcess" << endl;
		getline(cin, ticketIssueType);

		if (ticketIssueType == "S" || ticketIssueType == "s")
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

		cout << "Description of Issue?" << endl;
		cout << issueType << endl;
		getline(cin, ticketDescription);

		cout << "How many users impacted?" << endl;
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

		cin.ignore();
		cout << "Your issue ID is: " << ID << endl;
		cout << "--------------------------" << endl;
		
	} while (ans !='n' && ans !='n');
	
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
	cin.clear();
	cin.ignore();
}

//Method  to continue
//bool Ticket::continueTicket()
//{
//
//	cout << "Open new ticket?  enter Y to continue Press. \n"
//		<< "Or press 0 to stop: \n";
//	
//	return (cin.get() != '0');
//	
//}


int main()
{

	
	const int MAXTICKETS = 100;
	Ticket myTickets[MAXTICKETS]; //Declare myTickets array
	
	
	for (int i = 0; i < MAXTICKETS; i++)
	{
		myTickets[i].CaptureTicket();
	}
	for (int i = 0; i < MAXTICKETS; i++)
	{
		myTickets[i].ShowTicket();
		myTickets[0].CloseTicket();
	}
	

	return 0;
}
