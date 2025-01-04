// New -> allocates a memory
// Delete -> deallocates a memory
// Note: with New keyword delete is required
#include<iostream>
#include<vector>
#include<memory>
using namespace std;

class User{
  public:
    User(){
      cout<<"created new User\n";
    }
    ~User(){
      cout<<"destroyed new User\n";
    }
    void test()const{
      cout<<"I am test from User\n";
    }
};  



int main(){
  {
    unique_ptr<User> sam = make_unique<User>();
    sam->test();
    // unique_ptr<User> sam2 = sam;  // NOT ALLOWED
  }
  {
    shared_ptr<User> tim = make_shared<User>();
    weak_ptr<User> wtim = tim;
    shared_ptr<User> tim2 = tim;
  }
  cout<<"outside code\n";

  return 0;
}