#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string isValid(string s){
    //Complete this function
    int * vector = new int[26];
    memset(vector,0, sizeof(int)*26);
    //cout<<s.length()<<endl;
    for(int i = 0; i != s.length(); i++)
    {
    	//cout<< s[i] - 'a' <<endl;
        vector[ s[i] - 'a' ]++;
    }

    for(int j = 0; j != 26; j++)
    {
    	cout<< "Occurence: " << char(j+'a') << vector[j] <<endl;
    	
    }
    cout<<endl;
    int chance = 1;

    for(int j = 1; j != 26; j++)
    { 
    	if( vector[j]!=0  && vector[j]!= -1 && vector[j] != vector[j-1] )
    	{
    		cout << "line 31" << endl;
    		if(chance == 1)
    		{
    			cout << "line 34" << endl;
    			chance = 0;
    			vector[j]=vector[j-1];
    			// j=1;
    		}
    		else
    		{
    			cout<<endl;
    			for(int j = 0; j != 26; j++)
    			{
    				
    				cout<< "Occurence: " << char(j+'a') << vector[j] <<endl;
    			}
    			delete[] vector;
    			return "NO";
    		}
    	}
    }
    
    delete[] vector;
    return "YES";
    
}

int main() {
    string s;
    cin >> s;
    string result = isValid(s);
    cout << result << endl;
    return 0;
}
