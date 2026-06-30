//Yash Raj//
//24k-0737//
#include <iostream>
#include <string>
using namespace std;

double hashedPassword(string password) {
    double hash = 5381;
    for (int i = 0; i < password.length(); i++) {
        hash = (hash * 33) + password[i];
    }
    return hash;
}

class user {
public:
    string name;
    int id;
    string permissions[5];
    string email;
    double hashed_password;

    user(string name, int id, string permissions[], string email, double hashed_password)
        : name(name), id(id), email(email), hashed_password(hashed_password) {
        for (int i = 0; i < 5; i++) {
            this->permissions[i] = permissions[i];
        }
    }

    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Permissions: ";
        for (int i = 0; i < 5; i++) {
            if (!permissions[i].empty()) cout << permissions[i] << " ";
        }
        cout << endl;
        cout << "Email: " << email << endl;
    }

    bool hasPermission(string action) {
        for (int i = 0; i < 5; i++) {
            if (permissions[i] == action) {
                return true;
            }
        }
        return false;
    }
};

void authenticateAndPerformAction(user* u, string action) {
    if (u->hasPermission(action)) {
        cout << u->name << " is authorized to perform " << action << endl;
    }
    else {
        cout << u->name << " is NOT authorized to perform " << action << endl;
    }
}

class student : public user {
public:
    bool assignments[10];

    student(string name, int id, string permissions[], string email, double hashed_password, bool assignments[])
        : user(name, id, permissions, email, hashed_password) {
        for (int i = 0; i < 10; i++) {
            this->assignments[i] = assignments[i];
        }
    }

    void submitAssignment(int n) {
        if (n >= 0 && n < 10) {
            assignments[n] = true;
            cout << "Assignment " << n + 1 << " Submitted!" << endl;
        }
        else {
            cout << "Invalid Assignment Number!" << endl;
        }
    }

    void display() override {
        cout << endl<<"Student Name: " << name << endl;
        user::display();
    }
};

class TA : public student {
public:
    string students[10];
    string projects[2];
    int projectCount;
    int studentCount;

    TA(string name, int id, string permissions[], string email, double hashed_password, bool assignments[])
        : student(name, id, permissions, email, hashed_password, assignments) {
        projectCount = 0;
        studentCount = 0;
    }

    void display() override {
        cout << endl<<"TA Name: " << name << endl;
        user::display();
        cout << "Assigned Students: ";
        for (int i = 0; i < studentCount; i++) {
            cout << students[i] << " ";
        }
        cout << endl<<"Projects: ";
        for (int i = 0; i < projectCount; i++) {
            cout << projects[i] << " ";
        }
        cout << endl;
    }

    void assignStudent(string studentName) {
        if (studentCount < 10) {
            students[studentCount++] = studentName;
            cout << "Student " << studentName << " assigned to TA " << name << endl;
        }
        else {
            cout << "Cannot assign more students. TA is full!" << endl;
        }
    }

    void addProject(string projectName) {
        if (projectCount < 2) {
            projects[projectCount++] = projectName;
            cout << "Project " << projectName << " assigned to TA " << name << endl;
        }
        else {
            cout << "Cannot assign more projects. TA has reached the limit!" << endl;
        }
    }

    void viewProjects() {
        cout << "TA " << name << " is working on projects:\n";
        for (int i = 0; i < projectCount; i++) {
            cout << "- " << projects[i] << endl;
        }
    }
};

class professor : public user {
public:
    professor(string name, int id, string permissions[], string email, double hashed_password)
        : user(name, id, permissions, email, hashed_password) {
    }

    void display() override {
        cout <<endl<< "Professor Name: " << name << endl;
        user::display();
    }

    void assignProject(TA& ta, string projectName) {
        ta.addProject(projectName);
    }
};

int main() {
	cout<<"Name: Yash Raj"<<endl;
	cout<<"Roll Number: 24k-0737"<<endl;
    string studentPermissions[5] = { "submitAssignment", "", "", "", "" };
    string taPermissions[5] = { "submitAssignment", "viewProjects", "manageStudents", "", "" };
    string profPermissions[5] = { "assignProjects", "labAccess", "", "", "" };
    bool studentAssignments[10] = { false };
    student s1("Saad", 101, studentPermissions, "Saad@gmail.com", hashedPassword("password123"), studentAssignments);
    TA t1("Yash Raj", 102, taPermissions, "Yashmandhan@gmail.com", hashedPassword("secure456"), studentAssignments);
    professor p1("Mubashir", 201, profPermissions, "Mubashir@gmail.com", hashedPassword("prof789"));

    s1.display();
    t1.display();
    p1.display();

    s1.submitAssignment(2);
    t1.assignStudent("Charlie");
    p1.assignProject(t1, "AI Research");
    t1.viewProjects();

    s1.display();
    t1.display();
    p1.display();

    authenticateAndPerformAction(&s1, "submitAssignment");
    authenticateAndPerformAction(&t1, "manageStudents");
    authenticateAndPerformAction(&p1, "labAccess");

    return 0;
}
