#include <iostream>
#include <vector>
using namespace std;
// positions: ...5 4, 3, 2, 1, 0
// Ones-compliment(it flips all bit 0->1 & 1->0): ~0100 = 1011

int getBit(int n, int pos) { 
  return ((n & (1 << pos)) != 0); 
}

// set 1 at position
int setBit(int n, int pos){
  return (n | (1<<pos));
}

// set 0 at position
int clearBit(int n, int pos){
  int mask = ~(1<<pos); // ones-compliment of 1 at pos
  return (mask & n);
}

// toggle bit at position
int updateBit(int n, int pos, int bitVal){
  //clear bit at pos
  int mask = ~(1<<pos);
  int new_n = n & mask;
  // set bit at pos
  return (new_n | (bitVal<<pos));
}

int main() {
  // Expected: 1 (binary of 5 is 101)
  cout << "getBit(5, 0): " << getBit(5, 0) << endl;  // Expected: 1
  cout << "getBit(5, 1): " << getBit(5, 1) << endl;  // Expected: 0
  cout << "getBit(5, 2): " << getBit(5, 2) << endl;  // Expected: 1

  cout << "setBit(5, 0): " << setBit(5, 0) << endl;  
  cout << "setBit(5, 1): " << setBit(5, 1) << endl;  
  cout << "setBit(5, 2): " << setBit(5, 2) << endl;  
  
  cout << "clearBit(5, 0): " << clearBit(5, 0) << endl;  // 4
  cout << "clearBit(5, 1): " << clearBit(5, 1) << endl;  // 5
  cout << "clearBit(5, 2): " << clearBit(5, 2) << endl;  // 1
  
  cout << "updateBit(5, 0): " << updateBit(5, 0, 0) << endl;  
  cout << "updateBit(5, 1): " << updateBit(5, 1, 0) << endl;  
  cout << "updateBit(5, 2): " << updateBit(5, 2, 0) << endl;  

  return 0;
}