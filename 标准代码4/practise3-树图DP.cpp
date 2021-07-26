//  practise3.cpp
//  Created by 朱自通 on 2021/5/20.

//图的遍历
1）DFS（邻接矩阵和邻接表版）
//邻接矩阵
int n,adj[MAX][MAX];
bool vis[MAX]={false};

for(int i=0;i<n;i++){
    if(vis[v]==false){
        DFS(v);
    }
}

void DFS(int s){
//    if(vis[v]==false){//这里不知道怎么设置边界条件？？不用设置最先的判断条件
        vis[v]==true;
        for(int i=0;i<n;i++){
            if(adj[v][i]!=INF&&vis[i]==false){
                DFS(i);
            }
        }
//    }
}

//邻接表
vector<int> adj[MAX];
bool vis[MAX]={false};
int n;

for(int i=0;i<n;i++){
    if(vis[i]==false){
        DFS(i);
    }
}

void DFS(int v){
//    if(vis[v]==false){
        vis[v]=true;
        for(int i=0;i<adj[v].size();i++){
            int u=adj[v][i];
            if(vis[u]==false){
                DFS(u);
            }
        }
//    }
}

2）BFS（邻接矩阵和邻接表版）
//邻接矩阵
int n,adj[MAX][MAX];
bool vis[MAX]={false};

for(int i=0;i<n;i++){
    if(vis[i]==false){
        BFS(i);
    }
}

void BFS(int s){
    queue<int> q;
    q.push(s);
    vis[s]=true;//入队就是已访问吗？？
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(adj[temp][i]!=INF&&vis[i]==false){
                q.push(i);
                vis[i]=true;
            }
        }
    }
}

//邻接表法
vector<int>adj[MAX];
int n;
bool vis[MAX]={false};

for(int i=0;i<n;i++){
    if(vis[i]==false){
        BFS(i);
    }
}

void BFS(int s){
    queue<int> q;
    q.push(s);
    vis[s]=true;
    while(!empty()){
        int temp=q.front();
        q.pop();
        for(int i=0;i<adj[temp].size();i++){
            int v=adj[temp][i];
            if(vis[v]==false){
                q.push(v);
                vis[v]=true;
            }
        }
    }
}

3）BFS（存储结点层号）//就相当于在原始的遍历上的（设置vis[v]=true,增加了额外的操作）
struct Node{
    int order,layer;
};

vector<Node> adj[MAX];
bool vis[MAX]={false};
int n;

for(int i=0;i<n;i++){
    if(vis[i]==false){
        BFS(i);
    }
}

void BFS(int s){//这里是需要定义int ,不是Node
    queue<Node> q;
    Node start;
    start.layer=0;//因为上面是定义了int ，因此这里定义一个Node，初始值为s;
    start.order=st;//这里好像是不需要设置序号初始化的
    q.push(start);
    vis[s]=true;
    while(!empty()){
        Node temp=q.front();//直接开一个外面的数组记录那个节点的深度不好么？？？？好啊！
        q.pop();
        int temporder=temp.order;
        int templayer=temp.layer;
        for(int i=0;i<adj[temporder].size();i++){
            int nextorder=adj[temporder][i].order;
            int nextlayer=adj[temporder][i].layer;
            nextlayer+=templayer;
            if(vis[nextorder]==false){
                //这个layer的更新，不受是否访问的影响因此要放在上面。
                q.push(adj[temporder][i]);
                vis[nextorder]=true;
            }
        }
    }
}

//最短路径
1）Dijkstra（邻接矩阵、邻接表）（只求出最短路径长度，求出最短路径路线，增加点权、边权、最短路径条数第二标尺）
struct Node{
    int order,distance;//邻接表要计算距离的话，存储的是结点，里面存储有序号和距离
};
vector<Node> adj[MAX];
bool vis[MAX]={false};//先写出遍历的，啥都不干的定义，再增加标尺
int n,d[MAX],wight[MAX],w[MAX],cost[MAX][MAX],c[MAX],num[MAX];
vetor<int> pre;

void dijkstra(int s){
    fill(d,d+MAX,INF);
    d[s]=0;
    memset(num,0,sizeof(num));//对于每一个结点都是要先进行初始化的吗？每一个标尺有两个量，只用初始化一个量就行
    memset(w,0,sizeof(w));
    memset(c,0,sizeof(c));
    
    for(int i=0;i<n;i++){
        pre[i]=i;
    }
    
    for(int i=0;i<n;i++){
        int u=-1;min=INF;
        for(int j=0;j<n;j++){
            if(vis[j]==false&&d[j]<min){
                u=j;
                min=d[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;
        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i].order;
            int dis=adj[u][i].distance;
            if(d[u]+dis<d[v]&&vis[v]==false){//一样的，只是这里的false，可以先套在两个的外面
                pre[v]=u;//这里是pre不是pre[MAX]，并且只有在d[]更新的时候才会进行pre的更新
                d[v]=d[u]+dis;
                c[v]=c[u]+cost[u][v];
                w[v]=w[u]+weight[v];
                num[v]=num[u];
            }
            else if(d[u]+dis==d[v]&&vis[v]==false){//这里还需要说明vis[false]吗？需要，也可以套在一起
                if(c[v]>c[u]+cost[u][v]){
                    c[v]=c[u]+cost[u][v];
                }
                if(w[v]<w[u]+weight[v]){
                    w[v]=w[u]+weight[v];
                }
                num[v]+=num[u];
            }
            //这里不能有vis[v]=true，因为这里实际上是更新距离，并没有访问结点，访问结点是在上面。
        }
    }
}

2）打印出最短路径
void print(int v){
    if(v==s){
        printf("%d",v);
        return;
    }
    print(pre[v]);//不知道对不对
    printf("%d",v);
}

3）Dijkstra+DFS（解决第二标尺问题）（求出所有可能路径的路线，遍历每条可能路径，更新最优值）
struct Node{
    int order,dis;
};
vector<Node> adj[MAX];
bool vis[MAX]={false};
int n,d[MAX];
vector<int> pre[MAX];

int cost[MAX][MAX],weight[MAX];
int c[MAX],w[MAX];

vector<int> Final,temp;
int c=INF,w=0;//维护的全局量


void dijkstra(int s){
    fill(d,d+MAX,INF);
    d[s]=0;
    
//    for(int i=0;i<n;i++){//反正后面都要清空，所以一开始是不用进行初始化的
//        pre[i].clear();
//    }
    
    for(int i=0;i<n;i++){
        int u=-1,min=INF;
        for(int j=0;j<n;j++){
            if(vis[j]==false&&d[j]<min){
                u=j;
                min=d[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;
        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i].order;
            int dis=adj[u][i].dis;
            if(d[u]+dis<d[v]&&vis[v]==false){
                d[v]=d[u]+dis;
                pre[v].clear();
                pre[v].push_back(u);
            }
            else if(d[u]+dis==d[v]&&vis[v]==false){
                pre[v].push_back(u);
            }
        }
    }
}

void DFS(int s){//不知道对不对啊
    if(s==st){
        temp.push_back(s);
        for(int temp.size()-1;i>=1;i--){
            int orh2=temp[i];
            int orh1=temp[i-1];
            tempc+=cost[orh1][orh2];//这样计算的方式对吗？
            tempw+=weight[orh2];
        }
        if(tempc<c) {
            c=tempc;
            Final=temp;
        }
        if(tempw>w){
            w=tempw;
            Final=temp;
        }
        temp.pop_back(s);
        return;
    }
    temp.push_back(s);//这样对吗？？
//  DFS(pre[s]);//因为有很多结点所以是有个循环的
    for(int i=0;i<pre[s].size();i++){
        DFS(pre[s][i]);
    }
    temp.pop_back(s);//这里是pop_back（）
}

4）打印出最优路径
for(int i=1;i<Final.size();i++){//不是很懂这里是啥意思？？
    printf("%d",Final[i]);
}

5）BF算法（判断是否有负环）
struct Node{
    int order,distance;
};

vector<Node> adj[MAX];//BF算法没有考虑每个顶点是否被访问，没有设置vis数组
int n,d[MAX];

bool BF(int s){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<adj[j].size();k++){
                int v=adj[j][k].oreder;
                int dis=adj[j][k].dis;
                if(d[v]>d[u]+dis){
                    d[v]=d[u]+dis;
                }
            }
        }
    }
    
    for(int j=0;j<n;j++){
        for(int k=0;k<adj[j].size();k++){//这里对吗？？
            int v=adj[j][k].oreder;
            int dis=adj[j][k].dis;
            if(d[v]>d[u]+dis){
                return false;
            }
        }
    }
    return true;
}


6）BF算法（输出最短路径条数，最短路径中最大点权）
struct Node{
    int order,distance;
};
vector<Node> adj[MAX];
int n,d[MAX];
int weight[MAX],w[MAX],num[MAX];
set<int> pre[MAX];//BF算法使用set集合

void BF(int s){
    fill(d,d+MAX,INF);
    d[s]=0;
    memset(w,0,sizeof(w));
    memset(num,0,sizeof(num));
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<adj[j].size();k++){
                int v=adj[j][k].order;
                int dis=adj[j][k].distance;
                if(d[v]>d[u]+dis){//BF算法和Dijkstra有啥不一样？？BF算法是对于每条边，可重复访问。
                    d[v]=d[u]+dis;
                    num[v]=num[u];
                    w[v]=w[u]+wight[v];
                    pre[v].clear();
                    pre[v].insert(u);
                }
                else if(d[v]==d[u]+dis){
                    if(w[v]<w[u]+weight[v]) w[v]=w[u]+wight[v];
                    pre[v].insert(u);
                    num[v]=0;//这里更新路径有点奇怪，需要从头统计，因为每次不一定是最优的。
                    set::iterator it;
                    for(it=pre[v].begin();it!=pre[v].end();it++){
                        num[v]+=num[*it];
                    }
                }
            }
        }
    }
}

7）SPFA算法（判断是否有负环）
vector<Node> adj[MAX];
int n,d[MAX];
bool vis[MAX]={false};
int num[MAX];

void SPFA(int s){
    fill(d,d+MAx,INF);
    d[s]=0;
    memset(num,0,sizeof(num));
    
    queue<int> q;//这里是int?
    q.push(s);
    vis[s]=true;
    num[s]++;//就算是源点也应该是num[s]++;而非num[s]=1
    while(!empty()){
        int temp=q.front();
        q.pop();//注意这里pop()出来以后要进行vis[temp]更新。
        vis[temp]=false;
        for(int i=0;i<adj[temp].size();i++){
            int v=adj[temp][i].order;
            int dis=adj[temp][i].distance;
            if(d[v]>d[u]+dis){//这里的松弛操作应该是独立于入队的。不应在这里写vis[v]==false
                d[v]=d[u]+dis;
                if(vis[v]==false){
                    q.push(v);
                    vis[v]=true;
                    num[v]++;
                    if(num[v]>n-1) return false;
                }
            }
        }
    }
    return true;
}

8）Floyd算法
int adj[MAX][MAX];
bool vis[MAX]={false};
int n;

void Floyd(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][k]!=INF&&adj[k][j]!=INF&&adj[i][k]+adj[k][j]<adj[i][j]){
                    adj[i][j]=adj[i][k]+adj[k][j];
                }
            }
        }
    }
    return;//这里需要return吗？？？不需要
}

//动态规划
1）斐波那契数列
//int dp[MAX];

//int F(int t){
    //边界
//    dp[1]=1;
//    dp[0]=1;
//    递推式子
//    for(int i=2;i<=t;i++){
//        dp[i]=dp[i-1]+dp[i-2];
//    }
//    return dp[t];
//}

int F(int t){
    if(t==1|t==0) return 1;
    if(dp[t]!=-1) return dp[t];
    else{
        dp[t]=F(n-1)+F(n-2);
        return dp[t];
    }
}

2）数塔问题
int dp[MAX][MAX];

//边界
for(int i=0;i<n;i++){
    dp[n][i]=num[n][i];
}
//递推式子
for(int i=n-1;i>=1;i--){
    for(int j=1;j<=i;j++){
        dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+num[i][j];
    }
}

3）最大连续子列和
int dp[MAX];
//边界
dp[0]=num[0];
//递推式子
for(int i=1;i<n;i++){
    dp[i]=max(num[i],dp[i-1]+num[i]);//记住其转移条件
}

4）最长不下降子序列
int dp[MAX];
//边界
int ans=-1;
for(int i=0;i<n;i++){//伪代码就是，先将考察的元素看成是一个单独的子序列，然后往前面添加看看有没有可能合并成更大的序列
    dp[i]=1;
    for(int j=0;j<i;j++){
        if(num[i]>num[j]&&dp[j]+1>dp[i]){
            dp[i]=dp[j]+1;
        }
    }
    ans=max(ans,dp[i]);
}

5）最长公共子序列
int dp[MAX][MAX];
int len1,len2;
//边界
for(int i=0;i<len1;i++){
    dp[i][0]=0;
}
for(int j=0;j<len2;j++){
    dp[0][j]=0;
}
//递推式子
for(int i=0;i<len1;i++){
    for(int j=0;j<len2;j++){
        if(num1[i]==num2[j]){
            dp[i][j]=dp[i-1][j-1]+1;
        }
        else {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
}

6）最长回文子串
int dp[MAX][MAX];
//边界
for(int i=0;i<len;i++){
    dp[i][i]=1;
    if(i<len-1){
        if(num[i]==num[i+1]){
            dp[i][i+1]=1;//dp数组里面只存储是不是回文子串，不存储长度
            ans=2;
        }
    }
}
//递推式子
for(int j=3;j<=n;j++){
    for(int i=0;i+j-1<n;i++){
        if(num[i]==num[i+j-1]&&dp[i+1][i+j-2]==1){
            dp[i][i+j-1]=1;
            ans=max(ans,j);
        }
    }
}

7）01背包
int dp[MAX];
//边界
for(int v=0;v<=n;v++){
    dp[v]=0;
}

for(int i=1;i<=n;i++){//这里应该从1开始
    for(int v=V;v>=w[i];v--){
        dp[v]=max(dp[v],dp[v-w[i]]+c[i]);
    }
}

8）完全背包
int dp[MAX];
//边界
for(int i=0;i<=n;i++){
    dp[i]=0;
}
//递推式子
for(int i=1;i<=n;i++){
    for(int v=w[i];v<V;v++){
        dp[v]=max(dp[v],dp[v-w[i]]+c[i]);
    }
}


//AVL树
struct node{
    int data,height;
    node *lchild,*rchild;
};
1)生成结点
node* create(int x){
    node *root=new node;
    root->data=x;
    root->height=1;
    root->lchild=NULL;
    root->rchild=NULL;
    return root;
    
}
2）树高三步骤
int getheight(node *root){
    if(root==NULL){//注意要进行判空
        return 0;
    }
    return root->height;
}

int getlbalence(node *root){
    return getheight(root->lchild)-getheight(root->rchild);
}

void update(node *root){
    root->height=max(getheight(lchild),getheight(rchild))+1;//因为这是void类型所以，前面有root->height
}
3）查找
void search(node *root,int x){
    if(root==NULL){
        return;
    }
    if(root->data==x){
        printf("%d",x);
    }
    else if(root->data>x){
        search(root->lchild);
    }
    else{
        search(root->rchild);
    }
}
3)插入
void R(node *root){
    node *temp=root->lchild;
    root->lchild=temp->rchild;
    temp->rchild=root;
    uodate(root);//这里一定注意要转动了就要更新树高，更新到结点里面。
    update(temp;)
    root=temp;
}
void L(node *root){
    node *temp=root->rchild;
    root->rchild=temp->lchild;
    temp->lchild=root;
    root=temp;
}

void insert(node* &root,int x){
    if(root==NULL){
        root=create(x);
        return;
    }
    if(root->data>x){
        insert(lchild,x);
        update(root);//这里只更新了root没有更新root->lchild,因为不需要，反正都要变的
        if(getbalance(root)==2){
            if(getbalence(root->lchild)==1){
                R(root);
            }
            else if(getbalence(root->lchild)==-1){
                L(root->lchild);
                R(root);
            }
        }
    }
    else{
        insert(rchild,x);
        update(root);
        updata(root->rchild);
        if(getbalance(root)==-2){
            if(getbalence(root->rchild)==-1){
                L(root);
            }
            else if(getbalence(root->lchild)==1){
                R(root->rchild);
                L(root);
            }
        }
    }
}

4）建立
node* create(int data[MAX]){
    node *root=NULL;
    for(int i=0;i<MAX;i++){
        insert(root,data[i]);
    }
    return root;
}


//并查集
1）初始化
for(int i=0;i<n;i++){
    father[i]=i;
}
2）查找
int find(int x){
    while(x!=father[x]){
        x=father[x];
    }
    return x;
}
3）合并
int Union(int x,int y){
    int fax=find(x);
    int fay-find(y);
    if(fax!=fay){
        father[fay]=fax;
    }
    return fax;
}
4）路径压缩
//迭代
int a=x;
while(x!=father[x]){
    x=father[x];
}
while(a!=father[a]){
    int z=a;
    a=father[a];
    father[z]=x;
    return x;
}
//递归
int find(x){
    if(x==father[x]){
        return x;
    }
    else{
        int F=find(father[x]);
        father[x]=F;
        return F;
    }
}

//堆
1）插入
void unjust(int low,int high){
    int i=high,j=high/2;
    while(j>=low){
        if(heap[j]<heap[i]){
            swap(heap[i],heap[j]);
            i=j;
            j/=2;
        }
        else{
            break;
        }
    }
}

void insert(int x){
    heap[++n]=x;
    upjust(1,n);
}
2）删除
void downjust(int low,int high){
    int  i=low,j=i*2;
    while(j<=high){
        if(heap[j]<heap[j+1]&&j+1<=high){
            j=j+1;
        }
        
        if(heap[i]<heap[j]){
            swap(heap[i],heap[j]);
            i=j;
            j=i*2;
        }
        else{
            break;//这里一定是有break的.
        }
    }
}

void Deletetop(){
    heap[1]=heap[n--];
    downjust(1,n);
}
3）建堆
void create(){
    for(int i=n/2;i>=1;i--){
        downjust(i,n);//注意这里是i-n；相当于从最后一点一点摞动。
    }
}

4）堆排序
void heapsort(){//堆这里是倒着枚举的
    create();
    for(int i=n;i>=1;i--){
        swap(heap[1],heap[i]);//并且这里还需要进行交换
        downjust(1,i-1);
    }
}

//哈夫曼树
1）
priority_queue<int,vector<int>,greater<int>> q;
while(q.size()>1){
    int x=q.top();
    q.pop();
    int y=q.top();
    q.pop();
    q.push(x+y);
    ans+=x+y;
}






//搜索
1）DFS
void dfs(node *root){
    if(root==NULL){
        return;
    }
    if(root->lchild!=NULL) dfs(root->lchild);//这样对吗？？
    if(root->rchild!=NULL) dfs(root->rchild);
}
2）BFS
void bfs(node *root){
    queue<node*> q;//这里是node还是node*??  node* ,因为访问树，进行的是访问它的结点指针。
    q.push(root);
    while(!empty()){
        node *temp=q.front();
        q.pop();
        if(root->lchlid!=NULL){
            q.push(root->lchild);//这里对吗？？  对对，仅当有左右子树的时候才可以访问。
        }
        if(root->rchild!=NULL){
            q.push(root->rchild);
        }
    }
}
//二叉树
//链表实现
1）生成结点
node* create(int x){
    node *root=new node;//这里是node还是node*。    node*,生成结点返回的是一个指针
    root->data=x;
    root->lchild=NULL;
    root->rchild=NULL;
    return root;
}
2）查找
void search(node *root,int x){
    if(root==NULL){
        return;
    }
    if(root->data==x){
        return;
    }
    search(root->lchild);
    search(root->rchild);
}

3）插入
void insert(node* &root,int x){
    if(root==NULL){
        root=create(x);
        return;
    }
    if(满足啥条件){
        insert(root->lchild,x);//递归体内重新写递归函数的时候需要注意的是参数一定不要少了。
    }
    if(满足啥条件){
        insert(root->rchild,x);
    }
}
4）创建
node* create(int data[]){
    node *root=NULL;
    for(int i=0;i<n;i++){
        insert(root,data[i]);
    }
    return root;
}
5）遍历（四种遍历方法）
void preorder(node *root){
    if(root==NULL){
        return;
    }
    visit();
    preorder(root->lchild);//对吗？？？  对对就是这样遍历的，遍历你要知道可以在哪些地方进行操作，比如这里的visit.
    preorder(root->rchild);
}

void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->lchild);
    visit();
    inorder(root->rchild);
}

void postorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->lchild);
    inorder(root->rchild);
    visit();
}

void level(node *root){
    queue<node*> q;
    q.push(root);
    while(!empty()){
        node *temp=q.front();//这里是node*还是啥？？
        q.pop();
        if(root->lchild!=NULL){
            q.push(root->lchild);
        }
        if(root->rchild!=NULL){
            q.push(root->rchild);
        }
    }
}
6）根据先序和中序遍历构造二叉树
node* create(int prel,int prer,int inl,int inr){
    if(prel>prer){//注意这里是需要写一个边界判断
        return;
    }
    node *root=new node;//这里就是申请一个新结点，注意使用静态写法，直接就是++index=root；
    root->data=pre[prel];//不是pre[0]，而是pre[prel];
//    root->lchild=NULL;
//    root->rchild=NULL;//这里不需要进行对root的孩子进行初始化，因为反正后面也是要更新的。
    int k=inl;
    for(;k<=inr;k++){
        if(in[k]==pre[prel]) break;
    }
    int numleft=k-inl;
    root->lchild=create(prel+1,pre+numleft,inl,k-1);
    root->rchild=create(prel+numleft+1,prer,k+1,inr);
    
    return root;//写函数体的时候，先把return root 写上，不让很容易忘掉。
}
//静态实现
struct Node{
    int data;
    int lchild,rchild;
}node[MAX];
1）生成结点
int create(int x){
    node[++index].data=x;
    node[index].lchild=-1;
    node[index].rchild=-1;
    return index;
}
2）查找
void search(int root,int x){
    if(root==-1){//注意这里是root的值为-1；
        return;
    }
    if(node[root].data==x){
        visit();
        return;
    }
    search(node[root].lchild);
    search(node[root].rchild);
}

3）插入
void insert(int &root,int x){//插入是不用进行返回的(void)
    if(root==-1){
        root=create(x);
        return;
    }
    if(啥条件）{
        insert(node[root].lchild,x);
    }
    if(啥条件）{
        insert(node[root].rchild,x);
    }
}

4）创建
       int create(int data[]){
        int root=-1;
        for(int i=0;i<n;i++){
            insert(root,data[i]);
        }
        return root;
    }
       
5）遍历（四种遍历方法）
       void preorder(int root){
           if(root==-1){
               return;
           }
           visit();
           preorder(node[root].lchild);//对吗？？？
           preorder(node[root].rchild);
       }

       void inorder(int root){
           if(root==-1){
               return;
           }
           inorder(node[root].lchild);
           visit();
           inorder(node[root].rchild);
       }

       void postorder(int root){
           if(root==-1){
               return;
           }
           inorder(node[root].lchild);
           inorder(node[root].rchild);
           visit();
       }

       void level(int root){
           queue<int> q;//这里是返回了地址，所以如果使用指针进行存储，那么就是存储<node*>
           q.push(root);
           while(!q.empty()){
               int temp=q.front();//这里是node*还是啥？？
               q.pop();
               visit();//层序遍历可以在这里进行访问。
               if(node[root].lchild!=-1){
                   q.push(node[root].lchild);
               }
               if(node[root].rchild!=-1){
                   q.push(node[root].rchild);
               }
           }
       }
       
6）根据先序和中序遍历构造二叉树
       int recreate(int prel,int prer,int inl,int inr){
        if(prel>prer){
            return;
        }
        int root=++index;
        node[root].data=pre[prel];
        int i=inl;
        for(;i<inr;i++){
            if(in[i]==pre[0]){
                break;
            }
        }
        int numleft=i-inl;
        node[root].lchild=recreate(prel+1,prel+i,inl,i-1);
        node[root.rchild]=recreate(pre+i+1,prer,i+1,inr);
        return root;
    }
//树       //树的这一节都是采用的静态写法
1）树的结点
       struct Node{
        int data;
        vector<int> child;
    }node[MAX];//这里是这样吗？？？是的，使用静态写法，一定要开一个结点数组
       
       struct Node{
        int data;
        int child[MAX];
    }node[MAX];
       
2）树的遍历（两种）
//先根遍历
       void pre(int root){
//        if(root==-1){
//            return;
//        }
        visit();//这里应该是访问当前结点
        for(int i=0;i<node[root].child.size();i++){
            pre(node[root].child[i]);//这里是root.吗？？  换成静态写法就是这样了。
        }
    }
       
//层序遍历
       void level(int root){
        queue<int> q;
        q.push(root);
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(int i=0;i<node[temp].child.size();i++){
                q.push(node[temp].child[i]);
            }
        }
    }
       
//BST
1）查找
       void search(node *root,x){
        if(root==NULL){
            return;
        }
        if(root->data==x){
            return;
        }
        else if(root->data>x){
            search(root->lchild,x);
        }
        else{
            search(root->rchild,x);
        }
    }
2）插入
       void insert(node* &root,x){
        if(root=NULL){
            root=create(x);
            return;
        }
        if(root->data==x){//这里一定是if-else if-else 的架构
            return;
        }
        else if(root->data>x){
            insert(root->lchild);
        }
        else{
            insert(root->rchild);
        }
    }
3）建立
       node* built(int data[]){
        node *root=NULL;
        for(int i==0;i<n;i++){
            insert(root,data[i]);
        }
        return root;
    }
4）删除（有点麻烦的)
//寻找最大元素
       node* max(node *root){
//        node *p=root;//这里可以不使用p进行指针，直接使用root进行下移；
        while(root->rchild!=NULL){
            root=root->rchild;
        }
        return root;
    }
//寻找最小元素
       node *min(node *root){
        while(root->lchild!=NULL){
            root=root->lchild;
        }
        return root;
    }
       
//       void Delete(node* &root,int x){//注意这个参数必须注明参数类型。
//        if(root->lchild==NULL&&root->rchild==NULL){//这个逻辑对吗？？不对不对，看下面的解析。
//            root=NULL;
//            return;
//        }
//        else if(root->lchild==NULL){
//            node *temp=min(root-<rchild);
//            root->data=temp->data;
//            Delete(root->rchild,temp->data);//因为最小的元素不一定是叶子结点，所以不能直接删掉，要继续递归
//        }
//        else{
//            node *temp=max(root->lchild);
//            root->data=temp->data;
//            Delete(root->lchild,temp->data);
//        }
//    }
       void Delete(node* &root,int x){
        if(root==NULL)return;
        if(root->data==x){
            if(root->lchild==NULL&&root->rchild==NULL){
                root=NULL;
            }
            else if(root->lchild!=NULL){
                node *temp=max(root->lchild);
                root->data=temp->data;
                Delete(root->lchild,temp->data);
            }
            else{
                node *temp=min(root->rchild);
                root->data=temp->data;
                Delete(root->rchild,temp->data);
            }
        }
        else if(root->data>x) Delete(root->lchild,x);
        else Delete(root->rchild,x);
    }
    
    





