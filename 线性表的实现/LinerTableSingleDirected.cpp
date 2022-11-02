#include<bits/stdc++.h>
using namespace std;
template<class DT> 
struct Node{
    DT data;
    struct Node<DT> *next;
};
template<class T>
class LinkTable_directed{
    private:
        Node<T> *start;
        long long m_length;
    public:
        LinkTable_directed();
        LinkTable_directed(T Datain[], long long length);
        ~LinkTable_directed();
        void OutputAll();
        long long GetMaxID();
        void Insert(T datain, long long pos);
        void Delete(long long pos);
        void Reverse();
        void Merge(LinkTable_directed<T> X);
};
template<class T>
void LinkTable_directed<T>::Merge(LinkTable_directed<T> X){
    LinkTable_directed<T>res;
    if(this->start->next==NULL||X.start->next==NULL)return;
    Node<T> *cur1 = this->start->next;
    Node<T> *cur2 = X.start->next;
    while(cur1!=NULL&&cur2!=NULL){
        while(cur1->data!=cur2->data){
            if(cur1->data>cur2->data)cur2 = cur2->next;
            else cur1 = cur1->next;
        }
        res.Insert(cur1->data, 1);
        cur1=cur1->next;
        cur2=cur2->next;
    }
    res.OutputAll();
}
template<class T>
LinkTable_directed<T>::LinkTable_directed(T Datain[], long long length){
    start = new Node<T>;
    start->next = NULL;
    Node<T> *back = start;
    for(int i=0;i<length;++i){
        Node<T> *data = new Node<T>;
        data->data = Datain[i];
        data->next=NULL;
        back->next=data;
        back = data;
    }
    m_length = length;
}
template<class T>
LinkTable_directed<T>::LinkTable_directed(){
    start = new Node<T>;
    start->next = NULL;
}
template<class T>
void LinkTable_directed<T>::OutputAll(){
    Node<T> *cur = start;
    while(cur->next != NULL){
        cout<< cur->next->data<<" ";
        cur = cur->next;
    }
    cout<<endl;
}
template<class T>
long long LinkTable_directed<T>::GetMaxID(){
    Node<T> *cur = start;
    long long maxID = 0;
    long long maxNum = -1;
    long long cnt=1;
    while(cur->next != NULL){
        if(cur->data > maxNum){
            maxID = cnt;
            maxNum = cur->data;
        }
        cur = cur->next;
        cnt++;
    }
    return maxID-1;
}
template<class T>
LinkTable_directed<T>::~LinkTable_directed(){
    /*Node<T> *cur = start;
    while (cur->next!=NULL){
        Node<T>*Nxt = cur->next;
        delete cur;
        cur = Nxt;
    }
    delete cur;*/
    //cout<< "LinkTable has been cleaned"<<endl;
}
template<class T>
void LinkTable_directed<T>::Reverse(){
    if(start->next==NULL)return;
    Node<T> *First = start->next;
    Node<T> *temp;
    Node<T> *pre = First;
    Node<T> *bac;
    while(First->next!=NULL){
        if(First->next->next==NULL)start->next = First->next;
        temp = First->next;
        bac = temp->next;
        temp->next = pre;
        pre = temp;
        First->next = bac;
    }
    //start->next = First->next;
    First->next=NULL;
}
template<class T>
void LinkTable_directed<T>::Insert(T datain, long long pos){
    Node<T> *cur = start;
    long long cnt = 1;
    while(cnt < pos){
        cur = cur->next;
        cnt++;
    }
    Node<T>*data = new Node<T>;
    data->data = datain;
    data->next = cur->next;
    cur->next = data;
    m_length++;
}
template<class T>
void LinkTable_directed<T>::Delete(long long pos){
    if(start->next==NULL)return;
    if(pos>m_length)return;
    if(pos == 1)start->next = start->next->next;
    Node<T> *cur = start->next;
    Node<T> *pre;
    Node<T> *bac;
    long long cnt = 1;
    while(cnt < pos){
        pre = cur;
        cur = cur->next;
        bac = cur->next;
        cnt++;
    }
    pre->next = bac;
    delete cur;
    m_length--;
}
void Merge(){ // 实现两个链表取交集，时间复杂度为O(n)，空间复杂度为O(n)
    int a[] = {1,2,3,4};
    LinkTable_directed<int>X(a, 4);
    int b[] = {3,4,5,6,7,8,9};
    LinkTable_directed<int>Y(b, 7);
    X.Merge(Y);
}
int main(){
    // 实现了单向链表的插入，删除，翻转操作
    /*int a[] = {1,2,3,4,5,6,7,8,9};
    LinkTable_directed<int>X(a, 9);
    printf("原列表为：");
    X.OutputAll();
    printf("插入100后");
    X.Insert(100, 3);
    X.OutputAll();
    printf("翻转后");
    X.Reverse();
    X.OutputAll();
    printf("删除后");
    X.Delete(4);
    X.OutputAll();
    printf("翻转后");
    X.Reverse();
    X.OutputAll();
    printf("%lld\n",X.GetMaxID());*/
    Merge();
    return 0;
}