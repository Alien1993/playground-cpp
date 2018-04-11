#include <iostream>
#include <list>
#include <map>

using namespace std;

int main() {
  list<int> coins{200, 100, 50, 20, 10, 5, 2, 1};
  auto amount = 243;
  
  map<double, int> change;
  
  for (const auto& c : coins) {
      change[static_cast<double>(c) / 100] = amount / c;
      amount -= c * (amount / c);
  }
  
  cout << "Change:" << endl;
  for (const auto& p : change) {
    cout << p.first << " x " << p.second << endl;
  }

  return 0;
}


/* 
Given a number of cents, write a function to make change with the fewest number of coins.

2.43 EUR -> 1x2, 2x.20, 1x.02, 1x.01
 */