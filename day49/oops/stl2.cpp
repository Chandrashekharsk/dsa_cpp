// operator overloading
#include<iostream>
#include<vector>
using namespace std;

class MyFloat{
  float ft;
  public:
    MyFloat(){
      ft = 0.1;
    }
    void getVal(){
      cout<< ft<<endl;
    }
    void operator()(float val){
      ft+=val;
    }
};

int main(){

  MyFloat obj;
  obj.getVal();
  obj(0.1);
  obj.getVal();


  return 0;
}