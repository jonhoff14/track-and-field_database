#ifndef READ_FROM_FILE_H
#define READ_FROM_FILE_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include "Athlete.h"
using namespace std;

map<string, Athlete> Read_From_File(string path) {

	// Map to hold athletes
	map<string, Athlete> a_map;
	map<string, Athlete>::iterator it;

	ifstream in ( path );
	vector<string> vect_of_words;
	string word;

	if ( !in )
		return a_map;

	// Push back words in file to vector
	while ( in >> word )
		vect_of_words.push_back ( word );
	
	string temp_name;
	string temp_event;
	string temp_mark;
	temp_name = vect_of_words[0];
	a_map[vect_of_words[0]] = Athlete(vect_of_words[0]);
	// Add athlete and stats to the map
	for ( int i = 1; i < vect_of_words.size(); i++ ) {
 
		if ( vect_of_words[i] == ";;")
			break;
		// If a semicolon is found, create an athlete
		if ( vect_of_words[i] == ";" ) {
			i++;
			temp_name = vect_of_words[i];
			a_map[temp_name] = Athlete(temp_name);
		}

		// If odd, this word is an event
		else if ( i % 2 == 1 ) {
			temp_event = vect_of_words[i];
			i++;
			temp_mark = vect_of_words[i];

			for ( it = a_map.begin(); it != a_map.end(); it++)
			{
				if ( it->first == temp_name )
					it->second.set_event(temp_event, temp_mark);
			}
		}
	}

	return a_map;
}

#endif