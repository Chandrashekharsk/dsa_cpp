#include <iostream>
#include <vector>
using namespace std;

class Phone {
  string _name = "";
  int _price = 0;
  string _os = "";

 public:
  Phone(); // default constructor
  Phone(const Phone&); // copy constructor
  Phone(const string& name, const string& os, const int& price); // parameterized constructor
  ~Phone(); // destructor

  string getOs() const { 
    return _os;
  }
};

Phone::Phone(): _name(), _os("Andy"), _price(){
  puts("Default constructor");
}
Phone::Phone(const string& name, const string& os, const int& price): _name(name), _os(os), _price(price){
  puts("Parameterized constructor");
}
Phone::Phone(const Phone& values){
  puts("OVERWRITE COPY CONSTRUCTOR");
  _name = "new-"+values._name;
  _os = "skinned-"+values._os;
  _price = values._price;
}

Phone::~Phone(){
  printf("Destructor called for %s\n",_name.c_str());
}



int main() { 
  Phone samsungA1;
  cout<<samsungA1.getOs()<<endl;
  Phone Oneplus8 ("Op8", "G2-Oxy", 35999);
  cout<<Oneplus8.getOs()<<endl;

  Phone Oneplus8s = Oneplus8;
  Oneplus8s.getOs();
  cout<<Oneplus8s.getOs()<<endl;

  return 0;
}