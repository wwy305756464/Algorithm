#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Sortmethod {
    public:
        virtual void sort(vector<int> &a) = 0;
};

class QuickSort : public Sortmethod{
    public:
        void sort(vector<int> &a){
            if(a.size() == 0) {
                return;
            }
            quicksort(a, 0, a.size() - 1);
        }

        void quicksort(vector<int>&a, int start, int end) {
            if (start >= end) {
                return;
            }

            int left = start;
            int right = end;
            int pivot = a[(start + end) / 2];

            while (left <= right) {
                while (left <= right && a[left] < pivot) {
                    left++;
                }
                while (left <= right && a[right] > pivot) {
                    right--;
                }
                if (left <= right) {
                    int temp = a[left];
                    a[left] = a[right];
                    a[right] = temp;
                    left++;
                    right--;
                }
            }

            quicksort(a, start, right);
            quicksort(a, left, end);
        }
};

// TODO: merge sort

class MergeSort : public Sortmethod{
    public:
        void sort(vector<int> &a) {
            if(a.size() == 0) {
                return;
            }
            
            vector<int> temp(a.size());
            mergesort(a, 0, a.size()-1, temp);
        }
    // private:
        void mergesort(vector<int> &a, int start, int end, vector<int> temp) {
            if (start >= end) {
                return;
            }

            mergesort(a, start, (start + end) / 2, temp);
            mergesort(a, (start + end) / 2 + 1, end, temp);
            merge(a, start, end, temp);
        }

        void merge(vector<int> &a, int start, int end, vector<int> temp) {
            int middle = (start + end) / 2;
            int left = start;
            int right = middle + 1;
            int index = left;

            while (left <= middle && right <= end) {
                if (a[left] < a[right]) {
                    temp[index] = a[left];
                    index++;
                    left++;
                }
                else {
                    temp[index] = a[right];
                    index++;
                    right++;
                }
            }

            while (left <= middle) {
                temp[index] = a[left];
                index++;
                left++;
            }

            while (right <= end) {
                temp[index] = a[right];
                index++;
                right++;
            }

            for (int i = start; i <= end; ++i){
                a[i] = temp[i];
            }
        }
};

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

