#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string item_vec_vec[4][4] =
    {{"-", "cpp", "java", "python"},
        {"-", "backend", "frontend"},
        {"-", "junior", "senior"},
        {"-", "chicken", "pizza"}};

vector<int> solution(vector<string> info_string_vec, vector<string> query_string_vec) {
  vector<vector<int>> info_vec_vec(108);
  for (const auto &info_string : info_string_vec) {
    int info_vec[4];
    int index_1 = 0, index_2 = info_string.find(' ', 0);
    for (int i = 0; i < 4; i++) {
      string info = info_string.substr(index_1, index_2 - index_1);
      index_1 = index_2 + 1;
      index_2 = info_string.find(' ', index_1);
      info_vec[i] = find(item_vec_vec[i], item_vec_vec[i] + 4, info) - item_vec_vec[i];
    }
    int score = stoi(info_string.substr(index_1, 10));
    for (int language : {0, info_vec[0]}) {
      for (int occupation : {0, info_vec[1]}) {
        for (int career : {0, info_vec[2]}) {
          for (int food : {0, info_vec[3]}) {
            int index = language * 27 + occupation * 9 + career * 3 + food;
            info_vec_vec[index].push_back(score);
          }
        }
      }
    }
  }
  for (int i = 0; i < 108; i++) {
    sort(info_vec_vec[i].begin(), info_vec_vec[i].end());
  }
  vector<int> answer_vec;
  for (const auto &query_string : query_string_vec) {
    int query_vec[4];
    int index_1 = 0, index_2 = query_string.find(' ', 0);
    for (int i = 0; i < 4; i++) {
      string query = query_string.substr(index_1, index_2 - index_1);
      index_1 = index_2 + 5;
      index_2 = query_string.find(' ', index_1);
      query_vec[i] = find(item_vec_vec[i], item_vec_vec[i] + 4, query) - item_vec_vec[i];
    }
    int target = stoi(query_string.substr(index_1 - 4, 10));
    int index = query_vec[0] * 27 + query_vec[1] * 9 + query_vec[2] * 3 + query_vec[3];
    answer_vec.push_back(info_vec_vec[index].end() - lower_bound(info_vec_vec[index].begin(), info_vec_vec[index].end(), target));
  }
  return answer_vec;
}