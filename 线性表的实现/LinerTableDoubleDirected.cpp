#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i,start,end) for(int i=start;i<=end;++i)
template<class DT>
struct Node{
    DT data;
    struct Node<DT> *fre;
    struct Node<DT> *next;
};
template<class T>
class LinerTableDoubleDirected{
    private:
        Node<T> *head;  // 头指针
        Node<T> *rare;  // 尾指针
        ll m_length;
    public:
        LinerTableDoubleDirected();
        LinerTableDoubleDirected(T datain[], ll length);
        ll QueryNumber(T data);
        void DeleteFirstNumber(T data);
        void Insert(T Datain, ll pos);
        void OutputAll();
        ~LinerTableDoubleDirected();
        
};
template<class T>
LinerTableDoubleDirected<T>::LinerTableDoubleDirected(){
    head = new Node<T>;
    rare = new Node<T>;
    head->next = rare;
    head->fre = NULL;
    rare->next = NULL;
    rare->fre = head;
}
template<class T>
LinerTableDoubleDirected<T>::LinerTableDoubleDirected(T datain[], ll length){
    head = new Node<T>;
    rare = new Node<T>;
    head->next = rare;
    head->fre = NULL;
    rare->next = NULL;
    rare->fre = head;
    loop(i,0,length-1){
        Node<T> *Data = new Node<T>;
        Data->fre = rare->fre;
        Data->next = rare;
        rare->fre->next = Data;
        rare->fre = Data;
        Data->data = datain[i];   
    }
    m_length=length;
}
template<class T>
void LinerTableDoubleDirected<T>::Insert(T datain, ll pos){
    ll cnt=1;
    Node<T> *cur=head;
    while(cur->next!=NULL){
        if(cnt == pos){
            Node<T> *Data = new Node<T>;
            Data->data = datain;
            Data->next = cur;
            Data->fre = cur->fre;
            cur->fre->next = Data;
            cur->fre = Data;
            return;
        }
        cnt++;
        cur = cur->next;
    }
    m_length++;
}
template<class T>
LinerTableDoubleDirected<T>::~LinerTableDoubleDirected(){
    Node<T> *cur=head;
    while(cur->next!=NULL){
        cur = cur->next;
        delete cur->fre;
    }
    delete cur;
}
template<class T>
void LinerTableDoubleDirected<T>::OutputAll(){
    Node<T> *cur=head;
    while(cur->next->next!=NULL){
        cur = cur->next;
        printf("%d ",cur->data);
    }
    printf("\n");
    //printf("%d\n",cur->data);
}
template<class T>
ll LinerTableDoubleDirected<T>::QueryNumber(T data){
    ll res = 0;
    Node<T> *cur=head;
    while(cur->next->next!=NULL){
        cur = cur->next;
        if(cur->data == data)res++;
    }
    return res;
}
template<class T>
void LinerTableDoubleDirected<T>::DeleteFirstNumber(T data){
    ll res = 0;
    Node<T> *cur=head;
    while(cur->next->next!=NULL){
        cur = cur->next;
        if(cur->data == data){
            cur->fre->next=cur->next;
            cur->next->fre=cur->fre;
            delete cur;
            return;
        }
    }
}
int main(){
    int a[] = {1,2,3,4,5,6,7,5};
    LinerTableDoubleDirected<int>X(a, 8);
    X.OutputAll();
    printf("%lld\n",X.QueryNumber(5));//求值为2的节点的个数，时间复杂度O(n)
    X.DeleteFirstNumber(5);//删除第一个值为5的节点，时间复杂度O(n)
    X.OutputAll();
    return 0;
}