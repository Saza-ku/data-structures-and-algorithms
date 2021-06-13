#include "map.hpp"

// テストコード
int main() {
    struct map m;
    m = *(create_map());

    char hoge[100] = "hoge";
    char hego[100] = "hego";
    char geho[100] = "geho";
    char gohe[100] = "gohe";
    map_put(hoge, 1, &m);
    map_put(hego, 2, &m);
    map_put(geho, 3, &m);
    map_put(gohe, 4, &m);
    map_remove(hoge, &m);
    map_put(hoge, 11, &m);
    map_update(hoge, 111, &m);
    map_update(geho, 33, &m);
    map_remove(hego, &m);
    map_put(hego, 22, &m);
    int hoge_result = *(map_find(hoge, &m));
    int geho_result = *(map_find(geho, &m));
    int hego_result = *(map_find(hego, &m));
    int gohe_result = *(map_find(gohe, &m));

    printf("hoge: %d\n", hoge_result);
    printf("hego: %d\n", hego_result);
    printf("geho: %d\n", geho_result);
    printf("gohe: %d\n", gohe_result);
}
