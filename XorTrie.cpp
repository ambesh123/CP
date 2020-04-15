struct trie{
    struct node{
        int count;
        node *child[2];
        node(){
            count = 0;
            child[0] = child[1] = NULL;
        }
    };

    node *root;
    int BIT = 20;

    trie(){
        root = new node();
        root->count = 1;
    }

    void insert(int x){//cout<<"Inserting "<<x<<endl;
        root->count++;
        node *crawl = root;
        for(int i = BIT; i >= 0; --i){
            int b = (x&(1<<i)) > 0;
            if(crawl->child[b] == NULL){
                crawl->child[b] = new node();
            }
            crawl = crawl->child[b];
            crawl->count++;
        }
    }

    void deleteCompletely(node *root){
        if(root == NULL)return;
        deleteCompletely(root->child[0]);
        deleteCompletely(root->child[1]);
        delete(root);
    }

    void deleteNumber(int x){//cout<<"Deleting "<<x<<endl;
        root->count--;
        node *crawl = root;
        for(int i = BIT; i >= 0; --i){
            int b = (x&(1<<i)) > 0;
            if(crawl->child[b] == NULL){
                //error no. does not exist
                cout<<"No. does not exist\n";
                return;
            }
            crawl = crawl->child[b];
            crawl->count--;
        }

        crawl = root;
        for(int i = BIT; i >= 0; --i){
            int b = (x&(1<<i)) > 0;
            if(crawl->child[b]->count == 0){
                deleteCompletely(crawl->child[b]);
                crawl->child[b] = NULL;
                break;
            }
            crawl = crawl->child[b];
        }
    }

    int findMaxXor(int x){
        node *crawl = root;
        int ans = 0;
        for(int i = BIT; i >= 0; --i){
            int b = (x&(1<<i)) == 0;
            if(crawl->child[b] == NULL){
                crawl = crawl->child[1-b];
            }
            else{
                ans |= (1<<i);
                crawl = crawl->child[b];
            }
        }
        return ans;
    }

    void printAll(node *p, int x, int lvl){
    	if(p==NULL)return;

    	if(lvl == -1){
    		cout<<x<<' ';
    		return;
    	}
        
    	printAll(p->child[0], x, lvl-1);
    	printAll(p->child[1], x|(1<<lvl), lvl-1);
    }

    void printNumbers(){
    	cout<<"Numbers in Trie: ";
    	printAll(root, 0, BIT);
    	cout<<endl;
    }
};
