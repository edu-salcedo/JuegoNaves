#ifndef ALARMA_H_INCLUDED
#define ALARMA_H_INCLUDED


class Alarma
{
    private:
        int cont;
    public:
        Alarma();
        bool alarm(int);
};


Alarma::Alarma()
{
    this ->cont=0;
}


bool Alarma::alarm(int seg)
{
    if(seg == 0){
		return false;
	}

	if(cont >= seg){
		cont = 0;
		return true;
	}

	cont++;
}
#endif // ALARMA_H_INCLUDED
