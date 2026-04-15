#include <vector>

int f (std::vector<int>& v){

    for (auto x : v){
        if (x == 0)
            break;
        else
            return 1;

        return 0;
    }

    return 0;
}