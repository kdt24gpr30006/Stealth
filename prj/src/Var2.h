#pragma once  
#include <cmath>  
#include <DxLib.h>

// 変数が２個のクラス  
template<typename T>  
class Var2  
{  
public:  
    T x;  
    T y;  

    // コンストラクタ  
    Var2() : x(0.0f), y(0.0f) {}                                // 0代入  
    Var2(float argX, float argY) : x(argX), y(argY) {}        // 引数を代入  

    void Clear() { x = y = 0; }                                    // 0初期化  
    void Set(float argX, float argY) { x = argX; y = argY; }    // 値のセット  

    float GetLength() const { return std::hypot(x, y); };        // 長さ取得  
    void Normalize();                                            // 正規化  
    void SetLength(float length);                                // 長さ設定  

    void GetMousePos();                                            // マウスの座標を取る  

    Var2& operator =  (const Var2& f2);                    // = 演算子のオーバーロード  
    Var2& operator += (const Var2& f2);                    // += 演算子のオーバーロード  
    Var2& operator -= (const Var2& f2);                    // -= 演算子のオーバーロード  
    Var2& operator *= (const Var2& f2);                    // *= 演算子のオーバーロード  
    Var2& operator /= (const Var2& f2);                    // /= 演算子のオーバーロード  
};  

// 正規化（ベクトルの長さを１にする）  
template<typename T>  
void Var2<T>::Normalize()  
{  
    float length = GetLength();  
    if (length > 0.0f)  
    {  
        x /= length;  
        y /= length;  
    }  
}  

// 長さ設定  
template<typename T>  
void Var2<T>::SetLength(float length)  
{  
    Normalize();  
    x = x * length;  
    y = y * length;  
}  

// マウスの座標を取る  
template<typename T>  
void Var2<T>::GetMousePos()  
{  
    int mouse_x, mouse_y;  
    GetMousePoint(&mouse_x, &mouse_y);  

    x = static_cast<float>(mouse_x);  
    y = static_cast<float>(mouse_y);  
}  

// = 演算子のオーバーロード  
template<typename T>  
Var2<T>& Var2<T>::operator=(const Var2<T>& f2)  
{  
    x = f2.x;  
    y = f2.y;  
    return *this;  
}  

// += 演算子のオーバーロード  
template<typename T>  
Var2<T>& Var2<T>::operator+=(const Var2<T>& f2)  
{  
    x += f2.x;  
    y += f2.y;  
    return *this;  
}  

// -= 演算子のオーバーロード  
template<typename T>  
Var2<T>& Var2<T>::operator-=(const Var2<T>& f2)  
{  
    x -= f2.x;  
    y -= f2.y;  
    return *this;  
}  

// *= 演算子のオーバーロード  
template<typename T>  
Var2<T>& Var2<T>::operator*=(const Var2<T>& f2)  
{  
    x *= f2.x;  
    y *= f2.y;  
    return *this;  
}  

// /= 演算子のオーバーロード  
template<typename T>  
Var2<T>& Var2<T>::operator/=(const Var2<T>& f2)  
{  
    x /= f2.x;  
    y /= f2.y;  
    return *this;  
}

// + 演算子のオーバーロード  
template<typename T>  
Var2<T> operator+(const Var2<T>& f2_1, const Var2<T>& f2_2)  
{  
    return Var2<T>(f2_1.x + f2_2.x, f2_1.y + f2_2.y);  
}  

// - 演算子のオーバーロード  
template<typename T>  
Var2<T> operator-(const Var2<T>& f2_1, const Var2<T>& f2_2)  
{  
    return Var2<T>(f2_1.x - f2_2.x, f2_1.y - f2_2.y);  
}  

// * 演算子のオーバーロード  
template<typename T>  
Var2<T> operator*(const Var2<T>& f2, const float f)  
{  
    return Var2<T>(f2.x * f, f2.y * f);  
}  

// / 演算子のオーバーロード  
template<typename T>  
Var2<T> operator/(const Var2<T>& f2, const float f)  
{  
    return Var2<T>(f2.x / f, f2.y / f);  
}
