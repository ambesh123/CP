#include<bits/stdc++.h>
using namespace std;

//#define fr(n) for(int i=0;i<n;i++)



int main()
{	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	int N,Q;
    vector <string> pr;  string str;
    cin>>N>>Q;
    
    cin.ignore();
    
    for(int i=0;i<N;i++){
        getline(cin,str);
        pr.push_back(str);
    }
    
    for(int i=0;i<Q;i++){
        getline(cin,str);
        string temp,del="----",value="Not Found!";  bool toRun=true;  int j=0,k=0;  // j points command   k points prog
        while(toRun){
        	
            if(j>=str.length() || k>= pr.size())break;
            
        	if(str.at(j)=='.' || str.at(j)=='~'){
        		
			        			//cout<<"temp is now "<<temp<<'\n';
			        	while(pr.at(k).find(temp)==string::npos && k<pr.size()){
			        			
			        			//to extract tag of current line
			        				string tag;	int tmp=1;
									while(pr.at(k).at(tmp)!=' ' && pr.at(k).at(tmp)!='>'){
									tag  = tag + pr.at(k).at(tmp);
									tmp++;
									}
										//cout<<"this line has tag = "<<tag<<'\n';
								//if tag is not required move k to it's end
				        			if(tag!=temp && tag[0]!='/'){
				        				string tempDel = '/'+tag;
				        				while(pr.at(k).find(tempDel)==string::npos && k<pr.size())k++;
				        					//cout<<"k incremented to "<<k<<'\n';
				        				if(k>=pr.size()-1){toRun=false; break;}
									}	
			        			//search for the delimeter
				        			else if(pr.at(k).find(del)!=string::npos){
				        					//cout<<"Delimeter encountered!\n";
				        				toRun=false;
				        				break;
									}
								 k++;
							}
							
							if(toRun && k<pr.size()){
								del = "/"+temp;
									//cout<<"delimeter updated to "<<del<<'\n';
			        			temp="";
			        			if(str.at(j)=='.')k++;
							}
							
			        		else break; 
        		
			}
			
		   if(str.at(j)=='~'){
				temp = ' '+str.substr(j+1)+' ';
					//cout<<"searching for "<<temp<<'\n';
				int point = pr.at(k).find(temp);
				if(point == string::npos){
					toRun=false;
					continue;
				}
				else{
					value = pr.at(k).substr(point + temp.length() +3);
					point = value.find('"');
					value= value.substr(0,point);
				}
			}
			else
            {
            	if(str.at(j)=='.')j++;
				temp+=str.at(j);
			}
			
			j++;
        }
        cout<<value<<'\n';
    }
    
} 
