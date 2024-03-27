//Liv Young
//HW4 pt2

#include "biggest_divisible_conglomerate.h"
#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Table Based Approach Comments:
//First, we sort the list from smallest to largest.
//Then, we take the largest element of the input(the last element of the input)
//and we put it in the table. Then we use an outer for loop to loop down through the list
//from the element at input.size() - 2 to 0. Each time we check if the current element is a conglomerate
//of any vectors currently in the table. If it is we update the table with a new solution candidate vector, if not
//we add the element to the table as a vector. If the element was 24 and had no conglomerates it would
//add to the table like this: [24].

//Time Complexity Comments:
//The time complexity of the previous approach was O(x^n), where x is the element in the input and n the work 
//done in the recursive step.
//The time complexity of this approach is O(x * n) where x is the length of the input 
//and n is the work done to compute a spot in the table.
//The dynamic approach is better!


//-----------------------------------
string vec_to_string(vector<int> v)
//-----------------------------------
{
    string s = "";
    s.append("[");
    for(size_t i = 0; i < v.size(); i++){
        string tmp = to_string(v[i]);
        s.append(tmp);
        if(i != v.size()-1){
            s.append(", ");
        }
    }
    s.append("]");
    return s;
}

//-------------------------------------------------
bool is_Conglomerate(int a, vector<int> v){
//-------------------------------------------------
    
    for(size_t i = 0; i < v.size(); i++){
        //since I sorted the list v[i] will always be greater than a
        if((v[i] % a != 0)){
            return false;
            break;
        }
    }
    return true;
}

//----------------------------------------------------------
vector<int> biggest_divisible_conglomerate(vector<int> input)
//----------------------------------------------------------
{
    //sorts list from smallest element to largest
    sort(input.begin(), input.end());
    
    if(input.size() <= 1){
        return input;
    }

    //establish table 
    vector<vector<int>> table{};
    vector<int> baseCase;

    //adds largest element to table, last element in input vector
    baseCase.push_back(input.at(input.size()-1));
    table.push_back(baseCase);
        
    for(int i = (int)(input.size() - 2); i >= 0; i--){
        vector<int>valid_conglomerate{};
        size_t len = table.size();
        bool has_conglomerate = false;
        for(size_t j = 0; j < len; j++){
            if(is_Conglomerate(input[i], table.at(j))){
                //creates new solution candidate vector
                has_conglomerate = true;
                valid_conglomerate = table.at(j);
                valid_conglomerate.push_back(input[i]);
                table.push_back(valid_conglomerate);
            }
        }

        if(has_conglomerate == false){
            //if the current number from the input vector does not have any conglomerates in the current table, add itself to the table.
            vector<int> itself;
            itself.push_back(input[i]);
            table.push_back(itself);
        }
    }

    //find the longest answer vector
    unsigned int currSize = 0;
    int currIdx = 0;
    for(size_t i = 0; i < table.size(); i++){
        if(table.at(i).size() > currSize){
            currSize = table.at(i).size();
            currIdx = i;
        }
    }

    return table[currIdx];
}
