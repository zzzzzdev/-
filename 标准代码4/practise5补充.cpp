//  practise5补充.cpp
//  Created by 朱自通 on 2021/5/23.

//科学计数法
void sci(char str[]){
	int len=strlen(str);
	if(str[0]=='-') printf("-");
	
	int exp=0,pos=0;
	while(str[pos]!='E'){
		pos++;
	}
	for(int i=pos+2;i<len;i++){
		exp=exp*10+(str[i]-'0');
	}
	if(exp==0){
		for(int j=0;j<pos;j++){
			printf("%c",str[i]);
		}
	}
	
	if(str[pos+1]=='-'){
		printf("0.");
		for(int i=0;i<exp-1;i++){
			printf("0");
		}
		printf("%c",str[0]);
		for(int j=2;j<pos;j++){
			printf("%c",str[i]);
		}
	}
	else{
		for(int i=0;i<pos;i++){
			if(str[i]=='.') continue;
			printf("%c",str[i]);
			if(i==exp+2&&pos-3!=exp) print(".");
		}
		
	}
	for(int i=0;i<exp-pos+2;i++){
		printf("0");
	}
	return;
}

//反转字符串
void reverse(char str[]){
	int len=strlen(str);
	char temp;
	for (int i=0; i<len/2; i++) {
		temp=str[i];
		str[i]=str[len-i-1];
		str[len-1-i]=temp;
	}
}

//多进制数映射到十进制
void change(char str[],int map[]){
	int len=strlen();
	int map[MAX];
	for (int i=0; i<len; i++) {
		if(str[i]>'0'&&str[i]<'9'){
			map[i]=str[i]-'0';
		}
		else{
			map[i]=str[i]-'a'+10;
		}
	}
}
//查询两个不同进制数在什么进制下会相等
int changetoten(char N[],int radix,int t){
	int len=strlen(N);
	int ans=0;
	for(int i=0;i<len;i++){
		ans=ans*radix+N[i]-'0';
	}
	return ans;
}

int cmp(char N[],int t,int radix){
	int n=changetoten(N,radix);
	if(n<0||n>t) return 1;
	else if(n<t){
		return -1;
	}
	else{
		return 0;
	}
}

int binery(int left,int right,int t,char N[],int radix){
//	int flag=cmp(N,t,radix);这个地方的flag值应该在while循环内部的，必须在内部才行的
	int mid;
	while(left<right){
		min=(left+right)/2;
		int flag=cmp(N,t,mid);//而且这里必须是mid进制的
		if(flag==0) return mid;
		else if(flag==-1) left=mid+1;
		else{
			right=mid;
		}
	}
	return -1;//输出解不存在
}

//设计一个计算器，包括中缀转后缀，计算后缀
struct node{
	double num;//这个一定是一个double类型的
	char op;
	bool flag;
};
string str;
stack<node> s;
queue<node> q;
map<char,int> oplevel;//这里是怎么进行设计的？？<>  应该是这样

oplevel['+']==oplevel['-']=1;
oplevel['*']==oplevel['/']=2;

void change(){
	for(int i=0;i<str.lenth();){
		if(str[i]>'0'&&str[i]<'9'){
			node temp;//
			temp.num=str[i]-'0';
			temp.flag=true;
			while(str[i]>'0'&&str[i]<'9'){//注意这里如果是数字的话，还有应该进行总体数字的求算。
				temp.num=temp.num*10+str[i]-'0';
				i++;
			}
			q.push(temp);
		}
		else{
			node temp;
			temp.flag=false;
			temp.op=str[i];
			while(!s.empty()&&oplevel[s.top().op]>oplevel[str[i]]){
				q.push(s.top());
				s.pop();
			}
			s.push(temp);
			i++;
		}
	}
	while(!s.empty()){//这里还要进行最后堆栈的检查。
		q.push(s.top());
		s.pop();
	}
}

double cal(char str[]){
	while(!q.empty()){
		node temp=q.front();
		q.pop();
		if(temp.flag==true){
			s.push(temp);
		}
		else{
			node tep;
			tep.flag=true;
			double temp2=s.top().num;
			s.pop();
			double temp1=s.top().num;
			s.pop();
			if(temp.op=='+') tep.num=temp1+temp2;
			else if(temp.op=='-')tep.num=temp1-temp2;
			else if(temp.op=='*') tep.num=temp1*temp2;
			else{
				tep.num=temp1/temp2;
			}
			s.push(tep);
		}
	}
	return s.top().num;
}

//去掉某个字符串的某个字符
string str;
for(string::iterator it=str.begin();it!=str.end();it++){
	if(*it=='c'){
		str.erase(it);
	}
}

//进制转化，包括十进制与其他进制之间的相互转化
1)
int change(char str[]){
	int ans=0;
	int len=strlen();
	for(int i=0;i<len;i++){
		ans=ans*10+(str[i]-'0');
	}
	return ans;
}
2)
void change(int n,int radix){
	int res[MAX],index=0;
	while(n!=0){
		res[index++]=n%radix;
		n/=radix;
	}
}
//判断一个高精度数是否是一个回文数
bool judge(bign a){
	for(int i=0;i<a.len/2;i++){
		if(a.d[i]!=a.d[a.len-1-i]) return false;
	}
	return true;
}

//将字符串转化成数字，作为唯一标识
int change(char str[]){
	int ans=0;
	for(int i=0;i<len;i++){
		ans=ans*26+(str[i]-'0');
	}
	return ans;
}

//字符串使用字典序排列
bool cmp(int a,int b){
	return strcmp(name[a],name[b])<0;
}

//map与string的初始化
string int_to_str;
map<char,int> str_to_int;
for(int=0;i<n;i++){
	int_to_str[i]=name[i];
	str_to_int[name[i]]=i;
}

//败者树问题队列实现
void baizheshu(){
	queue<int> q;
	while(n--){
		q.push(i++);
	}
	while(q.size()!=1){
		int group=n/ng;
		if(group%ng!=0) group++;
		for(int i=0;i<group;i++){
			int k=q.front();
			for(int j=0;j<ng;j++){
				int temp=q.front();
				if(mouse[temp]>mouse[k]){
					k=temp;
				}
				mouse[temp].rank=group+1;
				q.pop();
			}
			q.push(k);
		}
		n=group;
	}
	mouse[q.front].rank=1;
}

//静态链表获取有效结点
struct Node{
	int data,next;
	bool flag;
}node[MAX];

bool cmp(Node a,Node b){
	if(a.flag==false||b.flag==false) return a.flag>b.flag;
	else{
		return a.data<b.data;
	}
}
for(int i=0;i<n;i++){
	node[i].flag=false;
}

int p=head,cnt=0;
while(p!=-1){
	node[p].flag=true;
	cnt++;
	p=node[p].next;
}
sort(node,node+MAX,cmp);

for(int i=0;i<cnt;i++){
	,,,,,,,
}
//树的DFS
vector<int> child[MAX];
void DFS(int root,int height){
	if(child[root].size()==0){
		if(height>maxheight){
			maxheight=height;
			num=1;
		}
		else if(height==maxheight){
			num++;
		}
		return;//到达了边界一定要return
	}
	for(int i=0;i<child[root].size();i++){
		DFS(child[root][i],height+1);
	}
}
