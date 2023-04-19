#include <iostream>
#include "rod_cutting.h"


//basic introduction to the rod cutting problem:
// https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
int main(){
    using std::cout;
    using std::cin;
    using std::endl;
    using std::vector;

    vector<cut_value> cvs;
    cvs.push_back(cut_value(1,1));
    cvs.push_back(cut_value(3,5));
    cvs.push_back(cut_value(7,12));
    cvs.push_back(cut_value(10,18));


    vector<int> cuts = get_cuts(19,cvs);

    cout<<"cuts: ";
    for(int cut : cuts){
        cout<< cut<<" ";
    }
    cout<<endl;

    return 0;
}