#include <iostream>
#include <vector>

using namespace std;

//typedef struct network* parent;

struct network
{
	int data;
	int parent=-1;
};

bool CheckNodeInNetwork(vector<network>& a, int data1, int data2);
void ConnectNodeToNetwork(vector<network>& a,int data1, int data2);
int GetRoot(vector<network>& a,int data1);
void OutputResult(vector<bool> a);






bool CheckNodeInNetwork(vector<network>& a,int data1, int data2) {
	if (GetRoot(a, data1-1) == GetRoot(a, data2-1)) { return true; }
	else { return false; }
}

void ConnectNodeToNetwork(vector<network>& a,int data1, int data2) {
	a[data1 - 1].data = data1;
	a[data2 - 1].data = data2;
	int root1 = GetRoot(a,data1-1);
	int root2 = GetRoot(a,data2-1);
	//if (root1 != root2) {
	//	/*a[root2].parent = root1;*/
	//}
	if (root1 != root2) {
		if (a[root1].parent == -1 && a[root2].parent == -1) {
			a[root2].parent = root1;
			a[root1].parent--;
		}
		else {
			a[root1].parent < a[root2].parent ?
				a[root2].parent = root1 : a[root1].parent = root2;
		}
	}
}

void OutputNumberOfnetwork(vector<network>& node) {
	int number_network=0;
	for (auto i = node.begin(); i != node.end(); ++i) {
		if ((*i).parent < 0) {
			number_network++;
		}
	}
	if (number_network != 1) {
		cout << "There are " << number_network << " components.";
	}
	else {
		cout << "The network is connected.";
	}
}

int GetRoot(vector<network>&a,int number) {
	//number是数组的编号，不是computer的编号
	if ( a[number].parent < 0) {
		return number;
	}
	else {
		GetRoot(a, a[number].parent);
	}
}

void OutputResult(vector<bool> a) {
	for (auto i = a.begin(); i != a.end(); ++i) {
		if(*i){ cout << "yes" << endl; }
		else{ cout << "no" << endl; }
	}
}

int main() {
	int n;
	cin >> n;
	vector<network> node(n);
	vector<bool> result;
	char operate='0';
	int data1, data2;
	while(cin >> operate)
	{	
		if (operate == 'S') { break; }
		cin >> data1 >> data2;
		if (operate == 'C') 
		{
			if (CheckNodeInNetwork(node, data1, data2)) { 
				result.push_back(true);
				/*cout << "yes" << endl;*/ 
			}
			else { 
				result.push_back(false);
				/*cout << "no" << endl;*/ 
			}
		}
		if (operate == 'I') 
		{
			ConnectNodeToNetwork(node,data1, data2);
		}
	}
	OutputResult(result);
	OutputNumberOfnetwork(node);
	system("pause");
}