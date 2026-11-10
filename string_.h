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

