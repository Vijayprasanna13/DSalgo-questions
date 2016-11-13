#include <iostream>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char string[1000];
    cin.getline(string,sizeof(string));
    cout<<string;
    int target = 0;
    char hitArray[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
    for(int i = 0;hitArray[i];i++){
        target = 0;
        //cout<<hitArray[i];
        for(int j = 0;string[j];j++)
            if(hitArray[i] == tolower(string[j]))
		        {
		         target++;
		         cout<<hitArray[i]<<" is found "<<string[j]<<"\n";
		         break;
		        }
        if(!target)
            break;            
    }
    if(!target)
        cout<<"not panagram";
    else
        cout<<"panagram";
    return 0;
}

