#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<fstream>
#include<algorithm>



using namespace std;


void loadBucket(map<long , vector<string>>&bucket , long &count , long &top ,vector<long> &sortvect , string filename); 
void process (long top , map<long , vector<string>>&bucket ,vector<long> &sortvect);

bool sortDsc (long i,long j) { return (i>j); }



int main(int argc,char *argv[])
{
	map<long , vector<string>> bucket = map<long,vector<string>>();
	vector<long> sortvect = vector<long>();
	long rec_count , topfind;
    loadBucket(bucket ,rec_count , topfind ,sortvect ,"data.txt");
	process (topfind , bucket ,sortvect);


	cout << "-----------------------------------------" << endl;

	bucket = map<long,vector<string>>();
	sortvect = vector<long>();
	rec_count = 0; 
	topfind = 0;
	 loadBucket(bucket ,rec_count , topfind ,sortvect ,"sample1.txt");
	process (topfind , bucket ,sortvect);



	system("PAUSE");
	return 0;
}


void loadBucket(map<long , vector<string>>&bucket , long &count , long &top , vector<long> &sortvect ,string filename)
{
	ifstream inputFile(filename);
	string tmp ="";
	long entry = 1;

	
	
	while(inputFile)
	 {
        inputFile >> tmp;
	   if (entry == 1)
	   {
		  
		 count = atol(tmp.c_str());
	   }
	    if (entry == 2)
	   {
	    top = atol(tmp.c_str());
	   }
	   
	  if ( entry > 2)
	  {
		  if(entry % 2 == 0)
		  {
			  long key = sortvect[sortvect.size()-1];

			  if( bucket.find(key) == bucket.end())
			 {  
				 bucket[key].push_back(tmp);
			 
			 }
			 else
			 {
				 vector<string> temp = vector<string>();
				 temp.push_back(tmp);
				 bucket[key] = temp ;
				
			 
			 }
		  
			  
		  }
		  else
		  {
			  bool keyadded = false;

			  for (int u = 0; u < sortvect.size(); u++)
			  {
				  if(sortvect[u] == atol(tmp.c_str()))
				  {
					  keyadded = true;
					  break;
				   }

			  }

			  if(!keyadded )
			  {
			  sortvect.push_back(atol(tmp.c_str()));
			  }

		  }
		  

	  }
		
	  
	   
	   
	   entry++;
	
	 }

 
	

	inputFile.close();

	sort(sortvect.begin() , sortvect.end(),sortDsc);

	vector<long>::iterator transverse;
	 for ( transverse=sortvect.begin();  transverse!=sortvect.end(); ++transverse)
     cout << " " << *transverse;

	 sortvect.shrink_to_fit();
	 cout << endl;
	cout << count << endl;
	cout << top << endl;

	 cout << endl;
	 cout << endl;
	 cout << endl;
	
}


void process (long top , map<long , vector<string>>&bucket ,vector<long> &sortvect)
{
	while(top > 0)
	{
		for( long x = 0 ; x < sortvect.size(); x++)
		{
			long index = sortvect[x];

			cout << "index: " << index <<endl;

		//long size = bucket[index].size();

		//for( long j = 0; j < size; j++)
			//{
				
				cout << bucket[index][0] << endl;
				top--;
				if (top == 0)
				{
					break;
				}
			//}

			//if ( top == 0 )
			//{
				//break;
			//}
		}


	}


}