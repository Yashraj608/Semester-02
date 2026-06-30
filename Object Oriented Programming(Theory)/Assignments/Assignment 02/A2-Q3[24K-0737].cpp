#include<iostream>
using namespace std;
class vehicle{
protected:
	
		int vehicleid;
		static int totaldeliveries;
		int speed;
		public:
			
			vehicle(int vehicleid,int speed){
				this->vehicleid=vehicleid;
				this->speed=speed;
				totaldeliveries++;
			}
			virtual  void calculateroute(const string& route){

            cout<<"Selected Route: "<<route<<endl;
			}
			
			static int gettotaldeliveries(){
				return totaldeliveries;
			}
			
			int getspeed(){
				return speed;
			}
			int getvehicleid(){
				return vehicleid;
			}
			
			friend bool compareSpeeds(const vehicle& v1, const vehicle& v2, const vehicle& v3) {
                 return (v1.speed == v2.speed) && (v2.speed == v3.speed);
       }

			
			virtual void calculatedeliverytime(const string& route){
				cout<<"------Calculating Delivery Time------"<<endl;
				if(route=="Clifton"){
					cout<<vehicleid<<" Vehicle Delivering Time is approximately 15 minutes for route : "<<route<<endl;
				}
				else if(route=="North Nazimabad"){
					cout<<vehicleid<<" Vehicle Delivering Time is approximately 30 minutes for route : "<<route<<endl;
				}
				else if(route=="Gulshan-e-Iqbal"){
						cout<<vehicleid<<" Vehicle Delivering Time is approximately 45 minutes for route : "<<route<<endl;
				}
				else if(route=="Quaidabad"){
						cout<<vehicleid<<" Vehicle Delivering Time is approximately 1 hour minutes for route : "<<route<<endl;
				}
				else{
					cout<<"Invalid Route Selected"<<endl;
				}	
			}	
		virtual void command(const string &command,const string& packageid,const string& urgency)=0;
				
};
int vehicle ::totaldeliveries = 0;


class RamzanTimeShip : public vehicle{
	public:
		RamzanTimeShip(int vehicleid,int speed):vehicle(vehicleid,speed){
		}
		
		 void calculateroute(const string& route) override{
		 	cout<<"Yash Raj(24k-0737)"<<endl;
          cout<<"Selected Route: "<<route<<endl;
          cout<<"Ramzan Time Ship is verifying historical consistency before transport for route: "<<route<<endl;
			}
			void calculatedeliverytime(const string& route) override{
				cout<<"------Calculating Delivery Time------"<<endl;
				if(route=="Clifton"){
					cout<<vehicleid<<" Vehicle Delivering Time is approximately 15 minutes for route : "<<route<<endl;
				}
				else if(route=="North Nazimabad"){
					cout<<vehicleid<<" Vehicle Delivering Time is approximately 30 minutes for route : "<<route<<endl;
				}
				else if(route=="Gulshan-e-Iqbal"){
						cout<<vehicleid<<" Vehicle Delivering Time is approximately 45 minutes for route : "<<route<<endl;
				}
				else if(route=="Quaidabad"){
						cout<<vehicleid<<" Vehicle Delivering Time is approximately 1 hour minutes for route : "<<route<<endl;
				}
				else{
					cout<<"Invalid Route Selected"<<endl;
				}
			}
			
			
		void command(const string &command,const string& packageid,const string&urgency)override{
			cout<<"Command For Ramzan Time Ship: "<<command<<"- Package Id: "<<packageid<<" Urgency: "<<urgency<<endl;
			if(urgency=="Urgent"){
				cout<<"This Package is historically sensitive and requires validation !"<<endl;
			}
		}
		
		
};

class RamzanDrone: public vehicle{
	public:
			RamzanDrone(int vehicleid,int speed):vehicle(vehicleid,speed){
		}
		
		 void calculateroute(const string& route) override{
          cout<<"Selected Route: "<<route<<endl;
          cout<<"Ramzan Drone is calculating an aerial route for high speed delivery for route: "<<route<<endl;
			}
			void calculatedeliverytime(const string& route) override{
				cout<<"------Calculating Delivery Time------"<<endl;
				if(route=="Clifton"){
					cout<<vehicleid<<" Vehicle Delivering Time is approximately 15 minutes for route : "<<route<<endl;
				}
				else if(route=="North Nazimabad"){
					cout<<vehicleid<<" Vehicle Delivering Time is approximately 30 minutes for route : "<<route<<endl;
				}
				else if(route=="Gulshan-e-Iqbal"){
						cout<<vehicleid<<" Vehicle Delivering Time is approximately 45 minutes for route : "<<route<<endl;
				}
				else if(route=="Quaidabad"){
						cout<<vehicleid<<" Vehicle Delivering Time is approximately 1 hour minutes for route : "<<route<<endl;
				}
				else{
					cout<<"Invalid Route Selected"<<endl;
				}
			}
			
			
		void command(const string &command,const string& packageid,const string&urgency)override{
			cout<<"Command For Ramzan Drone: "<<command<<"- Package Id: "<<packageid<<" Urgency: "<<urgency<<endl;
			if(urgency=="Urgent"){
				cout<<"Activating High Speed mode to ensure an iftar meal arrives on time"<<endl;
			}
		}
		
};

class RamzanHyperpod : public vehicle{
	public:
		 	RamzanHyperpod(int vehicleid,int speed):vehicle(vehicleid,speed){
		}
		
		 void calculateroute(const string& route) override{
          cout<<"Selected Route: "<<route<<endl;
          cout<<"Ramzan Hyperpod is calculating an undrground route to carry bulk package for route: "<<route<<endl;
			}
			void calculatedeliverytime(const string& route) override{
				cout<<"------Calculating Delivery Time------"<<endl;
				if(route=="Clifton"){
					cout<<vehicleid<<" Vehicle Delivering Time is approximately 15 minutes for route : "<<route<<endl;
				}
				else if(route=="North Nazimabad"){
					cout<<vehicleid<<" Vehicle Delivering Time is approximately 30 minutes for route : "<<route<<endl;
				}
				else if(route=="Gulshan-e-Iqbal"){
						cout<<vehicleid<<" Vehicle Delivering Time is approximately 45 minutes for route : "<<route<<endl;
				}
				else if(route=="Quaidabad"){
						cout<<vehicleid<<" Vehicle Delivering Time is approximately 1 hour minutes for route : "<<route<<endl;
				}
				else{
					cout<<"Invalid Route Selected"<<endl;
				}
			}
			
				void command(const string &command,const string& packageid,const string&urgency)override{
				cout<<"No command is required for Ramzan Hyperpod"<<endl;
			}
};

void ResolveConflict(vehicle &v1, vehicle &v2, vehicle &v3) {
    if (v1.getspeed() == v2.getspeed() && v2.getspeed() == v3.getspeed()) {
        cout << "All three vehicles have the same efficiency, any can proceed with delivery." << endl;
    } else if (v1.getspeed() >= v2.getspeed() && v1.getspeed() >= v3.getspeed()) {
        cout << "Vehicle with ID: " << v1.getvehicleid() << " and speed: " << v1.getspeed() << " will proceed with the delivery" << endl;
    } else if (v2.getspeed() >= v1.getspeed() && v2.getspeed() >= v3.getspeed()) {
        cout << "Vehicle with ID: " << v2.getvehicleid() << " and speed: " << v2.getspeed() << " will proceed with the delivery" << endl;
    } else {
        cout << "Vehicle with ID: " << v3.getvehicleid() << " and speed: " << v3.getspeed() << " will proceed with the delivery" << endl;
    }
}


int main(){
		string route;
	    cout<<"Enter the Delivery route:-"<<endl;
	    cout<<"1. Clifton"<<endl;
	    cout<<"2. North Nazimabad"<<endl;
	    cout<<"3. Gulshan-e-Iqbal"<<endl;
	    cout<<"4. Quaidabad"<<endl;
	    cin>>route;
	  
	    cout<<"====Ramzan Time Ship===="<<endl;
	    RamzanTimeShip T(223,12);
	    T.calculateroute(route);
	    T.calculatedeliverytime(route);
	    T.command("Deliver","24k-0737","Urgent");
	    
	     cout<<"====Ramzan Drone===="<<endl;
	    RamzanDrone D(223,13);
	    D.calculateroute(route);
	    D.calculatedeliverytime(route);
	    D.command("Deliver","24k-0737","Urgent");
	    
	     cout<<"====Ramzan Hyperpod===="<<endl;
	    RamzanHyperpod H(223,21);
	    H.calculateroute(route);
	    H.calculatedeliverytime(route);
	
	cout<<"====Decision===="<<endl;  
	ResolveConflict(T,D,H);
	    
cout<<"Total Deliveries: "<<vehicle::gettotaldeliveries()<<endl;
	return 0;
}