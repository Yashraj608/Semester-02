#include<iostream>
using namespace std;
class Media{
public:
virtual void play(){
    cout<<"Play the song"<<endl;
}

virtual void stop(){
    cout<<"Song stopped"<<endl;
}

};
class Audio: public Media{
public:
void play()override{
    cout<<"Audio is playing..."<<endl;
}

void stop()override{
    cout<<"Audio stopped playing..."<<endl;
}
};

class Video: public Media{
public:
void play()override{
    cout<<"Playing video"<<endl;
}
void stop()override{
    cout<<"video stopped playing..."<<endl;
}
};
class Livestream: public Media{
public:
void play()override{
cout<<"Playing the music"<<endl;
}
void stop()override{
    cout<<"Livestream stopped..."<<endl;
}
};
int main(){

    Media*m[3];
    m[0] = new Audio();
    m[0]->play();
    m[0]->stop();

    m[1] = new Video();
    m[1]->play();
    m[1]->stop();

    m[2]= new Livestream();
    m[2]->play();
    m[2]->stop();
    return 0;

    for(int i =0; i<3;i++){
        delete m[i];
    }

    for(int i=0;i<3;i++){
        cout<<m[i]<<endl;
    }
}