#include <iostream>
using namespace std;

int MUL (int a, int b);
int FACT (int n);

int main() {
  int n = 4;
  cout << FACT (n) << "\n";
} 

int MUL (int a, int b){
  int c = 0;
  while (b > 0){
    c = c + a;
    b--;
  }
  return c;
}

int FACT (int n){
  if (n <= 1)
  return 1;
  else
  return MUL (n, FACT(n - 1));
}
