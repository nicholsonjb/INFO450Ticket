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
	string answer;
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
	
	

	do
	{
	cout << "Open new ticket? Press Y to continue " << endl;
	getline(cin, answer);
		
	cout << "Enter Customer Name: " << endl;
	getline(cin,name);
	cin.clear();
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
	cin.clear();
	cin.ignore();
	cout << "--------------------------\n\n";
	} while (answer == "Y");
	
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


//declare variables

//int numTickets = 0;
char answer;
int tickets = 0;

int main()
{

	
	const int MAXTICKETS = 100;
	Ticket myTickets[MAXTICKETS]; //Declare myTickets array
	
	
		

			for (int i = 0; i < myTickets[i].getID(); i++)
			{
				  myTickets[i].CaptureTicket();
				  
			}
			
		
				
			myTickets[MAXTICKETS].ShowTicket();
			
		
			/*myTickets[0].CloseTicket();*/
	
	

	return 0;
}
