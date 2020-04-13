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

    void insert(int x){
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

    bool deleteHelper(node *crawl, int x, int curr_bit){
    	if(curr_bit < 0)return false;
        int b = (x&(1<<curr_bit)) > 0;
        if(crawl->child[b] == NULL){
            //error x is not present in trie
            return false;
        }
        crawl->count--;
        bool deleted = deleteHelper(crawl->child[b], x, curr_bit-1);

        if(deleted)crawl->child[b] = NULL;

        deleted = false;

        if(crawl->count == 0){
            delete(crawl);
            deleted = true;
        }
        return deleted;
    }
    void deleteNumber(int x){
        deleteHelper(root, x, BIT);
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
