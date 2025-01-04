#include<iostream>
#include<vector>
using namespace std;

#include <iostream>

namespace Company {
  namespace Department {
    namespace Engineering {
      class SoftwareEngineer {
      public:
        void work() {
          std::cout << "Software Engineer is working on a project." << std::endl;
        }
      };
      class HardwareEngineer {
      public:
        void work() {
          std::cout << "Hardware Engineer is designing a circuit." << std::endl;
        }
      };
    }
    namespace Marketing{};
  }
};

int main(){

  


  return 0;
}