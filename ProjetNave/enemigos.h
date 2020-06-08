#ifndef ENEMIGOS_H_INCLUDED
#define ENEMIGOS_H_INCLUDED
class Enemigo
{
private:
    float x;
    float y;
    BITMAP* sprite;
    int cont;
    Alarma*alar;
    int tipo;
public:
    Enemigo(float,float,int);
    void mover_enemigo();
    void accion();

};

Enemigo::Enemigo(float _x, float _y, int _tipo)
{
    this ->x=_x;
    this ->y=_y;
    this ->sprite = load_bitmap("imagen/enemigo.bmp",NULL);
    this ->alar = new Alarma[15];
    this ->tipo = _tipo;
}

void Enemigo::accion()
{

    for (list<Bala*>::iterator it =balas.begin(); it !=balas.end(); it++) // iterador de las balas del jugador
    {
        Bala* b= *it;
        if (b->getx() >=x && b->getx() <= x+sprite->w && b->gety() >=y && b->gety() <= y+sprite->h) //condicion par que la bala desaparesca la bala cuando coliicione con el enemigo
        {
            delete b;
        }
    }
    draw_sprite(lienzo,this->sprite,x,y);           // imprime al enemigo  sobre el lienzo

}




void Enemigo::mover_enemigo()
{
    switch(this->tipo)            //  funcion para el movimiento  de la nave enmiga hay 0,1 y 2 dependiendo del switch
    {
    case 0:
        if(this->alar[0].alarm(6))
        {
            x+=0.3;
            y+=0;
        }
        break;
    case 1:
        if(this->alar[1].alarm(6))
        {
            x+= 0.2;
            y+= cos(x/13);
        }
        break;

    case 2:
        if(this->alar[0].alarm(2))
        {
            x+= 1.5;

            if(this->y >= SCREEN_H - (SCREEN_H/3))
            {
                cont = -1;
            }

            if(cont == -1)
            {
                y+= pow((x-(this->x - SCREEN_H/4))/100,2) * cont;
            }
            else
            {
                y+= pow(x/100,2);
            }
        }
        break;
    }
}

#endif // ENEMIGOS_H_INCLUDED
