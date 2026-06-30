//Yash Raj
//24k-0737//
#include<iostream>
#include<tuple>//this library will dispaly coordinates into parenthesis// 
using namespace std;

class ball {
	int x, y;
public:
	ball() {
		x = 0;
		y = 0;
	}
	int getBallX() {
		return x;
	}
	int getBallY() {
		return y;
	}
	tuple<int, int> getBallPosition() {
		return make_tuple(x, y);
	}
	void move(int dx, int dy) {
		x += dx;
		y += dy;
	}
};

class goal {
	int x, y;
public:
	goal() {
		x = 3;
		y = 3;
	}
	bool isReached(int ballX, int ballY) {
		return (x == ballX && y == ballY);
	}
};

class robot {
	string name;
	int hits;
public:
	robot(string n) {
		name = n;
		hits = 0;
	}
	void hitBall(int& ballX, int& ballY, const string& direction) {
		if (direction == "up") {
			ballY += 1;
		}
		else if (direction == "down") {
			ballY -= 1;
		}
		else if (direction == "left") {
			ballX -= 1;
		}
		else if (direction == "right") {
			ballX += 1;
		}
		hits++;
	}
	string getName() {
		return name;
	}
	int getHits() {
		return hits;
	}
};

class team {
	string teamName;
	robot* robo;
public:
	team(string team, robot* player) {
		teamName = team;
		robo = player;
	}
	string getTeam() {
		return teamName;
	}
	robot* getRobot() {
		return robo;
	}
};

class game {
	team* t1, * t2;
	goal g;
	ball b;
public:
	game(team* t1, team* t2) {
		this->t1 = t1;
		this->t2 = t2;
	}
	void play(team* t) {
		robot* robo = t->getRobot();
		cout<< t->getTeam() << " has started playing!\n";
		while (!g.isReached(b.getBallX(), b.getBallY())) {
			cout<<"Current ball position: (" << b.getBallX() << ", " << b.getBallY() << ")"<<endl;
			cout<<"Enter direction (up, down, left, right): ";
			string direction;
			cin >> direction;
			int ballX = b.getBallX();
			int ballY = b.getBallY();
			robo->hitBall(ballX, ballY, direction);
			b.move(ballX - b.getBallX(), ballY - b.getBallY());
			cout<<"Ball moved to: (" << ballX << ", " << ballY << ")" <<endl;
		}
		cout<<"Goal reached in "<<robo->getHits()<<" hits!"<<endl;
	}
	void startGame() {
		cout<<"Starting the game!"<<endl;
		play(t1);
		int hits1 = t1->getRobot()->getHits();
		b = ball();
		play(t2);
		int hits2 = t2->getRobot()->getHits();
		cout<<"Game Over!"<<endl;
		if (hits1 < hits2) cout << t1->getTeam() << " wins!" << endl;
		else if (hits2 < hits1) cout << t2->getTeam()<<"wins!"<<endl;
		else cout<<"It's a tie!"<<endl;
	}
};

int main() {
	cout<<"Name: Yash Raj"<<endl;
	cout<<"Roll Number: 24k-0737"<<endl;
	robot r1("Robot A");
	robot r2("Robot B");
	team teamOne("Team Alpha", &r1);
	team teamTwo("Team Beta", &r2);
	game g(&teamOne, &teamTwo);
	g.startGame();
	return 0;
}
