#include <fstream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <iostream>
using namespace std;
int main()
{
 int num=0,i=0;
 cout<<"Enter number of files: ";
 cin>>num;
 //cout<<num;
 while(i<num)
	{
	i++;
    char name [100],curr[8],word[100];
	itoa(i,curr,10);
	strcpy(name,"V:\\txt\\a(");
	strcat(name,curr);
	strcat(name,")");
	strcat(name,".txt");
	//cout<<name;
	int count=0;	
	fstream fil; 
	//cout<<i<<"\t";
	fil.open(name,ios::in);
	if(!fil.is_open())
		cout<<endl<<name<<" Error\n";
	else
	{	cout<<i<<"\n";
		while((!fil.eof())&&(count<200))
		 {
			 fil>>word;
			 int a=200,b=20000;
			 //cout<<"\nfirst"<<i<<"\tWord: "<<word;
			 for(int p=0;p<strlen(word);p++)
			 	{
			 		if(!isalpha(word[p]))
			 			{
			 			 for(int n=0;n<strlen(word);n++)
			 			 	word[n]='\0';
						 fil>>word;
			 			 //cout<<"\tNew word: "<<word;
			 			 p=0;
			 			}
			 			
			 	}//cout<<a<<"\t"<<b;
			//cout<<"\nIn: "<<i;
		   if(strcmpi(word,"the")==0)
			 {
			  count++;
			  //cout<<i;
			 }//cout<<"\tOut: "<<i<<"\tFinal word: "<<word;
		//cout<<"Count: "<<count<<"   "<<i<<"\thaha1";	 
		 }
		//cout<<"\thaha2"<<i; 
     fil.close();		 
	 if(count<200)
	 	{
		  fstream fil;
		  fil.open(name,ios::out);
		  fil.close();
		}
	}
	 //cout<<"\thaha3"<<i<<"\t"<<num<<endl;  
	}
 return 0;
}
