//  practise4入门数学.cpp
//  Created by 朱自通 on 2021/5/22.
//选择排序
void select(int A[]){
    for(int i=0;i<n;i++){
        int k=i;//这里要初始化k值
        for(int j=i;i<n;j++){
            if(A[k]>A[j]){
                k=j;
            }
        }
        int temp=A[i];
        A[i]=A[k];
        A[k]=temp;
    }
}

//插入排序
void insert(){
    for(int i=2;i<=n;i++){
        int temp=A[i],j=i;//注意这里要使用temp存储A[i]的值。
        while(j>=1&&temp<A[j-1]){
            A[j]=A[j-1];
            j--;
        }
        A[j]=temp;
    }
}

//归并排序
void merge(int A[],int firl,int firr,int secl,int secr){
    int i=firl,j=secl,temp[MAX]，index=0;//merge方法要先申请一个临时数组
    while(i<=firr&&j<=secr){
        if(A[i]<A[j]){
            temp[index++]=A[i++];
        }
        else{
            temp[index++]=A[j++];
        }
    }
    while(i<=firr){
        temp[index++]=A[i++];
    }
    while(j<=secr){
        temp[index++]=A[j++];
    }
    for(int k=0;k<index;k++){//这里是怎么进行赋值的？？复制为index啊！
        A[k+firl]=temp[k];//这里赋值都是从firl开始的。
    }
}

1）迭代
void mergesort(int A[]){//待排序的数组也是其中一个参数！！！且迭代的方法没有左右界
    for(int step=2;step/2<=n;step*=2){//注意这里的step/2<=n
        for(int i=1;i<=n;i+=step){//这里的数值变化
            int mid=i+step/2-1;
            if(mid+1<=n){//这里检验了是否存在右区间的合理性
                merge(A,i,mid,mid+1,min(i+step-1,n);//这里是怎么进行归并的？？？
            }
        }
    }
}

2)递归
void mergesort(int A[],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        mergesort(A,left,mid);
        mergesort(A,mid+1,right);
        merge(A,left,mid,mid+1,right);
    }
}

//快速排序
int partition(int A[],int left,int right){
    int temp=A[left];
    while(left<right){
        while(left<right&&A[right]>temp)right--;
        A[left]=A[right];
        while(left<right&&A[left]<temp)left++;
        A[right]=A[left];
    }
    A[left]=temp;
    return left;//这里是返回下标吗？？对，就是返回下标
}

void quicksort(int ,A[],int left,int right){
    if(left<right){//这里都是满足条件才进入
        int pos=partition(A,left,right);
        quicksort(left,pos-1);
        quicksort(pos+1,right);
    }
}

//字符串哈希，将一个字符串转化成hash，
int hash(char s[]){
    int i,ans=0;
    while(s[i]>'a'&&s[i]<'z'){
        ans+=ans*26+(s[i]-'a');//注意这样转化对吗？？
        i++;//这里是i++吗？？
    }
    while(s[i]>'0'&&s[i<'9']){
        ans+=ans*10+s[i]-'0';
        i++;
    }
    return ans;
}

//斐波那契数列，（递归求解）
int F(int index){
    if(index==1||index==0) return 1;
    else{
        return F(index-1)+F(index-2);
    }
}

//输出一个全排列
int n,p[MAX];//一共n个数,产生一个全排列的预先定义量
bool hash[MAX]={false};

void fullorder(int index){//处理第index号位置的号码
    if(index==n+1){//如果全排列完了，就输出它
        for(int i=0;i<n;i++){
            printf("%d",p[i]);
        }
        return;
    }
    for(int x=0;x<n;x++){//现在考虑第index位置可能的元素，考察每一个元素。
        if(hash[x]==false){//只有不在p[]里面的才可以放进去
            p[index]=x;
            hash[x]=true;
            fullorder(index+1);
            hash[x]=false;
        }
    }
}
//n皇后问题哦，暴力
int count=0;
int p[MAX];
bool hash[MAX]={false};
void gennerate(int n,int index){
	if(index==n+1){
		bool flag=true;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){//注意这两个的取值
				if(abs(i-j)==abs(p[i]-p[j])){
					flag==false;
				}
			}
		}
		if(flag) count++;
		return;
	}
	for(int x=0;x<n;x++){
		if(hash[x]==false){
			p[index]=x;
			hash[x]=true;
			generate(index+1);
			hash[x]=false;
		}
	}
}
                
//n皇后问题（回溯）
void generate(int index){
    if(index==n+1){
        count++;
        return;
    }
	for(int x=1;x<=n;x++){
		if(hash[x]==false){//再放入皇后之前先检查前面是否有违规的
			bool flag=true;
			for(int i=1;i<index;i++){
				for(int j=i+1;j<index;j++){
					if(abs(i-j)==abs(p[i]-p[j])){
						flag=false;
						break;
					}
				}
			}
			if(flag){//如果前面的没有违规，那么就可以放入第index个
				p[index]=x;
				hash[x]=true;
				generate(index+1);
				hash[x]=false;
			}
		}
	}
}
//二分查找
1）第一个大于等于x的元素
int binerysearch(int left,int right,int x){
    int mid;
    while(left<right){
        mid=(left+right)/2;
        if(num[mid]>=x)right=mid;
        else{
            left=mid+1;
        }
    }
    return left;
}
2）第一个大于x的元素
void bsearch(int left,int right,int x){
    while (left<right) {
        int mid=(left+right)/2;
        if(num[mid]>x)right=mid;
        else{
            left=mid+1;
        }
    }
    return left;
}
3）精确查找到某元素的位置
int bsearch(int left,int right,int x){
    while(left<right){
        int mid=(left=right)/2;
        if(num[mid]==x) return mid;
        else if(num[mid]>x) right=mid;
        else{
            left=mid+1;
        }
    }
}

//二分幂
1）迭代
ll binerypow(int a,int b,int mod){
	ll ans=1;
	whlie(b>0){
		if(b%2!=0){//迭代方法是从后往前进行的，也就是a总共进行幂次自乘。
			ans=ans*a%mod;
		}
		a=a*a;
		b/=2;
	}
	return ans;
}
2）递归
ll binerypow(ll a,ll b,ll mod){//二分幂应该是有返回值的
    if(b==0) return 1;
    if(b%2!=0) return=a*binerypow(a,b-1,mod)%mod;//这样对吗？？
    else{
        ll multy=binerypow(a,b/2,mod);
        return multy*multy%mod;
    }
}

//链表，指针
struct list{
    int data;
    list *next;
};
1）创建结点
list *create(int x){
    list *head=new list;
    head->data=x;
    head->next=NULL;
    return head;
}

2）创建链表
node* createlist(int A[],int n){
	node *p,*pre,*head;
	head=new node;
	head->next=NULL;//主要是这个思路
	pre=head;
	for(int i=0;i<n;i++){
		p=create(A[i]);
		pre->next=p;
		pre=p;
	}
	return head;
}


2）查找元素
list* serach(int *root,int x){
    list *p=root;
    while(p!=NULL){//链表的这里是这样的哦！
        if(p->data==x){
            break;
        }
        p=p->next;//这里是这样吗？？
    }
    return p;
}
3）插入元素
void insert(list* &head,int pos,int x){
    temp=create(x);
    list *p=head;
    while(pos--){
        p=p->next;//插入是这样吗？？ 先寻找地址
    }
    temp->next=p->next;
    p->next=temp;
}
4）删除元素
void Delete(list* head,int x){
    list *pre,p;
    pre=head;
    p=head->next;
    while(p!=NULL){
        while(p->data!=x){//删除是这样吗？？
            pre=p;
            p=p->next;
        }
        pre->next=p->next;
		delete(p);//注意这里还要进行delete操作，删除的结点。
        p=pre->next;
    }
}

//链表，静态实现
struct Node{
    int data;
    int next;
}node[MAX];
1）创建
int create(int x){
    node[++index].data=x;
    node[index].next=-1;
    return index;
}

2）查找元素
int search(int head,int x){
    int p=head;
    while(p!=-1){
        if(node[p].data==x){
            break;
        }
        p=node[p].next;
    }
    return p;
}

3）插入元素
void insert(int &head,int pos,int x){
    int p=head;
    int temp=create(x);
    while(pos--){
        p=node[p].next;
    }
    node[temp].next=node[p].next;
    node[p].next=temp;
}

				
4）删除元素
void Delete(int &head,int x){
    int pre=head,p=node[head].next;
    while(p!=-1){
        while(node[p].data!=x){
            pre=p;
            p=node[p].next;
        }
        node[pre].next=node[p].next;
		delete(p);
        p=node[pre].next;
    }
}




//最大公约数
int gcd(int a,int b){
	if(b==0) return a;
	return gcd(a,a%b);
}

//最大公倍数
int lcm(int a,int b){
	int gcd1=gcd(a,b);
	return a/gcd1*b;//注意这里的计算公式
}
				
//分数
1）表示
struct Fraction{
	int up,down;
};
2）分数化简
Fraction reduction(Fraction a){
	if(a.down<0){
		a.up=-a.up;
		a.down=-a.down;
	}
	else if(a.up==0){
		a.down=1;
	}
	else{
		int d=gcd(a.up,a.down);
		a.up/=d;
		a.down/=d;
	}
	return a;
}

3）分数的四则运算
Fraction add(Fraction a,Fraction b){
	Fraction c;
	c.up=a.up*b.down+a.down*b.up;
	c.down=a.down*b.down;
	return reduction(c);
}

4）分数输出
void showFraction(Fraction result){
	result=reduction(result);//输出分数首先记得化简
	if(result.down==1) printf("%lld",result.up);
	else if(abs(result.up)>result.down){
		printf("%d %d/%d",abs(result.up)/result.down,abs(result.up)%result.down,result.down);
	}
	else{
		printf("%d/%d",result.up,result.down);
	}
}

//素数
1）判断是否是素数
bool isprime(int n){
	if(n<=1) return false;//需要进行一个特判
	int sqr=(int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){//注意这个范围，sqr是可以取得的
		if(n%i==0)return false;
	}
	return true;
}
2）打印素数表
//暴力
int prime[MAX],pnum=0;
bool p[MAX]={false};
void Find_prime(int n){
	for(int i=2;i<n;i++){//打印素数这个就得从1开始了。
		if(isprime(i)){
			prime[pnum++]=i;
			p[i]=true;
		}
	}
}
//埃氏筛法
int prime[MAX],pnum=0;
bool p[MAX]={true};

void Find_prime(int n){
	for(int i=2;i<n;i++){
		if(p[i]==true){//这里是用什么进行判断，isprime的话，感觉很浪费时间？就是用p[]数组进行判断，不用prime.
			prime[pnum++]=i;
			for(int j=i+i;j<n;j+=i){
				p[j]=false;
			}
		}
	}
}

//质因子分解
1）质因子存储
struct Factor{
	int num;
	int cnt;
}fac[10];

2）寻找某数质因子
Find_prime();
int sqr=(int)sqrt(1.0*n);
//for(int i=2;i<sqr;i++){//这个应该是直接在素数表里面查找，所以开始为0；
	for(int i=0;i<pnum&&prime[i]<sqr;i++){
//	if(p[i]==true&&prime[i]<sqr&&i<pnum){//这样对吗？？不对不对
		if(n%prime[i]==0){
			fac[num].num=prime[i];
			fac[num].cnt=0;
			while(n%prime[i]==0){
				fac[num].cnt++;
				n/=prime[i];
			}
			num++;//这里的num++，奇迹也是可以放在下面的。
		}
		if(n==1) break;
	}
	if(n!=1){
		fac[num].num=n;
		fac[num++].cnt=1;
	}


3）质因子按照形式输出
void show(){
	for(int i=0;i<num;i++){
		if(fac[i].cnt==1){
			printf("%d",fac[i].num);
		}
		else{
			printf("%d^%d",fac[i].num,fac[i].cnt);//这个对吗？？
		}
		if(i<num-1){
			printf("*");
		}
	}
}

//高精度数运算
1）存储
struct bign{
	int d[MAX];
	int len;
	bign(){
		memset(d,0,sizeof(d));
		len=0;
	}
};

2）字符串转化成高精度数（因为高精度数一般都是以字符串形式读入的）
bign change(char s[]){
	bign c;
	c.len=strlen(s);
	for(int i=0;i<c.len;i++){
		c.d[i]=s[c.len-i-1]-'0';
	}
	return c;
}
3）比较两个高精度数
int compare(bign a,bign b){
	if(a.len>b.len) return 1;
	else if(a.len<b.len) return -1;
	else{
		for(int i=a.len;i>=1;i--){
			if(a.d[i]>b.d[i]) return 1;
			else if(a.d[i]<b.d[i]) return -1;
//			else{
//				return 0;//这个return 0；应该是放在外面的；
//			}
		}
		return 0;
	}
}

4）高精度数四则运算
//加
bign add(bign a,bign b){
	bign c;
	int carry=0;
	for(int i=0;i<a.len||i<b.len;i++){
		int temp=a.d[i]+b.d[i]+carry;
		c.d[c.len++]=temp%10;
		carry=temp/10;
	}
	if(carry!=0){
		c.d[c.len++]=carry;
	}
	return c;
}
//减
bign sub(bign a,bign b){
	bign c;
	for(int i=0;i<a.len||i<b.len;i++){
		if(a.d[i]<b.d[i]){
			a.d[i+1]--;
			a.d[i]+=10;
		}
		c.d[c.len++]=a.d[i]-b.d[i];
	}
	while(c.len-1>=1&&c.d[c.len-1]==0){
		c.len--;
	}
	return c;
}
//乘
bign multy(bign a,int b){
	bign c;
	int carry=0;//一定不要忘了定义这个carry
	for(int i=0;i<a.len;i++){//这里是小于a.len吗？？
		int temp=a.d[i]*b+carry;
		c.d[c.len++]=temp%10;
		carry=temp/10;
	}
	while(carry!=0){
		c.d[c.len++]=carry%10;
		carry/=10;
	}
	return c;
}
//除
bign divi(bign a,int b,int &r){//注意这里需要进行引用余数
	bign c;
	c.len=a.len;
	for(int i=a.len-1;i>=0;i--){
		int r=r*10+a.d[i];
		if(r<b) c.d[c.len++]=0;
		c.d[c.len++]=r/b;
		r=r%b;
	}
	while(c.len-1>=1&&c.d[c.len-1]==0){
		c.len--;
	}
	return c;
}





				
