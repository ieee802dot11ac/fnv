#pragma once

#include "d3d9i/d3d9types.h"
#include "types.h"

struct D3DXFLOAT16 { /* Size=0x2 */
    u16 value;
};

struct D3DXMATRIX : public D3DMATRIX {
    D3DXMATRIX(
        float,
        float,
        float,
        float,
        float,
        float,
        float,
        float,
        float,
        float,
        float,
        float,
        float,
        float,
        float,
        float
    );
    D3DXMATRIX(const D3DXFLOAT16 *);
    D3DXMATRIX(const D3DMATRIX &);
    D3DXMATRIX(const float *);
    D3DXMATRIX();
    float operator()(unsigned int, unsigned int) const;
    float &operator()(unsigned int, unsigned int);
    operator float *();
    operator const float *() const;
    D3DXMATRIX &operator=(const D3DXMATRIX &);
    D3DXMATRIX &operator*=(float);
    D3DXMATRIX &operator*=(const D3DXMATRIX &);
    D3DXMATRIX &operator+=(const D3DXMATRIX &);
    D3DXMATRIX &operator-=(const D3DXMATRIX &);
    D3DXMATRIX &operator/=(float);
    D3DXMATRIX operator+(const D3DXMATRIX &) const;
    D3DXMATRIX operator+() const;
    D3DXMATRIX operator-(const D3DXMATRIX &) const;
    D3DXMATRIX operator-() const;
    D3DXMATRIX operator*(float) const;
    D3DXMATRIX operator*(const D3DXMATRIX &) const;
    D3DXMATRIX operator/(float) const;
    int operator==(const D3DXMATRIX &) const;
    int operator!=(const D3DXMATRIX &) const;
};
