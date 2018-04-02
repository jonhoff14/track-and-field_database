#ifndef ATHLETE_H
#define ATHLETE_H
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include "Check_Event_Type.h"
using namespace std;

class Athlete {
public:

	// Default constructor
	Athlete(){}
	// Constructor
    Athlete(string name) : athlete_name(name) {}
	
	void set_event(string e_name, string mark) {
		if ( Is_Event(e_name) )
			events[e_name] = mark;			
	}
    
	// Virtual in order to allow children class to overide this member function
	virtual string get_event_mark(string e_name) {
		if ( Is_Event(e_name) ) {
			map<string, string>::iterator it;
			for ( it = events.begin(); it != events.end(); it++)
			{
				if ( it->first == e_name )
					return it->second;
			}
		}
		return "";
	}

	void display_all_events() {
		map<string, string>::iterator it;
		for ( it = events.begin(); it != events.end(); it++)
		{
			cout << it->first << " : " << it->second << endl;
		}
		cout << "\n\n";
	}

	// Check to see if athlete contains event
	bool check_all_events(string e_name) {
		map<string, string>::iterator it;
		for ( it = events.begin(); it != events.end(); it++)
		{
			if ( it->first == e_name )
				return true;
		}

		return false;
	}

	// Choose event to display and return mark
	string display_spec_event(string e_name) {
		map<string, string>::iterator it;
		for ( it = events.begin(); it != events.end(); it++)
		{
			if ( it->first == e_name )
				return it->second;
		}
	}

	string get_name() {return athlete_name;}

protected:
	map<string, string> events;
	string athlete_name;
	string event_name;
	string event_mark;
};

class Event_Group_Athlete : public Athlete {
public:

	Event_Group_Athlete() {}
	Event_Group_Athlete(string a_name, string e_name, string mark) {
		athlete_name = a_name;
		event_name = e_name;
		event_mark = mark;
	}
	
	// Return event name
	string get_event_name() {return event_name;}

	// Return event mark
	string get_event_mark() {return event_mark;}
	
};

// Functor to overload operator in order to sort vector by mark
class Compare_By_Mark {
public:
    bool operator() (Event_Group_Athlete &left, Event_Group_Athlete &right) {
        return (left.get_event_mark() > right.get_event_mark());
    }
};

// Functor to overload operator in order to sort vector by time
class Compare_By_Time {
public:
    bool operator() (Event_Group_Athlete &left, Event_Group_Athlete &right) {
        return (left.get_event_mark() < right.get_event_mark());
    }
};

#endif