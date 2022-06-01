#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include<iomanip>
#include<sstream>

using namespace std;

//MAX-HEAP Organization ----------------------------------------------------------
void heapInsert(vector<int>& h, int newValue) 
{
	h.push_back(newValue);					//add new node at the end of the vector
	int childIndex = h.size() - 1;			//index of the new node
	int parentIndex = (childIndex - 1) / 2;	//parent's index

	while (childIndex >= 0 && h[childIndex] > h[parentIndex]) 
	{
		int temp    = h[parentIndex];		//exchange parent and (bigger) child
		h[parentIndex]   = h[childIndex];
		h[childIndex] = temp;

		childIndex    = parentIndex;		//continue moving up the tree
		parentIndex      = (childIndex - 1) / 2;
	}
	cout << "\nInserting " << newValue << ">>  ";
	for (auto v : h) cout << v << ",";
	cout << endl;
}

int heapDelete(vector<int>& h) 
{
	//root holds the largest value in the tree
	int root = h[0];		
	cout << "Deleting: " << root << endl;

	//replace the root with the last heap element
	int parentIndex = 0;
	h[parentIndex] = h[h.size() - 1];

	//remove last element
	h.erase(h.end() - 1 );

	//n is the new heap's size
	int n = h.size();
	if (n == 0) return root;

	//indices to root's children nodes	
	int left  = 2 * parentIndex + 1;
	int right = 2 * parentIndex + 2;

	//childIndex will point to the larger descendant
	int childIndex = left; //arbitrary initialization
	if (left < n && right < n) {
		childIndex = (h[left] >= h[right] ? left : right);
	}

	while (childIndex < h.size() && h[parentIndex] < h[childIndex]) 
	{
		//exchange parentIndex and childIndex
		int temp = h[parentIndex];
		h[parentIndex] = h[childIndex];
		h[childIndex] = temp;

		//continue checking down the tree after exchange
		parentIndex = childIndex;
		left  = 2 * parentIndex + 1;
		right = 2 * parentIndex + 2;
		if(left<n && right<n)
			childIndex = (h[left] >= h[right] ? left : right);
		
	}
	
	for (auto v : h) cout << v << ",";
	cout << endl;



	return root;
}

int main()
{   // Populate the heap with  3, 5, 1, 19, 11, and 22.
	vector<int> h;
	heapInsert(h, 3);
	heapInsert(h, 5);
	heapInsert(h, 1);
	heapInsert(h, 19);
	heapInsert(h, 11);
	heapInsert(h, 22);
	cout << endl;

	int val;
	vector<int> vsorted;
	while (h.size() > 0) 
	{
		vsorted.insert(vsorted.begin(), heapDelete(h));
	}
	cout << endl;

	for (auto v : vsorted) cout << v << ", ";
	cout << endl;
}


