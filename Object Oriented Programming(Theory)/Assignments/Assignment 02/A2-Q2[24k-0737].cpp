#include <iostream>
using namespace std;
class ghosts {
    public:
    string name;
    int scareLevel;
    public:
    ghosts(){}; 
    ghosts(string name, int scareLevel):name(name),scareLevel(scareLevel){}
    virtual void performHaunting(){
        cout<<"SPOOOOOOOKKKKYYYYY !"<<endl;
    }
    int getscareLevel(){
	return scareLevel;
	 }
    friend ostream &operator<<(ostream &out,const ghosts &obj){
        out<<obj.name<<endl;
        out<<obj.scareLevel<<endl;
        return out;
    }
    ghosts operator+(ghosts const &obj){
        ghosts biggerGhost;
        biggerGhost.name=name+obj.name;
        biggerGhost.scareLevel=scareLevel+obj.scareLevel;
        return biggerGhost;
    }
};

class poltergeist : virtual public ghosts {
    public:
    poltergeist(string name, int scareLevel) : ghosts(name, scareLevel) {}
    void performHaunting() {
        cout << "GGGRRRRRRR BAANNGG !" << endl;
    }
};

class banshee : virtual public ghosts {
    public:
        banshee(string name, int scareLevel) : ghosts(name, scareLevel) {}
        void performHaunting() {
            cout << "OOOOOOOHHHHHHHH AAAAAAHHHHHH !" << endl;
        }
    };

class shadowGhost : virtual public ghosts {
    public:
    shadowGhost(string name, int scareLevel) : ghosts(name, scareLevel) {}
    void performHaunting() {
        cout << "EEEEHHHEHEHEHEHEHEHE !" << endl;
    }
};

class shadowPoltergeist : public shadowGhost, public poltergeist {
    public:
    shadowPoltergeist(string name, int scareLevel)
        : ghosts(name, scareLevel), shadowGhost(name, scareLevel), poltergeist(name, scareLevel) {}

    void performHaunting() {
        shadowGhost::performHaunting();
        poltergeist::performHaunting();
    }
};

class visitor {
public:
    string name;
    int bravery;
    
    visitor(string name, int bravery) : name(name), bravery(bravery) {}

    void visitorReact(int scareLevel)const {
        if (bravery < scareLevel) {
            cout << name << ": AAAAHHHH Run!" << endl;
        } else if (bravery > scareLevel) {
            cout << name << ": HAHAHAHA Look at that so-called GHOOOOST!" << endl;
        } else {
            cout << name << ": GGGGGHHHHHOOOOSSSSTTT!" << endl;
        }
    }
};

class hauntedHouse {
    string name;
    ghosts *g[10];
    int ghostCount;

public:
    hauntedHouse(string name) : name(name), ghostCount(0) {}
    ~hauntedHouse(){
        for (int i = 0; i < ghostCount; ++i)
            delete g[i];
    }
    void addGhost(ghosts *gho){
        if (ghostCount < 10){
            g[ghostCount++] = gho;
        }
    }
    friend void visit(const visitor v[], int visitorCount, const hauntedHouse &house);
};

void visit(const visitor v[], int visitorCount, const hauntedHouse &house) {
    cout << "Visitors Entering the House: " << house.name << endl;
    for (int i = 0; i < house.ghostCount; i++) {
        house.g[i]->performHaunting();
        for (int j = 0; j < visitorCount; j++) {
            v[j].visitorReact(house.g[i]->getscareLevel());
        }
    }
}

int main() {
	cout<<"Name :  Yash Raj having Roll Number: 24k-0737 have done this assignment"<<endl;
    hauntedHouse house1("Spooky Manor");
    house1.addGhost(new poltergeist("Yash", 7));
    house1.addGhost(new banshee("Saad", 5));
    house1.addGhost(new shadowGhost("Mubashir", 6));
     hauntedHouse house2("Dark Hollow");
    house2.addGhost(new shadowPoltergeist("Rehman", 8));
    house2.addGhost(new banshee("Sagar", 6));
    visitor v[4] = {{"Akash", 4}, {"Akshay", 7}, {"Aadu", 5}, {"Vivek", 3}};
    visit(v, 4, house1);
    visit(v, 4, house2);
     return 0;
}
