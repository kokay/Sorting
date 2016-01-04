#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Partition(int low, int high, vector<int>* sequence) {
  int p = high;
  int divideIdx = low;
  for (int i = low;i < high;++i) {
    if (sequence->at(i) < sequence->at(p)) {
      swap(sequence->at(i), sequence->at(divideIdx));
      ++divideIdx;
    }
  }
  swap(sequence->at(p), sequence->at(divideIdx));
  return divideIdx;
}

void Quicksort(int low, int high, vector<int>* sequence) {
  if (low < high) {
    int p = Partition(low, high, sequence);
    Quicksort(low, p - 1, sequence);
    Quicksort(p + 1, high, sequence);
  }
}

int main() {
  vector<int> test{ 9,7,3,4,1,2,6 };
  Quicksort(0, test.size() - 1, &test);
  for (auto& number : test) {
    cout << number << " ";
  }
  cout << endl;
}