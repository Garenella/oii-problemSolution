#include <bits/stdc++.h>

#define MAXN 200100

using namespace std;

int N, Q;
int tree[MAXN], lazy[MAXN];

void update_tree_lazy(int tree[], int lazy[], int nodo, int inizio_seg, int fine_seg, int inizio_query, int fine_query)
{
	if(lazy[nodo] != 0)
	{
		tree[nodo] = (fine_seg - inizio_seg + 1) - tree[nodo];
		
		if(inizio_seg != fine_seg)
		{
				lazy[nodo*2+1] ^= 1;
				lazy[nodo*2+2] ^= 1;
		}
		
		lazy[nodo] = 0;
	}
	
	if(fine_seg < inizio_query || inizio_seg > fine_query)
		return;
	
	if(inizio_seg >= inizio_query && fine_seg <= fine_query)
	{
		tree[nodo] = (fine_seg - inizio_seg + 1) - tree[nodo];
		
		if(inizio_seg != fine_seg)
		{
				lazy[nodo*2+1] ^= 1;
				lazy[nodo*2+2] ^= 1;
		}
		
		return;
	}
	
	int mid = (inizio_seg + fine_seg)/2;
	
	update_tree_lazy(tree, lazy, nodo*2+1, inizio_seg, mid, inizio_query, fine_query);
	update_tree_lazy(tree, lazy, nodo*2+2, mid+1, fine_seg, inizio_query, fine_query);
	
	tree[nodo] = tree[nodo*2+1] + tree[nodo*2+2];
	return;
}

int sum_tree_lazy(int tree[], int lazy[], int nodo, int inizio_seg, int fine_seg, int inizio_query, int fine_query)
{
	if(lazy[nodo] != 0)
	{
		tree[nodo] = (fine_seg - inizio_seg + 1) - tree[nodo];
		
		if(inizio_seg != fine_seg) //not leaf node
		{
				lazy[nodo*2+1] ^= 1; //switch value 0-1
				lazy[nodo*2+2] ^= 1;
		}
		
		lazy[nodo] = 0;
	}
	
	if(inizio_seg > fine_query || fine_seg < inizio_query)
		return 0;
	
	if(inizio_seg >= inizio_query && fine_seg <= fine_query)	
		return tree[nodo];
	
	int mid = (inizio_seg + fine_seg)/2;
	
	return sum_tree_lazy(tree, lazy, nodo*2+1, inizio_seg, mid, inizio_query, fine_query) +
	sum_tree_lazy(tree, lazy, nodo*2+2, mid+1, fine_seg, inizio_query, fine_query);
}

int potenza_vicina(int N)
{
	int i;
	for(i = 1; i < N; i += i)
		;
	return i;
}

//4 7
//1 0 3
//0 1 2
//1 0 1
//1 0 0
//0 0 3
//1 0 3
//1 3 3

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	cin >> N >> Q;
	
	int n = potenza_vicina(N);
	
	for(int i = 0; i < Q; i++)
	{
		int tipo, da, a;
		cin >> tipo >> da >> a;
		
		if(tipo == 0)
			update_tree_lazy(tree, lazy, 0, 0, n-1, da, a);
		else
			cout << sum_tree_lazy(tree, lazy, 0, 0, n-1, da, a) << endl;
	}
}
