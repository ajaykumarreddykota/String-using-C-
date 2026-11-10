#include<iostream>
#include<fstream>
using namespace std;
typedef unsigned int u32;
u32 strlen(const char *);
void strcpy(char *s,const char *ss);
class String;
int strcmp(String&,String&);
void strcat(char **s,char *m){
	int i=strlen(*s);
	char *c=new char[i+1+strlen(m)];
	strcpy(c,*s);
	int j=0;
	for(j=0;c[i]=m[j];i++,j++);
	delete[] *s;
	*s=c;
}
class String{
	char *s;
	int compare(String &b){
                String a(strlen(s)+1);
                strcpy(a.s,s);
                return strcmp(a,b);
        }
	public:
	static int x;
	String(){
		s=0;
	}
	String(int len){
		s=new char[len];
	}
	friend istream& operator>>(istream&, String &);
	friend istream& getline(istream&,String&);
        friend ostream& operator<<(ostream&,const String &);
	friend u32 strlen(const String&);
	friend char * strcpy(char *,const String&);
	friend char * strcpy(String & ,String &);
	friend char * strncpy(String &,String &,u32);	
	friend int strcmp(String&,String&);
	friend int strncmp(String&,String& ,u32);
	friend char * strcat(String &,String &);
	friend char * strcat(char *,String &);
	friend void strcat(char **s,char *m);
	friend char * strncat(String &,String &,u32 );
	friend char * strstr(String&,String &);
	friend char * strstr(String&,const char *);
	friend char * strchr(String &,const char );
	friend char * strrchr(String &,const char);
	friend char * strlwr(String &);
	friend char * strupr(String &);
	friend char * strrev(String &);
	String(const String &deep_copy){
		s=new char[strlen(deep_copy)+1];
		strcpy(s,deep_copy);
	}

	friend u32 strlen(const char *);
	friend void strcpy(char *s,const char *ss);

	String(const char *s){
		this->s=new char[strlen(s)+1];
		strcpy(this->s,s);
	}
	char& operator[](int i){
		return s[i];
	}
	bool operator>=(String &b){
		int c=compare(b);
		if(c==1||!c){
			return true;
		}else{
			return false;
		}
	}
	bool operator<=(String &b){
                int c=compare(b);
                if(c==-1||!c){
                        return true;
                }else{
                        return false;
                }
        }
	bool operator==(String &b){
                int c=compare(b);
                if(c==0){
                        return true;
                }else{
                        return false;
                }
        }
	bool operator!=(String &b){
                int c=compare(b);
                if(c==0){
                        return false;
                }else{
                        return true;
                }
        }
	bool operator>(String &b){
                int c=compare(b);
                if(c==1){
                        return true;
                }else{
                        return false;
                }
        }
	bool operator<(String &b){
                int c=compare(b);
                if(c==-1){
                        return true;
                }else{
                        return false;
                }
        }
	String operator=(String b){
		delete[] s;
		s=new char[strlen(b)+1];
		strcpy(s,b);
		return b;
	}
	String operator+(const String &a){
		String b(s);
		strcat(&b.s,a.s);
		return b;
	}
	String operator+=(String &a){
		String b=s;
		delete [] s;
		s=new char[strlen(b)+strlen(a)+1];
		strcpy(s,b);
                strcat(s,a);
                return b;
	}
	~String(){
		if(s != nullptr){
			delete[] s;
			s=nullptr;
		}
	}
};
int String::x;
istream& getline(istream& in,String &a){
	cin.getline(a.s,1000);
	return in;
}
ostream& operator<<(ostream& out,const String & a){
	cout<<a.s;
	return out;
}

istream& operator>>(istream&in,String &a){
	ofstream file("STR.txt");
	char c;
	int count=0;
	while(1){
		scanf("%c",&c);
		if(c=='\r' || c==' ' || c=='\n'){
			break;
		}
		file<<c;
	}
	file.close();
	ifstream i_file("STR.txt");
	delete [] a.s;
	a.s=new char[count+1];
	i_file>>a.s;
	i_file.close();
system("rm STR.txt");
	return in;
}
u32 strlen(const String &a){
        int i=0;
        for(i=0;a.s[i];i++);
        return i;
}
u32 strlen(const char *s){
        int i=0;
        for(i=0;s[i];i++);
        return i;
}
int strncmp(String&s1,String&s2,u32 n){
        int i=0;
        for(i=0;i<n;i++){
                if(s1[i]<s2[i]){
                        return -1;
                }else if(s1[i]>s2[i]){
                        return 1;
                }
        }
        return 0;
}
int strcmp(String&s1,String&s2){
        int i=0;
        for(i=0;s1[i] && s2[i];i++){
                if(s1[i]<s2[i]){
                        return -1;
                }else if(s1[i]>s2[i]){
                        return 1;
                }
        }
        if(s1[i]==s2[i]){
                return 0;
        }else if(!s1[i] && s2[i]){
                return -1;
        }else{
                return 1;
        }
}
char * strstr(String & a,String& s){
        int i,j,k;
        for( i=0;a[i];i++){
                for(j=0,k=i;s[j];j++,k++){
                        if(a[k] != s[j]){
                                break;
                        }
                }
                if(!s[j]){
                        return &a[i];
                }
        }
        return 0;
}
char * strlwr(String & s){
        for(int i=0;s[i];i++){
                if(s[i]>='A' &&s[i]<='Z'){
                        s[i]+=32;
                }
        }
        return &s[0];
}
char * strupr(String & s){
        for(int i=0;s[i];i++){
                if(s[i]>='a' &&s[i]<='z'){
                        s[i]-=32;
                }
        }
        return &s[0];
}
char * strrev(String &s){
        for(int i=0,j=strlen(s)-1;i<j;i++,j--){
                char c=s[i];
                s[i]=s[j];
                s[j]=c;
        }
        return &s[0];
}
char * strchr(String &a,const char ch){
        for(int i=0;a[i];i++){
                if(a[i]==ch){
                        return &a[i];
                }
        }
        return nullptr;
}
char * strrchr(String &a,const char ch){
        for(int i=strlen(a)-1;i>=0;i--){
                if(ch==a[i]){
                        return &a[i];
                }
        }
        return nullptr;
}
char * strstr(String & a,const char *s){
        int i,j,k;
        for( i=0;a[i];i++){
                for(j=0,k=i;s[j];j++,k++){
                        if(a[k] != s[j]){
                                break;
                        }
                }
                if(!s[j]){
                        return &a[i];
                }
        }
        return nullptr;
}

char * strcat(String &a,String &b){
        int i=strlen(a);
	for(int j=0;a[i]=b[j];i++,j++);
        return a.s;
}
char * strcat(char *s,String &b){
        int i=0;
	for(i=0;s[i];i++);
        strcpy(&s[i],b);
        return s;
}

char * strncat(String &a,String &b,u32 n){
        int i=strlen(a);
        for(int j=0;j<n;j++,i++){
                a[i]=b[j];
        }
        a[i]='\0';
        return a.s;
}
char * strncpy(String &a,String &b,u32 n){
        int i;
        for(i=0;i<n;i++){
                a[i]=b[i];
        }
        a[n]='\0';
        return &a.s[0];
}
void strcpy(char *s,const char *ss){
        for(int i=0;s[i]=ss[i];i++);
}
char * strcpy(String &a,String &b){
       return strcpy(&a.s[0],b);
}
char *strcpy(char *s,const String &a){
        for(int i=0;s[i]=a.s[i];i++);
        return s;
}
