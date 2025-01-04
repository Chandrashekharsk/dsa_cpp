#include<iostream>
#include<vector>
using namespace std;

class Money{
  public:
    void gotMoney(){
      puts("Got 5k in my account");
    }
};

class Man{
  string _name;
  int _age;
  Man(){};

  protected:
    Man(const string& name, const int& age):
      _name(name), _age(age){};
    void run(){
      puts("I can run");
    }
  public:
    void sayName()const;
};

void Man::sayName()const{
  cout<<"My name is: "<<_name <<", and age is: "<<_age<<endl;
}


class Superman : public Man{
  bool flight;
  public:
    Superman(const string& name): Man::Man(name, 26){};
    void run(){
      puts("I can run at light speed");
    }
};

class Spiderman : public Man, public Money {
  bool flight;
  public:
    Spiderman(const string& name): Man::Man(name, 19){};
    void run(){
      puts("I can run at normal speed");
    }
};

int main(){
  Superman clark("Kent");
  clark.sayName();

  Spiderman peter("peter");
  peter.sayName();
  peter.gotMoney();



  return 0;
}