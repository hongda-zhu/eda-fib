#include <iostream>
#include <vector>

using namespace std;

static const int MAX= 50;

// gen 5
int main (int argc, char** argv) {
  srand(time(NULL));
  int n = atoi(argv[1]);
  cout << n << endl;
  int pesos = 0;
  for (int i = 0; i < n; ++i) {
    int p = rand()%MAX + 1;    
    int v = rand()%MAX + 1;
    cout << p << " " << v << endl;
    pesos += p;
  }
  cout << int((double(pesos)/n)*(n/2)) << endl;
}
