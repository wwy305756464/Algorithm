#include  "sort.h"
#include <memory>
#include <random>
#include <ctime>

using namespace std;

int main() {
    default_random_engine e(std::time(0));
    uniform_int_distribution<int> u(0,100);
    uniform_int_distribution<int> n(0,20);
    int num = n(e);

    vector<int> test_case;
    cout << "Before sort: ";
    for (size_t i = 0; i < n(e); ++i) {
        int temp = u(e);
        cout << temp << " ";
        test_case.push_back(temp);
    }
    cout << endl;

    shared_ptr<Sortmethod> sort_ptr = make_shared<BubbleSort>();

    sort_ptr -> sort(test_case);
    cout << "Sort test case: ";
    for (auto a : test_case) {
        cout << a << " ";

    }
    cout << endl;
}