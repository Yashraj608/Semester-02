//Name : Yash Raj//
//Roll Number: 24k-0737//
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
 #include <ctime>
using namespace std;

class transporter;

string routes[3][8] = {
    { "Nazimabad", "Liaqtabad", "Hasan square", "Dalmia", "Johar more", "Natha Khan", "University", "" },
    { "Garden", "Jamat Khana", "Guru mandir", "Tariq route", "Shaheedemillat", "Baloch pull", "University", "" },
    { "Teen talwar", "Askari 3", "Kala_pull", "Akhtar_colony", "Kpt_bridge", "Korangi", "Landhi", "University" }
};


class Booking{
    string PayMentDate;
    string DeadlineForPayment;
    string Place;
    float price;
    int seat;
    int route;
    string CustomerName;
    public:
    void booked(string place,int n,float cost,int seatt,string namee){

        Place=place;
        route=n;
        price=cost;
        seat=seatt;
        CustomerName=namee;

        time_t now = time(0);
        tm *ltm = localtime(&now);
    
        ostringstream dateStream;
        ostringstream dateStream1;

        dateStream << 1900 + ltm->tm_year << "-"
                   << 1 + ltm->tm_mon << "-"
                   << ltm->tm_mday;
    
        string PayMentDate= dateStream.str();

        dateStream1 << 1900 + ltm->tm_year << "-"
        << 2 + ltm->tm_mon << "-"
        << ltm->tm_mday;


        DeadlineForPayment=dateStream1.str();

        fstream file("Booking.txt",ios::app);
        if(!file) {
            cout<<"Booking.txt does not exist!"<<endl;
            return ;
        }
        file << CustomerName << " " << route << " " << seat << " " << price << " " << Place << " " << PayMentDate << " " 
        << DeadlineForPayment << endl;
   
        file.close();
        cout<<"Your Seat is reserved!!"<<endl;

    }
};

class User {
    string Name;
    string CNIC;
    int age;
    string password;
    bool AlreadyDone;
    public:
    virtual string profession()=0;
    
    User():age(0){
        AlreadyDone=false;
    }

    User(string name,string cnic,int age,string pass):Name(name),CNIC(cnic),age(age),password(pass),AlreadyDone(false){}
    void Input(){
        cout<<"Enter Name:";
        cin>>Name;
        cout<<"Enter CNIC:";
        cin>>CNIC;
        cout<<"Enter Age:";
        cin>>age;
        cout<<"Enter Password:";
        cin>>password;
    }
    string GetName(){return Name;}
    string GetCNIC(){return CNIC;}
    int GetAge(){return age;}
    string Getpassword(){return password;}


    void SetAlreadyDone(){AlreadyDone=true;}
    string GetPass(){return password;}
    virtual void BookVehicle()=0;
    bool GetAlreadyDone(){return AlreadyDone;}
    virtual void AssignVehicle(transporter *t)=0;

};

// starting first 7-seats in coaster is for faculty and starting 12 seats in Bus also  for faculty

class Student:public User{
    static int TotalStudents;
    int semester;
    Booking book;
    public:
    Student(){}
    Student(string name,string cnic,int age,string pass):User(name,cnic,age,pass){}
    string profession(){return "student";}
    static void AssignedTotalUser(int s){TotalStudents=s;}
    int GetTotalUser(){return TotalStudents;}

    void BookVehicle();
    void AssignVehicle(transporter *t){};
};

class faculty:public User{
    static int TotalFaculty;
    string position;
    Booking book;
    public:
    faculty(){}
    string profession(){return "faculty";}
    static void AssignedTotalUser(int s){TotalFaculty=s;}
    int GetTotalUser(){return TotalFaculty;}
    faculty(string name,string cnic,int age,string pass):User(name,cnic,age,pass){}
    void AssignVehicle(transporter *t){};
    void BookVehicle();
};
class Driver:public User{
    static int TotalDrivers;
    string license;
    public:
    Driver(){}
    Driver(string name,string cnic,int age,string pass):User(name,cnic,age,pass){}
    string profession(){return "driver";}
    static void AssignedTotalUser(int s){TotalDrivers=s;}
    int GetTotalUser(){return TotalDrivers;}
    void BookVehicle(){}
    void AssignVehicle(transporter *t);
};

int Driver::TotalDrivers=0;
int faculty::TotalFaculty=0;
int Student::TotalStudents=0;

void GettingTotalUsers(){
    fstream driver("DriverDetails.txt");
    fstream driver2("Faculty.txt");
    fstream driver3("Students.txt");


    if(!driver3 || !driver2 || !driver) {
        cout<<"files for user data does not exit"<<endl;
        return ;
    }

    int count[3]={0,0,0};
    string sub;

    while(getline(driver,sub)) count[0]++;
    while(getline(driver2,sub)) count[1]++;
    while(getline(driver3,sub)) count[2]++;

    faculty::AssignedTotalUser(count[1]);
    Student::AssignedTotalUser(count[2]);
    Driver::AssignedTotalUser(count[0]);
}


class vehicle{
    protected:
    int totalSeats;
    bool *seats;
    bool IsAirCondtion;
    bool IsDriverAssign;
    int routeNumber;

    public:
    vehicle(){}
    vehicle(int RN,bool AC){
        routeNumber=RN;
        IsAirCondtion=AC;
        IsDriverAssign=false;
        seats=new bool[totalSeats];

        for(int i=0;i<totalSeats;i++ )
            seats[i]=false;
       
    }
    

    virtual void showDetails(){
        if(IsAirCondtion)
            cout<<"Air conditional :True"<<endl;
        else 
            cout<<"Air condtional : False"<<endl;
        
        if(routeNumber==1)
            cout<<"Route start from Nazimabad to University"<<endl;
        else if(routeNumber==2)
            cout<<"Route start from Garden to University"<<endl;
        else  
            cout<<"Route start from Teen talwar to university"<<endl;
        
    }
    
    void assignSeat(int s){seats[s-1]=true;}
    bool IsSeat(int s){return seats[s-1];}
    int GetRoute(){return routeNumber;}
    bool AirConditionAl(){return IsAirCondtion;}
    bool ISAlreadyAssign(){return IsDriverAssign;}
    void AssignDriverr(){IsDriverAssign=true;}
    
    ~vehicle(){
        delete[] seats;
    }
};

class Coaster:public vehicle{
    public:
    Coaster(){}

    void showDetails(){
        cout<<"Coaster"<<endl;
        vehicle::showDetails();
    }
    Coaster(int RN,bool AC):vehicle(RN,AC){totalSeats=32;}
};

class Bus:public vehicle{
    public:
    Bus(){}
    void showDetails(){
        cout<<"Bus"<<endl;
        vehicle::showDetails();
    }
    Bus(int RN,bool AC):vehicle(RN,AC){totalSeats=32;}
};


class transporter{
    string transporterName;
    vehicle **vec;
    int totalVehicles;
    public:
        transporter(string name,int TV):totalVehicles(TV),transporterName(name){ 
            vec=new vehicle*[TV];
            ifstream file;
            
            if(name=="Nadeem")
                file.open("NadeemRoutes.txt");
            else 
                file.open("ZulfiqarRoutes.txt");
            string line;

            if(!file)
                cout<<"file not found"<<endl;
            else{
             try{
                int i=0;
                string name,bus_coach;
                int route;
                bool IsAirconditional;
                while(getline(file,line)){
                    istringstream iss(line);
                    iss>>name>>route>>bus_coach>>IsAirconditional;
                    
                    if(bus_coach=="bus")
                        vec[i]= new Bus(route,IsAirconditional);
                    else 
                        vec[i]=new Coaster(route,IsAirconditional);

                    i++;
                }
            }
            catch(exception &e){
                cout<<e.what()<<endl;
            }
        }
   
        }
        
        void ReversedSeat(int n,int seat){vec[n]->assignSeat( seat);}
        bool IsVehicleAirConditinal(int n){return vec[n]->AirConditionAl();}
        bool CheckSeat(int n,int seat){return vec[n]->IsSeat(seat);}

        void  showVehicleDetails(int n){vec[n]->showDetails();}
        bool CheckDriver(int n){return vec[n]->ISAlreadyAssign();}
        int GetVehicleRoute(int n){vec[n]->GetRoute();}
        string GetName(){return transporterName;}
        int GetTotalVehicle(){return totalVehicles;}

        void showVehicleDetails(){
            for(int i=0;i<totalVehicles;i++){
                if(vec[i]->ISAlreadyAssign()) continue;
                cout<<"Vehicle number:"<<i+1<<endl;
                vec[i]->showDetails();
                cout<<endl;
            }
        }

        void AssigningVehicle(int n){vec[n]->AssignDriverr();}
        ~transporter(){delete[] vec;}

};

transporter trans[2]={
    {"Nadeem",25},
    {"Zulfiqar",22},
};


template <typename T>
T login_createAccount(T &t){

    int currentAccount;
    fstream AccountData;
    GettingTotalUsers();

    try{
    if(t.profession()=="driver")
        AccountData.open("DriverDetails.txt");
    else if(t.profession()=="student")
        AccountData.open("Students.txt");
    else 
        AccountData.open("Faculty.txt");

    if(!AccountData) throw 10;
    }
    catch(const int e){
        return t;
    }

    T* accounts = new T[t.GetTotalUser()]; 
    int counter=0;
    string line;
    string name,cnic,pass;
    int age;
while (getline(AccountData,line)) {
    istringstream iss(line);
    iss>>name>>cnic>>age>>pass;
    T temp(name,cnic,age,pass);
    accounts[counter++]=temp;
}  
AccountData.close();

    int end=1;
  
    int option;
    while(end){
        cout<<"Enter 1:for Creating account"<<endl<<"Enter 2 : Sign Up"<<endl<<"Enter 3: Cancel"<<endl;
        cin>>option;
        switch (option)
        {
        case 1:{
            T acc;
            acc.Input();
            string sub;

            int userNumber=-1;
            for(int i=0;i<accounts[0]. GetTotalUser();i++){
                if(accounts[i].GetName()==acc.GetName()){
                        userNumber=0;
                }
            }
            
            if(userNumber){

                try{
                    if(t.profession()=="driver")
                        AccountData.open("DriverDetails.txt",ios::app);
                    else if(t.profession()=="student")
                        AccountData.open("Students.txt",ios::app);
                    else 
                        AccountData.open("Faculty.txt",ios::app);
                
                    if(!AccountData) throw 10;
                        cout<<"Your account created sucessfully"<<endl;
                    }
                    catch(const int e){
                        cout<<"File does not exist that's why we are closing our program"<<endl;
                        return t;
                    }

            if(userNumber==-1){
             AccountData<<acc.GetName()<<" "<<acc.GetCNIC()<<" "<<acc.GetAge()<<" "<<acc.Getpassword()<<" "<<endl;
             AccountData.close();
             return t;
            }
       
            AccountData.close();
        }
        else{
            cout<<"this user Name already exist"<<endl;
        }
    }

        break;
        case 2:{
            int end2=1;
            string name,pass;
        
            while(end2){
               cout<<"Name:";
                cin>>name;
            for(int i=0;i<accounts[0].GetTotalUser();i++){
                if(name==accounts[i].GetName()){
                    do{
                        cout<<"Enter password:";
                        cin>>pass;
                        if(pass==accounts[i].GetPass()){
                                end2=0;
                                cout<<"You login sucessfully"<<endl;
                                return accounts[i];
                        }
                        else {
                            int dec;
                            cout<<"Wrong password!"<<endl;

                            cout<<"Do you want another time(0-No)"<<endl;
                            cin>>dec;
                            if(dec==0 ) break;
                        }
                    }while(1);
                }
            }
            
        }
        }
            break;
        case 3:
            end=0;
        break;
        default:
            break;
        }
    };
}



void Driver::AssignVehicle(transporter *t){
    int choose;
    cout<<"Enter the Transporter(0-Nadeem and  1-Zulfiqar):"<<endl;
    cin>>choose;
    choose =choose%2;
    t[choose].showVehicleDetails();

    cout<<endl;
    int id;
    cout<<"Assign to any Vehicle by it's vehicle ID:";
    cin>>id;
    t[choose].AssigningVehicle(id-1);

    fstream file("AssigningVehicle.txt",ios::app);
    if(!file) {
        cout<<"AssigningVehicle.txt does not  exist!"<<endl;    
        return;
    }
    file<<t[choose].GetName()<<" "<<id-1<<endl;
    file.close();
    cout<<"Thanks you assign to vehicle"<<endl;
}

void LoadingAssigningDriver(transporter *trans){
    fstream file("AssigningVehicle.txt");
    if(!file) {
        cout<<"AssigningVehicle.txt does not  exist!"<<endl;    
        return ;
    }
    string line;
    string name;
    int num;
    while(getline(file,line)){
        istringstream iss(line);
        iss>>name>>num;
        if(name=="Nadeem")
            trans[0].AssigningVehicle(num);
        else 
            trans[1].AssigningVehicle(num);
    }
    file.close();

}


void faculty::BookVehicle(){
    string place;
    cout<<"Enter place:";
    cin>>place;
    int n;

    for(int i=0;i<3;i++){
        for(int j=0;j<8;j++){
            if(routes[i][j]==place){
                n=i;
                i=4;
            }
        }
    }

    n++;
    int arrI[10];
    int arrJ[10];
    int arrCount=0;
    for(int i=0;i<2;i++){
        for(int j=0;j<trans[i].GetTotalVehicle();j++){

            if(trans[i].GetVehicleRoute(j)==n && trans[i].CheckDriver(j)){
                cout<<trans[i].GetVehicleRoute(j)<<endl;
                cout<<arrCount+1<<" ";
                trans[i].showVehicleDetails(j);
                arrI[arrCount]=i;
                arrJ[arrCount++]=j;
            }
        }
    }

    int  VehicleChoose;
    cout<<endl<<"Enter the vehicle number:";
    cin>>VehicleChoose;

    trans[arrI[VehicleChoose-1]].showVehicleDetails(arrJ[VehicleChoose-1]);

    int cost=0;
    int seat;
    cout<<"Enter the Seat Number:";
    cin>>seat;
    if(seat<13){
        if(trans[arrI[VehicleChoose-1]].CheckSeat(arrJ[VehicleChoose-1],seat)){
            cost=10000;
            cout<<"cost for point:"<<cost<<endl;
            if(trans[arrI[VehicleChoose-1]].IsVehicleAirConditinal(arrJ[VehicleChoose-1])){
                cost+=2000;
                cout<<"Extra for AC is 3500 but 1500 off for faculty"<<endl;
            }

            int dec;
            cout<<"Do you want to "<<cost<<" for point (1-yes and 0-No)";
            cin>>dec;

            if(dec==1){
                book.booked(place,n,cost,seat,GetName());
                trans[arrI[VehicleChoose-1]].ReversedSeat(arrJ[VehicleChoose-1],seat);
            }
        }   
    }
    else{
        cout<<"Seats from 13-50 only student can reserve"<<endl;
    }

}


void Student::BookVehicle(){
    string place;
    cout<<"Enter place:";
    cin>>place;
    int n;

    for(int i=0;i<3;i++){
        for(int j=0;j<8;j++){
            if(routes[i][j]==place){
                n=i;
                i=4;
            }
        }
    }

    n++;
    int arrI[10];
    int arrJ[10];
    int arrCount=0;
    for(int i=0;i<2;i++){
        for(int j=0;j<trans[i].GetTotalVehicle();j++){

            if(trans[i].GetVehicleRoute(j)==n && trans[i].CheckDriver(j)){
                // cout<<trans[i].GetVehicleRoute(j)<<endl;
                cout<<arrCount+1<<" ";
                trans[i].showVehicleDetails(j);
                arrI[arrCount]=i;
                arrJ[arrCount++]=j;
            }
        }
    }

    int  VehicleChoose;
    cout<<endl<<"Enter the vehicle number:";
    cin>>VehicleChoose;

    trans[arrI[VehicleChoose-1]].showVehicleDetails(arrJ[VehicleChoose-1]);

    int cost=0;
    int seat;

    while (1)
    {
        cout<<"Enter the Seat Number:";
        cin>>seat;
    if(seat>12){
        try{
        if(trans[arrI[VehicleChoose-1]].CheckSeat(arrJ[VehicleChoose-1],seat))
            throw 0;
            cost=10000;
            cout<<"cost for point:"<<cost<<endl;
            if(trans[arrI[VehicleChoose-1]].IsVehicleAirConditinal(arrJ[VehicleChoose-1])){
                cost+=3500;
                cout<<"Extra for AC is 3500"<<endl;
            }

            int dec;
            cout<<"Do you want to "<<cost<<" for point (1-yes and 0-No)";
            cin>>dec;

            if(dec==1){
                book.booked(place,n,cost,seat,GetName());
                trans[arrI[VehicleChoose-1]].ReversedSeat(arrJ[VehicleChoose-1],seat);
            }
            break;
        }
        catch(int e){
            cout<<"This seat was already reserved!"<<endl;
        }
    }
    else{
        cout<<"Seats from 1-12 only faculty can reserve"<<endl;
    }
    }
}



int main(){
	
	cout<<"Name: Yash Raj"<<endl;
	cout<<"Roll Number: 24k-0737"<<endl;

    LoadingAssigningDriver(trans);

    Driver driver,tempD;
    Student stu,tempS;
    faculty fau,tempF;


    User * u;
    int end=1;
    string profess;
    int dec=0;
    int Endprogram=1;
    while(Endprogram){
    while(end=1){
        cout<<"Do you want to sign up:(1-No and 0-yes)"<<endl;
        cin>>dec;
        if(dec==1)  break;

        cout<<"Enter the profession(driver,student or faculty):";
        cin>>profess;
        
        if(profess=="student"){
            tempS=login_createAccount(stu);
            u=&tempS;
        }
        else if(profess=="driver") {
            tempD=login_createAccount(driver);
            u=&tempD;
        }
        else if(profess=="faculty") {
            tempF=login_createAccount(fau);
            u=&tempF;
        }
        if(u->GetAge()) break;
    }   

    if(u->GetAge()){
    int opt;
    if(profess=="driver"){
        cout<<"Enter 1 to Assign with any vehicle:"<<endl;
        cin>>opt;
        if(opt==1)
            u->AssignVehicle(trans);
    }
    else if(profess=="student" || profess=="faculty"){
        
        fstream LastFile("Booking.txt");
        string subject;
        string name,sDate,DDate,place;
        float cost;
        int routee;
   
        if(!LastFile.is_open()){
            cout<<"Booking.txt does not exist!"<<endl;
            break;
        }

        time_t now = time(0);
        tm *ltm = localtime(&now);
    
        ostringstream dateStream;
        dateStream << 1900 + ltm->tm_year << "-"
                   << 1 + ltm->tm_mon << "-"
                   << ltm->tm_mday;
    
        string dateStr = dateStream.str();

        while(getline(LastFile,subject)){
            try{
            istringstream iss(subject);
        iss>>name>>routee>>cost>>place>>sDate>>DDate;

            if(u->GetName()==name && dateStr!=DDate){
                
                u->SetAlreadyDone();
                break;
            }
            }
            catch(...){
                cout<<"We can get correct data!"<<endl;
            }
        }
        if(!u->GetAlreadyDone()){
        cout<<"Enter 1 to reversing Seat!";
        cin>>opt;
        if(opt==1)
            u->BookVehicle();
        }
        else{
            cout<<"you can't reserved any other seat because you already reserve the seat!"<<endl;
        }
    } 
    }
   
    cout<<"Enter 0 for Exit or Enter any other number for remaining in program:";
    cin>>Endprogram;
}
    cout<<"Thanks you for your visit"<<endl;
}