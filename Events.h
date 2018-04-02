/*#include <algorithm>
using namespace std;

// Timed events must be compared starting with the smallest time
class Compare_Times{
public:
    bool operator() (Athlete &left, Athlete &right, string e_name) {
        return (left.get_event_mark(e_name) < right.get_event_mark(e_name));
    }
};

// Marked events must be compared starting with the largest mark
class Compare_Marks {
public:
    bool operator() (Athlete &left, Athlete &right, string e_name) {
        return (left.get_event_mark(e_name) < right.get_event_mark(e_name));
    }
};

class Events {
public:
	virtual void sort_map() = 0;
	virtual void display_event() = 0;

	string event_name;
	map<string, Athlete> Data_Map;
};

class Javelin : public Events {
public:
	Javelin(map<string, Athlete> Athlete_Map) {
		event_name = "Javelin";
		Data_Map = Athlete_Map;
	}

	Compare_Times comp;
	bool operator < (Events &right)
	{

	void sort_map(map<string, Athlete> temp_data_map) {
		Data_Map = temp_data_map;
		sort(Data_Map.begin(), Data_Map.end(), comp); 
		
	}

};

class One_Hundred : public Events {
public:
	One_Hundred (string e_name) {event_name = e_name;}
	void sort();

};

class Two_Hundred : public Events {
public:
	Two_Hundred (string e_name) {event_name = e_name;}
	void sort();

};

class Four_Hundred : public Events {
public:
	Four_Hundred (string e_name) {event_name = e_name;}
	void sort();

};

class Eight_Hundred : public Events {
public:
	Eight_Hundred (string e_name) {event_name = e_name;}
	void sort();

};

class Fifteen_Hundred : public Events {
public:
	Fifteen_Hundred (string e_name) {event_name = e_name;}
	void sort();

};

class Five_K : public Events {
public:
	Five_K (string e_name) {event_name = e_name;}
	void sort();

};

class Ten_K : public Events {
public:
	Ten_K (string e_name) {event_name = e_name;}
	void sort();

};

class One_Ten_Hurdles : public Events {
public:
	One_Ten_Hurdles (string e_name) {event_name = e_name;}
	void sort();

};

class Four_Hundred_Hurdles : public Events {
public:
	Four_Hundred_Hurdles (string e_name) {event_name = e_name;}
	void sort();

};

class Steeplechase : public Events {
public:
	Steeplechase (string e_name) {event_name = e_name;}
	void sort();

};

class Long_Jump : public Events {
public:
	Long_Jump (string e_name) {event_name = e_name;}
	void sort();

};

class Triple_Jump : public Events {
public:
	Triple_Jump (string e_name) {event_name = e_name;}
	void sort();

};

class High_Jump : public Events {
public:
	High_Jump (string e_name) {event_name = e_name;}
	void sort();

};

class Pole_Vault : public Events {
public:
	Pole_Vault (string e_name) {event_name = e_name;}
	void sort();

};

class Shot : public Events {
public:
	Shot (string e_name) {event_name = e_name;}
	void sort();

};

class Discus : public Events {
public:
	Discus (string e_name) {event_name = e_name;}
	void sort();

};

class Hammer : public Events {
public:
	Hammer (string e_name) {event_name = e_name;}
	void sort();

};

class Decathlon : public Events {
public:
	Decathlon (string e_name) {event_name = e_name;}
	void sort();

};

*/