#include<iostream>
#include<vector>

using namespace std;

template <class T>
class vect_queue
{
    vector<T> vect;
    size_t size_;

public:
    int que_front_, que_back_;

    vect_queue()
    {
        size_ = 0;
        que_front_ = -1;
        que_back_ = -1;
    }

    vect_queue(T val)
    {
        vect.push_back(val);
        size_ = 1;
        que_front_ = 0;
        que_back_ = 0;
    }

    T front()
    {
        return vect.at(que_front_);
    }

    void dequeue()
    {
        vect.erase(vect.begin());
        size_--;
        que_back_--;
        if (size_ == 0)
            que_front_ = -1;
    }

    void enque(T val)
    {
        vect.push_back(val);
        size_++;
        que_back_++;
        if (que_front_ == -1)
            que_front_ = 0;
    }

    void print_vect()
    {
        int i;
        for (i = 0; i < size_; i++)
            cout << vect.at(i) << ", ";
        cout << endl;
    }
};

int main()
{
    vect_queue<int> v;

    cout << "\nAdding to empty queue\n";
    v.enque(1);
    v.print_vect();
    cout << "Front index: " << v.que_front_ << endl;
    cout << "Back index : " << v.que_back_ << endl;

    cout << "\nAdding to non-empty queue\n";
    v.enque(2);
    v.print_vect();
    cout << "Front index: " << v.que_front_ << endl;
    cout << "Back index : " << v.que_back_ << endl;

    cout << "\nRemoving from queue with > 1 elements\n";
    v.dequeue();
    v.print_vect();
    cout << "Front index: " << v.que_front_ << endl;
    cout << "Back index : " << v.que_back_ << endl;

    cout << "\nRemoving from queue with 1 element\n";
    v.dequeue();
    v.print_vect();
    cout << "Front index: " << v.que_front_ << endl;
    cout << "Back index : " << v.que_back_ << endl;
}
