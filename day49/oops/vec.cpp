#include<iostream>
#include<vector>
using namespace std;

// class Corners{
//   public:
//     float a, b, c, d;
// };

struct Corners{
  float a, b, c, d;
};

ostream& operator<<(ostream& stream, const Corners& corner){
  stream << corner.a<<" "<<corner.b<<" "<<corner.c<<" "<<corner.d;
  return stream;
}


int main(){
  vector<Corners> corners;
  corners.push_back({1,2,3,4});
  corners.push_back({5,6,7,8});

  for(int i = 0; i<corners.size(); ++i){
    cout<<corners[i]<<endl;
  }

  return 0;
}