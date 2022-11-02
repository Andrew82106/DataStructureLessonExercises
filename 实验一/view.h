#ifndef VIEW_H
#define VIEW_H
#include<bits/stdc++.h>
const int maxCache = 100;
char StartMes[] = "Welcome to use this real number calculator!\nFor more information please use the command 'RC --help'";
char Kowa0[] = "---------------------------------RC calculator>>";
char Kowa[] = "Command(RC User)::";

char HelpMsg[] = "  RC --add [real part] [virtual part]\n  RC --delete [index]\n  RC --choose [index1][operator][index2]\n  RC --query [index]\n  RC --showall\nDetailed usage:\n";
char TYPE0[] = "help";
char ERRORMsg[] = "ERROR::illegal input message format.May be you should check the command again";
char Exit[] = "Thanks for inviting us!";
char ExtraMsg[] = "Note:\n  If you type in data without format above,we will consider that you want to exit this program and exit immediately.\n";

char ChoiceOne[] = "  Input the real part and the virtual part of a number: 'RC --add [real part] [virtual part]'\n";
char TYPE1[] = "add";
char AddSuc[] = "INFO::Add real number successfully";
char ChoiceTwo[] = "  Input the index of the number: 'RC --delete [index]'\n";
char TYPE2[] = "delete";
char DelSuc[] = "INFO::Delete real number successfully";
char ChoiceThree[] = "  Choose two items: 'RC --choose [index1][operator][index2]'.Operators we support: + - * /\n";
char TYPE3[] = "choose";
char ChoiceFour[] = "  Input the index of the number: 'RC --query [index]'\n";
char TYPE4[] = "query";
char ChoiceFive[] = "  Show al number: 'RC --showall'\n";
char TYPE5[] = "showall";

char RC[] = "RC";
char Line[] = "--";

#define showCommand(Msg) printf("%s\n%s\n%s",Msg,Kowa0,Kowa)
#define IfAlphaBetLowCase(a) ('a'<=a&&a<='z')
#define IfAlphaBetUpperCase(a) ('A'<=a&&a<='Z')
#define IfNumber(a) ('0'<=a&&a<='9')
#define CheckOperatorLegal(a) (a=='+'||a=='-'||a=='*'||a=='/')
#define clean(arry, num) memset(arry,num,sizeof(arry))
#define loop(i,start,end) for(int i=start;i<=end;++i)

#include "code.cpp"
#include "ShowMenu.cpp"
//#include "colorSetting.cpp"
#endif
