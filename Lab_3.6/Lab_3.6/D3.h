#include "D1.h"
#include "D2.h"

class D3 : public D1, public D2 {
protected:
    int d3;
public:
    D3(int v1, int v2, int vd1, int vd2, int vd3);
    ~D3();
    void show() override;
};