// Student ID: 20274909

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Hanoi.h"

using namespace std;

int main()
{
   Hanoi test = Hanoi();
   cout << test.solve(3, 1, 2, 3);
}

std::string Hanoi::lookup_moves(int num_discs, int src, int dst) {
   return "";
}

std::string Hanoi::get_moves(int num_discs, int src, int dst, int tmp) {
   string output = "";
   
   if (num_discs == 1) {
      output += to_string(src) + "->" + to_string(dst) + "\n";
      return output;
   }
   else if (num_discs == 0) {
      return output;
   }
   else {
      output += get_moves(num_discs - 1, src, tmp, dst);
      output += to_string(src) + "->" + to_string(dst) + "\n";
      output += get_moves(num_discs - 1, tmp, dst, src);
   }
   return output;
}

std::string Hanoi::solve(int num_discs, int src, int dst, int tmp) {
   string output = "# Below, 'A->B' means 'move the top disc on pole A to pole B'\n";
   output += get_moves(num_discs, src, dst, tmp);
   return output;
}