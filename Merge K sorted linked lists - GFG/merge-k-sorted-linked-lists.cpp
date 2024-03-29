//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* merge(Node *first,Node *second)
    {
        if(!first)
            return second;
        if(!second)
            return first;
        Node *dummy=new Node(-1);
        Node *ptr=dummy;
        while(first && second)
        {
            if(first->data<=second->data)
            {
                ptr->next=first;
                ptr=ptr->next;
                first=first->next;
            }
            else
            {
                ptr->next=second;
                ptr=ptr->next;
                second=second->next;
            }
        }
        while(first)
        {
            ptr->next=first;
            ptr=ptr->next;
            first=first->next;  
        }
        while(second)
        {
            ptr->next=second;
            ptr=ptr->next;
            second=second->next;            
        }
        return dummy->next;
    }
    Node * mergeKLists(Node *arr[], int K)
    {
       for(int i=1;i<K;++i)
       {
           arr[i]=merge(arr[i-1],arr[i]);
       }
       return arr[K-1];
        
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends