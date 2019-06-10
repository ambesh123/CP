#include <bits/stdc++.h>
#define inp_out_work ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define testCase    int T; cin>>T; while(T--)
#define fr(i,n) for(int i=0;i<n;i++)
#define rfr(i,n) for(int i=n-1;i>=0;i--)
#define fro(s,e) for(int i=s;i<=e;i++)
#define pb push_back
#define ll long long
#define debug(P) cout<<#P<<' '<<P<<endl
#define mod 1000000007
#define MAXN 1001

using namespace std;

const int alph_size = 26;

struct trie {
    struct trie *child[alph_size];
    bool endword;
    trie(){
        endword = false;
        fr(i,alph_size)child[i]=NULL;
    }
};

void insert(trie *root,string key){
    trie *crawl = root;
    fr(i,key.length()){
        int index = key[i]-'a';
        if(crawl->child[index]==NULL)crawl->child[index]= new trie;
        crawl = crawl->child[index];
    }
    crawl->endword = true;
}

string longestPrefixMatch(trie *root,string word){
    trie *crawl=root,*temp; int l=0;
    string res="";
    while(crawl!=NULL && l<word.length()){
        temp = crawl;
        int index = word[l]-'a';
        res.pb(word[l]);
        crawl = crawl->child[index];
        l++;
    }
    if(crawl==NULL){res.erase(--res.end()); crawl = temp;}

    while(!(crawl->endword)){
        fr(i,alph_size)if(crawl->child[i]){res.pb((char)('a'+i)); crawl = crawl->child[i];}
    }
    return res;
}

int main(){
    //inp_out_work
    int n;
    cin>>n;
    string s[n];
    trie *root = new trie();
    fr(i,n){
        cin>>s[i];
    }
    fr(i,n)insert(root,s[i]);
    testCase{
        string word;
        cin>>word;
        cout<<longestPrefixMatch(root,word)<<endl;
    }
}
