#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<fstream>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

const string NUM[]={"0","1","2","3","4","5","6","7","8","9","10"};

int main()
{
	ofstream os("Result");
	for(int i=1;i<=10;++i)
	{
		system(("./a.cpp.out < data"+NUM[i]+".in > output").c_str());
		if(system(("diff output data"+NUM[i]+".out").c_str()))
			os<<i<<endl;
	}
	return 0;
}
