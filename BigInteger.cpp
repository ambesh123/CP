#include<bits/stdc++.h>
using namespace std;


class BigInteger{
    string value;
    public:
    BigInteger(){}

    BigInteger(string val){
        for(int i=0;i<val.length();i++){
            value+= val.at(val.length()-i-1) - (char)48;
        }
    }
    BigInteger(long val){
        int temp;
        while(val){
            temp = val%10;
            val = val/10;
            value+= (char)(temp);
        }
    }

    string addString(string s1,string s2){
        string temp;    int carry = 0,sum;
        string mxs,mns; //max length and min length string

        if(s1.length() >= s2.length()){
            mxs = s1;
            mns = s2;
        }
        else{
            mxs = s2;
            mns = s1;
        }
        for(int i=0;i<mns.length();i++){
            sum = carry + (int)mns.at(i) + (int)mxs.at(i);
            if(sum>9){carry=1; sum-=10;}
            else carry=0;
            temp+=(char)sum;
        }

        for(int i=mns.length();i<mxs.length();i++){
            sum = carry + (int)mxs.at(i);
            if(sum>9){carry=1; sum-=10;}
            else carry=0;
            temp+=(char)sum;
        }

        if(carry)temp+=(char)carry;
        return temp;
    }

    BigInteger operator +(BigInteger &b2){
        BigInteger b;
        b.value = addString(value, b2.value);
        return b;
    }

    BigInteger operator -(BigInteger &b2){
        int borrow=0,diff;
        string temp;
        for(int i=0;i<b2.value.length();i++){
            diff = (int)value.at(i) - (int)b2.value.at(i) - borrow;
            if(diff<0){diff+=10; borrow =1;}
            else borrow=0;
            temp+=diff;
        }
        for(int i=b2.value.length(); i<value.length() ;i++){
            diff = (int)value.at(i) - borrow;
            if(diff<0){diff+=10; borrow =1;}
            else borrow=0;
            temp+=diff;
        }
        BigInteger b;
        b.value = temp;
        return b;
    }

    BigInteger operator *(BigInteger &b2){
        int carry=0, mul;
        string temp,temp1,zer="";

        for(int i=0;i<b2.value.length();i++){
            for(int j=0;j<value.length();j++){
                mul = (int)b2.value.at(i) * (int)value.at(j) +carry;
                if(mul>9){carry = mul/10; mul=mul%10;}
                else carry = 0;
                temp1+=(char)mul;
            }
            if(carry)temp1+=(char)carry; carry=0;
            temp1 = zer + temp1;
            temp = addString(temp,temp1);
            temp1="";   zer+=(char)0;
        }
        BigInteger b;
        b.value=temp;
        return b;
    }

    BigInteger operator /(BigInteger &b2){//not done yet
        BigInteger b;
        if(b2 > *this){
            b.value = (char)0;
            return b;
        }
        string temp = "";

    }

    bool operator > (BigInteger &b2){
        if(b2.value.length() > value.length())return false;
        if(b2.value.length() < value.length())return true;

        for(int i = value.length()-1; i >= 0 ; i--){
            if(b2.value[i] < value[i])return true;
            if(b2.value[i] > value[i])return false;
        }
        return false;
    }

   bool operator < (BigInteger &b2){
        if(b2.value.length() > value.length())return true;
        if(b2.value.length() < value.length())return false;

        for(int i = value.length()-1; i >= 0 ; i--){
            if(b2.value[i] < value[i])return false;
            if(b2.value[i] > value[i])return true;
        }
        return false;
    }

    bool operator == (BigInteger &b2){
        if(b2.value.length() != value.length())return false;

        for(int i = value.length()-1; i >= 0 ; i--){
            if(b2.value[i] != value[i])return false;
        }
        return true;
    }

    string getValue(){
        string svalue;
        for(int i=0;i<value.length();i++)svalue+=value.at(value.length()-1-i)+(char)48;
        return svalue;
    }

    void setValue(long val){
        value = "";
        int temp;
        while(val){
            temp = val%10;
            val = val/10;
            value+= (char)(temp);
        }
    }
};



int main(){

    BigInteger b1(34535) , b2(2894) , b3 (2894);

    cout<<( b1 == b3 )<<( endl )<<( b2 == b3 )<<( endl )<<( b3 > b1 )<<( endl )<<( b2 > b3 )<<( endl )<<( b1 > b2) << endl;

    exit(0);
    int n;
    while(n!=-1){
        BigInteger b1(1),b2;
        cout<<"Enter a number to find it's factorial:\n";
        cin>>n;
        for(int i=1;i<=n;i++){
            b2.setValue(i);
            b1 = b1*b2;
        }
        cout<<"Obtained value is:\n";
        cout<<b1.getValue()<<'\n';}
}
