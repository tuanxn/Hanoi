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
   cout << test.solve(3, 1, 2, 3);
}


std::string Hanoi::lookup_moves(int num_discs, int src, int dst) {
   if (_cache.empty()) {
      return "";
   }

   if (_cache[num_discs][src][dst] != "") {
      return _cache[num_discs][src][dst];
   }
   return "";
}

std::string Hanoi::get_moves(int num_discs, int src, int dst, int tmp) {
   
   string look_up = lookup_moves(num_discs, src, dst);
   if (look_up != "") {
      return look_up;
   }

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
   _cache[num_discs][src][dst] = output;
   return output;
}

std::string Hanoi::solve(int num_discs, int src, int dst, int tmp) {
   

   if (_cache.empty()) {
      _cache.resize(num_discs + 1);

      for (int i = 0; i <= num_discs; i++) {
         _cache[i].resize(4);
         for (int j = 0; j < 4; j++) {
            _cache[i][j].resize(4);
            for (int k = 0; k < 4; k++) {
               _cache[i][j][k] = "";
            }
         }
      }
   }


   string output = "# Below, 'A->B' means 'move the top disc on pole A to pole B'\n";
   output += get_moves(num_discs, src, dst, tmp);

   //for (int i = 0; i <= num_discs; i++) {
   //   cout << "disc:" + to_string(i) + " ";
   //   for (int j = 0; j < 4; j++) {
   //      cout << "src pole:" + to_string(j) + " ";
   //      for (int k = 0; k < 4; k++) {
   //         cout << "dst pole: " + to_string(k) + " :" + _cache[i][j][k] + "\n";
   //      }
   //   }
   //}

   return output;
}