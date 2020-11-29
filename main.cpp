#include <iostream>

using namespace  std;

struct Node{
    int x;
    int y;
    string name;
    Node * m_pSon[4];
    Node(int x, int y, string name):x(x), y(y), name(name){
        for(int i = 0 ; i < 4; i++)m_pSon[i]=0;
    }
};

class QuadTree{

private:
    Node* root;
public:
    QuadTree():root(0){};

    void Insert(int x, int y, string name){
        Insert(x,y,name,root);
    }


    void Insert(int x, int y, string name, Node * & r){
        if(!r){r = new Node(x, y, name); return;}
        Insert(x,y,name, r->m_pSon[get_cuadrante(x,y,r)]);
    }

private:
    int get_cuadrante(int xp, int yp, Node * r){
        if(xp > r->x && yp < r->y)return 3;
        if(xp < r->x && yp < r->y)return 2;
        if(xp > r->x && yp > r->y)return 1;
        if(xp < r->x && yp > r->y)return 0;
    }
};




int main() {
    QuadTree Q;
    Q.Insert(35, 42, "Chicago");
    Q.Insert(5, 45, "Denver");
    Q.Insert(27, 35, "Omaha");
    Q.Insert(90, 5, "Miami");
    Q.Insert(52, 10, "Mobile");
    Q.Insert(85, 15, "Atlanta");
    Q.Insert(62, 77, "Toronto");
    Q.Insert(82, 65, "Buffalo");

    cout << "termino..."<<endl;
    return 0;
}
