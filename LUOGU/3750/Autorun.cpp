#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

int main()
{
	for(int i=1;i<=20;++i)
	{
		system(("./a.cpp.out < "+to_string(i)+".in > output").data());
		if(system(("diff output "+to_string(i)+".out").data()))
			cout<<i<<"!!"<<endl;
	}
	return 0;
}
