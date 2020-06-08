#ifndef BALA_H_INCLUDED
#define BALA_H_INCLUDED
class Bala
{
private:
    int x;
    int y;
    BITMAP* sprite;
public:
    void mover_bala();
    Bala(int x,int y);
    int getx();
    int gety();
    ~Bala();
};

list < Bala*>balas;

int Bala::getx()
{
    return x;
}

int Bala::gety()
{
    return y;
}

Bala ::Bala(int x,int y)
{
    this ->x=x;
    this->y=y;
    this->sprite=load_bitmap("imagen/bala.bmp",NULL);
}

void Bala::mover_bala()
{

    if(y>0)
    {
        y--;
    }
    else
    {
        this->~Bala();
    }

    draw_sprite(lienzo,sprite,x,y);  //dibuja la bala sobre el fondo
}

Bala::~Bala()
{
    balas.remove(this);
}

static bool alarm(int secons){
	static int cont = 0;

	if(secons == 0){
		return false;
	}

	if(cont >= secons){
		cont = 0;
		return true;
	}

	cont++;

	return false;
}
#endif // BALA_H_INCLUDED
