//Yash Raj
//24k-0737//
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class student{
	string name;
	string rollnumber;
    string  department;
    bool feespaid;
    bool transportactivecard;
    string ans;
    string route;
    string pickup;
    string dropoff;
    
	public:
		student(string name,string rollnumber,string department){
			this->name=name;
			this->rollnumber=rollnumber;
			this->department=department;
			this->feespaid= false;
			this->transportactivecard= false;
		}
		
		void registerfortransport(){
			string answer;
			cout<<"Do you want to register for transport(Yes/No)"<<endl;
			getline(cin,answer);
			if(answer=="yes"){
				checkfees();
			}
			else{
			cout<<"Exiting the program"<<endl;
				exit(0);
			}
			
		}
		void checkfees(){
			cout<<name<<" have you paid your semester fees?"<<endl;
			cin>>ans;
			cin.ignore();
			if(ans=="yes"){
				feespaid =true;
				activatetransportcard();
				booktransport();
			}
			else {
				cout<<"Sorry! "<<name<<" to book your transport you must pay your semester fees"<<endl;
				exit(0);
			}
		}
		void booktransport(){
			cout<<"Enter your route:"<<endl;
			cout<<"1.Clifton"<<endl;
			cout<<"2.Tariq Road"<<endl;
			cout<<"3.North Nazimabad"<<endl;
			cout<<"4.Shahra-e-Faisal"<<endl;
			getline(cin,route);
			cout<<"Enter your pickup point:"<<endl;
			getline(cin,pickup);
			cout<<"Enter your drop off point:"<<endl;
			getline(cin,dropoff);
			cout<<"you have successfully booked your transport for "<<route<<" route"<<endl;
		}	
		void activatetransportcard(){
			if(feespaid){
				transportactivecard=true;
				cout<<name<<" your transport card has been activated! Book your transport:"<<endl;				
			}
		}
		void displaydetails(){
			cout<<"====Student Details===="<<endl;
			cout<<"Name: "<<name<<endl;
			cout<<"Roll number: "<<rollnumber<<endl;
			cout<<"Department: "<<department<<endl;
			cout<<"fees paid(Yes/No):"<<ans<<endl;
			cout<<"Route: "<<route<<endl;
			cout<<"Pickup point: "<<pickup<<endl;
			cout<<"drop off point:"<<dropoff<<endl;
			 
		}
		string getroute(){
			return route;
		}
		string getname(){
			return name;
		}
		string getrollnumber(){
			return rollnumber;
		}
};

class driver{
	string name;
	int driverid;
	string number;
	string routeassigned;
	public:
		driver(string name,int driverid,string number){
			this->name=name;
			this->driverid=driverid;
			this->number=number;
			
		}
		void assignroute(string route){
			this->routeassigned=route;
		}
		void displaydriver(){
			cout<<"=====Driver Details====="<<endl;
			cout<<"Driver Name: "<<name<<endl;
			cout<<"Driver id: "<<driverid<<endl;
			cout<<"Driver phone number: "<<number<<endl;
			cout<<"Assigned Route:"<<routeassigned<<endl;
		}
		string getdrivername(){
			return name;
		}
};

class bus{
	string busnumber;
	string stops[3];
	int totalstudents;
	string busroute;
	public:
		bus(string busnumber,string stop1,string stop2,string stop3){
			this->busnumber=busnumber;
			stops[0]=stop1;
			stops[1]=stop2;
			stops[2]=stop3;
		}
		void assignroute(string route){
			this->busroute=route;
		}
		void assignstudent(student &s){
			cout<<s.getname()<<" with Roll Number "<<s.getrollnumber()<<" is assigned to"<<busnumber<<endl;
		}
		void recordattendance(student &s){
			cout<<s.getname()<<" with Roll Number: "<<s.getrollnumber()<<" has tapped their card"<<endl;
		}
	   void displaydetails(){
	   	cout<<"====Bus Details===="<<endl;
	   	cout<<"Bus Number:"<<busnumber<<endl;
	   	cout<<"Route:"<<busroute<<endl;
	   	cout<<"Stops:"<<stops[0]<<" "<<stops[1]<<" "<<stops[2]<<endl;
	   }
	   
	   void tapcard(student &s){
	   	cout<<"Student "<<s.getname()<<" with Roll number"<<s.getrollnumber()<<" has successfully tapped their card"<<endl;
	   }
	
};
int main(){
	cout<<"Name: Yash Raj"<<endl;
	cout<<"Roll Number: 24k-0737"<<endl;
	student s1("Yash Raj","24k-0737","cs");
	s1.registerfortransport();
	s1.displaydetails();
	
	driver d1("wajid",101,"03351242110");
	d1.assignroute(s1.getroute());
	d1.displaydriver();
	
	bus b1("bus-1232","teen Talwar","Kalapul","Quaidabad");
	b1.assignstudent(s1);
	b1.assignroute(s1.getroute());
	b1.tapcard(s1);
	b1.displaydetails();
}