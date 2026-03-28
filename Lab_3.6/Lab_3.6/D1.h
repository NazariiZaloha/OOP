
#include "B1.h"
#include "B2.h"

class D1 : public B1, public B2 {
protected:
    int d1;
public:
    D1(int v1, int v2, int vd1);
    ~D1();
    void show() override;
    int getD1() const { return d1; }
};
