#include"view.h"
using namespace std;
template<class T>
struct Node{
    T realPart;
    T virtualPart;
    struct Node<T> *nxt;
    Node operator+(const Node&x){
        Node<T> X;
        X.realPart = this->realPart + x.realPart;
        X.virtualPart = this->virtualPart + x.virtualPart;
        return X;
    }
    Node operator-(const Node&x){
        Node<T> X;
        X.realPart = this->realPart - x.realPart;
        X.virtualPart = this->virtualPart - x.virtualPart;
        return X;
    }
    Node operator*(const Node&x){
        Node<T> X;
        T a = this->realPart;
        T b = this->virtualPart;
        T c = x.realPart;
        T d = x.virtualPart;
        X.realPart = (a*c+b*d)/(c*c+d*d);
        X.virtualPart = (b*c-a*d)/(c*c+d*d);
        return X;
    }
    Node operator/(const Node&x){
        Node<T> X;
        X.realPart = (this->realPart * x.realPart)-(this->virtualPart * x.virtualPart);
        X.virtualPart = (this->realPart * this->virtualPart)+(x.realPart * x.virtualPart);
        return X;
    }
    void printData(){
        printf("RealNumber:%.2lf+%.2lfi\n",realPart, virtualPart);
    }
};
template<class DT>
class RealNumberLinkTable{
    private:
        Node<DT> *head;
        Node<DT> *rear;
        DT m_length;
    public:
        RealNumberLinkTable(){
            head = new Node<DT>;
            head->nxt = NULL;
            rear = new Node<DT>;
            rear->nxt = NULL;
            m_length = 0;
        }
        ~RealNumberLinkTable(){
            return;
        }
        void addRealNumber(DT RealPart,DT VirtualPart){
            Node<DT> *T = new Node<DT>;
            T->realPart = RealPart;
            T->virtualPart = VirtualPart;
            if(rear->nxt==NULL){
                rear->nxt = T;
                T->nxt = NULL;
                head->nxt = T;
            }
            else{
                rear->nxt->nxt = T;
                T->nxt = NULL;
                rear->nxt = T;
            }
            m_length++;
        }
        void deleteRealNumber(int ID){
            if(ID > m_length)return;
            int cnt = 1;
            Node<DT> *cur = head->nxt;
            Node<DT> *fre = head;
            while(cur->nxt != NULL){
                if(cnt == ID){
                    fre->nxt = cur->nxt;
                    if(rear->nxt == cur){
                        rear->nxt = (fre==head?NULL:fre);
                    }
                    delete cur;
                    m_length--;
                    return;
                }
                cnt++;
                fre = fre->nxt;
                cur = cur->nxt;
            }
        }
        void outputRealNumber(){
            Node<DT> *cur = head->nxt;
            int cnt = 1;
            while(cur!=NULL){
                printf("Number%d:%.2lf+%.2lfi\n",cnt, cur->realPart, cur->virtualPart);
                cnt++;
                cur = cur->nxt;
            }
        }
        Node<DT> getIthNumber(int pos){
            int cnt=1;
            Node<DT> *cur = head->nxt;
            while(cur!=NULL){
                if(cnt == pos)
                    return *cur;
                cur = cur->nxt;
                cnt++;
            }
            return *head;
        }
        int getLength(){
            return m_length;
        }
};