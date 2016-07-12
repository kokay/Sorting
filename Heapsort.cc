#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void HeapsortHeapify(const int insertedIdx, vector<int>* sequence) {
  int idx = insertedIdx;
  while (idx != 1) {
    if (sequence->at(idx) > sequence->at(idx / 2)) {
      swap(sequence->at(idx), sequence->at(idx / 2));
      idx = idx / 2;
    }
    else {
      break;
    }
  }
}

void DownHeap(const int firstSortedIdx, vector<int>* sequence) {
  int idx = 1;
  while (true) {
    if (idx * 2 >= firstSortedIdx) break;
    if (idx * 2 + 1 >= firstSortedIdx) {
      if (sequence->at(idx) < sequence->at(idx * 2)) {
        swap(sequence->at(idx), sequence->at(idx * 2));
      }
      break;
    }
    
    if (sequence->at(idx * 2) > sequence->at(idx * 2 + 1)) {
      if (sequence->at(idx) > sequence->at(idx * 2)) break;

      swap(sequence->at(idx), sequence->at(idx * 2));
      idx = idx * 2;
    }
    else {
      if (sequence->at(idx) > sequence->at(idx * 2 + 1)) break;

      swap(sequence->at(idx), sequence->at(idx * 2 + 1));
      idx = idx * 2 + 1;
    }
  }
}

void Heapsort(vector<int>* sequence) {
  sequence->insert(sequence->begin(), 0); 

  for (int i = 1;i < sequence->size();++i) { 
    HeapsortHeapify(i, sequence); 
  }

  for (int i = sequence->size() - 1;i >= 1;--i) { 
    swap(sequence->at(1), sequence->at(i));
    DownHeap(i, sequence); 
  }

  sequence->erase(sequence->begin()); 
}

int main() {
  vector<int> testVec{ 2,5,4,7,9,8,1,3,6 };
  Heapsort(&testVec);
  for (auto number : testVec) {
    cout << number << " ";
  }
  cout << endl;
}
