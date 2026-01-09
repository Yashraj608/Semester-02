//Yash Raj//
//Roll Number: 24k-0737//
#include <iostream>
#include <string>
#include <windows.h>
#include<cstdlib>
using namespace std;

class Student;
class Mentor;
class Sport;

class Student
{
private:
    int studentId;
    string studentName;
    int studentAge;
    string sportsInterest[2];
    int mentorAssignId;

public:
    // Constructor
    Student(int id, string name, int ageVal, string interests[], int mentor)
    {
        studentId = id;
        studentName = name;
        studentAge = ageVal;
        for (int i = 0; i < 2; i++)
        {
            sportsInterest[i] = interests[i];
        }
        mentorAssignId = mentor;
    }
    // Default Constructor
    Student()
    {
        studentId = 0;
        studentName = "";
        studentAge = 0;
        sportsInterest[0] = sportsInterest[1] = "";
        mentorAssignId = 0;
    }
    // Setters
    void setStudentId(int id) { studentId = id; }
    void setStudentName(string name) { studentName = name; }
    void setStudentAge(int age) { studentAge = age; }
    void setSportInterests(string s[])
    {
        for (int i = 0; i < 2; i++)
        {
            sportsInterest[i] = s[i];
        }
    }

    // getters
    int getStudentId() { return studentId; }
    string getStudentName() { return studentName; }
    int getStudentAge() { return studentAge; }
    int getMentorAssign() { return mentorAssignId; }
    string *getSportsInterests() { return sportsInterest; }
    // show Student Details
    void displayStudentDetails()
    {
        cout << "\nStudent Name: " << getStudentName();
        cout << "\nStudent ID: " << getStudentId();
        cout << "\nStudent Age: " << getStudentAge();
        cout << "\nMentor Assign ID: " << getMentorAssign();
    }
    // Methods
    void registerForMentorship(Mentor *M);
    void viewMentorDetails(Mentor *M);
    void updateSportsInterest();
};

class Mentor
{
private:
    int mentorId;
    string mentorName;
    string sportsExpertise[3];
    int maxLearners;
    int assignLearners[3];
    int learnersCount = 0;
    int mentorcount = 2;

public:
    // Parametrized Constructor
    Mentor(int mentorId, string mentorName, string sportsExpertise[], int maxLearners, int assignLearners[])
    {
        this->mentorId = mentorId;
        this->mentorName = mentorName;
        for (int i = 0; i < 3; i++)
        {
            this->sportsExpertise[i] = sportsExpertise[i];
        }
        this->maxLearners = maxLearners;
        for (int i = 0; i < 3; i++)
        {
            this->assignLearners[i] = assignLearners[i];
        }
    }
    // Default Constructor
    Mentor()
    {
        mentorId = 0;
        mentorName = "";
        sportsExpertise[0] = sportsExpertise[1] = sportsExpertise[2] = "";
        maxLearners = 0;
        assignLearners[0] = assignLearners[1] = assignLearners[2] = 0;
        mentorcount = 2;
    }

    // setters
    void setMentorName(string name) { mentorName = name; }
    void setMentorID(int id) { mentorId = id; }
    void setMaxLeaner(int maxL) { maxLearners = maxL; }
    void setSportExpertise(string sportExp[])
    {
        for (int i = 0; i < 3; i++)
        {
            sportsExpertise[i] = sportExp[i];
        }
    }
    void setAssignLearners(int assign) { assignLearners[learnersCount] = assign; }
    void setLearnerCount(int count) { learnersCount = count; }
    // getters
    string *getSportExpertise() { return sportsExpertise; }
    int getMentorId() { return mentorId; }
    string getMentorName() { return mentorName; }
    int getMaxlearnes() { return maxLearners; }
    int *getAssignLearners() { return assignLearners; }
    int getMentorCount() { return mentorcount; }
    int getLearnerCount() { return learnersCount; }
    void displayMentorDetails()
    {

        cout << "\nMentor ID:" << getMentorId();
        cout << "\nMentor Name:" << getMentorName();
        cout << "\nMentor Max Lerners: " << getMaxlearnes();
        int *temp = getAssignLearners();
        cout << "\nAssi<gn Learners: ";
        for (int i = 0; i < learnersCount; i++)
        {
            cout << "\nAssign Learner #(" << i + 1 << ") " << temp[i];
        }
        string *tem2 = getSportExpertise();
        for (int i = 0; i < 3; i++)
        {
            cout << "\nSport Expertise: " << tem2[i];
        }
    }
    void assignLearner(Student *s);
    void removeLearner(Student *s);
    void viewLearners();
    void provideGuidance();
};
class Skill
{
private:
    int skillID;
    string skillName;
    string skillDescription;

public:
    Skill(int id, string name, string desc) : skillID(id), skillName(name), skillDescription(desc) {}

    // setters
    void setID(int newid) { skillID = newid; }
    void setSkillName(string newskill) { skillName = newskill; }
    void setSkillDescription(string newDescription) { skillDescription = newDescription; }
    // getters
    int getID() { return skillID; }
    string getName() { return skillName; }
    string getSkillDescription() { return skillDescription; }

    void showSkillDetails()
    {
        cout << "\nSkill ID: " << getID();
        cout << "\nSkill Name: " << getName();
        cout << "\nSkill Description: " << getSkillDescription();
    }
    void updateSkillDescription(string newDescription)
    {
        cout << "\n-----------------------------------------------------------\n";
        skillDescription = newDescription;
        cout << "\nSkill Description Successfully ! ";
        cout << "\n-----------------------------------------------------------\n";
    }
};
class Sport
{
private:
    int sportId;
    string sportName;
    string sportDescription;
    string requiredSkill[3];
    int skillscount = 0;

public:
    Sport(int Sid, string Sname, string description, string requiredSkills[3])
    {
        sportId = Sid;
        sportName = Sname;
        sportDescription = description;
        for (int i = 0; i < 3; i++)
        {
            requiredSkill[i] = requiredSkills[i];
        }
    }
    Sport()
    {
        sportId = 0;
        sportName = "";
        sportDescription = "";
        requiredSkill[0] = requiredSkill[1] = requiredSkill[2] = "";
        skillscount = 0;
    }
    // setters
    void setSportId(int id) { sportId = id; }
    void setSportName(string name) { sportName = name; }
    void setSportDescription(string description) { sportDescription = description; }
    void setRequiredSkills(string skillsrequired[])
    {
        for (int i = 0; i < 3; i++)
        {
            requiredSkill[i] = skillsrequired[i];
        }
    }

    // getters
    int getsportId() { return sportId; }
    string getsportName() { return sportName; }
    string getsportDescription() { return sportDescription; }
    string *getSportrequiredSkills() { return requiredSkill; }

    void addSkill(Skill *s);
    void removeSkill(Skill *s);
};

// Students Methods
void Student::registerForMentorship(Mentor *M)
{
    string name;
    cout << "\nEnter your Name: ";
    cin >> name;
    int studentId;
    cout << "\nEnter your ID: ";
    cin >> studentId;
    if (M->getLearnerCount() >= 3)
    {
        cout << "\nMentor has already assigned maximum Students: ";
    }
    else
    {
        M->setAssignLearners(studentId);
        M->setLearnerCount(M->getLearnerCount() + 1);
        cout << "\n-------------------------------------------------\n";
        cout << "\nStudent has been Register Successfully: ";
        cout << "\n-------------------------------------------------\n";
    }
}
void Student::viewMentorDetails(Mentor *M)
{
    for (int i = 0; i < M->getMentorCount(); i++)
    {
        M[i].displayMentorDetails();
        cout << "\n------------------------------------------------------------\n";
    }
}
void Student::updateSportsInterest()
{
    string sportInterests[2];
    cout << "\nEnter the new sports intersrests # 1: ";
    cin >> sportInterests[0];
    cout << "\nEnter the new sports intersrests # 2: ";
    cin >> sportInterests[1];
    setSportInterests(sportInterests);
    cout << "\n----------------------------------------------\n";
    cout << "\nSports Interests Updated: ";
    cout << "\n-----------------------------------------------\n";
    cout << "\nAfter Updation: ";
    string *temp = getSportsInterests();
    for (int i = 0; i < 2; i++)
    {
        cout << "\nSports # " << i + 1 << " " << temp[i];
    }
    cout << "\n";
}
// Mentor Methods
void Mentor::assignLearner(Student *s)
{
    if (getLearnerCount() >= getMaxlearnes())
    {
        cout << "\nMaximum capacity has reached: ";
    }
    else
    {
        // cout<<"\nThese are students : ";
        // for (int i = 0; i < getLearnerCount(); i++)
        // {
        // s->displayStudentDetails();
        // }
        cout << "\n---------------------------------------\n";
        int id;
        cout << "\nEnter the student ID to assign: ";
        cin >> id;
        setAssignLearners(id);
        setLearnerCount(getLearnerCount() + 1);
        cout << "\nLearner has Assigned successfully: \n";
    }
    cout << "\n-----------------------------------------------------\n";
    displayMentorDetails();
}
void Mentor::removeLearner(Student *s)
{
    int id, found = 0, index = 0;
    cout << "\nEnter the Student ID to remove: ";
    cin >> id;

    int *learners = getAssignLearners();
    for (int i = 0; i < getLearnerCount(); i++)
    {
        if (learners[i] == id)
        {
            found = 1;
            index = i;
            break;
        }
    }

    if (found == 1)
    {
        for (int i = index; i < getLearnerCount() - 1; i++)
        {
            learners[i] = learners[i + 1];
        }
        setLearnerCount(getLearnerCount() - 1);

        cout << "\nStudent ID " << id << " has been removed successfully.";
    }
    else
    {
     cout<<"\n-----------------------------------------\n";
        cout << "\nStudent not found!";
        cout<<"\n-----------------------------------------\n";
    }
    displayMentorDetails();
}

void Mentor::viewLearners()
{
    for (int i = 0; i < getLearnerCount(); i++)
    {
        getAssignLearners();
    }
}
void Mentor::provideGuidance()
{
    cout << "\n--------------------------------------------------------\n";
    int id;
    cout << "\nEnter the student id to give Guidance: ";
    cin >> id;
    string feedback;
    cout << "\n-------------Give the Guidance:-------------\n ";
    cin.ignore();
    getline(cin, feedback);
    cout << "\n----------------------------------------------------\n";
}
void Sport::addSkill(Skill *s)
{
    if (skillscount >= 3)
    {
        cout << "\nSkills maximum limit reached ! ";
        return;
    }
    string newskill;
    string skilldesc;
    int newSkillId;

    cout << "\nEnter the Skill ID to add: ";
    cin >> newSkillId;
    cout << "\nEnter the Skill Name to add: ";
    cin >> newskill;
    cout << "\nEnter the Skill Description to add: ";
    cin.ignore();
    getline(cin, skilldesc);

    requiredSkill[skillscount] = newskill;
    skillscount++;
    s[skillscount - 1] = Skill(newSkillId, newskill, skilldesc);

    cout << "\n-----------------------------------------";
    cout << "\nSkill added successfully!";
    cout << "\nAter adding the sklls: ";
    for (int i = 0; i < skillscount; i++)
    {
        cout << "\nSkill #" << (i + 1) << ": " << requiredSkill[i];
    }
    cout << "\n-----------------------------------------\n";
}

void Sport::removeSkill(Skill *s)
{

    string removeskill;
    cout << "\nCurrent Skills:";
    for (int i = 0; i < skillscount; i++)
    {
        cout << "\n"
             << (i + 1) << ". " << requiredSkill[i];
    }

    cout << "\nEnter the skill Name to be removed: ";
    cin >> removeskill;

    int found = -1;
    for (int i = 0; i < skillscount; i++)
    {
        if (requiredSkill[i] == removeskill)
        {
            found = i;
            break;
        }
    }
    if (found == -1)
    {
        cout << "\nInvalis SKill not found !";
        return;
    }
    for (int i = found; i < skillscount - 1; i++)
    {
        requiredSkill[i] = requiredSkill[i + 1];
    }
    skillscount--;
    cout << "\n-----------------------------------------";
    cout << "\nSkill has been removed successfully!";
    cout << "\nAfter updation:";
    for (int i = 0; i < skillscount; i++)
    {
        cout << "\nSkill no " << i + 1 << ": " << requiredSkill[i];
    }
    cout << "\n-----------------------------------------\n";
}

int main()
{
    // Student Details:
    string interests1[2] = {"cricket", "football"};
    string interests2[2] = {"BasketBall", "football"};

    Student S[3] = {
        Student(101, "Ali", 19, interests1, 700),
        Student(102, "Ahmad", 20, interests2, 811)};

    // Mentor Details:
    string sportsExpertise1[3] = {"cricket", "football", "basketball"};
    string sportsExpertise2[3] = {"BasketBall", "VolleyBall", "basketball"};
    int assignLearners1[3] = {-1};
    int assignLearners2[3] = {-1};
    Mentor M[2] = {
        Mentor(900, "Ali", sportsExpertise1, 3, assignLearners1),
        Mentor(901, "Ahmad", sportsExpertise2, 3, assignLearners2)};
    // Sport Details:
    string requiredSkill1[3] = {"Batting", "Bowling", "fielding"};
    string requiredSkill2[3] = {"Runner", "Goalkeeper", "Field"};
    Sport Sb[5] = {
        Sport(500, "Cricket", "Batsmen", requiredSkill1),
        Sport(505, "Football", "GoalKeeper", requiredSkill2), Sport(), Sport(), Sport()};
    // Skill details:
    Skill s1(888, "batting", "Batting average is hightest");
    Skill s2(999, "bowling", "Best wicket taker");
  int choice;
 while(choice!=11){
    cout << "\nStudents Methods: \n";
    cout << "\n1.Register for Mentorship:";
    cout << "\n2. Mentor Details:";
    cout << "\n3.Update Sports Interests:";
    cout << "\n4.Assign Learner: ";
    cout << "\n5.Remove Learner:";
    cout << "\n6.View Leanners:";
    cout << "\n7.Provide Guidance: ";
    cout << "\n8.Add skill";
    cout << "\n9.Remove Skill";
    cout << "\n10.Enter the new Descritpion to Update:";
    cout<<"\n11.Exit"<<endl;
 
    int choice;
    cout << "\nEnter the Choice: ";
    cin >> choice;
    switch (choice)//Yash Raj//
//Roll Number: 24k-0737//
#include <iostream>
#include <string>
// #include <windows.h>
#include<cstdlib>
using namespace std;

class Student;
class Mentor;
class Sport;

class Student
{
private:
    int studentId;
    string studentName;
    int studentAge;
    string sportsInterest[2];
    int mentorAssignId;

public:
    // Constructor
    Student(int id, string name, int ageVal, string interests[], int mentor)
    {
        studentId = id;
        studentName = name;
        studentAge = ageVal;
        for (int i = 0; i < 2; i++)
        {
            sportsInterest[i] = interests[i];
        }
        mentorAssignId = mentor;
    }
    // Default Constructor
    Student()
    {
        studentId = 0;
        studentName = "";
        studentAge = 0;
        sportsInterest[0] = sportsInterest[1] = "";
        mentorAssignId = 0;
    }
    // Setters
    void setStudentId(int id) { studentId = id; }
    void setStudentName(string name) { studentName = name; }
    void setStudentAge(int age) { studentAge = age; }
    void setSportInterests(string s[])
    {
        for (int i = 0; i < 2; i++)
        {
            sportsInterest[i] = s[i];
        }
    }

    // getters
    int getStudentId() { return studentId; }
    string getStudentName() { return studentName; }
    int getStudentAge() { return studentAge; }
    int getMentorAssign() { return mentorAssignId; }
    string *getSportsInterests() { return sportsInterest; }
    // show Student Details
    void displayStudentDetails()
    {
        cout << "\nStudent Name: " << getStudentName();
        cout << "\nStudent ID: " << getStudentId();
        cout << "\nStudent Age: " << getStudentAge();
        cout << "\nMentor Assign ID: " << getMentorAssign();
    }
    // Methods
    void registerForMentorship(Mentor *M);
    void viewMentorDetails(Mentor *M);
    void updateSportsInterest();
};

class Mentor
{
private:
    int mentorId;
    string mentorName;
    string sportsExpertise[3];
    int maxLearners;
    int assignLearners[3];
    int learnersCount = 0;
    int mentorcount = 2;

public:
    // Parametrized Constructor
    Mentor(int mentorId, string mentorName, string sportsExpertise[], int maxLearners, int assignLearners[])
    {
        this->mentorId = mentorId;
        this->mentorName = mentorName;
        for (int i = 0; i < 3; i++)
        {
            this->sportsExpertise[i] = sportsExpertise[i];
        }
        this->maxLearners = maxLearners;
        for (int i = 0; i < 3; i++)
        {
            this->assignLearners[i] = assignLearners[i];
        }
    }
    // Default Constructor
    Mentor()
    {
        mentorId = 0;
        mentorName = "";
        sportsExpertise[0] = sportsExpertise[1] = sportsExpertise[2] = "";
        maxLearners = 0;
        assignLearners[0] = assignLearners[1] = assignLearners[2] = 0;
        mentorcount = 2;
    }

    // setters
    void setMentorName(string name) { mentorName = name; }
    void setMentorID(int id) { mentorId = id; }
    void setMaxLeaner(int maxL) { maxLearners = maxL; }
    void setSportExpertise(string sportExp[])
    {
        for (int i = 0; i < 3; i++)
        {
            sportsExpertise[i] = sportExp[i];
        }
    }
    void setAssignLearners(int assign) { assignLearners[learnersCount] = assign; }
    void setLearnerCount(int count) { learnersCount = count; }
    // getters
    string *getSportExpertise() { return sportsExpertise; }
    int getMentorId() { return mentorId; }
    string getMentorName() { return mentorName; }
    int getMaxlearnes() { return maxLearners; }
    int *getAssignLearners() { return assignLearners; }
    int getMentorCount() { return mentorcount; }
    int getLearnerCount() { return learnersCount; }
    void displayMentorDetails()
    {

        cout << "\nMentor ID:" << getMentorId();
        cout << "\nMentor Name:" << getMentorName();
        cout << "\nMentor Max Lerners: " << getMaxlearnes();
        int *temp = getAssignLearners();
        cout << "\nAssi<gn Learners: ";
        for (int i = 0; i < learnersCount; i++)
        {
            cout << "\nAssign Learner #(" << i + 1 << ") " << temp[i];
        }
        string *tem2 = getSportExpertise();
        for (int i = 0; i < 3; i++)
        {
            cout << "\nSport Expertise: " << tem2[i];
        }
    }
    void assignLearner(Student *s);
    void removeLearner(Student *s);
    void viewLearners();
    void provideGuidance();
};
class Skill
{
private:
    int skillID;
    string skillName;
    string skillDescription;

public:
    Skill(int id, string name, string desc) : skillID(id), skillName(name), skillDescription(desc) {}

    // setters
    void setID(int newid) { skillID = newid; }
    void setSkillName(string newskill) { skillName = newskill; }
    void setSkillDescription(string newDescription) { skillDescription = newDescription; }
    // getters
    int getID() { return skillID; }
    string getName() { return skillName; }
    string getSkillDescription() { return skillDescription; }

    void showSkillDetails()
    {
        cout << "\nSkill ID: " << getID();
        cout << "\nSkill Name: " << getName();
        cout << "\nSkill Description: " << getSkillDescription();
    }
    void updateSkillDescription(string newDescription)
    {
        cout << "\n-----------------------------------------------------------\n";
        skillDescription = newDescription;
        cout << "\nSkill Description Successfully ! ";
        cout << "\n-----------------------------------------------------------\n";
    }
};
class Sport
{
private:
    int sportId;
    string sportName;
    string sportDescription;
    string requiredSkill[3];
    int skillscount = 0;

public:
    Sport(int Sid, string Sname, string description, string requiredSkills[3])
    {
        sportId = Sid;
        sportName = Sname;
        sportDescription = description;
        for (int i = 0; i < 3; i++)
        {
            requiredSkill[i] = requiredSkills[i];
        }
    }
    Sport()
    {
        sportId = 0;
        sportName = "";
        sportDescription = "";
        requiredSkill[0] = requiredSkill[1] = requiredSkill[2] = "";
        skillscount = 0;
    }
    // setters
    void setSportId(int id) { sportId = id; }
    void setSportName(string name) { sportName = name; }
    void setSportDescription(string description) { sportDescription = description; }
    void setRequiredSkills(string skillsrequired[])
    {
        for (int i = 0; i < 3; i++)
        {
            requiredSkill[i] = skillsrequired[i];
        }
    }

    // getters
    int getsportId() { return sportId; }
    string getsportName() { return sportName; }
    string getsportDescription() { return sportDescription; }
    string *getSportrequiredSkills() { return requiredSkill; }

    void addSkill(Skill *s);
    void removeSkill(Skill *s);
};

// Students Methods
void Student::registerForMentorship(Mentor *M)
{
    string name;
    cout << "\nEnter your Name: ";
    cin >> name;
    int studentId;
    cout << "\nEnter your ID: ";
    cin >> studentId;
    if (M->getLearnerCount() >= 3)
    {
        cout << "\nMentor has already assigned maximum Students: ";
    }
    else
    {
        M->setAssignLearners(studentId);
        M->setLearnerCount(M->getLearnerCount() + 1);
        cout << "\n-------------------------------------------------\n";
        cout << "\nStudent has been Register Successfully: ";
        cout << "\n-------------------------------------------------\n";
    }
}
void Student::viewMentorDetails(Mentor *M)
{
    for (int i = 0; i < M->getMentorCount(); i++)
    {
        M[i].displayMentorDetails();
        cout << "\n------------------------------------------------------------\n";
    }
}
void Student::updateSportsInterest()
{
    string sportInterests[2];
    cout << "\nEnter the new sports intersrests # 1: ";
    cin >> sportInterests[0];
    cout << "\nEnter the new sports intersrests # 2: ";
    cin >> sportInterests[1];
    setSportInterests(sportInterests);
    cout << "\n----------------------------------------------\n";
    cout << "\nSports Interests Updated: ";
    cout << "\n-----------------------------------------------\n";
    cout << "\nAfter Updation: ";
    string *temp = getSportsInterests();
    for (int i = 0; i < 2; i++)
    {
        cout << "\nSports # " << i + 1 << " " << temp[i];
    }
    cout << "\n";
}
// Mentor Methods
void Mentor::assignLearner(Student *s)
{
    if (getLearnerCount() >= getMaxlearnes())
    {
        cout << "\nMaximum capacity has reached: ";
    }
    else
    {
        // cout<<"\nThese are students : ";
        // for (int i = 0; i < getLearnerCount(); i++)
        // {
        // s->displayStudentDetails();
        // }
        cout << "\n---------------------------------------\n";
        int id;
        cout << "\nEnter the student ID to assign: ";
        cin >> id;
        setAssignLearners(id);
        setLearnerCount(getLearnerCount() + 1);
        cout << "\nLearner has Assigned successfully: \n";
    }
    cout << "\n-----------------------------------------------------\n";
    displayMentorDetails();
}
void Mentor::removeLearner(Student *s)
{
    int id, found = 0, index = 0;
    cout << "\nEnter the Student ID to remove: ";
    cin >> id;

    int *learners = getAssignLearners();
    for (int i = 0; i < getLearnerCount(); i++)
    {
        if (learners[i] == id)
        {
            found = 1;
            index = i;
            break;
        }
    }

    if (found == 1)
    {
        for (int i = index; i < getLearnerCount() - 1; i++)
        {
            learners[i] = learners[i + 1];
        }
        setLearnerCount(getLearnerCount() - 1);

        cout << "\nStudent ID " << id << " has been removed successfully.";
    }
    else
    {
     cout<<"\n-----------------------------------------\n";
        cout << "\nStudent not found!";
        cout<<"\n-----------------------------------------\n";
    }
    displayMentorDetails();
}

void Mentor::viewLearners()
{
    for (int i = 0; i < getLearnerCount(); i++)
    {
        getAssignLearners();
    }
}
void Mentor::provideGuidance()
{
    cout << "\n--------------------------------------------------------\n";
    int id;
    cout << "\nEnter the student id to give Guidance: ";
    cin >> id;
    string feedback;
    cout << "\n-------------Give the Guidance:-------------\n ";
    cin.ignore();
    getline(cin, feedback);
    cout << "\n----------------------------------------------------\n";
}
void Sport::addSkill(Skill *s)
{
    if (skillscount >= 3)
    {
        cout << "\nSkills maximum limit reached ! ";
        return;
    }
    string newskill;
    string skilldesc;
    int newSkillId;

    cout << "\nEnter the Skill ID to add: ";
    cin >> newSkillId;
    cout << "\nEnter the Skill Name to add: ";
    cin >> newskill;
    cout << "\nEnter the Skill Description to add: ";
    cin.ignore();
    getline(cin, skilldesc);

    requiredSkill[skillscount] = newskill;
    skillscount++;
    s[skillscount - 1] = Skill(newSkillId, newskill, skilldesc);

    cout << "\n-----------------------------------------";
    cout << "\nSkill added successfully!";
    cout << "\nAter adding the sklls: ";
    for (int i = 0; i < skillscount; i++)
    {
        cout << "\nSkill #" << (i + 1) << ": " << requiredSkill[i];
    }
    cout << "\n-----------------------------------------\n";
}

void Sport::removeSkill(Skill *s)
{

    string removeskill;
    cout << "\nCurrent Skills:";
    for (int i = 0; i < skillscount; i++)
    {
        cout << "\n"
             << (i + 1) << ". " << requiredSkill[i];
    }

    cout << "\nEnter the skill Name to be removed: ";
    cin >> removeskill;

    int found = -1;
    for (int i = 0; i < skillscount; i++)
    {
        if (requiredSkill[i] == removeskill)
        {
            found = i;
            break;
        }
    }
    if (found == -1)
    {
        cout << "\nInvalis SKill not found !";
        return;
    }
    for (int i = found; i < skillscount - 1; i++)
    {
        requiredSkill[i] = requiredSkill[i + 1];
    }
    skillscount--;
    cout << "\n-----------------------------------------";
    cout << "\nSkill has been removed successfully!";
    cout << "\nAfter updation:";
    for (int i = 0; i < skillscount; i++)
    {
        cout << "\nSkill no " << i + 1 << ": " << requiredSkill[i];
    }
    cout << "\n-----------------------------------------\n";
}

int main()
{
	cout<<"Code Done by: Yash Raj"<<endl;
	cout<<"Roll Number: 24k-0737"<<endl;
    // Student Details:
    string interests1[2] = {"cricket", "football"};
    string interests2[2] = {"BasketBall", "football"};

    Student S[3] = {
        Student(101, "Ali", 19, interests1, 700),
        Student(102, "Ahmad", 20, interests2, 811)};

    // Mentor Details:
    string sportsExpertise1[3] = {"cricket", "football", "basketball"};
    string sportsExpertise2[3] = {"BasketBall", "VolleyBall", "basketball"};
    int assignLearners1[3] = {-1};
    int assignLearners2[3] = {-1};
    Mentor M[2] = {
        Mentor(900, "Ali", sportsExpertise1, 3, assignLearners1),
        Mentor(901, "Ahmad", sportsExpertise2, 3, assignLearners2)};
    // Sport Details:
    string requiredSkill1[3] = {"Batting", "Bowling", "fielding"};
    string requiredSkill2[3] = {"Runner", "Goalkeeper", "Field"};
    Sport Sb[5] = {
        Sport(500, "Cricket", "Batsmen", requiredSkill1),
        Sport(505, "Football", "GoalKeeper", requiredSkill2), Sport(), Sport(), Sport()};
    // Skill details:
    Skill s1(888, "batting", "Batting average is hightest");
    Skill s2(999, "bowling", "Best wicket taker");
  int choice;
 while(choice!=11){
    cout << "\nStudents Methods: \n";
    cout << "\n1.Register for Mentorship:";
    cout << "\n2. Mentor Details:";
    cout << "\n3.Update Sports Interests:";
    cout << "\n4.Assign Learner: ";
    cout << "\n5.Remove Learner:";
    cout << "\n6.View Leanners:";
    cout << "\n7.Provide Guidance: ";
    cout << "\n8.Add skill";
    cout << "\n9.Remove Skill";
    cout << "\n10.Enter the new Descritpion to Update:";
    cout<<"\n11.Exit"<<endl;
 
    int choice;
    cout << "\nEnter the Choice: ";
    cin >> choice;
    switch (choice)
    {
     case 1:
    {
     system("cls");
        S[0].registerForMentorship(&M[0]);
        break;
    }
    case 2:
    {
     system("cls");
        S[0].viewMentorDetails(M);
        break;
    }
    case 3:
    {
      system("cls");
        S[0].updateSportsInterest();
        break;
    }
    case 4:
    {
      system("cls");
        M[0].assignLearner(S);
        break;
    }
    case 5:
    {
      system("cls");
        M[0].removeLearner(S);
        break;
    }
    case 6:
    {
     system("cls");
        M[0].viewLearners();
        break;
    }
    case 7:
    {
      system("cls");
      M[0].provideGuidance();
        break;
    }
    case 8:
    {
      system("cls");
      Sb[0].addSkill(&s1);
      break;
    }
    case 9:
    {
     system("cls");
        Sb[0].removeSkill(&s2);
        break;
    }
    case 10:
    {
     system("cls");
        string description;
        cout << "\nEnter the new Description to Update: ";
        cin.ignore();
        getline(cin, description);
        s1.updateSkillDescription(description);
        cout << "\nAfter Updation: ";
        cout << s1.getSkillDescription() << endl;
        break;
    }
    case 11:
    	cout<<"Exiting the program"<<endl;
    	exit(0);
     return 0;
     break;
    default:
    {
        cout << "\nInvalid choice!" << endl;
        break;
    }
    }
}
    return 0;
}
    {
     case 1:
    {
     system("cls");
        S[0].registerForMentorship(&M[0]);
        break;
    }
    case 2:
    {
     system("cls");
        S[0].viewMentorDetails(M);
        break;
    }
    case 3:
    {
      system("cls");
        S[0].updateSportsInterest();
        break;
    }
    case 4:
    {
      system("cls");
        M[0].assignLearner(S);
        break;
    }
    case 5:
    {
      system("cls");
        M[0].removeLearner(S);
        break;
    }
    case 6:
    {
     system("cls");
        M[0].viewLearners();
        break;
    }
    case 7:
    {
      system("cls");
      M[0].provideGuidance();
        break;
    }
    case 8:
    {
      system("cls");
      Sb[0].addSkill(&s1);
      break;
    }
    case 9:
    {
     system("cls");
        Sb[0].removeSkill(&s2);
        break;
    }
    case 10:
    {
     system("cls");
        string description;
        cout << "\nEnter the new Description to Update: ";
        cin.ignore();
        getline(cin, description);
        s1.updateSkillDescription(description);
        cout << "\nAfter Updation: ";
        cout << s1.getSkillDescription() << endl;
        break;
    }
    case 11:
    	cout<<"Exiting the program"<<endl;
    	exit(0);
     return 0;
     break;
    default:
    {
        cout << "\nInvalid choice!" << endl;
        break;
    }
    }
}
    return 0;
}