#ifndef CONJUNTO_H
#define CONJUNTO_H
#include <QString>

namespace Pedro{
class Conjunto
{
private:
    int tamanho;
    int *array;
    int *arraySelectionSort;
public:
    Conjunto(int tamanho);
    QString getConjunto() const;
    ~Conjunto();
    int buscarValor(int valor) const;
    void selectionSort();
};
}

#endif // CONJUNTO_H
