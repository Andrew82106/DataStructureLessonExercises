#include"view.h"
bool Fault = false;
int findSubSeq(char *faSeq, char *sonSeq, int lengthFa,int lengthSon){
    int p0=0,p1=0;
    while(p0<lengthFa&&sonSeq[p1]!=faSeq[p0])p0++;
    while(p0<lengthFa&&p1<lengthSon&&faSeq[p0]==sonSeq[p1])p0++,p1++;
    if(p1==lengthSon)return p0-1;
    else return -1;
}
bool safelyInput(char CommandIn[]){
    char r=getchar();int p=0;
    while(r!='\n'){
        CommandIn[p] = r;p++;
        r=getchar();
        if(p>maxCache)return 0;
    }return 1;
}
bool ifIsEqual(char *faSeq, char *sonSeq, int lengthFa,int lengthSon){return (findSubSeq(faSeq, sonSeq, lengthFa, lengthSon)+1);}
int identifyType(char CommandIn[]){
    int p = findSubSeq(CommandIn, RC, strlen(CommandIn), strlen(RC));
    if(p==-1)return -1;
    p = findSubSeq(CommandIn, Line, strlen(CommandIn), strlen(Line)) + 1;
    char type[10];int p1=0;
    while('a'<=CommandIn[p]&&CommandIn[p]<='z'){type[p1] = CommandIn[p];p1++;p++;}
    if(ifIsEqual(type, TYPE0, strlen(type), strlen(TYPE0)))return 0;
    else if(ifIsEqual(type, TYPE1, strlen(type), strlen(TYPE1)))return 1;
    else if(ifIsEqual(type, TYPE2, strlen(type), strlen(TYPE2)))return 2;
    else if(ifIsEqual(type, TYPE3, strlen(type), strlen(TYPE3)))return 3;
    else if(ifIsEqual(type, TYPE4, strlen(type), strlen(TYPE4)))return 4;
    else if(ifIsEqual(type, TYPE5, strlen(type), strlen(TYPE4)))return 5;
    else return -1;
}
double FindNextDouble(char Input[], int &pos, int length){
    double res = 0;bool flag = false;
    double neg = 1;
    while(pos<length&&!IfNumber(Input[pos])){
        if(Input[pos]=='-')neg=-1;
        pos++;
    }
    while(pos<length&&IfNumber(Input[pos])){res = (res*10)+Input[pos]-'0',pos++,flag=1;}
    if(Input[pos]!='.')return res;
    else pos++;
    double k = 0.1;
    while(pos<length&&IfNumber(Input[pos]))res += (Input[pos] - '0')*k,k*=0.1,pos++;
    if(flag)return neg*res;
    else{
        Fault = true;
        return 0;
    }
}
int FindNextInt(char Input[], int &pos, int length){
    int res = 0;bool flag = false;
    while(pos<length&&!IfNumber(Input[pos]))pos++;
    while(pos<length&&IfNumber(Input[pos])){res = (res*10)+Input[pos]-'0',pos++,flag=1;}
    if(flag)return res;
    else{
        Fault = true;
        return 0;
    }
}