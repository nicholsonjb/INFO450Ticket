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
	char ticketStatus;
	char ticketIssueType;
	int ticketPriority;
	char name;
	char ticketDescription;
public:

	ticket();
	int getID();
	int CaptureTicket();
	void ShowTicket();
	void CloseTicket();


};


int main()
{
    return 0;
}

