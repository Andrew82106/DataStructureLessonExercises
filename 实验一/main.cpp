#include "view.h"
RealNumberLinkTable<double>X;
Node<double> calc(char Operator, int index1, int index2){
    Node<double>A = X.getIthNumber(index1);
    Node<double>B = X.getIthNumber(index2);
    Node<double>C;
    if(Operator=='+')C = A+B;
    else if(Operator=='-')C = A-B;
    else if(Operator=='*')C = A*B;
    else if(Operator=='/')C = A/B;
    else Fault = true;
    return C;
}
void showView(){
    /*
    RC --help [add/delete/choose/query]
    RC --add [real part] [virtual part]
    RC --delete [index]
    RC --choose [index1][operator][index2]
    RC --query [index]
    */
    showCommand(StartMes);
    char CommandCache[maxCache+10];
    while(1){
        clean(CommandCache,0);
        safelyInput(CommandCache);
        int Type = identifyType(CommandCache);
        if(Type==0){// RC --help [add/delete/choose/query]
            printf("%s",HelpMsg);
            printf("%s",ChoiceOne);
            printf("%s",ChoiceTwo);
            printf("%s",ChoiceThree);
            printf("%s",ChoiceFour);
            printf("%s",ChoiceFive);
            printf("%s",ExtraMsg);
            printf("%s\n%s",Kowa0, Kowa);
        }
        else if(Type==1){// RC --add [real part] [virtual part]
            int pos = findSubSeq(CommandCache, Line, strlen(CommandCache), strlen(Line));
            double realpart, virpart;
            realpart = FindNextDouble(CommandCache, pos, strlen(CommandCache));
            if(Fault){showCommand(ERRORMsg);Fault = false;continue;}
            virpart = FindNextDouble(CommandCache, pos, strlen(CommandCache));
            if(Fault){showCommand(ERRORMsg);Fault = false;continue;}
            X.addRealNumber(realpart, virpart);
            showCommand(AddSuc);
        }
        else if(Type==2){//RC --delete [index]
            int pos = findSubSeq(CommandCache, Line, strlen(CommandCache), strlen(Line));
            int index;
            index = FindNextDouble(CommandCache, pos, strlen(CommandCache));
            if(X.getLength()<index){showCommand(ERRORMsg);Fault = false;continue;}
            X.deleteRealNumber(index);
            showCommand(DelSuc);
        }
        else if(Type==3){//RC --choose [index1][operator][index2]
            int pos = findSubSeq(CommandCache, Line, strlen(CommandCache), strlen(Line));
            int index1;
            index1 = FindNextDouble(CommandCache, pos, strlen(CommandCache));
            if(X.getLength()<index1){showCommand(ERRORMsg);Fault = false;continue;}
            char Operator = CommandCache[pos];
            int index2;
            index2 = FindNextDouble(CommandCache, pos, strlen(CommandCache));
            Node<double> RES = calc(Operator, index1, index2);
            if(X.getLength()<index2){showCommand(ERRORMsg);Fault = false;continue;}
            printf("INFO::Calculate Result:%.2lf %.2lfi\n",RES.realPart, RES.virtualPart);
            printf("%s\n%s",Kowa0, Kowa);
        }
        else if(Type==4){//RC --query [index]
            int pos = findSubSeq(CommandCache, Line, strlen(CommandCache), strlen(Line));
            int index;
            index = FindNextDouble(CommandCache, pos, strlen(CommandCache));
            if(X.getLength()<index){showCommand(ERRORMsg);Fault = false;continue;}
            Node<double> RES = X.getIthNumber(index);
            printf("INFO::Query Result=%.2lf %.2lfi\n",RES.realPart, RES.virtualPart);
            printf("%s\n%s",Kowa0, Kowa);
        }
        else if(Type==5){//RC --showall
            int length = X.getLength();
            loop(ID,1,length){
                Node<double> RES = X.getIthNumber(ID);
                printf("INFO::Query Result%d=%.2lf %.2lfi\n",ID, RES.realPart, RES.virtualPart);
            }
            
            printf("%s\n%s",Kowa0, Kowa);
        }
        else{
            printf("%s",Exit);
            break;
        }
    }
}
int main(){
    /*Node<double>X;X.realPart=12;X.virtualPart=-12;
    Node<double>Y;Y.realPart=120;Y.virtualPart=-120;
    Node<double>Z=X/Y;
    Z.printData();*/
    showView();
    return 0;
}