#include "rod_cutting.h"
#include <algorithm>
#include <iostream>

struct val_choice{
    int val;
    int choice;

    val_choice(int v, int c):val(v),choice(c){ }
};



std::vector<int> get_cuts(int length, std::vector<cut_value> cvs){
    using std::vector;
    //sorting, number of priced cuts likely much smaller than length 
    std::sort(cvs.begin(),cvs.end(),
        [](cut_value& x, cut_value& y){
            return x.cut < y.cut;
        }); 


    vector<val_choice> vcs;
    vcs.push_back(val_choice(0,0));//zero length rod is 0
    
    //index is length in vcs (~ 1-indexed)
    for(int i = 1; i<=length; ++i){
        int val = -1;
        int choice = 0;
        
        for(int j =0;j<cvs.size();++j){
            cut_value cv = cvs[j];
            int smaller_length = i-cv.cut;
            if(smaller_length < 0) { // no negative length rods
                break;
            }
            int curr_value=vcs[smaller_length].val+cv.value;
            if (curr_value > val){
                val = curr_value;
                choice = cv.cut;
            }
        }
        vcs.push_back(val_choice(val,choice));
    }
    vector<int>cuts;
    
    int sub_solution = length;
    while(sub_solution>0){
        val_choice vc = vcs[sub_solution];
        cuts.push_back(vc.choice);
        sub_solution -= vc.choice;
    }

    return cuts;
}