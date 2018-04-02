#ifndef OUTPUT_TO_VECTOR_H
#define OUTPUT_TO_VECTOR_H

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<Event_Group_Athlete> Output_Event_Vector(map<string, Athlete> ath_map, string e_name, bool mark_type) {
	vector<Event_Group_Athlete> ath_vect;
	map<string, Athlete>::iterator it;
	string a_name;

	// Traverse map to find athletes with certain event
	for ( it = ath_map.begin(); it != ath_map.end(); it++)
	{
		if ( it->second.check_all_events(e_name) ) {
			// Create Event_Group_Athlete objects with proper arguments and push
			//	into a vector for specifically one event type
			ath_vect.push_back(Event_Group_Athlete(it->second.get_name(), e_name, it->second.get_event_mark(e_name)));
		}
	}

	// If marked event, compare by mark
	if ( mark_type ) {
		Compare_By_Mark comp;
		sort(ath_vect.begin(), ath_vect.end(), comp);
	}
	
	// Else compare by time
	else {
		Compare_By_Time comp;
		sort(ath_vect.begin(), ath_vect.end(), comp);
	}
		
	return ath_vect;
}

#endif