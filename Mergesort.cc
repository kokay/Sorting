#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void Marge(int low, int mid, int high, vector<int>* sequence) {
  deque<int> first, second;
  for (int i = low;i <= mid;++i)      first.push_back(sequence->at(i));
  for (int i = mid + 1;i <= high;++i) second.push_back(sequence->at(i));

  int idx = low;
  while (!first.empty() && !second.empty()) {
    if (first.front() < second.front()) {
      sequence->at(idx++) = first.front();
      first.pop_front();
    }
    else {
      sequence->at(idx++) = second.front();
      second.pop_front();
    }
  }
  for (int i = 0;i < first.size();++i) {
    sequence->at(idx++) = first.at(i);
  }
  for (int i = 0;i < second.size();++i) {
    sequence->at(idx++) = second.at(i);
  }
}

void Mergesort(int low, int high, vector<int>* sequence) {
  if (low < high) {
    int mid = low + (high - low) / 2;
    Mergesort(low, mid, sequence);
    Mergesort(mid + 1, high, sequence);
    Marge(low, mid, high, sequence);
  }
}

int main() {
  vector<int> sequence = { 9,8,7,6,5,4,3,2,1 };
  Mergesort(0, sequence.size() - 1, &sequence);

  for (auto number : sequence) {
    cout << number << " ";
  }
  cout << endl;
}