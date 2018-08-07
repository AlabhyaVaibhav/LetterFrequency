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
 cout<<num;
 
 fstream filt;
 filt.open("result.txt",ios::out);
	
 if(!filt.is_open())
	cout<<"Error opening file result\n";
 else
 {
  while(i<num)
	{
	i++;

	char name [100],curr[8],ch;
	double a[27]={0};
	itoa(i,curr,10);
	strcpy(name,"V:\\txt\\a(");
	strcat(name,curr);
	strcat(name,")");
	strcat(name,".txt");
	cout<<name;
		
	fstream fil; 
	fil.open(name,ios::in);
	if(!fil.is_open())
		cout<<endl<<name<<" Error\n";
	else
	{
		while(!fil.eof())
		 { 
			fil>>ch;
		   if(isalpha(ch))
			 {
			  ch=tolower(ch);
			  a[ch-97]++;
			  a[26]++;
			 }
		 }
	 cout<<endl;
	 for(int j=0;j<26;j++)
		{
		 a[j]=(a[j]/a[26])*100;
		 cout<<char(j+97)<<": "<<a[j]<<"\t";
		}
	 cout<<"Total: "<<a[26];
	 for(int k=0;k<26;k++)
		filt<<a[k]<<"\t";
	 filt<<endl;
	  fil.close();
	 }
	}
  }

 filt.close();
 return 0;
}
