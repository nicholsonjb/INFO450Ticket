// INFO450Ticket.cpp : Defines the entry point for the console application.
//Author: James Nicholson
//Spring 2017
//Purpose: Write a program  that collects input to track technical support tickets 
//for issues called into a help center
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
	ticketStatus = "OPEN";
}

int Ticket::getID()
{
	return ID;
}

//Method to CaptureTicket Info
void Ticket::CaptureTicket()
{
	cout << "What is the Name of the Caller?" << endl;
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


	cout << "Your issue ID is: " << ID << endl;
	cin.clear();
	cin.ignore();
	cout << "--------------------------" << endl;
}

//Method to TicketDisplay
void Ticket::ShowTicket()
{
	cout << "--------------------------\n";
	cout << "Ticket Listing: " << endl;
	cout << "--------------------------\n\n";
	cout << "Ticket ID: " << ID << endl;
	cout << "Type: " << issueType << endl;
	cout << "Status: " << ticketStatus << endl;
	cout << "Description: " << ticketDescription << endl;
	cout << "User: " << name << endl;
	cout << "Users Impacted: " << usersImpacted << endl;
	cout << "Priroity: " << ticketPriority << endl;
	cout << "--------------------------\n\n";
}

void Ticket::CloseTicket()
{
	ticketStatus = "CLOSED!";
	cout << "Ticket number " << ID << " is " << ticketStatus << endl;
}


int main()
{
	int newTickets = 0;
	const int MAXTICKETS = 100;
	char choice;
	Ticket myTickets[MAXTICKETS]; //Declare myTickets array

	cout << "Welcome to the Information Help Desk " << endl;
	cout << "-------------------------------------\n\n";
	do
	{
		myTickets[newTickets].CaptureTicket();
		newTickets++;
		cout << "Do you want to open another ticket? Y/N" << endl;
		cin >> choice;
	}
	while (choice == 'Y');

	for (int i = 0; i < newTickets; i++)
	{
		myTickets[i].ShowTicket();
	}

	myTickets[0].CloseTicket();

	return 0;
}
