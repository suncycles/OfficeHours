//Michael Sun 6/9/2023

#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <ctime>
#include <iterator>
#include <map>
#include <vector> 

using namespace std;

void printQueue(queue<int> q);

class Office{
public:
	multimap<int,string> studentTopics;

	set<string> topics;

	Office(): mins(0), timeOverHour(0), numStudents(0), timeWaited(0){}
	
	void start(){

		fillQueue();

		while(!students.empty()) {
			mins += students.front();

			students.pop();

			cout<<"time: "<< mins <<endl;
			mins++;

			cout<< "students: ";
			printQueue(students);
			cout<< "\n";
		}
		checkTime();

	}

	void fillQueue() {
		for (int i = 0; i < 60; ++i)
		{
			if(studentComes()) {
				int t = studentTime();
				students.push(t);
				numStudents++;
				timeWaited+=(i-t);

				string s = topic();
				topics.insert(s);
				int name = studentName();
				studentTopics.insert(pair<int,string>(name,s));

			}
		} // students

		cout<<"students: ";
		printQueue(students);
	}

	int studentName() {
		return rand()%30 +1;
	} // student names will be numbers 1-30

	bool studentComes() {
	    int i = (rand()%100)+1; 
	    //cout<<i;
	    if(i < 11) { //10% chance of a student coming
	    	// a student came
	    	if(mins<60){
	    		return true;
	    	}
	    }else {
	    	return false;
	    }   
	    return false;
	} // 10% chance of student coming per min, returns True or False
	
	int studentTime() {
		int i = (rand()%30)+1; // student takes a random amount of time from 1-30 mins
		return i;
	} // generates and returns an int between 1 - 60

	string topic() {
		int s = rand()%10 + 1;
		
		switch(s) {
		case 1:
			return "algebra";
		case 2:
			return "english";
		case 3: 
			return "french";
		case 4:
			return "biology";
		case 5:
			return "chemistry";
		case 6: 
			return "health";
		case 7:
			return "sociology";
		case 8: 
			return "geometry";
		case 9:
			return "linear algebra";
		case 10: 
			return "japanese";
		}
		return"null";

	} // generates a topic 1-10

	void checkTime() {

		timeOverHour = mins - 60;
		
		if(timeOverHour > 0) {
			cout << "Office Hours lasted " << timeOverHour <<" mins over an hour \n ";
		}else {
			cout<< "office hours lasted under an hour \n";
		}

		cout<<"\nSimulation Ended\n\n";	
		
	} // calculates time over the hour

	int getNumStudents() {return numStudents;}
	int getTime() {return mins;}
	int getTimeOver() {return timeOverHour;}
	int getTimeWaited() {return timeWaited;}
	set<string> gettopics() {return topics;}

private:
	queue<int> students;
	int mins;
	int timeOverHour;
	int numStudents;
	int timeWaited;
};

struct StudentData {
	int name;
	string topic;
};

void sortFile(vector<StudentData> &data, string column, string direction) { // SORTING IMPLEMENTATION
	//This function is really dumb!!!
	// I can't use a universal sorting algo because it compares different things
	// within a struct and in diff directions

	int n = data.size();


    if (direction == "ascending") {

    	if (column == "name") {
			int i, j;
		    bool swapped;

		    for (i = 0; i < n - 1; ++i) {
	       		swapped = false;

		        for (j = 0; j < n - i - 1; j++) {
		            if (data[j].name > data[j + 1].name) {
		                swap(data[j], data[j + 1]);
		                swapped = true;
		            }
		        }
		        if (swapped == false)
		            break;
		    }
    	} 
    	else if (column == "topic") {
    		int i, j;
		    bool swapped;

		    for (i = 0; i < n - 1; ++i) {
	       		swapped = false;

		        for (j = 0; j < n - i - 1; j++) {
		            if (data[j].topic > data[j + 1].topic) {
		                swap(data[j], data[j + 1]);
		                swapped = true;
		            }
		        }
		        if (swapped == false)
		            break;
		    }
    	}

    } else if (direction == "descending") {

        if (column == "name") {
			int i, j;
		    bool swapped;

		    for (i = 0; i < n - 1; ++i) {
	       		swapped = false;

		        for (j = 0; j < n - i - 1; j++) {
		            if (data[j].name < data[j + 1].name) {
		                swap(data[j], data[j + 1]);
		                swapped = true;
		            }
		        }
		        if (swapped == false)
		            break;
		    }
    	} 
    	else if (column == "topic") {
    		int i, j;
		    bool swapped;

		    for (i = 0; i < n - 1; ++i) {
	       		swapped = false;

		        for (j = 0; j < n - i - 1; j++) {
		            if (data[j].topic < data[j + 1].topic) {
		                swap(data[j], data[j + 1]);
		                swapped = true;
		            }
		        }
		        if (swapped == false)
		            break;
		    }
    	}
    } 
}

void search(vector<StudentData> v, int s, vector<string> ret) {
	//get which students asked about that topic at which office hours
	for (int i = 0; i < v.size(); ++i)
	{
		if(v[i].topic == s) {
			ret.push_back(v[i].name);
		}
	}
}
void search(vector<StudentData> v, string s, vector<string> ret) {
	//get which office hours she/he attended and what topic she/he asked about
	for (int i = 0; i < v.size(); ++i)
	{
		if(v[i].name == s) {
			ret.push_back(i.topic); 
		}
	}

}	//Searching implementation doesnt work, i didnt have enough time to really work on it
//search by student (and get which office hours she/he attended and what topic she/he asked about) 
//or by subject (and get which students asked about that topic at which office hours).

void printQueue(queue<int> q) {
	    queue<int> g = q;
	    while (!g.empty()) {
	        cout << '\t' << g.front();
	        g.pop();
	    }
	    cout << '\n';
} // helper func to print out a queue

int main() {
	int numSims = 0;
	double numStudents = 0.0;
	double totalTimeOver = 0.0;
	double totalTime = 0.0;
	double timeWaited = 0.0;
	multimap<int, string> totalMap;

	for (int i = 0; i < 10; ++i)
	{
		Office a;
		a.start();
		cout << "topics: ";
		string filename = "Office Hours #" + to_string(i+1);
		ofstream file(filename);
		for (auto it = a.topics.begin(); it!=a.topics.end(); it++)
		    {
		        cout<<", "<<*it;
		        file << " " << *it;
		        file << "\n";
		    }
		cout << endl;

		multimap<int, string>::iterator itr;

	    cout << "\tSTUDENT\tTOPIC\n";
	    for (itr = a.studentTopics.begin(); itr != a.studentTopics.end(); ++itr) {
	        cout << '\t' << itr->first << '\t' << itr->second << '\n';
	        totalMap.insert(pair<int, string>(itr->first,itr->second));
	    }
	    cout << endl;

		numStudents += a.getNumStudents();
		totalTime += a.getTime();
		totalTimeOver += a.getTimeOver();
		numSims ++;
		timeWaited+=a.getTimeWaited();
	} // sim runner

	//WRITE TO FILE
	// cout << "TOTALS\n";
	// cout << "\tSTUDENT\tTOPIC\n";
	multimap<int, string>::iterator itr;
	vector<StudentData> data;

	for (itr = totalMap.begin(); itr != totalMap.end(); ++itr) {
		int name = itr->first;
		string topic = itr->second;
		//write to file
		ofstream file("student " + to_string(name));
	    file << "student " << name <<" came to office hours a total of "<< totalMap.count(itr->first) << " times" << "\n";
	    file << "topics covered:\n";
	    StudentData d; // inserting a struct StudentData into data set to sort later
	    d.name = name;
	    d.topic = topic; 
	    data.push_back(d);
	    for (int i = 0; i < totalMap.count(itr->first); ++i)
	    {
	    	file << itr->second << "\n";
	    	++itr;
	    }
	}

	sortFile(data, "topic", "descending");

	for (int i = 0; i < data.size(); ++i)
	{
		cout << data[i].name << "\t" << data[i].topic << endl;
	}

	cout << endl;


	cout<< "\nRan a total of "<< numSims << " simulations.";
	cout<< "\nThe total amount of students that showed up was " << numStudents << endl;
	cout<< numStudents/numSims << " students on average showed up to each office hours";
	cout<< "\nEach student took " << (totalTime/numStudents) << " mins on average.";
	cout<< "\nEach office hours lasted " << double(totalTimeOver/numSims) << " mins average over the 1 hour mark.";
	cout<< "\nStudents waited a total of "<< timeWaited << " mins with an average of " << timeWaited/numStudents << " mins per student.";


	return 0;
}
