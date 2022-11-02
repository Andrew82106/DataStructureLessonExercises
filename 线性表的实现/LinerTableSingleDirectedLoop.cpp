#include<bits/stdc++.h>
using namespace std;
template<class DT> 
struct Node{
    DT data;
    struct Node<DT> *next;
};
template<class T>
class LinkTable_directed_L{
    private:
        Node<T> *start;
        long long m_length;
    public:
        LinkTable_directed_L();
        LinkTable_directed_L(T Datain[], long long length);
        ~LinkTable_directed_L();
        void OutputAll();
        void Insert(T datain, long long pos);
        void Delete();
        void Reverse();
};
template<class T>
LinkTable_directed_L<T>::LinkTable_directed_L(T Datain[], long long length){
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
LinkTable_directed_L<T>::LinkTable_directed_L(){
    start = new Node<T>;
    start->next = NULL;

}
template<class T>
void LinkTable_directed_L<T>::OutputAll(){
    Node<T> *cur = start;
    while(cur->next != NULL){
        cout<< cur->next->data<<" ";
        cur = cur->next;
    }
    cout<<endl;
}
template<class T>
LinkTable_directed_L<T>::~LinkTable_directed_L(){
    Node<T> *cur = start;
    while (cur->next!=NULL){
        Node<T>*Nxt = cur->next;
        delete cur;
        cur = Nxt;
    }
    delete cur;
}
template<class T>
void LinkTable_directed_L<T>::Insert(T datain, long long pos){
    if(pos>m_length)return;
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
void LinkTable_directed_L<T>::Delete(){
    if(start->next==NULL)return;
    Node<T> *cur = start->next;
    Node<T> *pre = start;
    //bool flag = false;
    while (cur->next != NULL&&cur->next->next != NULL){
        //flag = false;
        if(cur->data == cur->next->data){
            pre->next = cur->next;
            delete cur;
            cur = pre->next;
            //flag = true;
        }
        else{
            pre = cur;
            cur = cur->next;
        }   
    }
}
int main(){
    int a[] = {1,2,3,4,5,6,7,7,7,8,9};
    LinkTable_directed_L<int>X(a, 11);
    X.OutputAll();
    X.Delete();//实现循环单链表L就地删除所有值重复的结点
    X.OutputAll();
    return 0;
}