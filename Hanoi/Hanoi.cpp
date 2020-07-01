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
   std::cout << test.solve(0, 2, 3, 1);
   std::cout << test.solve(1, 2, 1, 3);
   std::cout << test.solve(3, 2, 3, 1);
   std::cout << test.solve(2, 1, 3, 2);
}


std::string Hanoi::lookup_moves(int num_discs, int src, int dst) {

   if (_cache.empty()) {

      for (int i = 0; i <= num_discs; i++) {
         vector<vector < string >> temp;
         _cache.push_back(temp);
         for (int j = 0; j < 4; j++) {
            vector<string> temp2;
            _cache[i].push_back(temp2);
            for (int k = 0; k < 4; k++) {
               _cache[i][j].push_back("");
            }
         }
      }
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
      _cache[num_discs][src][dst] = output;
      return output;
   }
   else if (num_discs == 0) {
      _cache[num_discs][src][dst] = output;
      return output;
   }
   else {
      output += get_moves(num_discs - 1, src, tmp, dst);
      output += to_string(src) + "->" + to_string(dst) + "\n";
      output += get_moves(num_discs - 1, tmp, dst, src);
   }
   _cache[num_discs][src][dst] = output;
   //_cache[num_discs - 1].clear();
   return output;
}

std::string Hanoi::solve(int num_discs, int src, int dst, int tmp) {

   if (_cache.size() != num_discs+1) {

      for (int i = _cache.size(); i <= num_discs; i++) {
         vector<vector < string >> temp;
         _cache.push_back(temp);
         for (int j = 0; j <= src; j++) {
            vector<string> temp2;
            _cache[i].push_back(temp2);
            for (int k = 0; k <= dst; k++) {
               _cache[i][j].push_back("");
            }
         }
      }
   }


   string output = "# Below, 'A->B' means 'move the top disc on pole A to pole B'\n";
   output += get_moves(num_discs, src, dst, tmp);

   for (int i = 0; i <= num_discs; i++) {
      for (int j = 0; j <= src; j++) {
         for (int k = 0; k <= dst; k++) {
            cout << "_cache["+to_string(i) + "][" + to_string(j) + "][" + to_string(k) + "] = " + _cache[i][j][k] + "\n";
         }
      }
   }

   return output;
}