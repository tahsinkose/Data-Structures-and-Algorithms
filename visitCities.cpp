#include <iostream>
#include "StackL.h"
#include <cstdlib>

/* Imitating Recursion through Stacks. 
   It is known that Iterative Algorithms are much faster than their Recursion equivalents. Because each new function call
   introduces a bunch of new state variables to execution stack. Even native recursion implementations can be converted into 
   iterative equivalents through Stacks. This program is a small example of it.
*/

using namespace std;

enum city {P=0,Q,R,S,T,W,X,Y,Z};

int main()
{

	Stack<city> myStack(100);

	int m[9][9]={1,0,1,0,0,1,0,0,0,
			   0,1,0,0,0,0,1,0,0,
			   0,0,1,0,0,0,1,0,0,
                           0,0,0,1,1,0,0,0,0,
                           0,0,0,0,1,1,0,0,0,
			   0,0,0,1,0,1,0,1,0,
			   0,0,0,0,0,0,1,0,0,
			   0,0,1,0,0,0,0,1,1, 	
			   0,0,0,0,0,0,0,0,1};

	int visited[9]={0,0,0,0,0,0,0,0,0};
       // Starting city is T:
       myStack.push(T);
       visited[T]=1;
	// Trying to reach Z.
       while ((!myStack.isEmpty()) && (myStack.getTop()!=Z))
       {
       	       city tmp=myStack.getTop(); //myStack.showContent();	 	 
	       bool backtrackflag=true; 	
               for (int c=0; c<=8; c++)
	          if ((m[tmp][c]== 1) && (visited[c]==0)) {
			myStack.push((city)c);
                        visited[c]=1;
			backtrackflag=false;}
	       if (backtrackflag) myStack.pop();
	}
		   
	if (myStack.isEmpty()) cout<<"No path exists"<<endl;
	else cout<<"Path Exists"<<endl;
        
        //myStack.showContent();	

	return 0;

}
	
