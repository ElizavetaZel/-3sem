#include <iostream>

struct subset_node {
    int key;
    subset_node *left;
    subset_node *right;
};

// инициализация пустого дерева (аналогично списку, пустое дерево это указатель на NULL)
bool init(subset_node **sn) {
    *sn = 0;
    return true;
}

// 2. поиск элемента в дереве, нужно вернуть указатель на элемент с тем же key или, если такого элемента не нашлось, то NULL
subset_node* find(subset_node *sn, int k) {
    while (sn) {
        if (sn->key == k) return sn;
        if (k < sn->key) sn = sn->left;
        else sn = sn->right;
    }
    return 0;
}

// 3. добавление элемента в дерево, дубли игнорировать (ничего не добавлять в дерево, если там уже есть элемент с таким же key) и возвращать false
bool insert(subset_node **sn, int k) {
    if (*sn == 0) {
        *sn = new subset_node;
        (*sn)->key = k;
        (*sn)->left = 0;
        (*sn)->right = 0;
        return true;
    }
    
    subset_node *cur = *sn;
    while (1) {
        if (cur->key == k) return false; // дубль
        if (k < cur->key) {
            if (cur->left == 0) {
                cur->left = new subset_node;
                cur->left->key = k;
                cur->left->left = 0;
                cur->left->right = 0;
                return true;
            }
            cur = cur->left;
        } else {
            if (cur->right == 0) {
                cur->right = new subset_node;
                cur->right->key = k;
                cur->right->left = 0;
                cur->right->right = 0;
                return true;
            }
            cur = cur->right;
        }
    }
}

// поиск наименьшего
subset_node* find_min(subset_node *sn) {
    while (sn->left) sn = sn->left;
    return sn;
}

// 4. удаление элемента из дерева (если элемента не нашлось, то ничего не удалять и вернуть false)
bool remove(subset_node **sn, int k) {
    if (*sn == 0) return false;
    
    
    if (k < (*sn)->key) return remove(&((*sn)->left), k);
    if (k > (*sn)->key) return remove(&((*sn)->right), k);
    
    subset_node *to_delete = *sn;
    
    if (to_delete->left == 0) {
        *sn = to_delete->right;
        delete to_delete;
        return true;
    }
    
    if (to_delete->right == 0) {
        *sn = to_delete->left;
        delete to_delete;
        return true;
    }
    
    subset_node *min_right = find_min(to_delete->right);
    
    to_delete->key = min_right->key;
    
    return remove(&(to_delete->right), min_right->key);
}

// 5. количество элементов в дереве
unsigned int size(subset_node *sn) {
    if (sn == 0) return 0;
    return 1 + size(sn->left) + size(sn->right);
}

// 6. высота дерева
unsigned int height(subset_node *sn) {
    if (sn == 0) return 0;
    unsigned int left_h = height(sn->left);
    unsigned int right_h = height(sn->right);
    return 1 + (left_h > right_h ? left_h : right_h);
}

// 7. очистить всю используемую память
void destructor(subset_node **sn) {
    if (*sn == 0) return;
    destructor(&((*sn)->left));
    destructor(&((*sn)->right));
    delete *sn;
    *sn = 0;
}

// dfs
void dfs_(subset_node *sn, int *arr, int *pos) {
    if (sn == 0) return;
    dfs_(sn->left, arr, pos);
    arr[(*pos)++] = sn->key;
    dfs_(sn->right, arr, pos);
}

// 8. обход в глубину, возвращает указатель на массив из динамической памяти (кучи)
int* DFS(subset_node *sn) {
    int n = size(sn);
    if (n == 0) return 0;
    
    int *arr = new int[n];
    int pos = 0;
    dfs_(sn, arr, &pos);
    return arr;
}