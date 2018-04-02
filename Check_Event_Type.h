#ifndef CHECK_EVENT_TYPE_H
#define CHECK_EVENT_TYPE_H

#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

bool Check_Event_Type(string e_name) {
	string events_array[] = {
		"Long_Jump",
		"Triple_Jump",
		"High_Jump",
		"Pole_Vault",
		"Javelin_Throw",
		"Hammer_Throw",
		"Discus_Throw",
		"Shot_Put",
		"Decathlon",

		"110_Hurdles",
		"400_Hurdles",
		"100m",
		"200m",
		"400m",
		"800m",
		"1500m",
		"Steeple",
		"5000m",
		"10000m",
		"4x100m",
		"4x400m"
	};
	
	for ( int i = 0; i < 9; i++) {
		if ( e_name == events_array[i] )
			return true;
	}

	for ( int i = 9; i < sizeof(events_array) / sizeof(string); i++) {
		if ( e_name == events_array[i] )
			return false;
	}

	// If event is not found in list, abort program
	//cout << "ERROR! " << e_name << "does not match any of the event names. Program aborted.\n";
	printf("ERROR!\n");

	exit (1);
}

bool Is_Event(string e_name) {
	string events_array[] = {
		"Long_Jump",
		"Triple_Jump",
		"High_Jump",
		"Pole_Vault",
		"110_Hurdles",
		"400_Hurdles",
		"Javelin_Throw",
		"Hammer_Throw",
		"Discus_Throw",
		"Shot_Put",
		"Decathlon",
		"100m",
		"200m",
		"400m",
		"800m",
		"1500m",
		"Steeple",
		"5000m",
		"10000m",
		"4x100m",
		"4x400m"
	};
	
	for ( int i = 0; i < sizeof(events_array) / sizeof(string); i++) {
		if ( e_name == events_array[i] )
			return true;
	}

	// If event is not found in list, abort program
	//cout << "ERROR! " << e_name << "does not match any of the event names. Program aborted.\n";
	printf("ERROR!\n");

	exit (1);
}


#endif