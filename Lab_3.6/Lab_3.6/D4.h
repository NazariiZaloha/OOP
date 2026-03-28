#include "D3.h"

class D4 : public D3 {
protected:
    int d4;
public:
    D4(int v1, int v2, int vd1, int vd2, int vd3, int vd4);
    ~D4();
    void show() override;
};