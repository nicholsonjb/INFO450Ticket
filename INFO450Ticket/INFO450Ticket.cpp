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
	char ticketIssueType[50];
	int ticketPriority;
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
	cout << "Enter Customer Name: " << endl;
	gets_s(name);
	cout << "enter ticket status: " << endl;
	gets_s(ticketStatus);
	cout << "E"

}


int main()
{

	
    return 0;
}

