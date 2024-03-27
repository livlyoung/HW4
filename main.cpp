#include "biggest_divisible_conglomerate.h"

#include <vector>
#include <cassert>
#include <iostream>
#include <set>


int main() {

	// Test 1 (example from assignment description)
	vector<int> values = {28, 22, 7, 2, 8, 14, 24, 56};
	vector<int> ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	set<int> answerSet(ans.begin(), ans.end());
	set<int> soln = {56, 14, 7, 28};
	bool first = (answerSet == soln);
	soln = {56, 28, 14, 2};
	bool second = (answerSet == soln);
	assert(first || second);

	// Test 2
	values = {10, 5, 3, 15, 20};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {20, 5, 10};
	set<int> answerSet2(ans.begin(), ans.end());
	assert(answerSet2 == soln);

	// Test 3
	values = {10, 2, 40, 32, 20};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {10, 2, 40, 20};
	set<int> answerSet3(ans.begin(), ans.end());
	assert(answerSet3 == soln);

	// Test 4
	values = {11, 7, 13, 19};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	set<int> answerSet4(ans.begin(), ans.end());
	soln = {11};
	bool largest1 = (answerSet4 == soln);
	soln = {19};
	bool smallest1 = (answerSet4 == soln);
	assert(smallest1 || largest1);

	// Test 5
	values = {7};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {7};
	set<int> answerSet5(ans.begin(), ans.end());
	assert(answerSet5 == soln);

	// Test 6
	values = {};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {};
	set<int> answerSet6(ans.begin(), ans.end());
	assert(answerSet6 == soln);

	// Test 7
	values = {3, 91};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	set<int> answerSet7(ans.begin(), ans.end());
	soln = {91};
	bool largest2 = (answerSet7 == soln);
	soln = {3};
	bool smallest2 = (answerSet7 == soln);
	assert(smallest2 || largest2);


	// Test 8 (vector of size 2 input)
	values = {2, 5};
	ans = biggest_divisible_conglomerate(values);
	cout << "Input: " << vec_to_string(values) << endl;
	cout << "Output: " << vec_to_string(ans) << endl << endl;
	set<int> answerSet8(ans.begin(), ans.end());
	soln = {5};
	bool largest3 = (answerSet8 == soln);
	soln = {2};
	bool smallest3 = (answerSet8 == soln);
	assert(smallest3 || largest3);

	// Test 9 (all prime numbers)
	values = {2, 3, 5, 7, 11, 13};
	ans = biggest_divisible_conglomerate(values);
    cout << "Input: " << vec_to_string(values) << endl;
    cout << "Output: " << vec_to_string(ans) << endl << endl;
    set<int> answerSet9(ans.begin(), ans.end());
    soln = {13};
    bool largest4 = (answerSet9 == soln);
    soln = {2};
    bool smallest4 = (answerSet9 == soln);
    assert(smallest4 || largest4);



	return 0;
}
