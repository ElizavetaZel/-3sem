bool init(subvector *qv)
{
    qv ->mas = NULL;
    qv ->top = 0;
    qv ->capacity = 0;
    return true;
} // инициализация пустого недовектора (top и capacity по нулям, а mas это NULL)

bool resize(subvector *qv, unsigned int new_capacity)
{
    unsigned int const new_top = (qv->top > new_capacity) ? new_capacity : qv->top;
    int * new_mas = new int[new_capacity];
    for (unsigned int i = 0; i< new_top; ++i)
    {
        new_mas[i] = qv->mas[i];
    }
    delete[] qv->mas;
    qv ->mas = new_mas;
    qv ->top = new_top;
    qv->capacity = new_capacity;
    return true;
}

bool push_back(subvector *qv, int d)
{
    if (qv -> top == qv -> capacity)
    {
        resize(qv, (qv ->capacity)*2 + 4);
    }
    qv ->mas[qv -> top] = d;
    ++qv->top;
    return true;
} // добавление элемента в конец недовектора с выделением дополнительной памяти при необходимости



int pop_back(subvector *qv)
{
    if (qv->top == 0)
    {
        return 0;
    }
    return qv->mas[--qv->top];


}


void shrink_to_fit(subvector *qv)
{
    resize(qv, qv->top);
} // очистить неиспользуемую память, переехав на новое место с уменьшением capacity до top



void clear(subvector *qv)
{
    qv->top = 0;
} // очистить содержимое недовектора, занимаемое место при этом не меняется



void destructor(subvector *qv)
{
    delete[] qv->mas;
    init(qv);

} 