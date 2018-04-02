#include "Read_From_File.h"
#include "Output_To_Vector.h"
#include "Athlete.h"
#include "Check_Event_Type.h"
#include <stdexcept>
#include <limits>
#include <ios>
using namespace std;

int read_int(const string& prompt, int low, int high) 
{
			cin.exceptions(ios_base::failbit);
				
			int num = 0;

			bool range = false;
			while(!range)
			{
				cout << prompt;
				if ( low > high )
					throw invalid_argument("The specified range is empty"); 
				try  {
						cin >> num;
						range = (num >= low && num <= high );
						if(num < low || num > high )
							cout << "Invalid Entry. Try Again." << endl;
				} catch(ios_base::failure& ex)
				{
					if (cin.eof())
					{   throw ios_base::failure( "read_int: EOF encountered");
					}
					else if(cin.bad())
					{	throw ios_base::failure( "read_int unrecoverable");
					}
					else if( cin.fail() )
					{	cout << "Bad numeric string -- try again\n";	
						cin.clear();
						cin.ignore(numeric_limits<int>::max(), '\n');
					}

				}
		}
		cin.exceptions(ios_base::goodbit);
		return num;
}

int main() {
	map<string, Athlete> Athlete_Map;
	map<string, Athlete>::iterator it;
	string path;
	path = "C:\Sample.txt";

	vector<Event_Group_Athlete> event_vector;
	Athlete_Map = Read_From_File(path);

	// Make bool function to return if event is marked or time
	//string e_name = "Javelin_Throw";
	//event_vector = Output_Event_Vector(Athlete_Map, e_name, Check_Event_Type(e_name));

	int operatr = 0;
	int command = 10;

	while( operatr == 0) {
		if (command == 1){
			cout << endl << endl;
			for ( it = Athlete_Map.begin(); it != Athlete_Map.end(); it++)
			{
				cout << it->first << endl;
				it->second.display_all_events();
			}
		}
		else if (command == 2){
			cout<< endl << endl;
			cout<< "Event:		Athletes:	Mark:" << endl << endl;
			string temp_event;
			cout << "Enter an event! ";
			cin >> temp_event;
			cout << endl;
			vector<Event_Group_Athlete> temp_event_vect;
			temp_event_vect = Output_Event_Vector(Athlete_Map,temp_event, Check_Event_Type(temp_event));

			for ( int i = 0; i < temp_event_vect.size(); i++ ) {
				cout << temp_event_vect[i].get_event_name() 
					 <<	"  " << temp_event_vect[i].get_name()
					 << "  " << temp_event_vect[i].get_event_mark() 
					 << endl;
			}

			cout << endl;

		}
		else if (command == 3){
			cout<< endl << endl;
			cout<< "Enter Athletes name you want to see: " << endl << endl;
			string temp_name_athlete_input;
			cin >> temp_name_athlete_input;
			for ( it = Athlete_Map.begin(); it != Athlete_Map.end(); it++)
			{
				if ( it->second.get_name() == temp_name_athlete_input ) {
					cout << it->second.get_name() << endl;
					it->second.display_all_events();
				}
			}
		}

		else if (command == 4){
			cout<< endl << endl;
			cout<< "Enter Athlete's name you want to add: " << endl << endl;
			string temp_name_athlete_input;
			cin >> temp_name_athlete_input;

			bool name_exists = false; // This will change to true if athlete's name is already in the map
			for ( it = Athlete_Map.begin(); it != Athlete_Map.end(); it++)
			{
				if ( it->first == temp_name_athlete_input ) {
					cout << "Name already exists.\n";
					name_exists = true;
					cout << it->second.get_name() << endl;
					it->second.display_all_events();
				}
			}

			if ( name_exists == false ){
				Athlete_Map[temp_name_athlete_input] = Athlete(temp_name_athlete_input);
			for ( it = Athlete_Map.begin(); it != Athlete_Map.end(); it++, name_exists == false)
			{
				if ( it->first == temp_name_athlete_input ) {
					cout<< "Enter the event name you want to add a mark to: " << endl;
					string temp_event_input;
					cin >> temp_event_input;
					cout << "Enter the mark: " << endl<< endl;
					string temp_mark_input;
					cin >> temp_mark_input;
					it->second.set_event(temp_event_input,temp_mark_input);					
					break;
				}
			}

			//Create Athlete all events 
		}
		else if (command == 5){
			cout<< endl << endl;
			cout<< "Enter Athletes name you want to add an event to: " << endl<< endl;
			string temp_name_athlete_input;
			cin >> temp_name_athlete_input;

			for ( it = Athlete_Map.begin(); it != Athlete_Map.end(); it++)
			{
				if ( it->first == temp_name_athlete_input ) {
					cout<< "Enter the event name you want to add a mark to: " << endl;
					string temp_event_input;
					cin >> temp_event_input;
					cout << "Enter the mark: " << endl<< endl;
					string temp_mark_input;
					cin >> temp_mark_input;
					it->second.set_event(temp_event_input,temp_mark_input);					
					break;
				}

				cout << "Athlete not in map!\n";
			}
		}
		}


	cout << "Welcome to the Track and Field Data Base.\n";
	cout << "Main Menu:\n" << endl;
	cout << "Print out all Athletes:		[1]" << endl;
	cout << "Print out an Event:		[2]"<< endl;
	cout << "Print out an Athlete's Profile:	[3]"<< endl;
	cout << "Add an Athlete:			[4]"<< endl;
	cout << "Add an Event to an Athlete:	[5]"<< endl;
	cout << "Quit Program:			[6]"<< endl;
	string prompt("Enter Action Number: 		 ");
	try
	{
		 command = read_int( prompt, 1, 6 );
	} catch ( runtime_error & ex )
	{
		cout << "Read int encountered a run time error" <<  (ex.what()) << endl; 
	}


	if (command == 6){
		operatr = 1;
		cout<< "THANK YOU FOR USING OUR TRACK AND FIELD DATA SYSTEM"<< endl;
	}
}

return 0;
}

