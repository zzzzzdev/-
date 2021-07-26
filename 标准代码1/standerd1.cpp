//字符串hash

int hashFunc(char s[], int len) {
	int id = 0;
	for (int i = 0; i < len-1; i++) {
		id = id * 26 + s[i] - 'A';
	}
	id = id * 10 + (s[len-1] - '0');
	return id;
}
//字符hash
int change(char c) {
	if (c > '0'&&c < '9') return c - '0';
	if (c > 'a'&&c < 'z') return c - 'a' + 10;
	if(c>'A'&&c<'Z') return c - 'A' + 36;
}


//二分模板，适用于lower_bound以及uppe_bound

1)用于左闭右闭区间,寻找第一个大于等于x的元素的下标

int lower_bound(int a[], int left, int right,int x) {
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (a[mid] >= x) right = mid;
		else left = mid + 1;
	}
	return left;
}

2)用于左闭右闭区间, 寻找第一个大于x的元素的下标

int upper_bound(int a[], int left, int right, int x) {
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (a[mid] > x)right = mid;
		else left = mid + 1;
	}
	return left;
}

3)用于左开右闭区间

int BinerySearch(int a[], int left, int right, int x) {
	int mid;
	while (left + 1 < right) {
		mid = (left + right) / 2;
		if (a[mid] >= right) right = mid;
		else left = mid;
	}
	return right;
}


//快速幂（二分幂）

1）递归写法

long long BineryPow(long long a, long long b,long long m) {
	if (b == 0) return 1;
	if (b % 2 == 1) return a * BineryPow(a, b - 1,  m)%m;
	else {
		long long mul = BineryPow(a, b / 2, m);
		return mul * mul%m;
	}
}

2)迭代写法

typedef long long LL;
LL BinerySearch(LL a, LL b, LL m) {
	int ans = 1;
	while (b > 0) {
		if (b % 2) ans = ans * a%m;
		a = a * a%m;
		b >> 1;
	}
	return ans;
}

//归并排序

void merge(int a[], int L1, int L2, int R1, int R1) {
	int temp[MAX], index = 0;
	int i = L1, j = L2;
	while (i < R1&&j < R2) {
		if (a[i] >= a[j]) temp[index++] = j++;
		else temp[index++] = i++;
	}
	while (i < R1) temp[index++] = i++;
	while (j < R2) temp[index++] = j++;

	for (int k = 0; k < index; k++) {
		a[L1 + k] = temp[k];
	}
}

1）递归
void mergesort(int a[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergesort(a, left, mid);
		mergesort(a, mid + 1, right);
		merge(a, left, mid, mid + 1, right);
	}
}

2)非递归
void mergesort(int a[], int left, int right) {
	for (int step = 2; step / 2 < n; step *= 2) {
		for (int i = 1; i < n; i++) {
			int mid = (left + right) / 2;
			if (mid + 1 <= n) {
				merge(a, i, mid, mid + 1, min(i + step - 1), n);
			}
		}
	}
}
3)小改进
void mergesort(int a[], int left, int right) {
	for (int step = 2; step / 2 <= n; step *= 2) {
		for (int i = 1; i < n; i++) {
			sort(a + i, a + min(i + step, n + 1));
		}
	}
}


//快速排序

int Partition(int a[], int left, int right) {
	int temp = a[left];
	while (left < right) {
		while (a[right > temp]) right--;
		a[right] = a[left];
		while (a[left < temp]) left++;
		a[left] = a[right];
	}
	a[left] = temp;
	return left;
}

void QuickSort(int a[], int left, int right) {
	if (left < right) {
		int pos = Partition(a, left, right);
		QuickSort(a, left, pos);
		QuickSort(a, pos + 1, right);
	}
}

//插入排序
void InsertSort(int a[],int len){
	int temp,j;
	for(int i=0;i<len;i++){
		temp=a[i];
		j=i;
		while(j>0&&a[j-1]>temp){
			a[j]=a[j-1];
			j--;
		}
		a[j]=temp;
	}	
}

//栈的操作
#include<stack>
using namespace std;
stack<int> s;
s.clear();
s.size();
s.top();
s.push();
s.pop();
s.empty();

//队列的操作
#include<queue>
using namespace std;
queue<int> q;
q.clear();
q.front();
q.rear();
q.size();
q.empty();
q.push();
q.pop();


//链表的操作

1）动态链表
struct node {
	int data;
	node *next;
};

//创建
node* create(int a[]) {
	node *p, *pre, *head;
	head = new node;
	head->next = NULL;
	pre = head;
	for (int i = 0; i < n; i++) {
		p = new node;
		p->data = a[i];
		p->next = NULL;
		pre->next = p;
		pre = p;
	}
	return head;
}

//查找元素
node *search(node* head, int x) {
	node *p = head->next;
	while (p != NULL) {
		if (p->data == x) return p;
		p = p->next;
	}
	return NULL;
}

//插入元素
void Insert(node *head, int pos, int x) {
	node *p=head->next;
	for (int i = 0; i < pos - 1; i++) {
		p = p->next;		
	}
	node *q = new node;
	q->data = x;
	q->next = p->next;
	p->next = q;
}

//删除元素
void Delete(node *head.int x) {
	node *p, *pre;
	p = head->next;
	pre = head;
	while (p != NULL) {
		if (p->data == x) {
			pre->next = p->next;
			delete(p);
			p = pre->next;
		}
		else {
			pre = p;
			p = p->next;
		}
	}
}

2)静态链表

//创建静态链表
struct Node {
	int data;
	int next;
}node[MAX];

//创建新节点
int create(int index, int x) {
	node[index].data = x;
	node[index].next = -1;
	return index++;
}

//查找元素
int search(int root, int x) {
	int p;
	p = root;
	while (p != -1) {
		if (node[p].data == x)return p;
		p = node[p].next;
	}
	return -1;
}

//插入元素,插入到pos位置
void Insert(int root, int x,int index,int pos) {
	int p = root;
	for (int i = 0; i < pos - 1; i++) {
		p = node[p].next;
	}
	int New = create(index, x);//得到下标
	node[New].next = node[p].next;
	node[p].next = New;
}

//删除元素
void Delete(int root, int x) {
	int p = node[root].next;
	int pre = root;
	while (p != -1) {
		if (node[p].data == x) {
			node[pre].next = node[p].next;
			p = node[p].next;
		}
		else {
			pre = p;
			p = node[p].next;
		}
	}
}

//DFS
void dfs(int root) {
	if (root == -1)
		return;
	if (有左孩子) return dfs(node[root].lchild);
	if (有右孩子) return dfs(node[root].rchild);
}

//BFS
void bfs(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		访问其子节点
		/*
		if(node[root].lchild) bfs(node[root].lchild);
		if(node[root].rchild) bfs(node[root].rchild);
		*/
		/*
		for(int i=0;i<node[root].child.size();i++){
			bfs(node[root].child[i]);
		}
		*/
	}
}

//二叉树（链表实现）
1）创建结点
node *crenode(int x) {
	node *p = new node;
	p->data = x;
	p->lchild = p->rchild = NULL;
	return p;
}

2)查找、修改(修改为new)
void search(node* root, int x,int new) {
	if (root == NULL)
		return;
	if (root->data == x) {
		root->data = new;
		return;
	}
	search(root->lchild, x, new);
	search(root->rchild, x, new);
}

3)插入
void Insert(node* &root, int x) {
	if (root == NULL) {
		root = creat(x);
		return;
	}
	if(可以往左插)Insert(root->lchild, x);
	if(可以往右插)Insert(root->rchild, x);
}

4）二叉树的创建
node* create(int a[], int n) {
	node *root = NULL;
	for (int i = 0; i < n; i++) {
		Insert(root, a[i]);
	}
	return root;
}

//二叉树的遍历
1）先、中、后序遍历
void preorder(node* root) {
	if (root == NULL) {
		return;
	}
	visit();
	preorder(root->lchild);
	preorder(root->rchild);
}

2)记录层数的层序遍历
struct node {
	int data;
	int order;
	node *lchild, *rchild;
};
void layerorder(node *root) {
	queue<node*> q;//存放node*地址
	root->order = 1;//先+1,后push
	q.push(root);
	while (!q.empty()) {
		node *now = q.front();
		q.pop();
		if (now->lchild!=NULL) {
			now->lchild->order = now->order + 1;
			q.push(now->lchild);
		}
		if (now->rchild!=NULL) {
			now->rchild->order = now->order + 1;
			q.push(now->rchild);
		}
	}
}

//由先序序列和中序序列，重构二叉树
node *create(int prel, int prer, int inl, int inr) {
	if (prel > prer) {
		return NULL;
	}
	node *root = new node;
	root->data = pre[prel];
	int k;
	for (k = inl; k <= inr; k++{
		if(in[k]==pre[prel]) break;
	}
	int num=k-inl;
	root->rchild=create(prel+1,prel+num,inl,k-1);
	root->lchild=create(pre+num+1,prer,k+1,inr);
	return root;
}

//二叉树（静态实现）
struct Node {
	int data;
	int lchild, rchild;
}node[MAX];

1)生成结点
int create(int x) {
	node[index].data = x;
	node[index].lchild = node[index].rchild = -1;
	return index++;
}

2)查找、修改
void Search(int root, int x,int new) {
	if (root == -1) {
		return;
	}
	if (node[root].data == x) {
		node[root].data = new;
	}
	Search(node[root].lchild, x,new);
	Search(node[root].rchild, x,new);
}

3)插入
void Insert(int &root, int x) {
	if (root == NULL) {
		root=create(x);
		return;
	}
	if()Insert(node[root].lchild, x);
	if()Insert(node[root].rchild, x);
}

4)二叉树的建立
int create(int a[], int n) {
	int root = -1;
	for (int i = 0; i < n; i++) {
		Insert(root, a[i]);
	}
	return root;
}

5)先中后序遍历
void order(int root) {
	if (root == -1) {
		return;
	}
	visit();
	order(node[root].lchild);
	order(node[root].rchild);
}

6)带有高度的层序遍历
struct Node {
	int data,layer;
	int lchild, rchild;
}node[MAX];
void layeroreder() {
	queue<int> q;
	node[root].layer = 1;
	q.push(root);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (node[now].lchild != -1) {
			node[node[now].lchild].layer = node[now].layer + 1;
			q.push(node[now].lchild);
		}
		if (node[now].rchild != -1) {
			node[node[now].rchild].layer = node[now].layer + 1;
			q.push(node[now].rchild);
		}
	}
}

//树
struct Node {
	int data;
	vector<int> child;
}node[MAX];

1)创建节点
int create(int x) {
	node[index].data = x;
	node[index].child.clear();
	return index++;
}

2)先根遍历
void preorder(int root) {
	visit();
	for (int i = 0; i < node[root].child.size(); i++) {
		preorder(node[root].child[i]);
	}
}

3)层序遍历
void layerorder(int root) {
	queue<int>q;
	q.push(root);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < node[root].child.size(); i++) {
			q.push(node[root].child[i]);
		}
	}
}

//BST树

1）查找
node* search(node* root,int x) {
	if (root == NULL) {
		return;
	}
	if (root->data == x) {
		return root;
	}
	else if (root->data < x) {
		search(root->rchild, x);
	}
	else search(root->lchild, x);
}

2）插入
void Insert(node* &root, int x) {
	if (root == NULL) {
		root = create(x);
		return;
	}
	if (root->data == x) {
		return;
	}
	else if (root->data > x) {
		Insert(root->lchild, x);
	}
	else {
		search(root->rchild, x);
	}
}
3）删除
node* findmax(node *root) {
	if (root == NULL) {
		return NULL;
	}
	while (root->rchild != NULL) {
		root = root->rchild;
	}
	return root;
}
node* findmin(node* root) {
	if (root == NULL) {
		return NULL;
	}
	while (root->lchild != NULL) {
		root = root->lchild;
	}
	return root;
}

void Delete(node* root, int x) {
	if (root == NULL) {
		return;
	}
	if (root->data == x) {
		if (root->lchild==NULL&&root->rchild==NULL) {
			root = NULL;
		}
		else if (root->lchild != NULL) {
			node *max = findmax(root->lchild);
			root->data = max->data;
			Delete(root->lchild, max->data);
		}
		else {
			node *min = findmin(root->rchild);
			root->data = min->data;
			Delete(root->rchild, min->data);
		}
	}
	else if (root->data > x) {
		Delete(root->lchild, x);
	}
	else {
		Delete(root->rchild, x);
	}
}
4）创建
node *create(int a[], int n) {
	node *root = NULL;
	for (int i = 0; i < n; i++) {
		Insert(root, a[i]);
	}
	return root;
}
//AVL树
struct Node {
	int key;
	int lchild, rchild;
	int height;
}node[MAX];

1）创建节点
int create(int x) {
	node[index].key = x;
	node[index].height = 1;//这里需要更新高度
	node[index].lchild = node[index].rchild = -1;
	return index++;
}

2）查找
void search(int root,int x) {
	if (root == -1) {
		return;
	}
	if (node[root].key == x) {
		return;
	}
	else if (node[root].key >= x) search(node[root].lchild, x);
	else search(node[root].rchild, x);
}
3）插入
int getheight(int root) {
	if (root == -1) return 0;//先做判断
	return node[root].height;
}

void updateheight(int root) {
	node[root].height=max(getheight(node[root].lchild), getheight(node[root].rchild)) + 1;
}

int getbalencefactor(int root) {
	return getheight(node[root].lchild) - getheight(node[root].rchild);
}

void R(int &root) {
	int p;
	p = node[root].lchild;
	node[root].lchild = node[p].rchild;
	node[p].rchild = root;
	updateheight(root);
	updateheight(p);
	root = p;
}
void L(int &root) {
	int p=node[root].rchild;
	node[root].rchild = node[p].lchild;
	node[p].lchild = root;
	updateheight(root);
	updateheight(p);
	root = p;
}

void Insert(int &root, int x) {
	if (root == -1) {
		root = create(x);
		return;
	}
	if (node[root].key == x) {
		return;
	}
	if (node[root].key > x) {
		Insert(node[root].lchild, x);
		updateheight(root);
		if (getbalaencefactor(root) == 2) {
			if (getbalaencefactor(node[root].lchild)==1)) {
				R(root);
			}
			else if(getbalaencefactor(node[root].lchild) == -1){
				L(node[root].lchild);
				R(root);
			}
		}
	} 
	else {
		Insert(node[root].rchild, x);
		updateheight(root);
		if (getbalaencefactor(root) == -2){
			if (getbalaencefactor(node[root].rchild) == -1) {
				L(root);
			}
			else if (getbalaencefactor(node[root].rchild) == 1) {
				R(node[root].rchild);
				L(root);
			}
		}
	}
}
4）删除
插入一样
5）创建
int create(int a[], int len) {
	int root = -1;
	for (int i = 0; i < len; i++) {
		Insert(root, a[i]);
	}
	return root;
}

//并查集
int father[MAX];
1）初始化
for (int i = 0; i < MAX; i++) {
	father[i] = i;
}
2）查找
//非递归
int searchfather(int x) {
	while (father[x] != x) {
		x = father[x];
	}
	return x;
}
//递归
int searchfather(int x) {
	if (father[x] == x) return x;
	else return searchfather(father[x]);
}

2）路径压缩（递归与非递归方法）
//非递归
int searchfather(int x) {
	int a = x;
	while (father[x] != x) {
		x = father[x];
	}
	while (father[a] != a) {
		int z = a;
		father[z] = x;
		a = father[a];
	}
	return x;
}

//递归
int searchfather(int x) {
	if (father[x] == x) return x;
	else {
		int father = searchfather(father[x]);
		father[x] = father;
		return father;
	}
}
3）合并
void(int a, int b) {
	int father1 = searchfather(a);
	int father2 = searchfather(b);
	if (father1 != father2) {
		father[father1] = father2;
	}
}

//堆
heap[n];

void downjust(int low, int high) {
	int i = low;
	int j = i * 2;
	while (j <= high) {
		if (j + 1 <= high && heap[j] < heap[j + 1]) {
			j = j + 1;
		}
		if (heap[i] < heap[j]) {
			swap(heap[i], heap[j]);
			i = j;
			j = i * 2;
		}
		else break;
	}
}

void upjust(int low, int high) {
	int i = high;
	int j = i / 2;
	while (j >= low) {
		if (heap[j] < heap[i]) {
			swap(heap[i], heap[j]);
			i = j;
			j = i / 2;
		}
		else break;
	}
}

1）创建堆
void create(int heap[]) {
	for (int i = n / 2; i >= 1; i++) {
		downjust(i, n);
	}
}
2）删除堆顶
void Delete() {
	heap[1] = heap[n--];
	downjust(1, n);
}
3）插入
void Insert(int x) {
	heap[++n] = x;
	upjust(1, n);
}
4）堆排序
void heapsort() {
	create();
	for (int i = n; i > 1; i--) {//注意i不能为1 
		swap(heap[1], heap[i]);
		downjust(1, i - 1);
	}
}
//哈夫曼树
1）创建
priority_queue<> q;
while (q.size() > 1) {
	int nw1 = q.top();//注意这里是top()
	q.pop();
	int nw2 = q.top();
	q.pop();
}













