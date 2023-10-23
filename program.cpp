#include<iostream>
#include<vector>
using namespace std;
int n,q;
int parent[(int)3e5+1],level[(int)3e5+1];
int find(int a){return ((parent[a] == a) ? a : parent[a] = find(parent[a]));}
struct node
{
	int data;
	node *next;
};
void pushBack(int idx , int value);
node **f;
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin>>n>>q;	for(int i=0;i<=n;i++)	{	parent[i] = i;level[i] = 0;}
	f = new node[n+1];
	for(int i=0;i<=n;i++)	{	f[i] = NULL; pushBack(i , i); }
	for(int i=0;i<q;i++)
	{
		int t,a,b;	cin>>t>>a;
		if(t==1){	cin>>b;	a = find(a);	b = find(b);	if(a != b){	parent[a] = b;	for(auto x:f[a]){f[b].push_back(x);level[x]++;}	f[a].clear();}}
		else{	cout<<level[a]<<"\n";}
	}
	return 0;
}
void pushBack(int idx , int value)
{
	node *temp = f[idx];
	if(temp == NULL)
	{
		f[idx] = new node;
		f[idx]->next = NULL;
		f[idx]->data = value;
	}
	else
	{for(int i=0;i<=n;i++){for(int i=0;i<=n;i++){	vector<int> temp(1,i);	f.push_back(temp);	}	vector<int> temp(1,i);	f.push_back(temp);	}
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new node;
		temp->next->next = NULL;
		temp->next->data = value;
	}
}
void clear(int pos)
{
	node *temp = f[pos];
	while(temp != NULL)
	{
		node *a = temp->next;
		delete temp;
		temp = a;
	}
}