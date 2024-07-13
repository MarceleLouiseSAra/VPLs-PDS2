#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Ponto{
    public:
    int x;
    int y;
    
    Ponto (int a, int b) : x(a), y(b) {}

    void setX(int _x){
        this->x = _x;
    }
    
    void setY(int _y){
        this->y = _y;
    }
    
    int getX(){
        return this->x;
    }
    
    int getY(){
        return this->y;
    }
};

class figuraGeometrica{
    public:
    Ponto centro;
    
    figuraGeometrica(int a, int b) : centro(a, b) {}
    
    virtual void Desenha(){
        cout << setprecision(2) << fixed;
        cout << centro.getX() << " " << centro.getY() << " ";
    }
    
    virtual float calculaArea() = 0;

};


class Retangulo : public figuraGeometrica{
    public:
    int lado1;
    int lado2;
    
    Retangulo(int a, int b, int c, int d) : figuraGeometrica(a, b), lado1(c), lado2(d) {}

    void Desenha() override{
        figuraGeometrica::Desenha();
        cout << "RETANGULO" << endl;
        
    }
    
    float calculaArea() override{
        return lado1*lado2;
    }
    
    ~Retangulo() {
        cout << "Destrui o Retangulo!";
    }
};

class Circulo : public figuraGeometrica{
    public:
    int raio;

    Circulo(int a, int b, int c) : figuraGeometrica(a, b), raio(c) {}
    
    void Desenha() override{
        figuraGeometrica::Desenha();
        cout << "CIRCULO" << endl;
    }
    
    float calculaArea() override{
        return M_PI*(raio*raio);
    }
    
    ~Circulo() {
        cout << "Destrui o circulo!";
    }
};

class Triangulo : public figuraGeometrica{
    public:
    int base;
    int altura;
    
    Triangulo(int a, int b, int c, int d) : figuraGeometrica(a, b), base(c), altura(d) {}
    
    void Desenha() override{
        figuraGeometrica::Desenha();
        cout << "TRIANGULO" << endl;
    }
    
    float calculaArea() override{
        return (base*altura)/2;
    }
    
    ~Triangulo() {
        cout << "Destrui o Triangulo!";

    }
};



int main(){
    
    //cout << M_PI << endl;
    
    vector<figuraGeometrica*> vetor;
    
    char modo;
    while(1){
        cin >> modo;
        
        if(modo=='R'){
            int c1, c2, l1, l2;
            cin >> c1;
            cin >> c2;
            cin >> l1;
            cin >> l2;
            Retangulo* r = new Retangulo(c1, c2, l1, l2);
            vetor.push_back(r);
        }
        
        if(modo=='C'){
            int c1, c2, R;
            cin >> c1;
            cin >> c2;
            cin >> R;
            Circulo* c = new Circulo(c1, c2, R);
            vetor.push_back(c);
            
        }
        
        if(modo=='T'){
            int c1, c2, b, a;
            cin >> c1;
            cin >> c2;
            cin >> b;
            cin >> a;
            Triangulo* t = new Triangulo(c1, c2, a, b);
            vetor.push_back(t);
        }
        
        if(modo=='D'){
            vector<figuraGeometrica*>::iterator it;
            for(it = vetor.begin(); it != vetor.end(); it++){
                (*it)->Desenha();
            }
        }
        
        if(modo=='A'){
            float sum = 0;
            vector<figuraGeometrica*>::iterator it;
            for(it = vetor.begin(); it != vetor.end(); it++){
                sum += (*it)->calculaArea();
            }
            cout << sum << endl;
        }
        
        if(modo=='E'){
            break;
        }
        
    }
    return 0;
}