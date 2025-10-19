#pragma once  
#include <DxLib.h>
#include <cmath>  

// 2Dベクトルクラス  
template<typename T>
class Vec2
{
public:

	T x, y;

	// コンストラクタ  
	Vec2(T arg_x = 0, T arg_y = 0) : x(arg_x), y(arg_y) {}
	Vec2(const Vec2& v2) : x(v2.x), y(v2.y) {}

	// 値設定
	void Set(T arg_x, T arg_y) { x = arg_x; y = arg_y; }

	// 長さ取得  
	T GetLength() const { return std::sqrt(x * x + y * y); };
	// 長さの２乗取得
	T GetLengthSq() const { return x * x + y * y; };

	// 正規化  
	Vec2<T> Normalize();

	// 内積取得
	T Dot(const Vec2& f2) const { return x * f2.x + y * f2.y; }

	// 演算子オーバーロード
	Vec2& operator =  (const Vec2& f2);                    // = 演算子のオーバーロード  
	Vec2& operator += (const Vec2& f2);                    // += 演算子のオーバーロード  
	Vec2& operator -= (const Vec2& f2);                    // -= 演算子のオーバーロード  
	Vec2& operator *= (const Vec2& f2);                    // *= 演算子のオーバーロード  
	Vec2& operator /= (const Vec2& f2);                    // /= 演算子のオーバーロード  
};

// 正規化
template<typename T>
inline Vec2<T> Vec2<T>::Normalize()
{
	// ベクトルの長さを取得
	float length = GetLength();

	// ０のときはそのまま返す
	if (length == 0.0f)
		return Vec2<T>(0, 0);

	// 長さで割る
	x /= length;
	y /= length;

	// 正規化後のベクトルを返す
	return Vec2<T>(x, y);

}

// = 演算子のオーバーロード  
template<typename T>
Vec2<T>& Vec2<T>::operator=(const Vec2<T>& f2)
{
	x = f2.x;
	y = f2.y;
	return *this;
}

// += 演算子のオーバーロード  
template<typename T>
Vec2<T>& Vec2<T>::operator+=(const Vec2<T>& f2)
{
	x += f2.x;
	y += f2.y;
	return *this;
}

// -= 演算子のオーバーロード  
template<typename T>
Vec2<T>& Vec2<T>::operator-=(const Vec2<T>& f2)
{
	x -= f2.x;
	y -= f2.y;
	return *this;
}

// *= 演算子のオーバーロード  
template<typename T>
Vec2<T>& Vec2<T>::operator*=(const Vec2<T>& f2)
{
	x *= f2.x;
	y *= f2.y;
	return *this;
}

// /= 演算子のオーバーロード  
template<typename T>
Vec2<T>& Vec2<T>::operator/=(const Vec2<T>& f2)
{
	x /= f2.x;
	y /= f2.y;
	return *this;
}

// + 演算子のオーバーロード  
template<typename T>
Vec2<T> operator+(const Vec2<T>& f2_1, const Vec2<T>& f2_2)
{
	return Vec2<T>(f2_1.x + f2_2.x, f2_1.y + f2_2.y);
}

// - 演算子のオーバーロード  
template<typename T>
Vec2<T> operator-(const Vec2<T>& f2_1, const Vec2<T>& f2_2)
{
	return Vec2<T>(f2_1.x - f2_2.x, f2_1.y - f2_2.y);
}

// * 演算子のオーバーロード  
template<typename T>
Vec2<T> operator*(const Vec2<T>& f2, const float f)
{
	return Vec2<T>(f2.x * f, f2.y * f);
}

// / 演算子のオーバーロード  
template<typename T>
Vec2<T> operator/(const Vec2<T>& f2, const float f)
{
	return Vec2<T>(f2.x / f, f2.y / f);
}


// マウスの座標を取る  
template<typename T>
void GetMousePos(T& x, T& y)
{
	int mouse_x, mouse_y;
	GetMousePoint(&mouse_x, &mouse_y);

	x = static_cast<T>(mouse_x);
	y = static_cast<T>(mouse_y);
}