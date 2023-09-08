#include <iostream>
#include<vector>
#include<queue>
using namespace std;


bool canVisitAllRooms(vector<vector<int>>&rooms)
{
	queue<int>q;
	vector<bool>vis(rooms.size(),false);
	q.push(0);
	while(!q.empty())
	{
		int start=q.front();
		q.pop();
		if(vis[start]==true)
		continue;
		
		vis[start]=true;
		
		for(auto it:rooms[start])
		{
			q.push(it);
		}
	}
	
	for(int i=0;i<vis.size();i++)
	{
		if(vis[i]==false)
		  return false;
	}
	return true;
}

int main(int argc, char** argv) {
	vector<vector<int>>rooms={
	{1,3},
	{3,0,1},  //o(v+e) bfs
	{2},
	{0}
	};
	if(canVisitAllRooms(rooms))
	{
		cout<<"can visited";
	}
	else
	{
		cout<<"not visited";
	}
}
