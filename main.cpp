#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<string> info_vec, vector<string> query_vec) {
  vector<int> output_vec;
  return output_vec;
}

int main() {
  vector<string> info_vec{"java backend junior pizza 150", "python frontend senior chicken 210",
      "python frontend senior chicken 150", "cpp backend senior pizza 260",
      "java backend junior chicken 80", "python backend senior chicken 50"};
  vector<string> query_vec{"java and backend and junior and pizza 100",
      "python and frontend and senior and chicken 200", "cpp and - and senior and pizza 250",
      "- and backend and senior and - 150", "- and - and - and chicken 100",
      "- and - and - and - 150"};
  for (int &output : solution(info_vec, query_vec)) {
    cout << output << " ";
  }
  return 0;
}
