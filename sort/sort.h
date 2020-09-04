#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Sortmethod {
    public:
        virtual void sort(vector<int> &a) = 0;
};

// TODO: quick sort
class QuickSort : public Sortmethod{
    public:
        void sort(vector<int> &a){

        }
};

// TODO: merge sort

// TODO: select sort

// TODO: insert sort

// TODO: bubble sort

// TODO: shell sort

// TODO: heap sort

// TODO: counting sort

// TODO: bucket sort

// TODO: radio sort


class SelectSort : public Sortmethod{
    public:
        void sort(vector<int> &a) {
            if(a.size() < 2) return;
            cout << "\nThis is Select sort " << endl;
            for (int i = 0; i != a.size(); ++i) {
                int min = i;
                int temp = a[i];
                for (int j = i + 1; j != a.size(); ++j) {
                    if (a[j] < a[min]) min = j;
                }
                a[i] = a[min];
                a[min] = temp;
            }
        }
};

