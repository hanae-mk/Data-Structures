#pragma once

#include <iostream>
#include "clsDate.h"
#include <stack>   //STL Library
#include <queue>   //STL Library

using namespace std;

class clsQueueLine
{
private:

	string _Prefix = "";
	short _TotalTickets = 0;
	short _AverageServeTime = 0;

	//Sub Class
	class clsTicket
	{
	private:

		string _Prefix = "";
		short _Number = 0;
		string _TicketTime = "";
		short _WaitingClients = 0;
		short _AverageServeTime = 0;
		
	public:

		clsTicket(string Prefix, short Number, short WaitingClients, short AverageServeTime)
		{
			_Prefix = Prefix;
			_Number = Number;
			_TicketTime = clsDate::GetSystemDateTimeString();
			_WaitingClients = WaitingClients;
			_AverageServeTime = AverageServeTime;
		}

		//Those Properties Are Read Only

		string Prefix() 
		{
			return _Prefix; 
		}

		short Number() 
		{
			return _Number;
		}

		string FullNumber()
		{
			return _Prefix + to_string(_Number);
		}

		string TicketTime()
		{
			return _TicketTime;
		}

		short WaitingClients()
		{
			return _WaitingClients;
		}

		short AverageServeTime()
		{
			return _AverageServeTime * _WaitingClients;
		}

		void Print()
		{	
			cout << "\n\t\t\t   _______________________\n";
			cout << "\n\t\t\t\t     " << FullNumber();
			cout << "\n\n\t\t\t    " << _TicketTime;
			cout << "\n\t\t\t    Waiting Clients = " << _WaitingClients;
			cout << "\n\t\t\t\tServe Time In";
			cout << "\n\t\t\t\t " << AverageServeTime() << " Minutes.";
			cout << "\n\t\t\t   _______________________\n";			
		}
	};

public:

	queue <clsTicket> QueueLine;

	clsQueueLine(string Prefix, short AverageServeTime)
	{
		_Prefix = Prefix;
		_TotalTickets = 0;
		_AverageServeTime = AverageServeTime;
	}

	void IssueTicket()
	{
		_TotalTickets++;
		clsTicket Ticket(_Prefix, _TotalTickets, WaitingClients(), _AverageServeTime); //New Ticket
		QueueLine.push(Ticket);
	}

	short WaitingClients()
	{
		return QueueLine.size();
	}

	string WhoIsNext()
	{
		if (QueueLine.empty())
			return "\nNo Clients Left.\n";
		else
			return QueueLine.front().FullNumber();
	}

	bool ServeNextClient()
	{
		if (QueueLine.empty())
			return false;
		
		QueueLine.pop();
		   return true;
	}

	short ServedClients()
	{
		return _TotalTickets - WaitingClients();
	}

	void PrintInfo()
	{
		cout << "\n\t\t\t______________________________\n";
		cout << "\n\t\t\t\t   Queue Info";
		cout << "\n\t\t\t______________________________\n";
		cout << "\n\t\t\t  Prefix          = " << _Prefix;
		cout << "\n\t\t\t  Total Tickets   = " << _TotalTickets;
		cout << "\n\t\t\t  Served Clients  = " << ServedClients();     /*_ServedClients*/
		cout << "\n\t\t\t  Waiting Clients = " << WaitingClients();    /*_WaitingClients*/
		cout << "\n\t\t\t  Next Client     = " << WhoIsNext();
		cout << "\n\t\t\t______________________________\n\n";
	}

	void PrintTicketsLineRTL()
	{
		cout << "\n\t\tTickets : ";

		if (QueueLine.empty())
			cout << "No Tickets.\n";
			
		else
		{
			//we copy the queue in order to not lose the original queue
			queue <clsTicket> TempQueueLine = QueueLine;

			while (!TempQueueLine.empty())
			{
				clsTicket Ticket = TempQueueLine.front();
				cout << " " << Ticket.FullNumber() << " <-- ";
				TempQueueLine.pop();
			}
		}

		cout << "\n";
	}

	void PrintTicketsLineLTR()
	{
		cout << "\n\t\tTickets : ";

		if (QueueLine.empty())
			cout << "No Tickets.\n";

		else
		{
			queue <clsTicket> TempQueueLine = QueueLine;
			stack <clsTicket> TempStackLine;

			while (!TempQueueLine.empty())
			{		
				TempStackLine.push(TempQueueLine.front());
				TempQueueLine.pop();
			}

			while (!TempStackLine.empty())
			{
				clsTicket Ticket = TempStackLine.top();
				cout << " " << Ticket.FullNumber() << " --> ";
				TempStackLine.pop();
			}
		}

		cout << "\n";
	
	}

	void PrintAllTickets()
	{
		cout << "\n\n\n\t\t\t\t---Tickets---";

		if (QueueLine.empty())
			cout << "\n\n\n\t\t\t\t ---No Tickets---\n";

		queue <clsTicket> TempQueueLine = QueueLine;

		while (!TempQueueLine.empty())
		{
			TempQueueLine.front().Print();
			TempQueueLine.pop();
		}
	}
	

	

	





};

