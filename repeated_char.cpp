#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

int main()
{
	string data = "012345678900123";
	unordered_map <char,int> st;

	for(int i =0; i!= data.length(); i++)
	{
		unordered_map<char,int>::const_iterator got0 = st.find( data[i] );

		if( got0 == st.end()) // not exist
		{
			st.insert(make_pair(data[i],0)); // inserting
		}
		else // update
		{
			
			if( got0->second == 0 )
			{
				cout << "erase"<<endl;
				st.erase(got0);
				st.insert(make_pair(data[i],1));
			}
			
		}
	}

	for (auto& x: st)
    	std::cout << x.first << ": " << x.second << std::endl;

	for(int i =0; i!= data.length(); i++) 
	{
		unordered_map<char,int>::const_iterator got0 = st.find( data[i] );
		if(got0->second == 0)
		{
			cout<< "Found [" << data[i]<< "] repeat once!\n"<< endl;
			break;
		}
	}
}