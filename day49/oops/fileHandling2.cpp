#include<iostream>
#include<vector>
using namespace std;

constexpr int maxbuffer = 1024;

int main(){
  const char* fileName = "mythisfile.txt";
  const char* information = "lorem ipsum dolor sit amet";

  // FILE* fh = fopen(fileName, "w");
  // FILE* fh = fopen(fileName, "a");
  // for(int i=0; i<50; ++i){
  //   fputs(information, fh);
  // }
  // fclose(fh);

  char buf[maxbuffer];
  FILE* fh = fopen(fileName, "r");
  while(fgets(buf, maxbuffer, fh)){
    fputs(buf, stdout);
  }
  fclose(fh);

  return 0;
}