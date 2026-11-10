#include"Sting_.h"
int main(){
        String s1="ajay",s2;
        cin>>s2;
        cout<<s2<<endl<<s1<<endl;
        s2+=s1+=s2+s1;
        cout<<s2<<endl;
        cout<<s1[2]<<endl;
}
