# Matrix53's Template

[TOC]

## C++与 STL

### 快读快写

```c++
//整数快速读入快速输出，__int128适用
template<typename T>
inline void read(T &a){
    bool neg=false;
    char t=getchar();
    a=0;
    while(!isdigit(t)){if(t=='-') neg=true; t=getchar();}
    while(isdigit(t)){a=(a<<1)+(a<<3)+(t^48); t=getchar();}
    if(neg) a=-a;
}
template<typename T>
void _print(T a){
    if(a>0){
        _print(a/10);
        putchar(a%10+'0');
    }
}
template<typename T>
inline void print(T a){
    if(a==0){putchar('0'); return;}
    if(a<0){putchar('-'); a=-a;}
    _print(a);
}
```

## 算法思想

## 数据结构

### 基础结构

```c++
//小根堆
const int N=1e6+5;
int heap[N],p;
int top(){return heap[1];}
void pop(){
    heap[1]=heap[p--];
    int now=1;
    while(now<p){
        int rec=(now<<1);
        if(rec>p) break;
        if((rec+1<=p)&&(heap[rec]>heap[rec+1])) ++rec;
        if(heap[rec]>heap[now]) break;
        swap(heap[rec],heap[now]);
        now=rec;
    }
}
void push(int x){
    heap[++p]=x;
    int now=p;
    while(now>1){
        int rec=(now>>1);
        if(heap[rec]>heap[now]) swap(heap[rec],heap[now]);
        else break;
        now=rec;
    }
}
```

### 主席树

```c++
//不建空树的主席树，查询区间第k小，需要将数据离散化
const int C=2e5+5;
int root[C],cnt;
struct node{
    int l,r,sum;
}ct[C*20];
void update(int l,int r,int old,int &now,int pos){
    ct[++cnt]=ct[old];ct[cnt].sum++;now=cnt;
    if(l==r) return;
    int mid=(l+r)>>1;
    if(mid>=pos) update(l,mid,ct[old].l,ct[cnt].l,pos);
    else update(mid+1,r,ct[old].r,ct[cnt].r,pos);
}
int query(int l,int r,int old,int now,int k){
    if(l==r) return l;
    int num=ct[ct[now].l].sum-ct[ct[old].l].sum;
    int mid=(l+r)>>1;
    if(num>=k) return query(l,mid,ct[old].l,ct[now].l,k);
    else return query(mid+1,r,ct[old].r,ct[now].r,k-num);
}
```

### 并查集

```c++
const int maxn=100005;
int u[maxn],h[maxn],n;
void init(){
    for(int i=1;i<=n;++i){u[i]=i; h[i]=0;}
}
int find(int x){
    int r=x;
    while(u[r]!=r) r=u[r];
    int i=x,j;
    while(i!=r){j=u[i]; u[i]=r; i=j;}
    return r;
}
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(h[x]==h[y]){h[x]++; u[y]=x;}
    else{
        if(h[x]<h[y]) u[x]=y;
        else u[y]=x;
    }
}
```

### 线段树

```c++
//线段树，带懒惰标记的堆式储存，下标从1开始
const int C=100005;
struct node{
    int l,r;
    long long val;
}st[C<<2];
long long lazy[C<<2],data[C];
void build(int s,int t,int p){
    st[p].l=s;st[p].r=t;
    if(s==t){
        st[p].val=data[s];
        return;
    }
    int mid=(s+t)/2;
    build(s,mid,2*p);
    build(mid+1,t,2*p+1);
    st[p].val=st[2*p].val+st[2*p+1].val;
}
void update(int s,int t,int p,long long inc){
    node &tmp=st[p];
    if(s<=tmp.l&&tmp.r<=t){
        tmp.val+=inc*(tmp.r-tmp.l+1);
        lazy[p]+=inc;
        return;
    }
    int mid=(tmp.l+tmp.r)/2;
    if(tmp.l!=tmp.r&&lazy[p]){
        lazy[2*p]+=lazy[p];
        lazy[2*p+1]+=lazy[p];
        st[2*p].val+=lazy[p]*(mid-tmp.l+1);
        st[2*p+1].val+=lazy[p]*(tmp.r-mid);
        lazy[p]=0;
    }
    if(s<=mid) update(s,t,2*p,inc);
    if(mid<t) update(s,t,2*p+1,inc);
    tmp.val=st[2*p].val+st[2*p+1].val;
}
long long query(int s,int t,int p){
    node &tmp=st[p];
    if(s<=tmp.l&&tmp.r<=t) return tmp.val;
    int mid=(tmp.l+tmp.r)/2;
    if(lazy[p]){
        lazy[2*p]+=lazy[p];
        lazy[2*p+1]+=lazy[p];
        st[2*p].val+=lazy[p]*(mid-tmp.l+1);
        st[2*p+1].val+=lazy[p]*(tmp.r-mid);
        lazy[p]=0;
    }
    long long ans=0;
    if(s<=mid) ans=query(s,t,2*p);
    if(t>mid) ans+=query(s,t,2*p+1);
    return ans;
}
```

### 树状数组

```c++
//单点修改，区间查询(区间修改，单点查询可用差分数组实现)
typedef long long ll;
const int C=100005;
ll bit[C];
int lowbit(int x){return x&(-x);}
void add(int id,ll val){
    for(int i=id;i<=C;i+=lowbit(i)){bit[i]+=val;}
}
ll query(int x){
    ll ans=0;
    while(x>=1){ans+=bit[x]; x-=lowbit(x);}
    return ans;
}
```

### Splay 树

```c++
const int N=1e5+5;
int rt,tot,fa[N],ch[N][2],val[N],cnt[N],sz[N];
struct Splay{
	void pushup(int x){sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+cnt[x];}
	bool get(int x){return x==ch[fa[x]][1];}
	void clear(int x){ch[x][0]=ch[x][1]=fa[x]=val[x]=sz[x]=cnt[x]=0;}
	void rotate(int x){
		int y=fa[x],z=fa[y],chk=get(x);
		ch[y][chk]=ch[x][chk^1];
		fa[ch[x][chk^1]]=y;
		ch[x][chk^1]=y;
		fa[y]=x;
		fa[x]=z;
		if(z) ch[z][y==ch[z][1]]=x;
		pushup(y);
	}
	void splay(int x){
		for(int f=fa[x];f;rotate(x),f=fa[x])
			if(fa[f]) rotate(get(x)==get(f)?f:x);
		rt=x;
	}
	void ins(int k){
		if(!rt){
			val[++tot]=k;
			cnt[tot]++;
			rt=tot;
			pushup(rt);
			return;
		}
		int cur=rt,f=0;
		while(true){
			if(val[cur]==k){
				cnt[cur]++;
				pushup(cur);
				pushup(f);
				splay(cur);
				break;
			}
			f=cur;
			cur=ch[cur][val[cur]<k];
			if(!cur){
				val[++tot]=k;
				cnt[tot]++;
				fa[tot]=f;
				ch[f][val[f]<k]=tot;
				pushup(tot);
				pushup(f);
				splay(tot);
				break;
			}
		}
	}
	int rk(int k){
		int res=0,cur=rt;
		while(true){
			if(k<val[cur]){
				cur=ch[cur][0];
			}else{
				res+=sz[ch[cur][0]];
				if(k==val[cur]){
					splay(cur);
					return res+1;
				}
				res+=cnt[cur];
				cur=ch[cur][1];
			}
		}
	}
	int kth(int k){
		int cur=rt;
		while(true){
			if(ch[cur][0]&&k<=sz[ch[cur][0]]){
				cur=ch[cur][0];
			}else{
				k-=cnt[cur]+sz[ch[cur][0]];
				if(k<=0){
					splay(cur);
					return val[cur];
				}
				cur=ch[cur][1];
			}
		}
	}
	int pre(){
		int cur=ch[rt][0];
		while(ch[cur][1]) cur=ch[cur][1];
		splay(cur);
		return cur;
	}
	int nxt(){
		int cur=ch[rt][1];
		while(ch[cur][0]) cur=ch[cur][0];
		splay(cur);
		return cur;
	}
	void del(int k){
		rk(k);
		if(cnt[rt]>1){
			cnt[rt]--;
			pushup(rt);
			return;
		}
		if(!ch[rt][0]&&!ch[rt][1]){
			clear(rt);
			rt=0;
			return;
		}
		if(!ch[rt][0]){
			int t=rt;
			rt=ch[rt][1];
			fa[rt]=0;
			clear(t);
			return;
		}
		if(!ch[rt][1]){
			int t=rt;
			rt=ch[rt][0];
			fa[rt]=0;
			clear(t);
			return;
		}
		int t=rt;
		int x=pre();
		fa[ch[t][1]]=x;
		ch[x][1]=ch[t][1];
		clear(t);
		pushup(rt);
	}
};
```

## 搜索

## 动态规划

### 背包问题

```c++
struct node{
    int pos,value;
}que[30005];
int ans[30005],V;
inline void zeroOnePack(int weight,int value){
    int i,tmp;
    for(i=V;i>=weight;--i){
        tmp=ans[i-weight]+value;
        if(tmp>ans[i]) ans[i]=tmp;
    }
}
inline void completePack(int weight,int value){
    int i,tmp;
    for(i=weight;i<=V;++i){
        tmp=ans[i-weight]+value;
        if(tmp>ans[i]) ans[i]=tmp;
    }
}
inline void multiplePack(int weight,int value,int num){
    if(num*weight>=V) completePack(weight,value);
    else{
        int mod,k;
        for(mod=0;mod<weight;++mod){
            int head=0,tail=0;
            for(k=0;k<=(V-mod)/weight;++k){
                int x=k;
                int y=ans[mod+k*weight]-k*value;
                while(head<tail&&que[tail-1].value<=y) tail--;
                while(head<tail&&que[head].pos<k-num) head++;
                que[tail].pos=x;
                que[tail].value=y;
                tail++;
                ans[mod+k*weight]=que[head].value+k*value;
            }
        }
    }
}
```

## 字符串

### 字符串哈希

```c++
//使用时注意取模
unsigned int BKDRHash(char *s){
    unsigned int seed=31,key=0;
    while(*s) key=key*seed+(*s++);
    return key&0x7fffffff;
}
```

### 字典树

```c++
//前缀字典树
const int maxv=1e5+5;
struct Trie{
    int tr[maxv][26],tot;
    int cnt[maxv];
    void insert(char *s){
        int p=0;
        for(int i=0;s[i];++i){
            int n=s[i]-'a';
            if(!tr[p][n]) tr[p][n]=++tot;
            p=tr[p][n];
            cnt[p]++;
        }
    }
    int find(char *s){
        int p=0;
        for(int i=0;s[i];++i){
            int n=s[i]-'a';
            if(!tr[p][n]) return 0;
            p=tr[p][n];
        }
        return cnt[p];
    }
};
```

### KMP

```c++
const int maxl=1e6+5;
int fail[maxl];
void getFail(char *p,int plen){
    fail[0]=0;fail[1]=0;
    for(int i=1;i<plen;++i){
        int j=fail[i];
        while(j>0&&p[i]!=p[j]) j=fail[j];
        fail[i+1]=(p[i]==p[j]?j+1:0);
    }
}
void kmp(char *p,char *s,int plen,int slen){
    int last=-1;
    getFail(p,plen);
    int j=0;
    for(int i=0;i<slen;++i){
        while(j&&s[i]!=p[j]) j=fail[j];
        if(s[i]==p[j]) ++j;
        if(j==plen){
            //该匹配在s中的起点为i+1-plen，末尾为i
        }
    }
}
```

### AC 自动机

```c++
const int maxv=1e6+5;
struct AC{
    int tr[maxv][26],tot;
    int cnt[maxv],fail[maxv];
    void insert(char *p){
        int u=0;
        for(int i=0;p[i];++i){
            if(!tr[u][p[i]-'a']) tr[u][p[i]-'a']=++tot;
            u=tr[u][p[i]-'a'];
        }
        cnt[u]++;
    }
    void getFail(){
        queue<int> q;
        for(int i=0;i<26;++i)
            if(tr[0][i]) q.push(tr[0][i]);
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(int i=0;i<26;++i){
                if(tr[u][i]){
                    fail[tr[u][i]]=tr[fail[u]][i];
                    q.push(tr[u][i]);
                }else{
                    tr[u][i]=tr[fail[u]][i];
                }
            }
        }
    }
    int query(char *s){
        int u=0,res=0;
        for(int i=0;s[i];++i){
            u=tr[u][s[i]-'a'];
            for(int j=u;j&&cnt[j]!=-1;j=fail[j]){
                res+=cnt[j]; cnt[j]=-1;
            }
        }
        return res;
    }
};
```

### 后缀数组

```c++
const int N=2e5+5;
//n为字符串长度，m-1为字符串ASCII码的最大值
int sa[N],cnt[N],t1[N],t2[N];
void getSa(char *s,int n,int m){
    int i,*x=t1,*y=t2;
    for(i=0;i<m;++i) cnt[i]=0;
    for(i=0;i<n;++i) cnt[x[i]=s[i]]++;
    for(i=1;i<m;++i) cnt[i]+=cnt[i-1];
    for(i=n-1;i>=0;--i) sa[--cnt[x[i]]]=i;
    for(int k=1;k<=n;k<<=1){
        int p=0;
        for(i=n-k;i<n;++i) y[p++]=i;
        for(i=0;i<n;++i) if(sa[i]>=k) y[p++]=sa[i]-k;
        for(i=0;i<m;++i) cnt[i]=0;
        for(i=0;i<n;++i) cnt[x[y[i]]]++;
        for(i=1;i<m;++i) cnt[i]+=cnt[i-1];
        for(i=n-1;i>=0;--i) sa[--cnt[x[y[i]]]]=y[i];
        swap(x,y);
        p=1;x[sa[0]]=0;
        for(i=1;i<n;++i)
            x[sa[i]]=(y[sa[i-1]]==y[sa[i]])&&(y[sa[i-1]+k]==y[sa[i]+k])?p-1:p++;
        if(p>=n) break;
        m=p;
    }
}
int rk[N];
void getRk(int n){
    for(int i=0;i<n;++i) rk[sa[i]]=i;
}
int height[N];
void getHeight(char *s,int n){
    int k=0;
    for(int i=0;i<n;++i){
        if(k) k--;
        int j=sa[rk[i]-1];
        while(s[i+k]==s[j+k]) k++;
        height[rk[i]]=k;
    }
}
```

### 后缀自动机

```c++
struct state{
  int len,link;
  map<char,int> next;
};
const int maxv=1e5+5;
struct SAM{
    state st[maxv*2];
    int sz,last;
    void init(){
      st[0].len=0;
      st[0].link=-1;
      sz++;
      last=0;
    }
    void extend(char c){
        int cur=sz++;
        st[cur].len=st[last].len+1;
        int p=last;
        while(p!=-1&&!st[p].next.count(c)){
            st[p].next[c]=cur;
            p=st[p].link;
        }
        if(p==-1){
            st[cur].link=0;
        }else{
            int q=st[p].next[c];
            if(st[p].len+1==st[q].len){
                st[cur].link=q;
            }else{
                int clone=sz++;
                st[clone].len=st[p].len+1;
                st[clone].next=st[q].next;
                st[clone].link=st[q].link;
                while(p!=-1&&st[p].next[c]==q){
                    st[p].next[c]=clone;
                    p=st[p].link;
                }
                st[q].link=st[cur].link=clone;
            }
        }
        last=cur;
    }
};
```

### Manacher

```c++
const int maxl=1e5+5;
struct Manacher{
    int r[maxl<<1],len;
    char t[maxl<<1];
    int init(char *s){
        t[0]='$',t[1]='#';
        len=2;
        for(int i=0;s[i];++i)
            t[len++]=s[i],
            t[len++]='#';
        t[len]='\0';
        return len;
    }
    int solve(){
        int ans=-1,id=0,mx=0;
        for(int i=1;i<=len;++i){
            if(i<mx) r[i]=min(r[(id<<1)-i],mx-i);
            else r[i]=1;
            while(t[i-r[i]]==t[i+r[i]]) r[i]++;
            if(mx<i+r[i]) mx=i+r[i],id=i;
            ans=max(ans,r[i]-1);
        }
        return ans;
    }
};
```

### 最小表示法

```c++
int solve(char *s,int n){
    int k=0,i=0,j=1;
    while(k<n&&i<n&&j<n){
        if(s[(i+k)%n]==s[(j+k)%n]){++k;}
        else{
            if(s[(i+k)%n]>s[(j+k)%n]) i=i+k+1;
            else j=j+k+1;
            if(i==j) ++i;
            k=0;
        }
    }
    return min(i,j);
}
```

## 数学

### 高精度

```c++
//高精度非负整数
#define MAXN 9999
#define MAXSIZE 1010
#define DLEN 4
struct BigNum{
    int a[500];
    int len;
    BigNum();
    BigNum(const int);
    BigNum(const char*,int);
    BigNum(const char*);
    BigNum(const BigNum&);
    BigNum& operator=(const BigNum&);
    friend istream& operator>>(istream&,BigNum&);
    friend ostream& operator<<(ostream&,BigNum&);
    BigNum operator+(const BigNum&)const;
    BigNum operator-(const BigNum&)const;
    BigNum operator*(const BigNum&)const;
    BigNum operator/(const int&)const;
    BigNum operator^(const int&)const;
    int operator%(const int&)const;
    bool operator>(const BigNum&)const;
    bool operator>(const int&)const;
    void print();
};
BigNum::BigNum(){
  len=1;
  memset(a,0,sizeof(a));
}
BigNum::BigNum(const int b){
    int c,d=b;
    len=0;
    memset(a,0,sizeof(a));
    while(d>MAXN){
        c=d-(d/(MAXN+1))*(MAXN+1);
        d=d/(MAXN+1);
        a[len++]=c;
    }
    a[len++]=d;
}
BigNum::BigNum(const char *s,int L){
  	int t,k,index=0,i;
  	memset(a,0,sizeof(a));
  	len=L%DLEN? L/DLEN+1:L/DLEN;
  	for (i=L-1;i>=0;i-=DLEN){
    	k=max(0,i-DLEN+1),t=0;
    	for(int j=k;j<=i;++j) t=t*10+s[j]-'0';
    	a[index++]=t;
  	}
}
BigNum::BigNum(const char *s){BigNum(s,strlen(s));}
BigNum::BigNum(const BigNum &T):len(T.len){
    memset(a,0,sizeof(a));
    for(int i=0;i<len;++i) a[i]=T.a[i];
}
BigNum& BigNum::operator=(const BigNum &n){
    len=n.len;
    memset(a,0,sizeof(a));
    for(int i=0;i<len;++i) a[i]=n.a[i];
    return *this;
}
//输入不能有前导0
istream& operator>>(istream &in,BigNum &b){
    char ch[MAXSIZE<<2];
    in>>ch;
    int L=strlen(ch);
    int cnt=0,sum;
    for(int i=L-1;i>=0;){
        sum=0;
        int t=1;
        for(int j=0;j<4&&i>=0;++j,--i,t*=10) sum+=(ch[i]-'0')*t;
        b.a[cnt]=sum;
        cnt++;
    }
    b.len=cnt++;
    return in;
}
ostream& operator<<(ostream &out,BigNum &b){
    out<<b.a[b.len-1];
    for(int i=b.len-2;i>=0;--i) printf("%04d",b.a[i]);
    return out;
}
BigNum BigNum::operator+(const BigNum &T)const{
    BigNum t(*this);
    int big=T.len>len? T.len:len;
    for(int i=0;i<big;++i){
        t.a[i]+=T.a[i];
        if(t.a[i]>MAXN){
            t.a[i+1]++;
            t.a[i]-=MAXN+1;
        }
    }
    t.len=t.a[big]? big+1:big;
    return t;
}
BigNum BigNum::operator-(const BigNum &T)const{
    bool flag;
    BigNum t1,t2;
    if(*this>T){t1=*this; t2=T; flag=0;}
    else{t1=T; t2=*this; flag=1;}
    int big=t1.len;
    for(int i=0;i<big;++i){
        if(t1.a[i]<t2.a[i]){
            int j=i+1;
            while(t1.a[j]==0) ++j;
            t1.a[j--]--;
            while(j>i) t1.a[j--]+=MAXN;
            t1.a[i]+=MAXN+1-t2.a[i];
        }
        else t1.a[i]-=t2.a[i];
    }
    while(t1.a[big-1]==0&&big>1) --big;
    t1.len=big;
    if(flag) t1.a[big-1]=-t1.a[big-1];
    return t1;
}
BigNum BigNum::operator*(const BigNum &T)const{
    BigNum ret;
    int i,j,up,tmp1,tmp2;
    for(i=0;i<len;++i){
        up=0;
        for(j=0;j<T.len;++j){
            tmp1=a[i]*T.a[j]+ret.a[i+j]+up;
            if(tmp1>MAXN){
                tmp2=tmp1%(MAXN+1);
                up=tmp1/(MAXN+1);
                ret.a[i+j]=tmp2;
            }
            else{
                up=0;
                ret.a[i+j]=tmp1;
            }
        }
        if(up) ret.a[i+j]=up;
    }
    ret.len=i+j;
    while(ret.a[ret.len-1]==0&&ret.len>1) --ret.len;
    return ret;
}
BigNum BigNum::operator/(const int &b)const{
    BigNum ret;
    int i,down=0;
    for(i=len-1;i>=0;--i){
        ret.a[i]=(a[i]+down*(MAXN+1))/b;
        down=a[i]+down*(MAXN+1)-ret.a[i]*b;
    }
    ret.len=len;
    while(ret.a[ret.len-1]==0&&ret.len>1) --ret.len;
    return ret;
}
int BigNum::operator%(const int &b)const{
    int i,d=0;
    for(i=len-1;i>=0;--i) d=((d*(MAXN+1))%b+a[i])%b;
    return d;
}
//n次幂，n必须大于等于0
BigNum BigNum::operator^(const int &n)const{
    BigNum t(*this),ret(1);
    for(int m=n;m;m>>=1){
        if(m&1) ret=ret*t;
        t=t*t;
    }
    return ret;
}
bool BigNum::operator>(const BigNum &T)const{
    if(len!=T.len) return len>T.len;
    int tmp=len-1;
    while(a[tmp]==T.a[tmp]&&tmp>=0) --tmp;
    return tmp>=0&&a[tmp]>T.a[tmp];
}
bool BigNum::operator>(const int &t)const{
    BigNum b(t);
    return *this>b;
}
void BigNum::print(){
    printf("%d",a[len-1]);
    for(int i=len-2;i>=0;--i) printf("%04d",a[i]);
}
```

### 多项式

```c++
//快速傅里叶变换(FFT)
const double PI=acos(-1.0);
struct Complex{
    double x,y;
    Complex(double _x=0.0,double _y=0.0){
        x=_x;
        y=_y;
    }
    Complex operator-(const Complex &b)const{
        return Complex(x-b.x, y-b.y);
    }
    Complex operator+(const Complex &b)const{
        return Complex(x+b.x,y+b.y);
    }
    Complex operator*(const Complex &b)const{
        return Complex(x*b.x-y*b.y,x*b.y+y*b.x);
    }
};
/**
 * 进行FFT和IFFT前的反置变换
 * 位置i和i的二进制反转后的位置互换
 * len必须为2的幂
 */
void change(Complex y[],int len){
    int i,j,k;
    for(int i=1,j=len/2;i<len-1;i++){
        if(i<j) swap(y[i],y[j]);
        // 交换互为小标反转的元素，i<j保证交换一次
        // i做正常的+1，j做反转类型的+1，始终保持i和j是反转的
        k=len/2;
        while(j>=k){
            j=j-k;
            k>>=1;
        }
        if(j<k) j+=k;
    }
}
/**
 * 做FFT，最低幂次项在0处
 * len必须是2^k形式
 * on==1时是DFT，on==-1时是IDFT
 */
void fft(Complex y[],int len,int on){
    change(y,len);
    for(int h=2;h<=len;h<<=1){
        Complex wn(cos(2*PI/h),sin(on*2*PI/h));
        for(int j=0;j<len;j+=h){
            Complex w(1,0);
            for(int k=j;k<j+h/2;k++){
                Complex u=y[k];
                Complex t=w*y[k+h/2];
                y[k]=u+t;
                y[k+h/2]=u-t;
                w=w*wn;
            }
        }
    }
    if(on==-1){
        for(int i=0;i<len;++i){
            y[i].x/=len;
            y[i].x=int(y[i].x+0.5);
        }
    }
}
```

## 图论

### 单源最短路

```c++
//SPFA算法，使用前必须调用init，有addedge函数
typedef long long ll;
const ll inf=LLONG_MAX/2;
const int maxv=1e6+5;
const int maxe=1e6+5;
struct _edge{
    int to,next;
    ll w;
}edge[maxe];
int n,m,cnt,head[maxv];
int neg[maxv],pre[maxv];
bool inq[maxv];
ll dis[maxv];
void print_path(int s,int t){
    if(s==t){printf("%d ",s); return;}
    print_path(s,pre[t]);
    printf("%d ",t);
}
void init(){
    for(int i=0;i<maxe;++i) edge[i].next=-1;
    for(int i=0;i<maxv;++i) head[i]=-1;
    cnt=0;
}
void addedge(int u,int v,ll w){
    edge[cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
int spfa(int s){
    memset(neg,0,sizeof(neg));
    neg[s]=1;
    for(int i=1;i<=n;++i){
        dis[i]=inf;
        inq[i]=false;
    }
    dis[s]=0;
    queue<int> q;
    q.push(s);
    inq[s]=true;
    while(!q.empty()){
        int u=q.front();q.pop();
        inq[u]=false;
        for(int i=head[u];~i;i=edge[i].next){
            int v=edge[i].to;
            ll w=edge[i].w;
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                pre[v]=u;
                if(!inq[v]){
                    inq[v]=true;
                    q.push(v);
                    neg[v]++;
                    if(neg[v]>n) return 1;
                }
            }
        }
    }
    return 0;
}
//Dijkstra算法，没有addedge函数，但是无需初始化
typedef long long ll;
const ll inf=LLONG_MAX/2;
const int maxv=1e5+5;
struct edge{
    int to;
    ll w;
    edge(int a,ll b):to(a),w(b){}
};
struct qnode{
    int id;
    ll ndis;
    qnode(int a,ll b):id(a),ndis(b){}
    bool operator<(const qnode &a)const{
        return ndis>a.ndis;
    }
};
vector<edge> g[maxv];
int n,m,pre[maxv];
ll dis[maxv];
bool done[maxv];
void print_path(int s,int t){
    if(s==t){printf("%d ",s); return;}
    print_path(s,pre[t]);
    printf("%d ",t);
}
void dijkstra(int s){
    for(int i=1;i<=n;++i){dis[i]=inf; done[i]=false;}
    dis[s]=0;
    priority_queue<qnode> q;
    q.push(qnode(s,0));
    while(!q.empty()){
        qnode u=q.top();
        q.pop();
        if(done[u.id]) continue;
        done[u.id]=true;
        for(auto v:g[u.id]){
            if(done[v.to]) continue;
            if(dis[v.to]>u.ndis+v.w){
                dis[v.to]=u.ndis+v.w;
                q.push(qnode(v.to,dis[v.to]));
                pre[v.to]=u.id;
            }
        }
    }
}
```

### 最大流

```c++
//Dinic算法
typedef long long ll;
const int N=1e4+5,M=2e5+5;
const ll inf=LLONG_MAX;
int tot=1,lnk[N],ter[M],nxt[M],dep[N],cur[N];
ll val[M];
void add(int u,int v,ll w){
  ter[++tot]=v;
  nxt[tot]=lnk[u];
  lnk[u]=tot;
  val[tot]=w;
}
void addedge(int u,int v,ll w){
    add(u,v,w);
    add(v,u,0);
}
int bfs(int s,int t){
    memset(dep,0,sizeof(dep));
    memcpy(cur,lnk,sizeof(lnk));
    queue<int> q;
    q.push(s);
    dep[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=lnk[u];i;i=nxt[i]){
            int v=ter[i];
            if(val[i]&&!dep[v]){
                q.push(v);
                dep[v]=dep[u]+1;
            }
        }
    }
    return dep[t];
}
ll dfs(int u,int t,ll flow){
    if(u==t) return flow;
    ll ans=0;
    for(int &i=cur[u];i&&ans<flow;i=nxt[i]){
        int v=ter[i];
        if(val[i]&&dep[v]==dep[u]+1){
            ll x=dfs(v,t,min(val[i],flow-ans));
            if(x){
                val[i]-=x;
                val[i^1]+=x;
                ans+=x;
            }
        }
    }
  if(ans<flow) dep[u]=-1;
  return ans;
}
ll dinic(int s,int t){
    ll ans=0;
    while(bfs(s,t)){
        ll x;
        while((x=dfs(s,t,inf))) ans+=x;
    }
    return ans;
}
```

### 二分图匹配

```c++
//匈牙利(Hungary)算法
template<typename T>
struct hungary{
    int n;
    vector<int> matchx; //左集合对应的匹配点
    vector<int> matchy; //右集合对应的匹配点
    vector<int> pre; //连接右集合的左点
    vector<bool> visx; //拜访数组左
    vector<bool> visy; //拜访数组右
    vector<T> lx;
    vector<T> ly;
    vector<vector<T>> g;
    vector<T> slack;
    T inf;
    T res;
    queue<int> q;
    int org_n;
    int org_m;
    hungary(){}
    hungary(int _n,int _m){ //n和m为二分图两个集合中的顶点数 下标从0开始
        org_n=_n;
        org_m=_m;
        n=max(_n,_m);
        inf=numeric_limits<T>::max();
        res=0;
        g=vector<vector<T>>(n,vector<T>(n));
        matchx=vector<int>(n,-1);
        matchy=vector<int>(n,-1);
        pre=vector<int>(n);
        visx=vector<bool>(n);
        visy=vector<bool>(n);
        lx=vector<T>(n,-inf);
        ly=vector<T>(n);
        slack=vector<T>(n);
    }
    //从左集合u向右集合v连边
    //负值还不如不匹配 因此设为0不影响
    void addEdge(int u,int v,int w){g[u][v]=max(w,0);}
    bool check(int v){
        visy[v]=true;
        if(matchy[v]!=-1){
            q.push(matchy[v]);
            visx[matchy[v]]=true;  // in S
            return false;
        }
        //找到新的未匹配点 更新匹配点 pre数组记录着"非匹配边"上与之相连的点
        while(v!=-1){
            matchy[v]=pre[v];
            swap(v,matchx[pre[v]]);
        }
        return true;
    }
    void bfs(int i){
        while(!q.empty()) q.pop();
        q.push(i);
        visx[i]=true;
        while(true){
            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(int v=0;v<n;v++){
                    if(!visy[v]){
                        T delta=lx[u]+ly[v]-g[u][v];
                        if(slack[v]>=delta){
                            pre[v]=u;
                            if(delta) slack[v]=delta;
                            else if(check(v)) return; //delta=0代表有机会加入相等子图 找增广路 找到就return 重建交错树
                        }
                    }
                }
            }
            //没有增广路 修改顶标
            T a=inf;
            for(int j=0;j<n;j++){
                if(!visy[j]) a=min(a,slack[j]);
            }
            for(int j=0;j<n;j++){
                if(visx[j]) lx[j]-=a; //S
                if(visy[j]) ly[j]+=a; //T
                else slack[j]-=a; //T'
            }
            for(int j=0;j<n;j++){
                if(!visy[j]&&slack[j]==0&&check(j)) return;
            }
        }
    }
    void solve(){
        //初始顶标
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                lx[i]=max(lx[i],g[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            fill(slack.begin(),slack.end(),inf);
            fill(visx.begin(),visx.end(),false);
            fill(visy.begin(),visy.end(),false);
            bfs(i);
        }
        //custom
        for(int i=0;i<n;i++){
            if(g[i][matchx[i]]>0) res+=g[i][matchx[i]];
            else matchx[i]=-1;
        }
        cout<<res<<"\n";
        for(int i=0;i<org_n;i++) cout<<matchx[i]+1<<" ";
        cout<<"\n";
    }
};
```

### 树上问题

```c++
//树链剖分：重链剖分
const int maxv=500005;
const int maxe=500005<<1;
int to[maxe],nxt[maxe],head[maxv],cur; //链式前向星建树
int fa[maxv],dep[maxv],siz[maxv],hson[maxv]; //dfs1中更新的对象
int top[maxv],dfn[maxv],rnk[maxv],tot; //dfs2中更新的对象
inline void _addedge(int x,int y){
    ++cur;
    nxt[cur]=head[x];
    head[x]=cur;
    to[cur]=y;
}
inline void addedge(int x,int y){
    _addedge(x,y);
    _addedge(y,x);
}
int dfs1(int now,int d){
    dep[now]=d;
    siz[now]=1;
    for(int i=head[now];i;i=nxt[i]){
        int tmp=to[i];
        if(siz[tmp]) continue;
        siz[now]+=dfs1(tmp,d+1);
        fa[tmp]=now;
        if(siz[tmp]>siz[hson[now]]) hson[now]=tmp;
    }
    return siz[now];
}
void dfs2(int now,int t){
    top[now]=t;
    ++tot;
    dfn[now]=tot;
    rnk[tot]=now;
    if(hson[now]){
        dfs2(hson[now],t);
        for(int i=head[now];i;i=nxt[i]){
            int tmp=to[i];
            if(top[tmp]) continue;
            if(tmp!=hson[now]) dfs2(tmp,tmp);
        }
    }
}
int lca(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]>dep[top[y]]) x=fa[top[x]];
        else y=fa[top[y]];
    }
    return dep[x]>dep[y]? y:x;
}
```

## 计算几何

### 浮点运算

```c++
const double pi=acos(-1.0);
const double eps=1e-8;
const int maxp=1010;
int sgn(double x){
    if(fabs(x)<eps) return 0;
    return x>0? 1:-1;
}
int dcmp(double x,double y){
    if(fabs(x-y)<eps) return 0;
    return x<y? -1:1;
}
```

### 点和线

```c++
struct Point{
    double x,y;
    Point():x(0),y(0){}
    Point(double a,double b):x(a),y(b){}
    Point operator+(Point a){return Point(x+a.x,y+a.y);}
    Point operator-(Point a){return Point(x-a.x,y-a.y);}
    Point operator*(double k){return Point(k*x,k*y);}
    Point operator/(double k){return Point(x/k,y/k);}
    bool operator==(const Point& a)const{return sgn(x-a.x)==0&&sgn(y-a.y)==0;}
    bool operator<(const Point& a)const{
        return sgn(x-a.x)<0||(sgn(x-a.x)==0&&sgn(y-a.y)<0);
    }
};
bool cmpx(Point a,Point b){return a.x<b.x;}
bool cmpy(Point a,Point b){return a.y<b.y;}
double dis(Point a,Point b){return hypot(a.x-b.x,a.y-b.y);}
typedef Point Vector;
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double det(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
double len(Vector a){return hypot(a.x,a.y);}
double len2(Vector a){return dot(a,a);}
//两个向量的夹角
double angle(Vector a,Vector b){return acos(dot(a,b)/len(a)/len(b));}
//向量A的单位法向量
Vector normal(Vector a){return Vector(-a.y/len(a),a.x/len(a));}
//向量A逆时针旋转rad弧度
Vector rotate(Vector a,double rad){
    return Vector(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));
}
bool isParallel(Vector a,Vector b){return sgn(det(a,b))==0;}
struct Line{
    Point p1,p2;
    Line(){}
    Line(Point a,Point b):p1(a),p2(b){}
    Line(Point p,double angle){
        p1=p;
        if(sgn(angle-pi/2)==0) p2=p1+Point(0,1);
        else p2=p1+Point(1,tan(angle));
    }
    //ax+by+c=0
    Line(double a,double b,double c){
        if(sgn(a)==0){
            p1=Point(0,-c/b);
            p2=Point(1,-c/b);
        }else if(sgn(b)==0){
            p1=Point(-c/a,0);
            p2=Point(-c/a,1);
        }else{
            p1=Point(0,-c/b);
            p2=Point(1,(-c-a)/b);
        }
    }
};
typedef Line Segment;
//返回直线倾斜角，0≤angle<pi
double angle(Line a){
    double k=atan2(a.p2.y-a.p1.y,a.p2.x-a.p1.x);
    if(sgn(k)<0) k+=pi;
    if(sgn(k-pi)==0) k-=pi;
    return k;
}
//点和线段的关系：0为在线段延长线上，1为线段端点，2为在线段上，3为左侧，4为右侧
int relation(Point p,Segment s){
    int sign=sgn(det(s.p2-s.p1,p-s.p1));
    if(sign) return sign>0? 3:4;
    sign=sgn(dot(s.p2-p,s.p1-p));
    if(sign) return sign>0? 0:2;
    return 1;
}
//两直线的关系：0为平行，1为重合，2为相交
int relation(Line a,Line b){
    int sign=sgn(det(a.p2-a.p1,b.p2-b.p1));
    if(sign) return 2;
    sign=sgn(det(a.p1-b.p1,a.p1-b.p2));
    return sign? 0:1;
}
//点到直线的距离
double dis(Point p,Line l){
    return fabs(det(p-l.p1,l.p2-l.p1))/dis(l.p1,l.p2);
}
//点在直线上的投影
Point projection(Point p,Line l){
    double k=dot(l.p2-l.p1,p-l.p1)/len2(l.p2-l.p1);
    return l.p1+(l.p2-l.p1)*k;
}
//点关于直线的对称点
Point symmetry(Point p,Line l){
    Point q=projection(p,l);
    return Point(2*q.x-p.x,2*q.y-p.y);
}
//两条直线的交点，在调用前要保证两条直线不平行且不重合
Point cross(Line a,Line b){
    double s1=det(a.p2-a.p1,b.p1-a.p1);
    double s2=det(a.p2-a.p1,b.p2-a.p1);
    Point a=normal(a.p1);
    return Point(b.p1.x*s2-b.p2.x*s1,b.p1.y*s2-b.p2.y*s1)/(s2-s1);
}
```

### 多边形

```c++
struct Polygon{
    int n;
    Point p[maxp];
    Line v[maxp];
};
//求点集p的凸包，结果存放在ch中，n为点集顶点数，v为凸包顶点数
int convexHull(Point *p,int n,Point *ch){
    sort(p,p+n);
    n=unique(p,p+n)-p;
    int v=0;
    for(int i=0;i<n;++i){
        while(v>1&&det(ch[v-1]-ch[v-2],p[i]-ch[v-2])<=0) v--;
        ch[v++]=p[i];
    }
    int j=v;
    for(int i=n-2;i>=0;i--){
        while(v>j&&det(ch[v-1]-ch[v-2],p[i]-ch[v-2])<=0) v--;
        ch[v++]=p[i];
    }
    if(n>1) v--;
    return v;
}
//旋转卡壳，求点集两点之间最长距离，ch为点集凸包，n为凸包顶点数
double longDis(Point *ch,int n){
    if(n==2) return dis(ch[0],ch[1]);
    int i=0,j=0;
    for(int k=0;k<n;++k){
        if(ch[k].x<ch[i].x) i=k;
        if(ch[j].x<ch[k].x) j=k;
    }
    double res=0;
    int si=i,sj=j;
    while(i!=sj||j!=si){
        res=max(res,dis(ch[i],ch[j]));
        if(det(ch[(i+1)%n]-ch[i],ch[(j+1)%n]-ch[j])<0) i=(i+1)%n;
        else j=(j+1)%n;
    }
    return res;
}
//点集内两点最短距离，[left,right]为当前区间，p为点集，t用于临时储存
//使用前需对p中的点按xy坐标排序
double shortDis(int left,int right,Point *p,Point *t){
    double ans=DBL_MAX;
    if(left==right) return ans;
    if(left+1==right) return dis(p[left],p[right]);
    int mid=(left+right)/2;
    ans=min(shortDis(left,mid,p,t),shortDis(mid+1,right,p,t));
    int k=0;
    for(int i=left;i<=right;++i){
        if(fabs(p[mid].x-p[i].x)<ans) t[k++]=p[i];
    }
    sort(t,t+k,cmpy);
    for(int i=0;i<k;++i){
        for(int j=i+1;j<k;++j){
            if(t[j].y-t[i].y>=ans) break;
            ans=min(ans,dis(t[i],t[j]));
        }
    }
    return ans;
}
//点和多边形的关系：3为点上，2为边上，1为内部，0为外部
int relation(Point pt,Point *p,int n){
    for(int i=0;i<n;++i){
        Line v=Line(p[i],p[(i+1)%n]);
        int k=relation(pt,v);
        if(k==1) return 3;
        if(k==2) return 2;
    }
    int num=0;
    for(int i=0;i<n;++i){
        int j=(i+1)%n;
        int c=sgn(det(pt-p[j],p[i]-p[j]));
        int u=sgn(p[i].y-pt.y);
        int v=sgn(p[j].y-pt.y);
        if(c>0&&u<0&&v>=0) num++;
        if(c<0&&u>=0&&v<0) num--;
    }
    return num!=0;
}
//多边形有向面积
double area(Point *p,int n){
    double s=0;
    for(int i=0;i<n;++i)
        ans+=det(p[i],p[(i+1)%n]);
    return s/2;
}
//多边形的重心
Point center(Point *p,int n){
    Point ans(0,0);
    double s=area(p,n);
    if(!sgn(s)) return ans;
    for(int i=0;i<n;++i)
        ans+=(p[i]+p[(i+1)%n])*det(p[i],p[(i+1)%n]);
    return ans/s/6;
}
```

### 圆

```c++
struct Circle{
    Point c;
    double r;
    Circle(){}
    Circle(Point p,double d):c(p),r(d){}
    Circle(double x,double y,double d){c=Point(x,y); r=d;}
};
//点和圆的关系：0为点在圆内，1为点在圆上，2为点在圆外
int relation(Point p,Circle C){
    double sign=sgn(dis(p,C.c)-C.r);
    if(sign) return sign>0? 2:0;
    return 1;
}
//直线和圆的关系：0为直线和圆相交，1为直线和圆相切，2为直线和圆相离
int relation(Line v,Circle C){
    int sign=sgn(dis(C.c,v)-C.r);
    if(sign) return sign>0? 2:0;
    return 1;
}
//直线和圆的交点，pa和pb为交点，返回值为交点个数
int cross(Line v,Circle C,Point &pa,Point &pb){
    double d=dis(C.c,v);
    if(d>C.r) return 0;
    Point q=projection(C.c,v);
    double k=sqrt(C.r*C.r-d*d);
    if(sgn(k)==0){
        pa=q;
        pb=q;
        return 1;
    }
    Point n=(v.p2-v.p1)/len(v.p2-v.p1);
    pa=q+n*k;
    pb=q-n*k;
    return 2;
}
```

### 三维几何

```c++
struct Point3{
    double x,y,z;
    Point3(){}
    Point3(double a,double b,double c):x(a),y(b),z(c){}
    Point3 operator+(Point3 a){return Point3(x+a.x,y+a.y,z+a.z);}
    Point3 operator-(Point3 a){return Point3(x-a.x,y-a.y,z-a.z);}
    Point3 operator*(double k){return Point3(x*k,y*k,z*k);}
    Point3 operator/(double k){return Point3(x/k,y/k,z/k);}
    bool operator==(const Point3 &a)const{
        return sgn(x-a.x)==0&&sgn(y-a.y)==0&&sgn(z-a.z)==0;
    }
};
typedef Point3 Vector3;
double dot(Vector3 a,Vector3 b){return a.x*b.x+a.y*b.y+a.z*b.z;}
Vector3 det(Vector3 a,Vector3 b){
    return Point3(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
}
double len(Vector3 a){return sqrt(dot(a,a));}
double len2(Vector3 a){return dot(a,a);}
double angle(Vector3 a,Vector3 b){return acos(dot(a,b)/len(a)/len(b));}
double area2(Point3 a,Point3 b,Point3 c){return len(det(b-a,c-a));}
double volume6(Point3 a,Point3 b,Point3 c,Point3 d){return dot(det(b-a,c-a),d-a);}
struct Line3{
    Point3 p1,p2;
    Line3(){}
    Line3(Point3 a,Point3 b):p1(a),p2(b){}
};
typedef Line3 Segment3;
double dis(Point3 p,Line3 v){
    return len(det(v.p2-v.p1,p-v.p1))/dis(v.p1,v.p2);
}
Point3 projection(Point3 p,Line3 v){
    double k=dot(v.p2-v.p1,p-v.p1)/len2(v.p2-v.p1);
    return v.p1+(v.p2-v.p1)*k;
}
struct Plane{
    Point3 p1,p2,p3;
    Plane(){}
    Plane(Point3 a,Point3 b,Point3 c):p1(a),p2(b),p3(c){}
};
//平面法向量，不是单位法向量
Vector3 normal(Plane f){return det(f.p2-f.p1,f.p3-f.p1);}
int isParallel(Plane f1,Plane f2){
    return len(det(normal(f1),normal(f2)))<eps;
}
int isVertical(Plane f1,Plane f2){
    return sgn(dot(normal(f1),normal(f2)))==0;
}
int cross(Line3 u,Plane f,Point3 &p){
    Point3 v=normal(f);
    double x=dot(v,u.p2-f.p1);
    double y=dot(v,u.p1-f.p1);
    double d=x-y;
    if(sgn(x)==0&&sgn(y)==0) return -1;
    if(sgn(d)==0) return 0;
    p=((u.p1*x)-(u.p2*y))/d;
    return 1;
}
//三维凸包
const int MAXN=2050; //最大顶点数
const double eps=1e-8;
struct CH3D{
	struct face{
		int a,b,c;
		bool ok;
	};
	int n;
	Point3 P[MAXN];
	int num;
	face F[8*MAXN];
	int g[MAXN][MAXN];
	double dblcmp(Point3 &p,face &f){
		Point3 m=P[f.b]-P[f.a];
		Point3 n=P[f.c]-P[f.a];
		Point3 t=p-P[f.a];
		return dot(det(m,n),t);
	}
	void deal(int p,int a,int b){
		int f=g[a][b];
		face add;
		if(F[f].ok){
			if(dblcmp(P[p],F[f])>eps) dfs(p,f);
			else{
				add.a=b;add.b=a;add.c=p;
				add.ok=true;
				g[p][b]=g[a][p]=g[b][a]=num;
				F[num++]=add;
			}
		}
	}
	void dfs(int p,int now){
		F[now].ok=false;
		deal(p,F[now].b,F[now].a);
		deal(p,F[now].c,F[now].b);
		deal(p,F[now].a,F[now].c);
	}
	bool same(int s,int t){
		Point3 &a=P[F[s].a];
		Point3 &b=P[F[s].b];
		Point3 &c=P[F[s].c];
		return fabs(volume6(a,b,c,P[F[t].a]))<eps&&
				fabs(volume6(a,b,c,P[F[t].b]))<eps&&
				fabs(volume6(a,b,c,P[F[t].c]))<eps;
	}
	void create(){
		int i;
		face add;
		num=0;
		if(n<4) return;
		bool flag=true;
		for(i=1;i<n;++i){
			if(len(P[0]-P[i])>eps){
				swap(P[1],P[i]);
				flag=false;break;
			}
		}
		if(flag) return;flag=true;
		for(i=2;i<n;++i){
			if(len(det(P[0]-P[1],P[1]-P[i]))>eps){
				swap(P[2],P[i]);
				flag=false;break;
			}
		}
		if(flag) return;flag=true;
		for(i=3;i<n;++i){
			if(fabs(dot(det(P[0]-P[1],P[1]-P[2]),P[0]-P[i]))>eps){
				swap(P[3],P[i]);
				flag=false;break;
			}
		}
		if(flag) return;
		for(i=0;i<4;++i){
			add.a=(i+1)%4;
			add.b=(i+2)%4;
			add.c=(i+3)%4;
			add.ok=true;
			if(dblcmp(P[i],add)>0) swap(add.b,add.c);
			g[add.a][add.b]=g[add.b][add.c]=g[add.c][add.a]=num;
			F[num++]=add;
		}
		for(i=4;i<n;++i){
			for(int j=0;j<num;++j){
				if(F[j].ok&&dblcmp(P[i],F[j])>eps){
					dfs(i,j);break;
				}
			}
		}
		int tmp=num;
		for(i=num=0;i<tmp;++i){
			if(F[i].ok) F[num++]=F[i];
		}
	}
	double area(){
		double res=0;
		for(int i=0;i<num;++i)
			res+=area2(P[F[i].a],P[F[i].b],P[F[i].c]);
		return res/2.0;
	}
	double volume(){
		double res=0;
		Point3 tmp(0,0,0);
		for(int i=0;i<num;++i)
			res+=volume6(tmp,P[F[i].a],P[F[i].b],P[F[i].c]);
		return fabs(res/6.0);
	}
	int triangle(){
		return num;
	}
	int polygon(){
		int i,j,res,flag;
		for(i=res=0;i<num;++i){
			flag=1;
			for(j=0;j<i;++j){
				if(same(i,j)){
					flag=0;break;
				}
			}
			res+=flag;
		}
		return res;
	}
};
```

## 杂项

### LIS 和 LCS

```c++
//a的最大严格递增子序列，返回序列长度，时间复杂度nlgn
char a[10005],tmp[10005];
int LIS(){
    int p=0;
    int lena=strlen(a);
    for(int i=0;i<lena;++i){
        int t=lower_bound(tmp,tmp+p,a[i])-tmp;
        if(t==p) tmp[p++]=a[i];
        else tmp[p]=a[i];
    }
    return p;
}
//a和b的最大公共子序列，返回序列长度，时间复杂度与序列性质有关
char b[10005];
vector<int> pos[26];
int tmp1[10005];
int LCS(){
    int lenb=strlen(b);
    for(int i=0;i<lenb;++i) pos[b[i]-'a'].push_back(i);
    int lena=strlen(a);
    int p=0;
    for(int i=0;i<lena;++i){
        for(auto j:pos[a[i]-'a']){
            int t=lower_bound(tmp1,tmp1+p,j)-tmp1;
            if(t==p) tmp1[p++]=j;
            else tmp1[t]=j;
        }
    }
    return p;
}
```
