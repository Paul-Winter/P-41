#include <iostream>
#include <set>
#include <vector>

std::vector<int> unique_elements(const std::vector<int> arr_1, const std::vector<int> arr_2, int size_1, int size_2)
{
	std::set<int> set_1(arr_1.begin(), arr_1.end());
	std::set<int> set_2(arr_2.begin(), arr_2.end());
	std::vector<int> result;
	for (const int& elem : set_1) if (set_2.find(elem) == set_2.end()) result.push_back(elem);
	for (const int& elem : set_2) if (set_1.find(elem) == set_1.end()) result.push_back(elem);
	return result;
}

int main()
{
	std::vector<int> array_1 = { 6,8,6,7,3 };
	std::vector<int> array_2 = { 2,5,8,7,3 };
	std::vector<int> unique = unique_elements(array_1, array_2, (int)array_1.size(), (int)array_2.size());
	for (int elem : unique) std::cout << elem << " ";
	return 0;
}