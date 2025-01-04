#include<iostream>
#include<vector>
using namespace std;



int main(){

  static const char* originalFile = "originalFile.txt";
  // FILE* fh = fopen(originalFile, "w");
  // fclose(fh);

  static const char* editedFile = "editedFile.txt";
  // rename(originalFile, editedFile);
  remove(editedFile);

  return 0;
}